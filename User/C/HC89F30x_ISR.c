/******************* (C) COPYRIGHT 2009~2019 holychip **************************
* File Name          : HC89F30x_ISR.c
********************************************************************************


*******************************************************************************/
#include "HC89F303.h"

//================================================================================
extern void CTK_ISR_Handle(void);

/****************************************************************************
* Function Name  : ISR_INT0
* Description    : INT0 interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void ISR_INT0(void)      interrupt INT0_VECTOR
{
  while(1);
}

/****************************************************************************
* Function Name  : ISR_Timer0
* Description    : Timer0 interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
//void ISR_Timer0(void)     interrupt TIMER0_VECTOR
//{
//  while(1);
//}

/****************************************************************************
* Function Name  : ISR_INT1
* Description    : INT1 interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void ISR_INT1(void)       interrupt INT1_VECTOR
{
  while(1);
}

/****************************************************************************
* Function Name  : ISR_Timer1
* Description    : Timer1 interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
//void ISR_Timer1(void)     interrupt TIMER1_VECTOR
//{
//  while(1);
//}

/****************************************************************************
* Function Name  : ISR_UART1
* Description    : UART1 interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void ISR_UART1(void)     interrupt UART1_VECTOR
{
  while(1);
}

/****************************************************************************
* Function Name  : ISR_WDT
* Description    : WDT interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void ISR_WDT(void)       interrupt WDT_VECTOR
{
  while(1);
}

/****************************************************************************
* Function Name  : ISR_IIC
* Description    : IIC interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void ISR_IIC(void)       interrupt IIC_VECTOR
{
  while(1);
}

/****************************************************************************
* Function Name  : ISR_Timer3
* Description    : Timer3 interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void ISR_Timer3(void)     interrupt T3_VECTOR
{
  while(1);
}

/****************************************************************************
* Function Name  : ISR_Timer4
* Description    : Timer4 interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void ISR_Timer4(void)     interrupt T4_VECTOR
{
  while(1);
}

/****************************************************************************
* Function Name  : ISR_PWM
* Description    : PWM interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void ISR_PWM(void)       interrupt PWM_VECTOR
{
  while(1);
}

/****************************************************************************
* Function Name  : ISR_CTK
* Description    : CTK interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void ISR_CTK(void)      interrupt CTK_VECTOR
{
  CTK_ISR_Handle();
}

/****************************************************************************
* Function Name  : ISR_ADC
* Description    : ADC interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void ISR_ADC(void)      interrupt ADC_VECTOR
{
  while(1);
}

/****************************************************************************
* Function Name  : ISR_INT16_17
* Description    : INT16~17 interrupt request
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
void ISR_INT16_17(void)  interrupt INT16_17_VECTOR
{
  while(1);
}

/*********************************END OF FILE************************************/
/******************* (C) COPYRIGHT 2009~2019 holychip ***************************/
