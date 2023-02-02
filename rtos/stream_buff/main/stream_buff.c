#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/stream_buffer.h>

TaskHandle_t task1_handle, task2_handle;
StreamBufferHandle_t stream_buf;
unsigned char rec_buff[200];
static int taskcore = 1;
void task_1(void *data)
{
    printf("Task 1 started....\n");
    xStreamBufferSend(stream_buf,"First message \n",15,pdMS_TO_TICKS(10000));
    xStreamBufferSend(stream_buf,"Second message \n",15,pdMS_TO_TICKS(10000));
    xStreamBufferSend(stream_buf,"Third message \n",15,pdMS_TO_TICKS(10000));
    printf("Task 1: Sending data to Task 2\n");
    vTaskDelete(NULL);
}

void task_2(void *data)
{
    printf("Task 2 started....\n");
    ssize_t rsize = xStreamBufferReceive(stream_buf,&rec_buff, 200,pdMS_TO_TICKS(10000));
    printf("Task 2: Received data: %d ::    %s \n",rsize, rec_buff );
    vTaskDelete(NULL);
}

void app_main(void)
{
    BaseType_t res_1, res_2;
    stream_buf = xStreamBufferCreate(200, 45);
    res_1  = xTaskCreatePinnedToCore(task_1, "First_task", 2048, NULL, 8, &task1_handle, taskcore);
    if(res_1 == pdPASS)
    {
        printf("    Task 1 successfully created...\n");
    }
    res_2 = xTaskCreatePinnedToCore(task_2, "Second_task", 2048, NULL, 5, &task2_handle, taskcore);
    if(res_2 == pdPASS)
    {
        printf("    Task 2 successfully created...\n");
    }
}


