
#include "Serial_Drv.h"


SoftwareSerial mySerial(SOFT_RX_PIN, SOFT_TX_PIN); // RX, TX

static char rx_buff[128];
E_BOOL isRxComplete = E_FALSE;  // whether the string is complete

static int serial_putc( char c, struct __file * )
{
  mySerial.write( c );
  return c;
}
static void printf_begin(void)
{
  fdevopen( &serial_putc, 0 );
}

static void uart_putc(void *p, char c)
{
  mySerial.write(c);
}


#if SW_PRINTF_EN
#include <stdio.h>
FILE __stdout;  

//------------------------------------
//函数名：fputc()
// 参数：int ch，FILE *f
// 返回值：int
// 功能：重新定义stdio.h中的fputc()函数，使printf()输出到USART1
int fputc(int ch, FILE *f)
{
    uart_putc(f, ch);
    return ch;
}
#endif



void FLASH_SAVE SerialDrv_Init(ATCMD_RxProcessFunc func)
{
   func = func;
   mySerial.begin(4800);
   //printf_begin();
   
  #if SW_PRINTF_EN
  os_printf("use <stdio.h> printf\r\n");
  #else
  init_tfp_printf(NULL, uart_putc);
  os_printf("use tfp_printf\r\n");
  #endif
  
   mySerial.println("Hello, world\r\n");
   
   
   Serial.begin(115200);
}

static const char HEX_CHAR[] = {
'0','1','2', '3',
'4','5','6', '7',
'8','9','A', 'B',
'C','D','E', 'F',
};

void SerialDrv_PrintHex(char c)
{
	mySerial.write(HEX_CHAR[(c & 0xF0) >> 4]);
	mySerial.write(HEX_CHAR[c & 0x0F]);
}

// send msg to wifi
void SerialDrv_UartSend(char *data)
{
   Serial.print(data);
}

// debug info output, no change line
void SerialDrv_Print(char *data)
{
  mySerial.print(data);
}



// debug info output, then change another line
void SerialDrv_Println(char *data)
{
   mySerial.println(data);
}


void SerialDrv_Task(ATCMD_RxProcessFunc AtCmdRxProcessFunc)
{
   int16_t len = 0;
   
   if (isRxComplete) 
   {
		len = os_strlen(rx_buff);
		AtCmdRxProcessFunc((uint8_t *)rx_buff, len);	
		isRxComplete = E_FALSE;
  }
}

void FLASH_SAVE SerialDrv_SetRxCompleteBool(E_BOOL isComplete)
{
   os_memset(rx_buff, 0, sizeof(rx_buff));
   isRxComplete = isComplete;
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() 
{
  uint8_t data = 0;
  static uint8_t index = 0;
  
  while (Serial.available()) 
  {
    data = (uint8_t)Serial.read();   // get the new byte
	if(isRxComplete == E_FALSE)
	{
	   if(index < sizeof(rx_buff))
	   {
	      rx_buff[index++] = data;
	   }
    }
    if (data == 0 || data == '\n') 
    {
        isRxComplete = E_TRUE;
		index = 0;
    }else if(index >= sizeof(rx_buff))
    {
       index = 0; 
	   os_memset(rx_buff, 0, sizeof(rx_buff));
    }
  }  
}


