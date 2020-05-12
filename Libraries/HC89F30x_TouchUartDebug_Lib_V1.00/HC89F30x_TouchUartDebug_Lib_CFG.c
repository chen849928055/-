/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_TouchUartDebug_Lib_CFG.c
* Author             : Touch Team
* Version            : V1.0.5.0
* Date               : 2019/10/01
********************************************************************************

注：本文件不建议用户自行修改！

*******************************************************************************/

//===================================================================================================
#include "HC89F303.h"
#include "HC89F30x_SYS.h"
#include "HC89F30x_TouchUartDebug_Lib_V1.00\HC89F30x_TouchUartDebug_Lib_CFG.h"

#if TouchUartDebugLib_SW
#pragma message "触摸串口调试功能：已开启，请调试结束后关闭"
#pragma message "触摸串口使用UART1相关资源，波特率由T4产生，若串口调试占用的资源与用户其它功能有冲突，请注意做相关必要的调整"
#include "HC89F30x_TouchUartDebug_Lib_V1.00\HC89F30x_TouchUartDebug_Lib_Build_Message.h"
#else
#pragma message "触摸串口调试功能：未开启"
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
#error		"触摸调试管脚设置错误，请在HC89F30x_TouchUartDebug_Lib_CFG.h文件中重新配置TouchUartDebugLib_TXD_Px_y"
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
