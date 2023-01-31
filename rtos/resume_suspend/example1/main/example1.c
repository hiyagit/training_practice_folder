#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t	multi_task_handle_1, multi_task_handle_2;

void task_1(void *data)
{
	while(1)
	{
		printf(" Task 1 started...\n");
        vTaskSuspend(multi_task_handle_1);
        printf("Task 1 After suspension stopped..\n");
		vTaskDelay(100);
	}
	vTaskDelete(multi_task_handle_1);
}

void task_2(void *data)
{
        while(1)
        {
            printf(" Task 2 started...\n");
            vTaskResume(multi_task_handle_1);
            printf("Task 1 resumed..\n");
            vTaskDelay(100);
        }
        vTaskDelete(multi_task_handle_2);
}


void app_main(void)
{
	BaseType_t  res_1, res_2;
	UBaseType_t  prio_1,prio_2, maintask_prio;
	res_1 = xTaskCreate(task_1, "Task_First", 1024, NULL, 3, &multi_task_handle_1);
	if(res_1 == pdPASS)
	{
		printf("Task 1 successfully created....\n");
	}

	res_2 = xTaskCreate(task_2, "Task_Second", 1024, NULL, 6, &multi_task_handle_2);
	if(res_2 == pdPASS)
        {
                printf("Task 2 successfully created....\n");
        }

	prio_1 = uxTaskPriorityGet(multi_task_handle_1);
	printf("Priority of Task 1: %d\n",prio_1);
	
	prio_2 = uxTaskPriorityGet(multi_task_handle_2);
        printf("Priority of Task 2: %d\n",prio_2);
	
	maintask_prio = uxTaskPriorityGet(NULL);
	printf("priority of main Task: %d\n",maintask_prio);

}
