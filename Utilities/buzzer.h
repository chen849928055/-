/***************************************************************************
* 独立按键的初始化及其功能函数
*
* 文 件: key.h
* 作 者: CJW
* 说 明：独立按键的初始化及其功能函数
* 编写时间: 2016.7.20
* 版 本：1.0
* 修改日期： 无
 
*---------------------------------------------------------------------------
* 注: //00表示没有按键
			//01表示按键1
			//02表示按键2
			//04表示按键3
			//08表示按键4
			//10表示按键5 
*****************************************************************************/
#ifndef __BUZZER_H
#define __BUZZER_H

#include "HC89F303.h" 
/* Includes ------------------------------------------------------------------------------------------------*/
 
////=====蜂鸣器驱动寄存器定义=====

extern	ux8 RM_BZ ;		 //蜂鸣器模式
extern	ux16 T_BzFre ; //蜂鸣间隔时间
extern	ux8 T_BBNum  ; //蜂鸣器在模式下的蜂鸣次数		
extern	ux8 F_Buz ;		 //驱动信号标志	
 

//=====buz 驱动端口====
 
#define		BUZ_FLIPS		{P3_4 = ~P3_4 ;} //BUZ IO 取反


//=====BUZ 端口操作====    有效端口为1 0
#define		OFFIO_BUZ		{P3_4 = 0;F_Buz = 0;} //
#define		ONIO_BUZ		{F_Buz = 1;}//

//----------------------------------
#define		VT_BUZ(x)   (x) 
//宏定义 BUZ的几中常见声音
#define	 	M_BZ			  (unsigned char)0
#define	 	M_BZ_KEY		(unsigned char)1		//短响
#define	 	M_BZ_BB			(unsigned char)3		//滴..滴 定时音 
#define	 	M_BZ_LKEY		(unsigned char)4		//长响
#define	 	M_BZ_ERR 		(unsigned char)5		//报警

      
/*****************************硬件I/O引脚定义,根据实际应用修改******************************/
 
void SetupBz(u8 RM_BZIn,u8 BNum);
void CmdBuz(void);       

//-------------------------------------------------------------------------------------------------------
#endif



