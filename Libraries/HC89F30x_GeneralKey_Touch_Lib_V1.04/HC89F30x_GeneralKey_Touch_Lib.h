/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_GeneralKey_Touch_Lib.h
* Author             : Touch Team�Z
* Version            : V1.0.5.0
* Date               : 2019/10/01
********************************************************************************

ע�����ļ��û������޸ģ�

*******************************************************************************/
#ifndef __HC89F30x_GeneralKey_Touch_Lib_H__
#define __HC89F30x_GeneralKey_Touch_Lib_H__

//===================================================================================================
extern void CTK_Init(void);			    //���ô˳���ǰ�����ȴ����ж��ܿ��أ�EA=1������ΪCTK��ʼ��ʱ����ҪCTK�ж����
extern void CTK_ISR_Handle(void);       //�˺���������CTK�ж�����е���
extern void Touch_Signal_Handle(void);  //����ɨ�����һ�ֺ󣬵���һ��
extern void Scan_Pause(void);           //CTKɨ����ͣ
extern void Scan_Continue(void);        //CTKɨ�����
extern void BaseLineReset(void);        //��λ����ͨ������

//===================================================================================================
extern bit  OneCycleScanDone;           //ɨ��һ����λһ�Σ�һ��ʱ�� �� ����ͨ��ɨ��ʱ�� * �����ļ��ͨ������
extern ux16 TouchKeyFlag;               //������Ӧ��־��ÿ1BIT ��Ӧһ��ͨ����BIT��Ӧλ��HCTouchLib_TK_CH_MASK���Ӧ
extern ux16	XDATA_CONFIRM_LONGTOUCH_TIME;//�������Чʱ�����ֵ
extern ux16	XDATA_THRESHOLD_NOISE_TIME; //��ֵ�������¼���ֵ
extern ux8	XDATA_THRESHOLD_RATIO;      //��ָ��ֵ����
extern ux8	XDATA_FineTuning;           //����Ͱ΢������

extern uc8  TOUCH_LIB_VERSION[];       //������汾���

#endif /*__HC89F30x_GeneralKey_Touch_Lib_H__*/
