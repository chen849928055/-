/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_SYS.c
********************************************************************************


*******************************************************************************/
#include	"HC89F303.h"
#include	"HC89F30x_SYS.h"

/****************************************************************************
* Function Name  :
* Description    :
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void SystemInit(void)
{
  //SYS CLOCK
  CLKSWR = (SYSCLK_SEL << 4) | SYSCLK_HSRC_DIV;//选择内部高频RC为系统时钟，内部高频RC 2分频，Fosc=16MHz

  CLKDIV = SYSCLK_FCPU_DIV;//Fosc 1分频得到Fcpu，Fcpu=16MHz

  //BOR
#if  1
  RSTDBC = 0XFF; 			//Timer = RSTDBC*8*Tcpu + 2Tcpu
  BORC = bmBOREN | bmBOR_DBC_EN | BOR_SET_2V4 ; 		//
#else
  BORC = BORC & ~bmBOREN;
#endif
}

/*********************************END OF FILE************************************/
/******************* (C) COPYRIGHT 2009~2019 holychip ***************************/
