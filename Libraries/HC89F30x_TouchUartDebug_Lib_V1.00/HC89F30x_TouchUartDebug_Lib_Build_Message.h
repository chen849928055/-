/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_TouchUartDebug_Lib_Lib_Build_Message.h
* Author             : Touch Team
* Version            : V1.0.5.0
* Date               : 2019/10/01
********************************************************************************

注：本文件不建议用户修改！

*******************************************************************************/
#ifndef __HC89F30x_TouchUartDebug_Lib_Build_Message_H__
#define __HC89F30x_TouchUartDebug_Lib_Build_Message_H__

//================================================================================
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Lib_CFG.h"
#include "HC89F30x_TouchUartDebug_Lib_V1.00\HC89F30x_TouchUartDebug_Lib_CFG.h"
#include "HC89F30x_IO_INIT.h"
#include "HC89F30x_PORT_MAP.h"

//================================================================================
#if (HCTouchLib_IC_BODY == IC_BODY_SOP16)
//================================================================================
#ifdef TouchUartDebugLib_TXD_P0_0
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_0,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_1
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_1,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,2)
#pragma message "Touch_TXD_PIN is P0_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_3
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_3,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_4
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_4,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_5
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_5,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_6
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_6,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_7
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,7,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,7)
#pragma message "Touch_TXD_PIN is P0_7"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_0
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P1_0,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_1
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P1_1,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_2
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P1_2,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,3)
#pragma message "Touch_TXD_PIN is P1_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,4)
#pragma message "Touch_TXD_PIN is P1_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,5)
#pragma message "Touch_TXD_PIN is P1_5"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_6
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,6,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,6)
#pragma message "Touch_TXD_PIN is P1_6"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_7
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,7,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,7)
#pragma message "Touch_TXD_PIN is P1_7"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_0
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,0,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,0)
#pragma message "Touch_TXD_PIN is P2_0"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_1
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,1,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,1)
#pragma message "Touch_TXD_PIN is P2_1"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,2)
#pragma message "Touch_TXD_PIN is P2_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,3)
#pragma message "Touch_TXD_PIN is P2_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,4)
#pragma message "Touch_TXD_PIN is P2_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_5
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P2_5,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_6
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P2_6,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_7
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P2_7,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P3_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(3,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(3,4)
#pragma message "Touch_TXD_PIN is P3_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P3_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(3,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(3,5)
#pragma message "Touch_TXD_PIN is P3_5"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP20_DIP20)
//================================================================================
#ifdef TouchUartDebugLib_TXD_P0_0
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_0,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_1
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_1,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,2)
#pragma message "Touch_TXD_PIN is P0_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,3)
#pragma message "Touch_TXD_PIN is P0_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_4
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_4,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_5
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_5,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_6
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_6,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_7
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,7,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,7)
#pragma message "Touch_TXD_PIN is P0_7"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_0
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P1_0,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_1
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,1,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,1)
#pragma message "Touch_TXD_PIN is P1_1"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,2)
#pragma message "Touch_TXD_PIN is P1_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,3)
#pragma message "Touch_TXD_PIN is P1_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,4)
#pragma message "Touch_TXD_PIN is P1_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,5)
#pragma message "Touch_TXD_PIN is P1_5"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_6
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,6,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,6)
#pragma message "Touch_TXD_PIN is P1_6"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_7
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,7,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,7)
#pragma message "Touch_TXD_PIN is P1_7"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_0
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,0,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,0)
#pragma message "Touch_TXD_PIN is P2_0"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_1
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,1,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,1)
#pragma message "Touch_TXD_PIN is P2_1"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,2)
#pragma message "Touch_TXD_PIN is P2_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,3)
#pragma message "Touch_TXD_PIN is P2_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,4)
#pragma message "Touch_TXD_PIN is P2_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,5)
#pragma message "Touch_TXD_PIN is P2_5"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_6
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P2_6,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_7
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P2_7,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P3_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(3,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(3,4)
#pragma message "Touch_TXD_PIN is P3_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P3_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(3,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(3,5)
#pragma message "Touch_TXD_PIN is P3_5"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP24)
//================================================================================
#ifdef  TouchUartDebugLib_TXD_P0_0
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,0,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,0)
#pragma message "Touch_TXD_PIN is P0_0"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_1
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,1,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,1)
#pragma message "Touch_TXD_PIN is P0_1"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,2)
#pragma message "Touch_TXD_PIN is P0_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,3)
#pragma message "Touch_TXD_PIN is P0_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_4
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_4,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_5
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_5,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_6
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P0_6,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_7
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,7,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,7)
#pragma message "Touch_TXD_PIN is P0_7"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_0
#define	SET_Touch_TXD_PORT_MODE			  
#define	Touch_TXD_MAP					        PMAP(3,7)
#error 	 				"Error：No P1_0,Please reconfigure TouchUartDebugLib_TXD_Px_y in HC89F30x_TouchUartDebug_Lib_CFG.h "
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_1
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,1,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,1)
#pragma message "Touch_TXD_PIN is P1_1"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,2)
#pragma message "Touch_TXD_PIN is P1_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,3)
#pragma message "Touch_TXD_PIN is P1_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,4)
#pragma message "Touch_TXD_PIN is P1_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,5)
#pragma message "Touch_TXD_PIN is P1_5"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_6
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,6,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,6)
#pragma message "Touch_TXD_PIN is P1_6"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_7
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,7,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,7)
#pragma message "Touch_TXD_PIN is P1_7"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_0
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,0,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,0)
#pragma message "Touch_TXD_PIN is P2_0"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_1
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,1,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,1)
#pragma message "Touch_TXD_PIN is P2_1"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,2)
#pragma message "Touch_TXD_PIN is P2_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,3)
#pragma message "Touch_TXD_PIN is P2_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,4)
#pragma message "Touch_TXD_PIN is P2_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,5)
#pragma message "Touch_TXD_PIN is P2_5"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_6
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,6,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,6)
#pragma message "Touch_TXD_PIN is P2_6"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_7
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,7,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,7)
#pragma message "Touch_TXD_PIN is P2_7"
#endif

#ifdef 	TouchUartDebugLib_TXD_P3_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(3,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(3,4)
#pragma message "Touch_TXD_PIN is P3_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P3_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(3,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(3,5)
#pragma message "Touch_TXD_PIN is P3_5"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP28)
//================================================================================
#ifdef  TouchUartDebugLib_TXD_P0_0
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,0,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,0)
#pragma message "Touch_TXD_PIN is P0_0"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_1
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,1,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,1)
#pragma message "Touch_TXD_PIN is P0_1"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,2)
#pragma message "Touch_TXD_PIN is P0_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,3)
#pragma message "Touch_TXD_PIN is P0_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,4)
#pragma message "Touch_TXD_PIN is P0_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,5)
#pragma message "Touch_TXD_PIN is P0_5"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_6
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,6,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,6)
#pragma message "Touch_TXD_PIN is P0_6"
#endif

#ifdef 	TouchUartDebugLib_TXD_P0_7
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(0,7,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(0,7)
#pragma message "Touch_TXD_PIN is P0_7"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_0
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,0,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,0)
#pragma message "Touch_TXD_PIN is P1_0"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_1
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,1,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,1)
#pragma message "Touch_TXD_PIN is P1_1"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,2)
#pragma message "Touch_TXD_PIN is P1_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,3)
#pragma message "Touch_TXD_PIN is P1_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,4)
#pragma message "Touch_TXD_PIN is P1_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,5)
#pragma message "Touch_TXD_PIN is P1_5"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_6
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,6,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,6)
#pragma message "Touch_TXD_PIN is P1_6"
#endif

#ifdef 	TouchUartDebugLib_TXD_P1_7
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(1,7,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(1,7)
#pragma message "Touch_TXD_PIN is P1_7"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_0
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,0,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,0)
#pragma message "Touch_TXD_PIN is P2_0"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_1
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,1,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,1)
#pragma message "Touch_TXD_PIN is P2_1"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_2
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,2,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,2)
#pragma message "Touch_TXD_PIN is P2_2"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_3
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,3,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,3)
#pragma message "Touch_TXD_PIN is P2_3"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,4)
#pragma message "Touch_TXD_PIN is P2_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,5)
#pragma message "Touch_TXD_PIN is P2_5"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_6
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,6,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,6)
#pragma message "Touch_TXD_PIN is P2_6"
#endif

#ifdef 	TouchUartDebugLib_TXD_P2_7
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(2,7,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(2,7)
#pragma message "Touch_TXD_PIN is P2_7"
#endif

#ifdef 	TouchUartDebugLib_TXD_P3_4
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(3,4,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(3,4)
#pragma message "Touch_TXD_PIN is P3_4"
#endif

#ifdef 	TouchUartDebugLib_TXD_P3_5
#define	SET_Touch_TXD_PORT_MODE			  SET_PORT_OUT(3,5,TouchUartDebugLib_TXD_PORT_Levelx,1)
#define	Touch_TXD_MAP					        PMAP(3,5)
#pragma message "Touch_TXD_PIN is P3_5"
#endif

#endif

#endif /* __HC89F30x_TouchUartDebug_Lib_Build_Message_H__ */
