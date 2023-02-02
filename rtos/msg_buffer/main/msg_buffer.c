#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/message_buffer.h>

TaskHandle_t task1_handle, task2_handle;
MessageBufferHandle_t msg_buf;
static int taskcore = 1;

void task_1(void *data)
{
    printf("Task 1 started....\n");
    xMessageBufferSend(msg_buf, "First_message",20,pdMS_TO_TICKS(5000));
    xMessageBufferSend(msg_buf, "Second_message",20,pdMS_TO_TICKS(5000));
    xMessageBufferSend(msg_buf, "Third_message",20,pdMS_TO_TICKS(5000));
    printf("Task 1: Sending data to Task 2\n");
    vTaskDelete(NULL);
}

void task_2(void *data)
{
    unsigned char rec_buff[200];
    printf("Task 2 started....\n");
    for(int count =0; count<3; count++)
    {
        xMessageBufferReceive(msg_buf,&rec_buff, 200,pdMS_TO_TICKS(5000));
        printf("Task 2: Received data is %s\n",rec_buff);
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    BaseType_t res_1, res_2;
    msg_buf = xMessageBufferCreate(200);
    res_1 = xTaskCreatePinnedToCore(task_1, "First_task", 2048, NULL, 3, &task1_handle, taskcore);
    if(res_1 == pdPASS)
    {
        printf("    Task 1 successfully created...\n");
    }
    res_2 = xTaskCreatePinnedToCore(task_2, "Second_task", 2048, NULL, 3, &task2_handle, taskcore);
    if(res_2 == pdPASS)
    {
        printf("    Task 2 successfully created...\n");
    }
}
