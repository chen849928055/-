/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_GeneralKey_Touch_Lib_CFG.c
* Author             : Touch Team
* Version            : V1.0.5.0
* Date               : 2019/10/01
********************************************************************************

注：本文件不建议用户自行修改！

*******************************************************************************/
//===================================================================================================
#include "HC_DEFINE.H"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Lib_CFG.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Filter.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Multibutton.h"

//===================================================================================================
#define HexadecimalToBinary(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)	\
(																\
	(a<<15)+(b<<14)+(c<<13)+(d<<12)+							\
	(e<<11)+(f<<10)+(g<<9)+(h<<8)+								\
	(i<<7)+(j<<6)+(k<<5)+(l<<4)+								\
	(m<<3)+(n<<2)+(o<<1)+(p<<0)									\
)
#define TKBIN HexadecimalToBinary

//===================================================================================================
#if (HCTouchLib_IC_BODY == IC_BODY_SOP16)
#pragma message "IC Body: HC89F301-SOP16"
#define TK_CH_MAX  		7
uc8 CODE_INTERNAL_INDEX[TK_CH_MAX] = {2, 7, 11, 12, 13, 14, 15};

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP20_DIP20)
#pragma message "IC Body: HC89F302-SOP20/DIP20"
#define TK_CH_MAX  		10
uc8 CODE_INTERNAL_INDEX[TK_CH_MAX] = {2, 3, 7, 9, 10, 11, 12, 13, 14, 15};

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP24)
#pragma message "IC Body: HC89F302-SOP24"
#define TK_CH_MAX  		12
uc8 CODE_INTERNAL_INDEX[TK_CH_MAX] = {0, 1, 2, 3, 7, 9, 10, 11, 12, 13, 14, 15};

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP28)
#pragma message "IC Body: HC89F303-SOP28"
#define TK_CH_MAX  		16
uc8 CODE_INTERNAL_INDEX[TK_CH_MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

#else
#define TK_CH_MAX  		1
uc8 CODE_INTERNAL_INDEX[TK_CH_MAX] = {0};
#error "No IC Body,Please reconfigure HCTouchLib_IC_BODY"
#endif

//===================================================================================================
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Lib_Build_Message.h"

//===================================================================================================
#if ((HCTouchLib_TK_CH_MASK & (0xFFFF >> (16 - TK_CH_MAX))) == 0)
#error "No channel is enabled,Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

//===================================================================================================
//开启的检测通道个数
#define HCTouchLib_OPENED_TK_AMOUNT \
((HCTouchLib_TK_CH_MASK>> 0 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 1 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 2 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 3 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>> 4 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 5 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 6 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 7 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>> 8 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 9 & 0x01L)+(HCTouchLib_TK_CH_MASK>>10 & 0x01L)+(HCTouchLib_TK_CH_MASK>>11 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>>12 & 0x01L)+(HCTouchLib_TK_CH_MASK>>13 & 0x01L)+(HCTouchLib_TK_CH_MASK>>14 & 0x01L)+(HCTouchLib_TK_CH_MASK>>15 & 0x01L))

#define  USERDATA  HCTouchLib_OPENED_TK_AMOUNT 

//===================================================================================================
#define HCTouchLib_NOISE_THRESHOLD { \
 HCTouchLib_SET0_N_THRESHOLD,  HCTouchLib_SET1_N_THRESHOLD,  HCTouchLib_SET2_N_THRESHOLD,  HCTouchLib_SET3_N_THRESHOLD,  \
 HCTouchLib_SET4_N_THRESHOLD,  HCTouchLib_SET5_N_THRESHOLD,  HCTouchLib_SET6_N_THRESHOLD,  HCTouchLib_SET7_N_THRESHOLD,  \
 HCTouchLib_SET8_N_THRESHOLD,  HCTouchLib_SET9_N_THRESHOLD,  HCTouchLib_SET10_N_THRESHOLD, HCTouchLib_SET11_N_THRESHOLD, \
 HCTouchLib_SET12_N_THRESHOLD, HCTouchLib_SET13_N_THRESHOLD, HCTouchLib_SET14_N_THRESHOLD, HCTouchLib_SET15_N_THRESHOLD  \
}

#define HCTouchLib_FINGER_THRESHOLD { \
 HCTouchLib_SET0_F_THRESHOLD,  HCTouchLib_SET1_F_THRESHOLD,  HCTouchLib_SET2_F_THRESHOLD,  HCTouchLib_SET3_F_THRESHOLD,  \
 HCTouchLib_SET4_F_THRESHOLD,  HCTouchLib_SET5_F_THRESHOLD,  HCTouchLib_SET6_F_THRESHOLD,  HCTouchLib_SET7_F_THRESHOLD,  \
 HCTouchLib_SET8_F_THRESHOLD,  HCTouchLib_SET9_F_THRESHOLD,  HCTouchLib_SET10_F_THRESHOLD, HCTouchLib_SET11_F_THRESHOLD, \
 HCTouchLib_SET12_F_THRESHOLD, HCTouchLib_SET13_F_THRESHOLD, HCTouchLib_SET14_F_THRESHOLD, HCTouchLib_SET15_F_THRESHOLD  \
}

//===================================================================================================
uc16	CODE_TK_CH_MASK                 = HCTouchLib_TK_CH_MASK;
uc8		CODE_CHANNEL_CALIBRATE_SW       = 0;
uc8		CODE_CALIBRATE_DEFLECTED_AREA   = 20;
uc8		CODE_CALIBRATE_TARGET_LINE      = 0;
uc8		CODE_DSCR                       = HCTouchLib_DSCR;
uc8		CODE_CTKDS_PRSDIV               = (0 << 4) | (1 << 3) | HCTouchLib_PRSDIV;
uc8		CODE_VD_RV                      = (HCTouchLib_VD << 4) | 0;
uc8		CODE_RBS                        = (0 << 7) | HCTouchLib_RBS;
uc8		CODE_Continue_Scan_SW           = 1;
uc8		CODE_OFFSET_SW                  = 0;
uc16	CODE_OVERHIGH_TIME              = HCTouchLib_OVERHIGH_TIME;
uc16	CODE_OVERLOW_TIME               = HCTouchLib_OVERLOW_TIME;
uc8		CODE_CONFIRM_TOUCH_TIME         = HCTouchLib_CONFIRM_TOUCH_TIME;
uc8		CODE_CONFIRM_NOTOUCH_TIME       = HCTouchLib_CONFIRM_NOTOUCH_TIME;
uc8		CODE_LIMIT_FACTOR               = HCTouchLib_LIMIT_FACTOR;
uc8		CODE_BARREL_CAPACITY            = HCTouchLib_NOISE_BARREL_CAPACITY;
uc16	CODE_NOISE_THRESHOLD[16]        = HCTouchLib_NOISE_THRESHOLD;
uc16	CODE_FINGER_THRESHOLD[16]       = HCTouchLib_FINGER_THRESHOLD;
uc8		CODE_OPENED_TK_AMOUNT           = HCTouchLib_OPENED_TK_AMOUNT;
uc8		CODE_Hysteresis					= HCTouchLib_Hysteresis;
uc8 	CODE_TK_CH_MAX                  = TK_CH_MAX;
uc8		CODE_FILTER_DEPTH				= HCTouchLib_FILTER_DEPTH;

//===================================================================================================
ux16	XDATA_RawData 	 [HCTouchLib_OPENED_TK_AMOUNT];
ux16	XDATA_RawDataBuf [HCTouchLib_OPENED_TK_AMOUNT];
sx16 	XDATA_BaseLine	 [HCTouchLib_OPENED_TK_AMOUNT];
ux16 	XDATA_OverLowCnt [HCTouchLib_OPENED_TK_AMOUNT];
ux16 	XDATA_OverHighCnt[HCTouchLib_OPENED_TK_AMOUNT];
ux8 	XDATA_TouchCnt   [HCTouchLib_OPENED_TK_AMOUNT];
ux8 	XDATA_NoTouchCnt [HCTouchLib_OPENED_TK_AMOUNT];
sx16 	XDATA_DifferAccum[HCTouchLib_OPENED_TK_AMOUNT];
ux16	XDATA_LongRstCnt [HCTouchLib_OPENED_TK_AMOUNT];
ux16	XDATA_THRNoiseCnt[HCTouchLib_OPENED_TK_AMOUNT];
ux8  	XDATA_AccessIndex[TK_CH_MAX];
ux16	XDATA_CONFIRM_LONGTOUCH_TIME	= HCTouchLib_CONFIRM_LONGTOUCH_TIME;
ux16	XDATA_THRESHOLD_NOISE_TIME		= HCTouchLib_CONFIRM_LONGTOUCH_TIME;
ux8		XDATA_THRESHOLD_RATIO			= 10;
ux8		XDATA_FineTuning				= 2;

/******************************************************************************************************
 * Revision history:
 *
 * Revision 1.01  	2017/12/18 14:10 Taboo.Z
 * Revision 1.0.2.0	2018/07/20 16:31 Jing.L
 * Revision 1.0.3.0	2018/09/10 14:38 Jing.L
 * Add: 1、增加迟滞以及触摸自动复位参数
 *		2、固定了部分参数设置
 * Revision 1.0.4.0	2019/03/06 13:59 Touch Team
 * Add: 1、按键最长有效时间程序中可做调整
 *		2、增加部分函数内部使用参数
 *		3、增加一个16位的LONGTOBIN，仅供配置TK通道使用
 * Revision 1.0.5.0	2019/09/17 19:11 Touch Team 
 *	    1、增加阈值噪声参数
 *		2、增加阈值比例
 *		3、增加噪声桶调整步进
 *
 ******************************************************************************************************/
 