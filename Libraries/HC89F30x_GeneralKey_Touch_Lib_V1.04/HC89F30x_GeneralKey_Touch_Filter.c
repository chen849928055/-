/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_GeneralKey_Touch_Filter.c
* Author             : Touch Team
* Version            : V1.0.5.0
* Date               : 2019/10/01
********************************************************************************

注：本文件不建议用户自行修改！

*******************************************************************************/
#include "HC89F303.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Lib.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Filter.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Lib_CFG.h"


//===================================================================================================
/***********************************调用相关库参数，用户不需修改************************************/
#define HexadecimalToBinary(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)	\
(																\
	(a<<15)+(b<<14)+(c<<13)+(d<<12)+							\
	(e<<11)+(f<<10)+(g<<9)+(h<<8)+								\
	(i<<7)+(j<<6)+(k<<5)+(l<<4)+								\
	(m<<3)+(n<<2)+(o<<1)+(p<<0)									\
)

#define TKBIN HexadecimalToBinary

#define HCTouchLib_OPENED_TK_AMOUNT \
((HCTouchLib_TK_CH_MASK>> 0 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 1 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 2 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 3 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>> 4 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 5 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 6 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 7 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>> 8 & 0x01L)+(HCTouchLib_TK_CH_MASK>> 9 & 0x01L)+(HCTouchLib_TK_CH_MASK>>10 & 0x01L)+(HCTouchLib_TK_CH_MASK>>11 & 0x01L)+\
 (HCTouchLib_TK_CH_MASK>>12 & 0x01L)+(HCTouchLib_TK_CH_MASK>>13 & 0x01L)+(HCTouchLib_TK_CH_MASK>>14 & 0x01L)+(HCTouchLib_TK_CH_MASK>>15 & 0x01L))
 
extern ux16	XDATA_RawData[];					//滤波后RawData
extern ux16	XDATA_RawDataBuf[];					//采集所得RawData

//===================================================================================================
#if HCTouchLib_FILTER_DEPTH	
ux16 XDATA_RawData_Filter[HCTouchLib_OPENED_TK_AMOUNT][HCTouchLib_FILTER_DEPTH];
#endif	

//===================================================================================================
#if HCTouchLib_FILTER_DEPTH						//使能滤波
static void BubbleSort(u16 fui_ArrData_a[], u8 fuc_Len)
{
    u16 fui_Temp = 0;
    u8 fuc_i = 0, fuc_j = 0;
    for (fuc_i=0; fuc_i<fuc_Len-1; fuc_i++)
	{
        for (fuc_j=0; fuc_j<fuc_Len-1-fuc_i; fuc_j++) 
		{ 
            if (fui_ArrData_a[fuc_j] > fui_ArrData_a[fuc_j+1]) 
			{ 
                fui_Temp = fui_ArrData_a[fuc_j];
                fui_ArrData_a[fuc_j] = fui_ArrData_a[fuc_j+1];
                fui_ArrData_a[fuc_j+1] = fui_Temp;
            }
        }	
	}
}
#endif	


void TouchRawDataFilter(void)
{
#if HCTouchLib_FILTER_DEPTH						
//使能滤波
	unsigned char fuc_i = 0, fuc_j = 0, fuc_z = 0;
	unsigned long ful_Num[HCTouchLib_OPENED_TK_AMOUNT] = {0x00};
	for(fuc_i = 0; fuc_i < HCTouchLib_OPENED_TK_AMOUNT; fuc_i++)
	{
		XDATA_RawData_Filter[fuc_i][HCTouchLib_FILTER_DEPTH-1] = XDATA_RawDataBuf[fuc_i];
		for(fuc_j = 0; fuc_j<HCTouchLib_FILTER_DEPTH-1; fuc_j++)
		{
			XDATA_RawData_Filter[fuc_i][fuc_j] = XDATA_RawData_Filter[fuc_i][fuc_j+1];
		}
		BubbleSort(XDATA_RawData_Filter[fuc_i],HCTouchLib_FILTER_DEPTH);
		for(fuc_z = 1; fuc_z<HCTouchLib_FILTER_DEPTH-1; fuc_z++)
		{
			ful_Num[fuc_i] += XDATA_RawData_Filter[fuc_i][fuc_z];
		}
		ful_Num[fuc_i] /=  (HCTouchLib_FILTER_DEPTH-2);
		XDATA_RawData[fuc_i] = (u16)(ful_Num[fuc_i]);	
	}
#else											//没有使能滤波
	unsigned char fuc_i = 0;
	for(fuc_i = 0;fuc_i < HCTouchLib_OPENED_TK_AMOUNT;fuc_i++)
	{
		XDATA_RawData[fuc_i] = XDATA_RawDataBuf[fuc_i];
	}	
#endif
}

/******************************************************************************************************
 * Revision history:
 *
 * Revision 1.01  	2017/12/18 14:10 Taboo.Z
 * Revision 1.0.2.0	2018/07/20 16:31 Jing.L
 * Revision 1.0.3.0	2018/09/10 14:38 Jing.L
 * Revision 1.0.4.0	2019/03/06 13:59 Touch Team
 * Revision 1.0.5.0	2019/09/17 19:23 Touch Team
 * Add: 1、首次增加RawData滤波功能
 ******************************************************************************************************/
