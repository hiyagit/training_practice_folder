#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t serial_task_handle;

void serial_task(void * data)
{
    printf("Serial task: started..\n");
    vTaskDelete(serial_task_handle);
}

void app_main(void)
{
    BaseType_t result;
    UBaseType_t prio, maintask_prio;
    result = xTaskCreate(serial_task, "serialtask", 2048, NULL, 3, &serial_task_handle);
    // result = xTaskCreate(serial_task, "serialtask", 2048, NULL, &serial_task_handle);
    if(result == pdPASS)
    {
        printf("Task successflly created!!\n");
    }
    prio = uxTaskPriorityGet(serial_task_handle);
    printf("Priority of serial task: %d\n",prio);
    maintask_prio = uxTaskPriorityGet(NULL);
    printf("Priority of main task: %d\n",maintask_prio);

}