/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_TouchUartDebug_Lib_CFG.h
* Author             : Touch Team
* Version            : V1.0.5.0
* Date               : 2019/10/01
********************************************************************************

注：凡是TouchUartDebugLib开头的宏定义，用户可以根据实际调试需要，修改后面的数据

*******************************************************************************/
#ifndef __HC89F30x_TouchUartDebug_Lib_CFG_H__
#define __HC89F30x_TouchUartDebug_Lib_CFG_H__

//===================================================================================================
//触摸调试开关  
//						0：禁止编译时加载触摸调试程序，触摸参数确定后，请选择“0”
//						1：允许编译时加载触摸调试程序，此时可以通过触摸调试工具及配套软件获取内部相关数据，方便用户开发时调试触摸参数
#define	TouchUartDebugLib_SW						1

//===================================================================================================
//触摸串口调试波特率设定，不建议修改，必需修改时，请用户自行确认所设波特率是否正常
#define TouchUartDebugLib_BAUDRATE  		1000000

// 选择触摸调试通信时数据端口， 格式TouchUartDebugLib_TXD_Px_y，如下若宏定义为”#define TouchUartDebugLib_TXD_P3_5" 表示触摸调试通信时选择P3.5 为 Touch_TXD端口
#define TouchUartDebugLib_TXD_P2_0     

//串口输出模式与驱动能力设定，一般不需要修改
#define TouchUartDebugLib_TXD_PORT_Levelx    GPIO_Out_PP

#endif /*__HC89F30x_TouchUartDebug_Lib_CFG_H__*/
