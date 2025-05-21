#ifndef FREERTOS_TASK_SCHEDULER_H
#define FREERTOS_TASK_SCHEDULER_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "config.h"
#include "own_stdio.h"
#include "dd_fsm.h"

void FreeRTOS_scheduler_setup(void *pvParameters);

void fsm_run_task(void *pvParameters);
void fsm_event_handler_task(void *pvParameters);
void fsm_init_task(void);

void vApplicationIdleHook(void);

#endif // !FREERTOS_TASK_SCHEDULER_H