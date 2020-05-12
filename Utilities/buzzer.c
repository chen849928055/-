/***************************************************************************

1、此程序适用有源和无源蜂鸣器的驱动
2、可自由定义多种蜂鸣声音
3、只需传递一个参数就能达到让BUZ的声音重复响几次
4、程序结构清晰 操作方便

 
*---------------------------------------------------------------------------
 
*****************************************************************************/
 
#include "buzzer.h" 
#include "timer.h" 
/* Includes ------------------------------------------------------------------------------------------------*/
 
 
// P0M0 = 0x01;                        //P00设置为模拟输入
//    P0M1 = 0x61;                        //P01设置为非施密特数字带上拉输入
//    P2M1 = 0x51;                        //P21设置为非施密特数字带下拉输入
//    P2M3 = 0x69;                        //P23设置为施密特数字带上拉输入
//    P3M4 = 0x59;                        //P34设置为施密特数字带下拉输入
//    P3M5 = 0x71;                        //P35设置为非施密特数字带上下拉输入
//    P2M5 = 0x79;                        //P25设置为施密特数字带上下拉输入
//    P2M6 = 0xC1;                        //P26设置为推挽输出
//    P2M7 = 0xC5;                        //P27设置为开漏输出
//    P1M7 = 0xE5;                        //P17设置为开漏带上拉输出	
 




ux8 RM_BZ ;		 //蜂鸣器模式
ux16 T_BzFre ; //蜂鸣间隔时间
ux8 T_BBNum  ; //蜂鸣器在模式下的蜂鸣次数		
ux8 F_Buz ;		 //驱动信号标志	



//*************************************
// 函数名称：SetBuz
// 函数功能：设置蜂鸣器模式
// 入口参数：该模式下的蜂鸣次数 
// 出口参数：无
// 返 回 值：无
//***************************************
void SetupBz(u8 RM_BZIn,u8 BNum)
{			
	T_BzFre = 0 ;		//蜂鸣频率	
	T_BBNum = BNum ;//该蜂鸣模式的蜂鸣总次数		
	RM_BZ = RM_BZIn ;	//蜂鸣模式
	OFFIO_BUZ ;		
}
//*************************************
// 函数名称：CmdBuz
// 函数功能：蜂鸣器控制  10ms运行一次
// 入口参数：无
// 出口参数：无
// 返 回 值：无
// 备注 ：以下编写了四种常用的蜂鸣器的提示音 读者可自行修改声音及再增加声音类型
//***************************************
void CmdBuz(void)
{
	if(buz_10ms_flag== 1)
	{
		buz_10ms_flag= 0;
		
			switch(RM_BZ)
			{
				case M_BZ: 			
					SetupBz(M_BZ,0);
					break ;			
				//--------------------
				case M_BZ_KEY: // 计1次
				
						T_BzFre ++ ;
						if(T_BzFre <= VT_BUZ(10))//5
						{
							ONIO_BUZ ;
						}							
						else 
						{
							SetupBz(M_BZ,0);
						}
					break ;				
			//----------------------------	
				case M_BZ_BB :	//定时音提示－翻炒提示音	
					if(T_BBNum != 0)
					{		
						T_BzFre ++ ;						
						if(T_BzFre<= VT_BUZ(20))	
						{						
								ONIO_BUZ ;
						}		
						else if(T_BzFre <= VT_BUZ(30))
						{
								OFFIO_BUZ ;
						}
						else if(T_BzFre <= VT_BUZ(50))
						{
								ONIO_BUZ 	; 
						}
						else if(T_BzFre <= VT_BUZ(100))
						{
								OFFIO_BUZ ;
						}					
						else
						{	
								T_BzFre = 0 ;
								T_BBNum -- ;
						}								
					}				
					else 
					{
						SetupBz(M_BZ,0);
					}							
					break ;
					
				//----------------------------
				case M_BZ_LKEY ://关机 长响音
					
					if(T_BBNum != 0)
					{								
						T_BzFre ++ ;
						if(T_BzFre <= VT_BUZ(80))//BZ_T1
						{								
								ONIO_BUZ ;
						}		
						else if(T_BzFre <= VT_BUZ(100))//BZ_T2
						{
								OFFIO_BUZ ;
						}						
						else 
						{
								T_BzFre = 0 ;	
								T_BBNum -- ;			
						}						
					}
					else 
					{
						SetupBz(M_BZ,0);
					}							
				
					break ;					
				//-------------------						
				case M_BZ_ERR :
					if(T_BBNum != 0)
					{								
						T_BzFre ++ ;						
						if(T_BzFre <= VT_BUZ(12))
						{
							ONIO_BUZ ;
						}	
						else if(T_BzFre <= VT_BUZ(20))
						{
							OFFIO_BUZ	;	
						}	
						else
						{
								T_BzFre = 0 ;	
								T_BBNum -- ;	
						}								
					}						
					else 
					{
						SetupBz(M_BZ,0);
					}					
					break ;							
				//-------------------						
				default : 				
						SetupBz(M_BZ,0);			
					break ;	
			}
	}
}


////---应用实例-----

//void main(void)
//{

//SetupBz(M_BZ_LKEY,2) ;//上电蜂鸣器长响两声 

//while(1)
//{
//	while(!F_10MS) ; //10MS跑一次主程序
//	F_10MS = 0 ;

//		
//	CmdBz() ; 
//}
//}


////中断服务程序
//void interrupt server(void)
//{
////定时125U中断一次
//	
//if(F_Buz)
//{
//	BUZ_FLIPS ; //BUZ 取反 针对无源BUZ -- 4K	
//	//ONIO_BUZ ; // BUZ直驱 针对有源BUZ
//}

//}      
 




















