/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_IO_INIT.h
********************************************************************************


*******************************************************************************/
#ifndef __HC89F30x_IO_INIT_H__
#define __HC89F30x_IO_INIT_H__

//================================================================================
//��������
#define	GPIO_In_AN							0X01			//ģ������(Analog),AD&CTKͨ��Ӧ��Ϊ��ģʽ,���ùܽſ���Ϊ��״̬, �����ڵ͹���ģʽ�³���©��
#define	GPIO_In_FLOATING					0X41			//������������(Floating)
#define	GPIO_In_PU							0X61			//��������������(Pull-Up)
#define	GPIO_In_PD							0X51			//��������������(Pull-Down)
#define	GPIO_In_STMEN						0X49			//����������ʹ��˹����(SMIT EN)
#define	GPIO_Out_PP							0XC1			//�������(Push-Pull)	
#define	GPIO_Out_OD_Level2					0XC5			//��©���(Open-Drain)		
#define	GPIO_Out_ODPU						0XE5			//��©���������(Open-Drain+Pull-Up)


#define SET_PORT_IN(port_num, pin_num,p_mode)						        ((P##port_num##M##pin_num) = p_mode) 
#define SET_PORT_OUT(port_num, pin_num,p_mode,p_data)						(((P##port_num##M##pin_num) = p_mode),((P##port_num##_##pin_num) = p_data) )

extern void IO_Init(void);

#endif /* __HC89F30x_IO_INIT__ */
