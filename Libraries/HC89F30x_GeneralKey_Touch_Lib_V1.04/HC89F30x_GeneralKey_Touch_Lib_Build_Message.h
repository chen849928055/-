/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_GeneralKey_Touch_Lib_Build_Message.h
* Author             : Touch Team�Z
* Version            : V1.0.5.0
* Date               : 2019/10/01
********************************************************************************

ע�����ļ��������û������޸ģ�

*******************************************************************************/
#ifndef __HC89F30x_GeneralKey_Touch_Lib_Build_Message_H__
#define __HC89F30x_GeneralKey_Touch_Lib_Build_Message_H__

//================================================================================
#if (HCTouchLib_IC_BODY == IC_BODY_SOP16)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK2��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK7��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK11��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK12��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK13��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK14��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK15��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP20_DIP20)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK2��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK3��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK7��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK9��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK10��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK11��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK12��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#pragma message "TK13��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#pragma message "TK14��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#pragma message "TK15��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP24)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK0��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK1��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK2��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK3��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK7��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK9��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK10��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#pragma message "TK11��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#pragma message "TK12��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#pragma message "TK13��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#pragma message "TK14��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#pragma message "TK15��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#error          "Error��Please reconfigure HCTouchLib_TK_CH_MASK"
#endif

#elif (HCTouchLib_IC_BODY == IC_BODY_SOP28)

#if (HCTouchLib_TK_CH_MASK & 0x0001L)
#pragma message "TK0��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0002L)
#pragma message "TK1��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0004L)
#pragma message "TK2��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0008L)
#pragma message "TK3��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0010L)
#pragma message "TK4��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0020L)
#pragma message "TK5��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0040L)
#pragma message "TK6��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0080L)
#pragma message "TK7��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0100L)
#pragma message "TK8��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0200L)
#pragma message "TK9��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0400L)
#pragma message "TK10��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x0800L)
#pragma message "TK11��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x1000L)
#pragma message "TK12��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x2000L)
#pragma message "TK13��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x4000L)
#pragma message "TK14��Enable"
#endif
#if (HCTouchLib_TK_CH_MASK & 0x8000L)
#pragma message "TK15��Enable"
#endif

#endif
//================================================================================
#if (HCTouchLib_DSCR > 255)
#error	"Error��Please setting HCTouchLib_DSCR < 256"
#endif

//================================================================================
#pragma message "CTK����Ƶ�ʣ�Fosc/2"

//================================================================================
//================================================================================
#if ((HCTouchLib_PRSDIV > 3)|(HCTouchLib_PRSDIV == 0))
#error 	"Error��Please setting 1 <= HCTouchLib_PRSDIV <= 3" 
#elif (HCTouchLib_PRSDIV ==1)
#pragma message "CTK��ŵ�Ƶ�ʣ�Fosc/4"
#elif (HCTouchLib_PRSDIV ==2)
#pragma message "CTK��ŵ�Ƶ�ʣ�Fosc/8"
#elif (HCTouchLib_PRSDIV ==3)
#pragma message "CTK��ŵ�Ƶ�ʣ�Fosc/16"
#endif
//================================================================================
#if (HCTouchLib_VD > 3)
#error 	"Error��Please setting HCTouchLib_VD < 4"
#elif (HCTouchLib_VD ==0)
#pragma message "CTK����Դ��ѹ��2V "
#elif (HCTouchLib_VD ==1)
#pragma message "CTK����Դ��ѹ��2.5V"
#elif (HCTouchLib_VD ==2)
#pragma message "CTK����Դ��ѹ��3V"
#elif (HCTouchLib_VD ==3)
#pragma message "CTK����Դ��ѹ��4V"
#endif

//================================================================================
#pragma message "CTK��ŵ�α�������"

//================================================================================
#pragma message "CTK�ο���ѹ��0.60V"

//================================================================================
#if (HCTouchLib_RBS > 7)
#error 	"Error��Please setting HCTouchLib_RBS < 8"
#elif (HCTouchLib_RBS ==0)
#pragma message "CTK�ŵ���裺0.5"
#elif (HCTouchLib_RBS ==1)
#pragma message "CTK�ŵ���裺1"
#elif (HCTouchLib_RBS ==2)
#pragma message "CTK�ŵ���裺2"
#elif (HCTouchLib_RBS ==3)
#pragma message "CTK�ŵ���裺4"
#elif (HCTouchLib_RBS ==4)
#pragma message "CTK�ŵ���裺8"
#elif (HCTouchLib_RBS ==5)
#pragma message "CTK�ŵ���裺16"
#elif (HCTouchLib_RBS ==6)
#pragma message "CTK�ŵ���裺32"
#elif (HCTouchLib_RBS ==7)
#pragma message "CTK�ŵ���裺64"
#endif

//================================================================================
#pragma message "CTK���Ƶ��ݣ����õ���"

//================================================================================
#pragma message "CTK����ɨ��ģʽ����"

//================================================================================
#pragma message "CTKɨ�貹�����ر�"

//================================================================================
#if ((HCTouchLib_CONFIRM_TOUCH_TIME == 0)|(HCTouchLib_CONFIRM_TOUCH_TIME > 255))
#error	"Error��Please setting 0 < HCTouchLib_CONFIRM_TOUCH_TIME < 256"
#endif

//================================================================================
#if ((HCTouchLib_CONFIRM_NOTOUCH_TIME == 0)|(HCTouchLib_CONFIRM_NOTOUCH_TIME > 255))
#error 	"Error��Please setting 0 < HCTouchLib_CONFIRM_NOTOUCH_TIME < 256"
#endif

//================================================================================
#if (HCTouchLib_Hysteresis == 0 )
#pragma message "������������: �ر�"
#elif (HCTouchLib_Hysteresis > 255))
#error 	"Error��Please setting 0 < HCTouchLib_Hysteresis < 256"
#endif

//================================================================================
#if (((0 < HCTouchLib_CONFIRM_LONGTOUCH_TIME)&&(HCTouchLib_CONFIRM_LONGTOUCH_TIME <= HCTouchLib_CONFIRM_TOUCH_TIME))|(HCTouchLib_CONFIRM_LONGTOUCH_TIME > 65535))
#error 	"Error��Please setting HCTouchLib_CONFIRM_LONGTOUCH_TIME = 0 or HCTouchLib_CONFIRM_TOUCH_TIME < HCTouchLib_CONFIRM_LONGTOUCH_TIME < 65536"
#endif

//================================================================================
#if ((HCTouchLib_LIMIT_FACTOR == 1)|(HCTouchLib_LIMIT_FACTOR > 256))
#error 	"Error��Please setting 1 < HCTouchLib_LIMIT_FACTOR < 256"
#endif

//================================================================================
#if ((HCTouchLib_OVERHIGH_TIME == 0)|(HCTouchLib_OVERHIGH_TIME > 65536))
#error 	"Error��Please setting 0 < HCTouchLib_OVERHIGH_TIME < 65536"
#endif

//================================================================================
#if (HCTouchLib_OVERLOW_TIME == 0)
#pragma message "CTK�ͻ�׼�߸�λ: �ر�"
#elif ((HCTouchLib_OVERLOW_TIME > 65536)|(HCTouchLib_OVERLOW_TIME < HCTouchLib_CONFIRM_NOTOUCH_TIME))
#error 	"Error��Please setting HCTouchLib_CONFIRM_NOTOUCH_TIME < HCTouchLib_OVERLOW_TIME < 65536"
#else
#pragma message "CTK�ͻ�׼�߸�λ: ��"
#endif

//================================================================================
#if ((HCTouchLib_NOISE_BARREL_CAPACITY <= 1)|(HCTouchLib_NOISE_BARREL_CAPACITY > 256))
#error 	"Error��Please setting 1 < HCTouchLib_NOISE_BARREL_CAPACITY < 256"
#endif

//================================================================================
#pragma message "CTKͨ��У׼: �ر�"

#define	HCTouchLib_SETn_N_THRESHOLD		50

//================================================================================
#if (HCTouchLib_FILTER_DEPTH == 0)
#pragma message "CTK RawData������λֵƽ���˲�: �ر�"
#elif ((HCTouchLib_FILTER_DEPTH >= 3)&&(HCTouchLib_FILTER_DEPTH <= 15))
#pragma message "CTK RawData������λֵƽ���˲�: ��"
#else
#error 	"Error��Please setting 3 <= HCTouchLib_FILTER_DEPTH <= 15"
#endif


#if (HCTouchLib_MULTIBUTTON == 0)
#pragma message "CTK ��ǿ����: �ر�"
#elif (HCTouchLib_MULTIBUTTON == 1)
#pragma message "CTK ��ǿ����: ��"
#else
#error 	"Error��Please setting HCTouchLib_MULTIBUTTON = 0 or HCTouchLib_MULTIBUTTON = 1"
#endif


//================================================================================
#if ((HCTouchLib_SET0_N_THRESHOLD <= 4 )|(HCTouchLib_SET0_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET0_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET1_N_THRESHOLD <= 4 )|(HCTouchLib_SET1_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET1_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET2_N_THRESHOLD <= 4 )|(HCTouchLib_SET2_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET2_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET3_N_THRESHOLD <= 4 )|(HCTouchLib_SET3_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET3_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET4_N_THRESHOLD <= 4 )|(HCTouchLib_SET4_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET4_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET5_N_THRESHOLD <= 4 )|(HCTouchLib_SET5_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET5_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET6_N_THRESHOLD <= 4 )|(HCTouchLib_SET6_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET6_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET7_N_THRESHOLD <= 4 )|(HCTouchLib_SET7_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET7_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET8_N_THRESHOLD <= 4 )|(HCTouchLib_SET8_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET8_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET9_N_THRESHOLD <= 4 )|(HCTouchLib_SET9_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET9_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET10_N_THRESHOLD <= 4 )|(HCTouchLib_SET10_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET10_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET11_N_THRESHOLD <= 4 )|(HCTouchLib_SET11_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET11_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET12_N_THRESHOLD <= 4 )|(HCTouchLib_SET12_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET12_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET13_N_THRESHOLD <= 4 )|(HCTouchLib_SET13_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET13_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET14_N_THRESHOLD <= 4 )|(HCTouchLib_SET14_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET14_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif
#if ((HCTouchLib_SET15_N_THRESHOLD <= 4 )|(HCTouchLib_SET15_N_THRESHOLD > HCTouchLib_SETn_N_THRESHOLD))
#error 	"Error��Please setting 4 < HCTouchLib_SET15_N_THRESHOLD <= HCTouchLib_SETn_N_THRESHOLD"
#endif

//================================================================================
#if ((HCTouchLib_SET0_F_THRESHOLD <= 24 )|(HCTouchLib_SET0_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET0_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET1_F_THRESHOLD <= 24 )|(HCTouchLib_SET1_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET1_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET2_F_THRESHOLD <= 24 )|(HCTouchLib_SET2_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET2_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET3_F_THRESHOLD <= 24 )|(HCTouchLib_SET3_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET3_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET4_F_THRESHOLD <= 24 )|(HCTouchLib_SET4_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET4_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET5_F_THRESHOLD <= 24 )|(HCTouchLib_SET5_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET5_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET6_F_THRESHOLD <= 24 )|(HCTouchLib_SET6_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET6_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET7_F_THRESHOLD <= 24 )|(HCTouchLib_SET7_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET7_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET8_F_THRESHOLD <= 24 )|(HCTouchLib_SET8_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET8_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET9_F_THRESHOLD <= 24 )|(HCTouchLib_SET9_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET9_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET10_F_THRESHOLD <= 24 )|(HCTouchLib_SET10_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET10_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET11_F_THRESHOLD <= 24 )|(HCTouchLib_SET11_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET11_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET12_F_THRESHOLD <= 24 )|(HCTouchLib_SET12_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET12_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET13_F_THRESHOLD <= 24 )|(HCTouchLib_SET13_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET13_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET14_F_THRESHOLD <= 24 )|(HCTouchLib_SET14_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET14_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif
#if ((HCTouchLib_SET15_F_THRESHOLD <= 24 )|(HCTouchLib_SET15_F_THRESHOLD > (HCTouchLib_DSCR+1)*256-1))
#error 	"Error��Please setting 24 < HCTouchLib_SET15_F_THRESHOLD <= (HCTouchLib_DSCR+1)*256+1"
#endif

#endif /* __HC89F30x_GeneralKey_Touch_Lib_Build_Message_H__ */

/******************************************************************************************************
 * Revision history:
 *
 * Revision 1.01	2017/12/18 14:10 Taboo.Z�Z
 * Revision 1.0.2.0	2018/07/20 16:26 Jing.L�Z
 * Revision 1.0.3.0	2018/09/10 14:26 Jing.L�Z
 * Add: 1�����ӳ�����ʾ���
 *		2��ɾ���˲��ֲ������
 * Revision 1.0.4.0	2019/03/06 14:33 Touch Team
 * Add: 1���޸Ĳ��ִ���
 * Revision 1.0.5.0	2019/09/17 19:16 Touch Team
 * Add: 1��ɾ�����ֲ������
 *		2������RawData�˲�ʹ�������ʾ
 *		3��������ǿ����ʹ�������ʾ
 *
 ******************************************************************************************************/

