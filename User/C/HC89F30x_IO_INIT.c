/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_IO_INIT.c
********************************************************************************


*******************************************************************************/
#include	"HC89F303.h"
#include	"HC89F30x_IO_INIT.h"

/****************************************************************************
* Function Name  :
* Description    :
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
// P0M0 = 0x01;                        //P00设置为模拟输入
//    P0M1 = 0x61;                        //P01设置为非施密特数字带上拉输入
//    P2M1 = 0x51;                        //P21设置为非施密特数字带下拉输入
//    P2M3 = 0x69;                        //P23设置为施密特数字带上拉输入
//    P3M4 = 0x59;                        //P34设置为施密特数字带下拉输入
//    P3M5 = 0x71;                        //P35设置为非施密特数字带上下拉输入
//    P2M5 = 0x79;                        //P25设置为施密特数字带上下拉输入
//    P2M6 = 0xC1;                        //P26设置为推挽输出
//    P2M7 = 0xC5;                        //P27设置为开漏输出
//    P1M7 = 0xE5;                        //P17设置为开漏带上拉输出	
void IO_Init(void)
{
	P0 = 0X00;
	P0M0 = GPIO_In_AN; //
	P0M1 = GPIO_In_AN; //
	P0M2 = GPIO_Out_PP; //   K1GPIO_Out_OD_Level2
//	P0M2 = GPIO_Out_ODPU;
	P0M3 = GPIO_In_AN; //
	P0M4 = GPIO_In_AN; //
	P0M5 = GPIO_In_AN; //
	P0M6 = GPIO_In_AN; //
	P0M7 = GPIO_In_AN; //

	P1M0 = GPIO_In_AN; //
	P1M1 = GPIO_In_AN; //
	P1M2 = GPIO_In_AN; //
	P1M3 = GPIO_In_AN; //
//	P1M3 = GPIO_Out_ODPU; //
	
	P1M4 = GPIO_In_AN; //
	P1M5 = GPIO_In_AN; //
	P1M6 = GPIO_In_AN; //
	P1M7 = GPIO_In_AN; //

	P2 = 0X00;
	P2M0 = GPIO_In_AN; //SW_SDA
	P2M1 = GPIO_In_FLOATING; //   WIFI状态信号捕捉
	P2M2 = GPIO_In_AN; //SW_SCK
	P2M3 = GPIO_In_FLOATING; //   433波形捕捉
	P2M4 = GPIO_Out_PP; // K2
	P2M5 = GPIO_In_AN; //
	P2M6 = GPIO_In_AN; //
	P2M7 = GPIO_In_AN; //

	P3 = 0X00;
	P3M4 = GPIO_Out_PP; // BUZ
	P3M5 = GPIO_Out_PP; // K3
}

/*********************************END OF FILE************************************/
/******************* (C) COPYRIGHT 2009~2019 holychip ***************************/
