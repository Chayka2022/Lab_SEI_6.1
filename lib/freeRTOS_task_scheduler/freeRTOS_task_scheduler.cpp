#include "freeRTOS_task_scheduler.h"


void FreeRTOS_scheduler_setup(void *pvParameters)
{
    xTaskCreate(
                    fsm_run_task,
                    "fsm_run_task",
                    100,
                    NULL,
                    1,
                    NULL
                );
    
    xTaskCreate(
                    fsm_event_handler_task,
                    "fsm_event_handler_task",
                    100,
                    NULL,
                    1,
                    NULL
                );

    vTaskStartScheduler();
}

void fsm_run_task(void *pvParameters)
{
    static uint8_t need_init = true;

    while(true)
    {  
        if(need_init)
        {
            fsm_init_task();
            need_init = false;
        }
        //printf("fsm_run_task\n\r");
        fsm_run();
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }

}

void fsm_event_handler_task(void *pvParameters)
{    
    static uint8_t need_init = 1;

    while(true)
    {
        if(need_init)
        {
            vTaskDelay(50/portTICK_PERIOD_MS);
            need_init = 0;
        }

        //printf("fsm_event_handler_task\n\r");
        fsm_event_handler();
        vTaskDelay(300/portTICK_PERIOD_MS);
    }
}

void fsm_init_task(void)
{
    own_stdio_setup();
    fsm_init();
}

void vApplicationIdleHook()
{
    
}