#include "main.h"
#include "stdio.h"

 static void TaskBlinkLed1(void *pvParameters);
 static void TaskBlinkLed2(void *pvParameters);
 int x,y;
void main()
{ 
     xTaskCreate(TaskBlinkLed1,"TaskModbusPoll", 2000, NULL, 5, NULL);
     xTaskCreate(TaskBlinkLed2,"TaskModbusPol2", 2000, NULL, 6, NULL);
     vTaskStartScheduler();
     
     while(1);
}

static void TaskBlinkLed1(void *pvParameters)
 {  
     for(;;) 
     {
       x++; 
       vTaskDelay(2000);
     }
 }

static void TaskBlinkLed2(void *pvParameters)
 {  
   for(;;) 
   {
      y++;
      vTaskDelay(2000);

     }
 }