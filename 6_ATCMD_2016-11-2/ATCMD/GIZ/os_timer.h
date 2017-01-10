
#ifndef __OS_TIMER_H__
#define  __OS_TIMER_H__

#include "Arduino.h"
#include "GlobalDef.h"
#include "GlobalFunc.h"
#include "string.h"

#define OS_TIMER_FLAG_DEACTIVATED 0x00
#define OS_TIMER_FLAG_ACTIVATED   0x01
#define OS_TIMER_FLAG_ONE_SHOT    0x00
#define OS_TIMER_FLAG_PERIODIC    0x02


#if TIMER_DEBUG_EN
#define TIMER_DEBUG  os_printf
#else
#define TIMER_DEBUG(...)
#endif

typedef void (*timeout_callback)(void * param);
typedef struct struct_os_timer T_OS_TIMER;

typedef void os_timer_func_t(void *timer_arg);
typedef T_OS_TIMER  os_timer_t;



typedef struct struct_os_timer
{
   T_OS_TIMER * prev;
   T_OS_TIMER * next;
   uint8_t         flag;
   uint32_t        init_tick;
   uint32_t        timeout_tick;
   timeout_callback timeout_func;
   void * param;
}T_OS_TIMER;

void OS_TimerInit(T_OS_TIMER * timer, timeout_callback timeout_func, void * param, uint32_t time, uint8_t flag);
OS_RESULT OS_TimerStart(T_OS_TIMER * timer);
void OS_TimerStop(T_OS_TIMER * timer);
void OS_TimerCheck(void);
void OS_TimerTickIncrease(uint32_t tick);
void OS_TimerTask(void);

#define  os_timer_disarm(timer)  OS_TimerStop(timer)
void os_timer_setfn(os_timer_t *timer, os_timer_func_t * func, void *parg);
void os_timer_arm(os_timer_t * timer, uint32_t ms, uint8_t is_repeat);

#endif

