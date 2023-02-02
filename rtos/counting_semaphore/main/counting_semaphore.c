#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

TaskHandle_t task_handle_1, task_handle_2, task_handle_3, task_handle_4;

SemaphoreHandle_t counting_sema;

static int taskcore = 1;

void task_1(void *data)
{
    printf("Task 1 started....\n");
    printf("Task 1 : Requesting for serial port\n");
    xSemaphoreTake(counting_sema,pdMS_TO_TICKS(20000));
    printf("Task 1: Got the serial port\n");
    vTaskDelay(10000/portTICK_PERIOD_MS);
    xSemaphoreGive(counting_sema);
    printf("Task 1: Released the serial port\n");
    vTaskDelete(NULL);
}

void task_2(void *data)
{
    // printf("Task 2 started....\n");
    printf("Task 2 : Requesting for serial port\n");
    xSemaphoreTake(counting_sema,pdMS_TO_TICKS(20000));
    printf("Task 2: Got the serial port\n");
    vTaskDelay(2000/portTICK_PERIOD_MS);
    xSemaphoreGive(counting_sema);
    printf("Task 2: Released the serial port\n");
    vTaskDelete(NULL);
}

void task_3(void *data)
{
    // printf("Task 2 started....\n");
    printf("Task 3 : Requesting for serial port\n");
    xSemaphoreTake(counting_sema,pdMS_TO_TICKS(20000));
    printf("Task 3: Got the serial port\n");
    vTaskDelay(3000/portTICK_PERIOD_MS);
    xSemaphoreGive(counting_sema);
    printf("Task 3: Released the serial port\n");
    vTaskDelete(NULL);
}

void task_4(void *data)
{
    // printf("Task 2 started....\n");
    printf("Task 4 : Requesting for serial port\n");
    xSemaphoreTake(counting_sema,pdMS_TO_TICKS(20000));
    printf("Task 4: Got the serial port\n");
    vTaskDelay(4000/portTICK_PERIOD_MS);
    xSemaphoreGive(counting_sema);
    printf("Task 4: Released the serial port\n");
    vTaskDelete(NULL);
}

void app_main(void)
{
    BaseType_t res_1, res_2, res_3, res_4;
    printf("Main Task\n");
    counting_sema = xSemaphoreCreateCounting(2,2);
    res_1 = xTaskCreatePinnedToCore(task_1,"First_task", 2048, NULL, 3, &task_handle_1, taskcore);
    if(res_1 == pdPASS)
    {
        printf("    Task 1 successfully created....\n");
    }
    res_2 = xTaskCreatePinnedToCore(task_2,"Second_task", 2048, NULL, 3, &task_handle_2, taskcore);
    if(res_2 == pdPASS)
    {
        printf("    Task 2 successfully created....\n");
    }
    res_3 = xTaskCreatePinnedToCore(task_3,"Third_task", 2048, NULL, 3, &task_handle_3, taskcore);
    if(res_3 == pdPASS)
    {
        printf("    Task 3 successfully created....\n");
    }
    res_4 = xTaskCreatePinnedToCore(task_4,"Fourh_task", 2048, NULL, 3, &task_handle_4, taskcore);
    if(res_4 == pdPASS)
    {
        printf("    Task 4 successfully created....\n");
    }
}
