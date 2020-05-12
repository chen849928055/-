/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_SYS.h
********************************************************************************


*******************************************************************************/
#ifndef __HC89F30x_SYS_H__
#define __HC89F30x_SYS_H__

//================================================================================
#define SYSCLK_SEL				1					//0-->�ڲ���Ƶ, 1-->�ڲ���Ƶ, 2-->�ⲿ����(��Ƶ���Ƶ������ѡ��ѡ��)

#define SYSCLK_HSRC_DIV			1					//0-->HSRC/1, 1-->HSRC/2, 2--> HSRC/4, 3-->HSRC/8	 �ڲ���Ƶʱ�ӷ�Ƶ��ֻ���ڲ���Ƶ��Ч	
#define SYSCLK_FCPU_DIV			1					//ʱ�ӷ�Ƶ 1~255

#if 	(SYSCLK_HSRC_DIV == 0)
#define SYSCLK_FOSC					32000000	//ֻ����ڲ�����RC	
#elif 	(SYSCLK_HSRC_DIV == 1)
#define SYSCLK_FOSC					16000000	//ֻ����ڲ�����RC
#elif 	(SYSCLK_HSRC_DIV == 2)
#define SYSCLK_FOSC					8000000		//ֻ����ڲ�����RC
#elif 	(SYSCLK_HSRC_DIV == 3)
#define SYSCLK_FOSC					4000000		//ֻ����ڲ�����RC
#endif

#define SYSCLK_FCPU 				(SYSCLK_FOSC/SYSCLK_FCPU_DIV)		//ֻ����ڲ�����RC

#define BOR_SET_1V8			0
#define BOR_SET_2V0			1
#define BOR_SET_2V4			2
#define BOR_SET_2V6			3
#define BOR_SET_3V0			4
#define BOR_SET_3V6			5
#define BOR_SET_3V9			6
#define BOR_SET_4V2			7

extern void SystemInit(void);

#endif/* __HC89F30x_SYS_H__ */
