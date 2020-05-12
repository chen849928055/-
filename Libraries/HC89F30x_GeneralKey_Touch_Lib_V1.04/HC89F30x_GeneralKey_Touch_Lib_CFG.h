/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_GeneralKey_Touch_Lib_CFG_H.h
* Author             : Touch Team�Z
* Version            : V1.0.5.0    
* Date               : 2019/10/01
********************************************************************************

ע������HCTouchLib��ͷ�ĺ궨�壬�û����Ը���ʵ�ʵ�����Ҫ���޸ĺ��������

*******************************************************************************/
#ifndef __HC89F30x_GeneralKey_Touch_Lib_CFG_H__
#define __HC89F30x_GeneralKey_Touch_Lib_CFG_H__

/****************************************IC�ͺż���װѡ��********************************************/
#define IC_BODY_SOP20_DIP20                   0   //HC89F302	SOP20/DIP20
#define IC_BODY_SOP24                         1   //HC89F302	SOP24
#define IC_BODY_SOP28                         2   //HC89F303	SOP28
#define IC_BODY_SOP16                         3   //HC89F301	SOP16

// IC�ͺż���װѡ��
#define HCTouchLib_IC_BODY                    3
/****************************************************************************************************/


/***************************************������Ҫ����ͨ��*******************************************/
// ������Ҫ����ͨ����־		 0: ����⣻1: �����⡣
//      HC89F303-SOP28              TK15 TK14 TK13 TK12 TK11 TK10  TK9  TK8  TK7  TK6  TK5  TK4  TK3  TK2  TK1  TK0  
//      HC89F302-SOP24               NC   NC   NC   NC  TK15 TK14 TK13 TK12 TK11 TK10  TK9  TK7  TK3  TK2  TK1  TK0  
//      HC89F302-SOP20/DIP20         NC   NC   NC   NC   NC   NC  TK15 TK14 TK13 TK12 TK11 TK10  TK9  TK7  TK3  TK2  
//      HC89F301-SOP16               NC   NC   NC   NC   NC   NC   NC   NC   NC  TK15 TK14 TK13 TK12 TK11  TK7  TK2  
#define HCTouchLib_TK_CH_MASK  TKBIN(  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  1 ,  1 ,  1 ,  0 ,  0 ,  0 ,  0 )
/****************************************************************************************************/


/***************************************���ô�����ؼĴ���*******************************************/
// �������ݲ���ʱ�Ӹ��������÷�Χ(0~255)������ͨ��ɨ��ʱ�� �� ((HCTouchLib_DSCR+1)*256 - 1)/(Fosc/2)
#define HCTouchLib_DSCR                         24//Ĭ��48

// ���ó�ŵ�Ƶ�ʣ����÷�Χ(1~3)��1->Fosc/4, 2->Fosc/8��3->Fosc/16
// ע����������CTK��ŵ�Ƶ������ΪFosc/8������ֵ����Ϊ2
#define HCTouchLib_PRSDIV     					2

// ���ô�������Դ��ѹ�����÷�Χ(0~3)��0->2v  1->2.5v 2->3v 3->4v������ѹԽ�󣬴�������ֵԽ��
// ʹ��ע�⣺���뱣֤оƬVDD��ѹ > �û����ô�������Դ��ѹ+0.5V
#define HCTouchLib_VD                           2  //3.3v>2.5+0.5

// ���ô����ŵ���裬���÷�Χ(0~7):0->�ŵ������С, 7->�ŵ�������,����0(С)-->7(��), �ŵ����ԽС,��������ֵԽС
#define HCTouchLib_RBS                          6      //Ĭ��6
/****************************************************************************************************/


/**************************************������ָ��ֵ��ز���******************************************/
// ����ȷ����ָ������������������Ч״̬���������÷�Χ(1~255)
// ������ʱ�� = HCTouchLib_CONFIRM_TOUCH_TIME �� ��������ɨ��ʱ�� �� �����ļ��ͨ��������
#define HCTouchLib_CONFIRM_TOUCH_TIME           2

// ����ȷ����ָ�뿪��������������Ч״̬���������÷�Χ(1~255)
// ������ʱ�� = HCTouchLib_CONFIRM_NOTOUCH_TIME �� ��������ɨ��ʱ�� �� �����ļ��ͨ��������
#define HCTouchLib_CONFIRM_NOTOUCH_TIME         2

// ���ô������ͣ��봥����ֵ���ʹ�ã���ֵӦ�Դ�������������ֵ
#define HCTouchLib_Hysteresis                   10    //15Ĭ��

// ������ֵ�����÷�Χ(5~50),�û�Ӧ����ʵ������������ø�ֵ�������ֵΪ��������ľ���ֵ��1.5��
// ����������ֵʱע����Ҫ��ʹ�õ�CTKͨ���Ӧ        //S0P28 //SOP24// SOP20/DIP20  //SOP16
#define HCTouchLib_SET0_N_THRESHOLD             10  //TK0	 //TK0	  //TK2		   //TK2	
#define HCTouchLib_SET1_N_THRESHOLD             10  //TK1	 //TK1	  //TK3		   //TK7
#define HCTouchLib_SET2_N_THRESHOLD             10	//TK2	 //TK2	  //TK7		   //TK11
#define HCTouchLib_SET3_N_THRESHOLD             10  //TK3	 //TK9    //TK9		   //TK12

#define HCTouchLib_SET4_N_THRESHOLD             10  //TK4	 //TK7	  //TK10	   //TK13
#define HCTouchLib_SET5_N_THRESHOLD             10  //TK5	 //TK9	  //TK11	   //TK14	
#define HCTouchLib_SET6_N_THRESHOLD             10  //TK6	 //TK10	  //TK12	   //TK15

#define HCTouchLib_SET7_N_THRESHOLD             10  //TK7	 //TK11	  //TK13	   //NC
#define HCTouchLib_SET8_N_THRESHOLD             10  //TK8	 //TK12	  //TK14	   //NC
#define HCTouchLib_SET9_N_THRESHOLD             10  //TK9	 //TK13	  //TK15	   //NC
#define HCTouchLib_SET10_N_THRESHOLD            10  //TK10	 //TK14	  //NC		   //NC
#define HCTouchLib_SET11_N_THRESHOLD            10  //TK11	 //TK15	  //NC		   //NC
#define HCTouchLib_SET12_N_THRESHOLD            10  //TK12	 //NC	  //NC		   //NC
#define HCTouchLib_SET13_N_THRESHOLD            10  //TK13	 //NC	  //NC		   //NC  //Ĭ��10
#define HCTouchLib_SET14_N_THRESHOLD            10  //TK14	 //NC	  //NC		   //NC
#define HCTouchLib_SET15_N_THRESHOLD            10  //TK15	 //NC	  //NC		   //NC

// ������ֵ��ȡֵ�����ʵ�������������ֵӦ���ٱ�֤��ͨ������ֵ3�����ϣ�5�����ϸ���
// ���ô�����ֵʱע����Ҫ��ʹ�õ�CTKͨ���Ӧ	//SOP28 //S0P24  //SOP20/DIP20 //SOP16
#define HCTouchLib_SET0_F_THRESHOLD				120	//TK0	  //TK0	   //TK2		      //TK2	
#define HCTouchLib_SET1_F_THRESHOLD				120	//TK1	  //TK1	   //TK3		      //TK7
#define HCTouchLib_SET2_F_THRESHOLD				120	//TK2	  //TK2	   //TK7		      //TK11
#define HCTouchLib_SET3_F_THRESHOLD				120	//TK3	  //TK3	   //TK9		      //TK12

#define HCTouchLib_SET4_F_THRESHOLD				120	//TK4	  //TK7	   //TK10		     //TK13
#define HCTouchLib_SET5_F_THRESHOLD				120	//TK5	  //TK9	   //TK11		     //TK14	
#define HCTouchLib_SET6_F_THRESHOLD				120	//TK6	  //TK10	 //TK12		     //TK15

#define HCTouchLib_SET7_F_THRESHOLD				120	//TK7	  //TK11	 //TK13		     //NC
#define HCTouchLib_SET8_F_THRESHOLD				120	//TK8	  //TK12	 //TK14		     //NC
#define HCTouchLib_SET9_F_THRESHOLD				120	//TK9	  //TK13	 //TK15		     //NC
#define HCTouchLib_SET10_F_THRESHOLD			120	//TK10	 //TK14	 //NC		       //NC
#define HCTouchLib_SET11_F_THRESHOLD			120	//TK11	 //TK15	 //NC		       //NC
#define HCTouchLib_SET12_F_THRESHOLD			120	//TK12	 //NC	   //NC		       //NC
#define HCTouchLib_SET13_F_THRESHOLD			120	//TK13	 //NC	   //NC		       //NC  //Ĭ��120
#define HCTouchLib_SET14_F_THRESHOLD			120	//TK14	 //NC	   //NC		       //NC
#define HCTouchLib_SET15_F_THRESHOLD			120	//TK15	 //NC	   //NC		       //NC
/****************************************************************************************************/


/**************************************���û��߸�����ز���******************************************/
// ���ô����������Чʱ�����ֵ�����ڴ�������������Ӧ��������仯		
//			���÷�Χ(0~65535)
//          0: �رմ˹���
//			��0: ��Differ����������ָ��ֵ(HCTouchLib_SETx_F_THRESHOLD)��ʱ������������ĸ�ֵ��ϵͳ���Զ����µ�ǰBaseline��
// ע�⣺HCTouchLib_CONFIRM_LONGTOUCH_TIME��0ʱ����������û�����ȷ����ָ��������(HCTouchLib_CONFIRM_TOUCH_TIME)
// ���Чʱ�� �� HCTouchLib_CONFIRM_LONGTOUCH_TIME * ��������ɨ��ʱ�� * �����ļ��ͨ������
#define HCTouchLib_CONFIRM_LONGTOUCH_TIME		1000    //Ĭ��1000

// ����ë�̵��ж����������ڹ����������������ɵľ��Ҵ���ֵ����
//			���÷�Χ(0~255)
//		    0: ���ж�ë�̣�
//          ��0: ������ֵ > HCTouchLib_LIMIT_FACTOR * HCTouchLib_SETx_F_THRESHOLD ʱ�ж�Ϊë��
//			������������ֵΪ100����ֵΪ3������ΪDifferֵ����300ʱΪë�̣���ʱ������Ч
#define HCTouchLib_LIMIT_FACTOR					0

// ����ë����������ֵ�����HCTouchLib_LIMIT_FACTORʹ�á����ڵ��������������ɴ�������ֵ��ʱ�����ʱ�Ļ��߸��£�����Ӳ�����ڴ��������ϵ�
//			���÷�Χ(0~65535)
//          0: �رմ˹���
//			��0: ��Differ��������ë��(HCTouchLib_LIMIT_FACTOR * HCTouchLib_TKx_F_THRESHOLD)��ʱ������������ĸ�ֵ��ϵͳ���Զ����µ�ǰBaseline
#define HCTouchLib_OVERHIGH_TIME				100      //Ĭ��300

// ���õͻ�׼�߸�λ����ֵ
//          0: �رմ˹���
//			��0: ��Differ�������ڸ�������ֵ(-HCTouchLib_SETx_N_THRESHOLD)��ʱ������������ĸ�ֵ��ϵͳ���Զ����µ�ǰBaseline
#define HCTouchLib_OVERLOW_TIME					100      //Ĭ��100

// ��������Ͱ������С
//			���÷�Χ(0~255)
//          ϵͳ����ڡ�����(HCTouchLib_SETx_N_THRESHOLD)֮���Differ�����ۼӣ����ۼӵĺʹ���������Ͱ��С�ڸ�����Ͱʱ������Baseline+2��-2��
#define HCTouchLib_NOISE_BARREL_CAPACITY		80   //Ĭ��80

/****************************************************************************************************/

#endif /*__HC89F30x_GeneralKey_Touch_Lib_CFG_H__*/

/******************************************************************************************************
 * Revision history:
 *
 * Revision 1.01	2017/12/18 14:10 Taboo.Z�Z
 * Revision 1.0.2.0	2018/07/20 16:26 Jing.L�Z
 * Revision 1.0.3.0	2018/09/10 14:26 Jing.L�Z
 * Add: 1�������˳��Ͳ���
 *		2��ɾ���˲��ּĴ������������Բ���
 *		3�����������Ű�
 * Revision 1.0.4.0	2019/03/06 10:44 Touch Team
 * Add: 1��ɾ���˲��ּĴ������������Բ���
 *		2��HCTouchLib_CONFIRM_LONGTOUCH_TIME�����пɶ�̬�޸�
 * Revision 1.0.5.0	2019/09/17 19:24 Touch Team
 * Add: 1��HCTouchLib_TK_CH_MASK��16���Ƹ�Ϊ2��������
 *		2�����ֲ��������޸�
 *
 ******************************************************************************************************/
