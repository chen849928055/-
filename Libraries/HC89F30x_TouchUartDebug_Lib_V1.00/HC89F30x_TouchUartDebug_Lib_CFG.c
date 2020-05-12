/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_TouchUartDebug_Lib_CFG.c
* Author             : Touch Team�Z
* Version            : V1.0.5.0
* Date               : 2019/10/01
********************************************************************************

ע�����ļ��������û������޸ģ�

*******************************************************************************/

//===================================================================================================
#include "HC89F303.h"
#include "HC89F30x_SYS.h"
#include "HC89F30x_TouchUartDebug_Lib_V1.00\HC89F30x_TouchUartDebug_Lib_CFG.h"

#if TouchUartDebugLib_SW
#pragma message "�������ڵ��Թ��ܣ��ѿ���������Խ�����ر�"
#pragma message "��������ʹ��UART1�����Դ����������T4�����������ڵ���ռ�õ���Դ���û����������г�ͻ����ע������ر�Ҫ�ĵ���"
#include "HC89F30x_TouchUartDebug_Lib_V1.00\HC89F30x_TouchUartDebug_Lib_Build_Message.h"
#else
#pragma message "�������ڵ��Թ��ܣ�δ����"
#endif

#if TouchUartDebugLib_SW
//===================================================================================================
void CTK_Debug_Mode_Uart_SendChar(u8 send_data);
void CTK_Debug_Mode_Uart_SendWord(u16 send_data);

//===================================================================================================
void CTK_TouchUartDebug_Init()
{
#ifndef		SET_Touch_TXD_PORT_MODE
#define		SET_Touch_TXD_PORT_MODE
#error		"�������Թܽ����ô�������HC89F30x_TouchUartDebug_Lib_CFG.h�ļ�����������TouchUartDebugLib_TXD_Px_y"
#endif

#ifndef 	Touch_TXD_MAP
#define		Touch_TXD_MAP  0x37
#endif

	SET_Touch_TXD_PORT_MODE;
	TXD_MAP = Touch_TXD_MAP;

	//T4
	SCON2 = 0x02;   // uart mode 1
	T4 = 65536.5 - (SYSCLK_FOSC / 16 / TouchUartDebugLib_BAUDRATE); //
	T4CON = 0x06;	//UART1 BaudRate fosc
}

//===================================================================================================
void CTK_Debug_Mode_Uart_SendChar(u8 send_data)
{
	SBUF = send_data;

	while(!TI);

	TI = 0;
}

//===================================================================================================
void CTK_Debug_Mode_Uart_SendWord(u16 send_data)
{
	SBUF = (u8)(send_data >> 8);

	while(!TI);

	TI = 0;

	SBUF = (u8)send_data;

	while(!TI);

	TI = 0;
}

#endif

/*********************************END OF FILE************************************/
/******************* (C) COPYRIGHT 2009~2019 holychip ***************************/
