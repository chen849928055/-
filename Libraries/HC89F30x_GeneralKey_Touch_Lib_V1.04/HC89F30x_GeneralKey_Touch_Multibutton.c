/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_GeneralKey_Touch_Multibutton.c
* Author             : Touch Team
* Version            : V1.0.5.0
* Date               : 2019/10/01
********************************************************************************

注：本文件不建议用户自行修改！

*******************************************************************************/
#include "HC89F303.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Lib.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Multibutton.h"
#include "HC89F30x_GeneralKey_Touch_Lib_V1.04\HC89F30x_GeneralKey_Touch_Lib_CFG.h"
#include <string.h>


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
extern sx16 XDATA_BaseLine[];					//Baseline
extern uc8 CODE_INTERNAL_INDEX[];				//对应IC的通道号
extern uc8 CODE_TK_CH_MAX;						//对应IC的通道总数

//===================================================================================================
#if HCTouchLib_MULTIBUTTON
unsigned char code nuc_OpenTouchChannel_a[HCTouchLib_OPENED_TK_AMOUNT] = HCTouchLib_OPENTOUCHCHANNEL;
#endif	

//===================================================================================================
#if HCTouchLib_MULTIBUTTON						//使能多按键处理
static void BubbleSort(s16 fi_ArrDataOne_a[], u8 fuc_ArrDataTwo_a[], u8 fuc_Len)
{
    s16 fi_TempOne = 0;
	u8  fuc_TempTwo = 0;
    u8 fuc_i = 0, fuc_j = 0;
    for (fuc_i=0; fuc_i<fuc_Len-1; fuc_i++)
	{
        for (fuc_j=0; fuc_j<fuc_Len-1-fuc_i; fuc_j++) 
		{ 
            if (fi_ArrDataOne_a[fuc_j] > fi_ArrDataOne_a[fuc_j+1]) 
			{ 
                fi_TempOne = fi_ArrDataOne_a[fuc_j];
                fi_ArrDataOne_a[fuc_j] = fi_ArrDataOne_a[fuc_j+1];
                fi_ArrDataOne_a[fuc_j+1] = fi_TempOne;
				
				fuc_TempTwo = fuc_ArrDataTwo_a[fuc_j];
				fuc_ArrDataTwo_a[fuc_j] = fuc_ArrDataTwo_a[fuc_j+1];
				fuc_ArrDataTwo_a[fuc_j+1] = fuc_TempTwo;
            }
        }	
	}
}

char Search(u8 fuc_SearchData, u8 fuc_ArrData_a[], u8 fuc_Len)
{
	s8 fc_Ret = -1;
	u8 fuc_i = 0;
	for(fuc_i=0; fuc_i<fuc_Len; fuc_i++)
	{
		if(fuc_ArrData_a[fuc_i] == fuc_SearchData)
		{
			fc_Ret = fuc_i;
			break;
		}
	}
	return fc_Ret;
}
#endif	



void TouchMultibuttonHandle(void)
{
#if HCTouchLib_MULTIBUTTON	
	u8  fuc_TouchKeyFlagNum = 0;
	u8  fuc_i = 0;
	s8 	fc_ChannelLocation	= 0;	
	s16 fi_MultibuttonDiffer_a[HCTouchLib_OPENED_TK_AMOUNT] = {0x0000};
	u8  fuc_BubbleSortChannel_a[HCTouchLib_OPENED_TK_AMOUNT] = {0x00};

	fuc_TouchKeyFlagNum = (TouchKeyFlag>> 0 & 0x01L)+(TouchKeyFlag>> 1 & 0x01L)+(TouchKeyFlag>> 2 & 0x01L)+(TouchKeyFlag>> 3 & 0x01L)+\
						  (TouchKeyFlag>> 4 & 0x01L)+(TouchKeyFlag>> 5 & 0x01L)+(TouchKeyFlag>> 6 & 0x01L)+(TouchKeyFlag>> 7 & 0x01L)+\
						  (TouchKeyFlag>> 8 & 0x01L)+(TouchKeyFlag>> 9 & 0x01L)+(TouchKeyFlag>>10 & 0x01L)+(TouchKeyFlag>>11 & 0x01L)+\
						  (TouchKeyFlag>>12 & 0x01L)+(TouchKeyFlag>>13 & 0x01L)+(TouchKeyFlag>>14 & 0x01L)+(TouchKeyFlag>>15 & 0x01L);
	//计算同时有几个通道同时有效
	if(fuc_TouchKeyFlagNum >= 2)
	{
		for(fuc_i = 0;fuc_i < HCTouchLib_OPENED_TK_AMOUNT;fuc_i++)
		{
			fi_MultibuttonDiffer_a[fuc_i] = XDATA_RawData[fuc_i] - XDATA_BaseLine[fuc_i];
		}
		memcpy(fuc_BubbleSortChannel_a,nuc_OpenTouchChannel_a,HCTouchLib_OPENED_TK_AMOUNT);
		//每次排序都重新更新通道排序
		BubbleSort(fi_MultibuttonDiffer_a,fuc_BubbleSortChannel_a,HCTouchLib_OPENED_TK_AMOUNT);
		//冒泡排序，将最大的通道放到fuc_BubbleSortChannel_a[HCTouchLib_OPENED_TK_AMOUNT-1]中
		fc_ChannelLocation = Search(fuc_BubbleSortChannel_a[HCTouchLib_OPENED_TK_AMOUNT-1],CODE_INTERNAL_INDEX,CODE_TK_CH_MAX);
		//
		if(fc_ChannelLocation!= -1)
		{
			TouchKeyFlag = (0x01<<fc_ChannelLocation);
		}
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
 * Add: 1、首次增加最强按键功能
 ******************************************************************************************************/