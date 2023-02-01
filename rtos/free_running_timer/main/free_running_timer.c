#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>

TaskHandle_t	task_handle;
TimerHandle_t timer_handle;

void timer_callback(TimerHandle_t timer_handle)
{
    printf("Timer fired..\n");
}

void task(void *data)
{
	while(1)
	{
		printf(" Task started...\n");
        timer_handle = xTimerCreate("free_running_timer",5000/portTICK_PERIOD_MS,pdTRUE, NULL, timer_callback);
        printf("Task After suspension stopped..\n");
        xTimerStart(timer_handle,0);
        vTaskDelete(task_handle);
    }
	
}


void app_main(void)
{
    BaseType_t  res;
    res = xTaskCreate(task, "Task_First", 2048, NULL, 3, &task_handle);
	if(res == pdPASS)
	{
		printf("Task successfully created....\n");
	}
}