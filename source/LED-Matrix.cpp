#include<cereal.h>

/******************指令表/Instructions**********************/
#define SYS_DIS 0x00                //关闭系统震荡/Turn off system shock
#define SYS_EN  0x01                //打开系统震荡/Turn on  system shock
#define LED_OFF 0x02                //关闭LED显示/Turn off LED display
#define LED_ON  0x03                //打开LED显示/Turn on LED display
#define BLINK_OFF   0x08            //关闭闪烁   /Close blink
#define BLINK_ON    0x09            //打开闪烁   /Open blink            
#define SLAVE_MODE  0x10            //从模式     /Slave mode
#define RC_MASTER_MODE  0x18        //内部RC时钟 /Use internal clock 
#define COM_OPTION  0x24            //24:16COM，NMOS。C：COM，PMOS。
#define PWM_DUTY    0xAF            //PWM亮度控制 /PWM Brightness Control
/****************引脚定义 I/O definition**********************/

#define HT_CS 16
#define HT_DATA 21
#define HT_RD 22
#define HT_WR 23

static NRF_GPIO_Type *gpiobase= (NRF_GPIO_Type *)NRF_GPIO_BASE;

inline void CSon(void) { gpiobase->OUTCLR= 1<<HT_CS; }
inline void CSoff(void) { gpiobase->OUTSET= 1<<HT_CS; }
inline void RDon(void) { gpiobase->OUTCLR= 1<<HT_RD; }
inline void RDoff(void) { gpiobase->OUTSET= 1<<HT_RD; }
inline void WRon(void) { gpiobase->OUTCLR= 1<<HT_WR; }
inline void WRoff(void) { gpiobase->OUTSET= 1<<HT_WR; }
inline void DATA0(void) { gpiobase->OUTCLR= 1<<HT_DATA; }
inline void DATA1(void) { gpiobase->OUTSET= 1<<HT_DATA; }
inline void RDdata(void) { gpiobase->DIRCLR= 1<<HT_DATA; }
inline void WRdata(void) { gpiobase->DIRSET= 1<<HT_DATA; }

static unsigned char com[12] = {
  0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C
};

void HT1632C_Write(unsigned char Data, unsigned char cnt)      //MCU向HT1632C写数据函数，高位在前/MCU writes the data to ht1632c, and the high position is in front
{
  unsigned char i;
  for(i=0; i<cnt; i++) {
    WRon();
    if(Data&0x80) {
      DATA1();
    } else {
      DATA0();
    }
    Data<<=1;
    WRoff();
  }
}

void HT1632C_Write_CMD(unsigned char cmd)                     //MCU向HT1632c写命令/MCU writes commands to ht1632c
{
  WRdata();
  CSon();
  HT1632C_Write(0x80,3);                                    //ID:100
  HT1632C_Write(cmd,9);
  CSoff();
}

void HT1632C_Write_DAT(unsigned char Addr, const uint16_t data[], unsigned char num)
{
  WRdata();
  CSon();
  HT1632C_Write(0xa0,3);                                    //ID:101
  HT1632C_Write(Addr<<1,7);

  uint16_t d= data[num];
  for(unsigned char i=0; i<12; i++) {
    WRon();
    if(d&0x8000) {
      DATA1();
    } else {
      DATA0();
    }
    d<<=1;
    WRoff();
  }
  CSoff();
}

void HT1632C_clr(void)  //清屏函数/Clear function
{
  unsigned char i;
  WRdata();
  CSon();
  HT1632C_Write(0xa0,3);
  HT1632C_Write(0x00,7);
  for(i=0; i<48; i++) {
    HT1632C_Write(0,8);
  }
  CSoff();
}

void HT1632C_Init(void)                 //HT1632C初始化函数/HT1632C Init Function
{
  gpiobase->OUTSET= 0x00E10000;
  gpiobase->PIN_CNF[HT_CS]= 0x1;
  gpiobase->PIN_CNF[HT_RD]= 0x1;
  gpiobase->PIN_CNF[HT_WR]= 0x1;
  gpiobase->PIN_CNF[HT_DATA]= 0x1;
  gpiobase->OUTSET= 0x00E10000;
  HT1632C_Write_CMD(SYS_DIS);         //关闭HT1632C内部RC时钟/Close the HT1632C internal clock
  HT1632C_Write_CMD(COM_OPTION);      //选择HT1632C工作模式/Select HT1632C work mode
  HT1632C_Write_CMD(RC_MASTER_MODE);  //选择内部RC时钟/Select internal clock
  HT1632C_Write_CMD(SYS_EN);          //打开HT1632C内部RC时钟/Open the HT1632C internal clock
  HT1632C_Write_CMD(PWM_DUTY);        //PWM亮度设置/Init the PWM Brightness
  HT1632C_Write_CMD(BLINK_OFF);       //关闭闪烁   /Close blink
  HT1632C_Write_CMD(LED_ON);          //打开LED显示/ Turn on LED display
}

void HT1632C_Read_DATA(unsigned char Addr)
{
  unsigned char i;
  RDdata();
  CSon();
  HT1632C_Write(0xc0,3);                                    //ID:101
  HT1632C_Write(Addr<<1,7);
  for(i=0; i<12; i++) {
    RDon();
    asm("nop");
    RDoff();
  }
  CSoff();
}

void HT1632C_Write_Pattern(const uint16_t pattern[])
{
  for (int col=0; col<12; col++) {
    HT1632C_Write_DAT(com[col],pattern,col);
  }
}
