
#ifndef __OS_TIMER_H__
#define  __OS_TIMER_H__

#include "Arduino.h"
#include "GlobalDef.h"
#include "GlobalFunc.h"
#include "string.h"

#define COS_TIMER_FLAG_DEACTIVATED 0x00
#define COS_TIMER_FLAG_ACTIVATED   0x01
#define COS_TIMER_FLAG_ONE_SHOT    0x00
#define COS_TIMER_FLAG_PERIODIC    0x02


#if TIMER_DEBUG_EN
#define TIMER_DEBUG  os_printf
#else
#define TIMER_DEBUG(...)
#endif

typedef void (*timeout_callback)(void * param);
typedef struct struct_cos_timer T_COS_TIMER;

typedef void os_timer_func_t(void *timer_arg);
typedef T_COS_TIMER  os_timer_t;



typedef struct struct_cos_timer
{
   T_COS_TIMER * prev;
   T_COS_TIMER * next;
   uint8_t         flag;
   uint32_t        init_tick;
   uint32_t        timeout_tick;
   timeout_callback timeout_func;
   void * param;
}T_COS_TIMER;

void COS_TimerInit(T_COS_TIMER * timer, timeout_callback timeout_func, void * param, uint32_t time, uint8_t flag);
OS_RESULT COS_TimerStart(T_COS_TIMER * timer);
void COS_TimerStop(T_COS_TIMER * timer);
void COS_TimerCheck(void);
void COS_TimerTickIncrease(uint32_t tick);
void COS_TimerTask(void);

#define  os_timer_disarm(timer)  COS_TimerStop(timer)
void os_timer_setfn(os_timer_t *timer, os_timer_func_t * func, void *parg);
void os_timer_arm(os_timer_t * timer, uint32_t ms, uint8_t is_repeat);

#endif

