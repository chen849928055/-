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
// P0M0 = 0x01;                        //P00����Ϊģ������
//    P0M1 = 0x61;                        //P01����Ϊ��ʩ�������ִ���������
//    P2M1 = 0x51;                        //P21����Ϊ��ʩ�������ִ���������
//    P2M3 = 0x69;                        //P23����Ϊʩ�������ִ���������
//    P3M4 = 0x59;                        //P34����Ϊʩ�������ִ���������
//    P3M5 = 0x71;                        //P35����Ϊ��ʩ�������ִ�����������
//    P2M5 = 0x79;                        //P25����Ϊʩ�������ִ�����������
//    P2M6 = 0xC1;                        //P26����Ϊ�������
//    P2M7 = 0xC5;                        //P27����Ϊ��©���
//    P1M7 = 0xE5;                        //P17����Ϊ��©���������	
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
	P2M1 = GPIO_In_FLOATING; //   WIFI״̬�źŲ�׽
	P2M2 = GPIO_In_AN; //SW_SCK
	P2M3 = GPIO_In_FLOATING; //   433���β�׽
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
