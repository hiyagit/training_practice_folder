#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#define MQ_SIZE 4
#define MSG_SIZE 64

TaskHandle_t task1_handle, task2_handle, task3_handle, task4_handle;
QueueHandle_t mq_handle;
static int taskcore = 1;

void task_1(void *data)
{
    int task1_data = 100;
    printf("Task1\n");
    while(1)
    {
        task1_data++;
        xQueueSend(mq_handle,&task1_data, pdMS_TO_TICKS(5000));
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

void task_2(void *data)
{
    int task2_data = 200;
    printf("Task2\n");
    while(1)
    {
        task2_data++;
        xQueueSend(mq_handle,&task2_data, pdMS_TO_TICKS(5000));
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

void task_3(void *data)
{
    int buffer = 0;
    printf("Task3\n");
    while(1)
    {
        xQueueReceive(mq_handle, &buffer, portMAX_DELAY);
        printf("Task 3: Received data: %d\n", buffer);
    }
    vTaskDelete(NULL);
}

void task_4(void *data)
{
    int buffer = 0;
    int count = 0;
    printf("Task4\n");
    while(1)
    {
        xQueueReceive(mq_handle, &buffer, pdMS_TO_TICKS(1000));
        printf("Task 4: Received data: %d\n", buffer);
        count++;
        if(count>20)
        {
            count = 0;
            vTaskDelay(pdMS_TO_TICKS(5000));
        }
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    BaseType_t res_1, res_2, res_3, res_4;
    mq_handle = xQueueCreate(MQ_SIZE, MSG_SIZE);
    res_1  = xTaskCreatePinnedToCore(task_1, "First_task", 2048, NULL, 3, &task1_handle, taskcore);
    if(res_1 == pdPASS)
    {
        printf("    Task 1 successfully created...\n");
    }
    res_2 = xTaskCreatePinnedToCore(task_2, "Second_task", 2048, NULL, 5, &task2_handle, taskcore);
    if(res_2 == pdPASS)
    {
        printf("    Task 2 successfully created...\n");
    }
    res_3 = xTaskCreatePinnedToCore(task_3, "Third_task", 2048, NULL, 8, &task3_handle, taskcore);
    if(res_3 == pdPASS)
    {
        printf("    Task 3 successfully created...\n");
    }
    res_4 = xTaskCreatePinnedToCore(task_4, "Fourth_task", 2048, NULL, 12, &task4_handle, taskcore);
    if(res_4 == pdPASS)
    {
        printf("    Task 4 successfully created...\n");
    }
}
