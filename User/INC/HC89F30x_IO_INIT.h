/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_IO_INIT.h
********************************************************************************


*******************************************************************************/
#ifndef __HC89F30x_IO_INIT_H__
#define __HC89F30x_IO_INIT_H__

//================================================================================
//输入设置
#define	GPIO_In_AN							0X01			//模拟输入(Analog),AD&CTK通道应设为此模式,闲置管脚可设为此状态, 避免在低功耗模式下出现漏电
#define	GPIO_In_FLOATING					0X41			//浮空数字输入(Floating)
#define	GPIO_In_PU							0X61			//带上拉数字输入(Pull-Up)
#define	GPIO_In_PD							0X51			//带下拉数字输入(Pull-Down)
#define	GPIO_In_STMEN						0X49			//数字输入下使能斯密特(SMIT EN)
#define	GPIO_Out_PP							0XC1			//推挽输出(Push-Pull)	
#define	GPIO_Out_OD_Level2					0XC5			//开漏输出(Open-Drain)		
#define	GPIO_Out_ODPU						0XE5			//开漏带上拉输出(Open-Drain+Pull-Up)


#define SET_PORT_IN(port_num, pin_num,p_mode)						        ((P##port_num##M##pin_num) = p_mode) 
#define SET_PORT_OUT(port_num, pin_num,p_mode,p_data)						(((P##port_num##M##pin_num) = p_mode),((P##port_num##_##pin_num) = p_data) )

extern void IO_Init(void);

#endif /* __HC89F30x_IO_INIT__ */
