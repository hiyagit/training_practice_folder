#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t	multi_task_handle_1, multi_task_handle_2, multi_task_handle_3;

void task_1(void *data)
{
	while(1)
	{
		printf(" Task 1 started...\n");
        vTaskSuspend(multi_task_handle_1);
        printf("Task 1 After suspension stopped..\n");
        printf("Task 1 resumed..\n");
		vTaskDelay(100);
	}
	vTaskDelete(multi_task_handle_1);
}

void task_2(void *data)
{
	while(1)
	{
		printf(" Task 2 started...\n");
        vTaskSuspend(multi_task_handle_2);
        printf("Task 2 After suspension stopped..\n");
        printf("Task 2 resumed..\n");
		vTaskDelay(100);
	}
	vTaskDelete(multi_task_handle_2);
}

void task_3(void *data)
{
        while(1)
        {
            printf(" Task 3 started...\n");
            vTaskResume(multi_task_handle_1);
            vTaskResume(multi_task_handle_2);   
            vTaskDelay(100);
        }
        vTaskDelete(multi_task_handle_3);
}

void app_main(void)
{
	BaseType_t  res_1, res_2, res_3;
	UBaseType_t  prio_1,prio_2, prio_3, maintask_prio;
	res_1 = xTaskCreate(task_1, "Task_First", 1024, NULL, 8, &multi_task_handle_1);
	if(res_1 == pdPASS)
	{
		printf("Task 1 successfully created....\n");
	}

	res_2 = xTaskCreate(task_2, "Task_Second", 1024, NULL, 6, &multi_task_handle_2);
	if(res_2 == pdPASS)
        {
                printf("Task 2 successfully created....\n");
        }

    res_3 = xTaskCreate(task_3, "Task_Third", 1024, NULL, 2, &multi_task_handle_3);
	if(res_3 == pdPASS)
	{
		printf("Task 3 successfully created....\n");
	}

	prio_1 = uxTaskPriorityGet(multi_task_handle_1);
	printf("Priority of Task 1: %d\n",prio_1);
	
	prio_2 = uxTaskPriorityGet(multi_task_handle_2);
        printf("Priority of Task 2: %d\n",prio_2);
	
    prio_3 = uxTaskPriorityGet(multi_task_handle_3);
	printf("Priority of Task 1: %d\n",prio_3);
	
	maintask_prio = uxTaskPriorityGet(NULL);
	printf("priority of main Task: %d\n",maintask_prio);

}


