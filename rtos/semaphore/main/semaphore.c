#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

TaskHandle_t task_handle_1, task_handle_2;

SemaphoreHandle_t sema_handle;

void task_1(void *data)
{
    printf("Received processing..!!     2\n");
    vTaskDelay(pdMS_TO_TICKS(2000));
    xSemaphoreGive(sema_handle);
    printf("Processing completed..!!    4\n");
    vTaskDelete(task_handle_1);
}

void task_2(void *data)
{
    printf("In the processing task_2..   1\n");
    xSemaphoreTake(sema_handle, pdMS_TO_TICKS(5000));
    printf("Process sent to task_1..    3\n");
    vTaskDelete(task_handle_2);
}

void app_main(void)
{
    BaseType_t res_1, res_2;

    sema_handle = xSemaphoreCreateBinary();
    
    res_2 = xTaskCreate(task_2, "task_2", 2048, NULL, 8, &task_handle_2);
    if(res_2 == pdPASS)
	{
		printf("    Task 1 successfully created....\n");
	}

    res_1 = xTaskCreate(task_1, "task_1", 2048, NULL, 5, &task_handle_1);
    if(res_1 == pdPASS)
	{
		printf("    Task 2 successfully created....\n");
	}

    vTaskDelay(pdMS_TO_TICKS(20000));
}
