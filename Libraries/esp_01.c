#include "esp_01.h"
 char Buff[100];
 int index=0;

void esp_01_init()
{   
  
USART1_init(115200);
printf("okokok");
char s1[20];
char str[500]="";

     USART_Send_string(USART1,"AT\r\n");
     delayms(100);
     
     USART_Send_string(USART1,"AT+RST\r\n");
     delayms(3000);
     index=0;
     
     USART_Send_string(USART1,"AT+CWMODE=1\r\n");
     delayms(100);
     while(strstr(Buff,"OK")==NULL);
     index=0;
     
     USART_Send_string(USART1,"AT+CWJAP=\"Realme 2\",\"12346789\"\r\n");
     delayms(1000);
     while(strstr(Buff,"WIFI GOT IP")==NULL);
     while(strstr(Buff,"OK")==NULL);
     index=0;
     
     
    
     USART_Send_string(USART1,"AT+CIPMUX=1\r\n");
     delayms(100);
     while(strstr(Buff,"OK")==NULL);
     index=0;
     
     USART_Send_string(USART1,"AT+CIFSR\r\n");
     delayms(100);
     while(strstr(Buff,"OK")==NULL);
     index=0;
   /*********************WEBSERVER INIT***********************/
     USART_Send_string(USART1,"AT+CIPSERVER=1,80\r\n"); 
     delayms(100);
     while(strstr(Buff,"OK")==NULL);
     index=0;
     
     USART_Send_string(USART1,"AT+CIPSTO=300\r\n");
     delayms(100);
     while(strstr(Buff,"OK")==NULL);
     
     while(strstr(Buff,"CONNECT")==NULL);
     
     sprintf(s1,"AT+CIPSEND=0,%d\r\n",strlen(str));
     
     USART_Send_string(USART1,s1);
     delayms(100);
     index=0;
     
     USART_Send_string(USART1,str);
     delayms(100);
     index=0;

     USART_Send_string(USART1,"AT+CIPCLOSE=0\r\n");
     delayms(100);
     index=0;
     
}
int x=0;
char ch;
void USART1_IRQHandler(void){
if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
{
    ch = USART_ReceiveData(USART1);
    printf("%c",ch);
    USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    }

}
 
void USART3_IRQHandler(){
    x++;
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET){
    ch = USART_ReceiveData(USART3);
    printf("%c",ch);
    USART_ClearITPendingBit(USART3, USART_IT_RXNE);
    }

}