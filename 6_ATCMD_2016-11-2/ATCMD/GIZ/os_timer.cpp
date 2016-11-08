
#include "Arduino.h"
#include "Serial_Drv.h"
#include "os_timer.h"



static T_COS_TIMER * head_handle = NULL;
static uint32_t timer_tick = 0;
	
void COS_TimerInit(T_COS_TIMER * timer, 
                                     timeout_callback timeout_func, 
                                     void * param,
                                     uint32_t time,
                                     uint8_t flag)
{
   timer->timeout_func = timeout_func;
   timer->param = param;
   timer->init_tick = time;
   timer->timeout_tick = Sys_GetRunTime() + time;
   timer->flag = flag;
}



OS_RESULT COS_TimerStart(T_COS_TIMER * timer)
{
   T_COS_TIMER * target = head_handle;
   while(target)
   {
      if(target == timer)
	  {
	     target->flag |= COS_TIMER_FLAG_ACTIVATED;
		 SERIAL_DEBUG("timer 0x%x existed\r\n", (long)timer);
		 return OS_OK;
	  }
	  target = target->next;
   }
   
   timer->next = head_handle;
   head_handle = timer;  // pointe to the last timer
   timer->flag |= COS_TIMER_FLAG_ACTIVATED;
   	
   TIMER_DEBUG("handle = 0x%x, flag = 0x%x\r\n", (long)head_handle, (long)timer->flag);
   
   return OS_OK;
}

void COS_TimerStop(T_COS_TIMER * timer)
{
   T_COS_TIMER * cur;
   
   for(cur = head_handle; cur; cur = cur->next)
   {
      
      if(cur == timer)
      {
         cur->flag &= ~ COS_TIMER_FLAG_ACTIVATED;
         TIMER_DEBUG("stop timer: 0x%x\r\n", (long)cur);
      }
   }
}

void COS_TimerCheck(void)
{
   T_COS_TIMER *cur = NULL;
   
   for(cur = head_handle; cur; cur = cur->next)
   {
      if(Sys_GetRunTime() >= cur->timeout_tick &&
	  	(cur->flag & COS_TIMER_FLAG_ACTIVATED))	
      {
		   TIMER_DEBUG("timer tick out: %d ms\r\n", Sys_GetRunTime());
		   if(! (cur->flag & COS_TIMER_FLAG_PERIODIC))
		   {
		       cur->flag &= ~COS_TIMER_FLAG_ACTIVATED;
		   }
		   else
		   {
		      cur->timeout_tick = Sys_GetRunTime() + cur->init_tick;
		   }
		   cur->timeout_func(cur->param);
      }
   }
}

void COS_TimerTickIncrease(uint32_t tick)
{
   timer_tick++;
}

void COS_TimerTask(void)
{
   if(Sys_GetRunTime() > (timer_tick + 10))  // 10 ms
   {
      timer_tick = Sys_GetRunTime();
      COS_TimerCheck();
   }
}

void os_timer_setfn(os_timer_t *timer, os_timer_func_t * func, void *parg)
{
   COS_TimerInit(timer, func, parg, 0, 0);
}

void os_timer_arm(os_timer_t * timer, uint32_t ms, uint8_t is_repeat)
{
   timer->init_tick = ms;
   timer->timeout_tick = Sys_GetRunTime() + ms;
   if(is_repeat)
   {
      timer->flag |= COS_TIMER_FLAG_PERIODIC;  // timer repeat
   }
   COS_TimerStart(timer);
}


