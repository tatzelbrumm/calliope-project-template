#include<cereal.h>

/******************Instructions**********************/
#define SYS_DIS 0x00                //Turn off system shock
#define SYS_EN  0x01                //Turn on  system shock
#define LED_OFF 0x02                //Turn off LED display
#define LED_ON  0x03                //Turn on LED display
#define BLINK_OFF   0x08            //Close blink
#define BLINK_ON    0x09            //Open blink            
#define SLAVE_MODE  0x10            //Slave mode
#define RC_MASTER_MODE  0x18        //Use internal clock 
#define COM_OPTION  0x24            //
#define PWM_DUTY    0xAF            //PWM Brightness Control
/****************I/O definition**********************/

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

void HT1632C_Write(unsigned char Data, unsigned char cnt)      //MCU writes the data to ht1632c, and the high position is in front
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

void HT1632C_Write_CMD(unsigned char cmd) //MCU writes commands to ht1632c
{
  WRdata();
  CSon();
  HT1632C_Write(0x80,3);
  HT1632C_Write(cmd,9);
  CSoff();
}

void HT1632C_Write_DAT(unsigned char Addr, const uint16_t data[], unsigned char num)
{
  WRdata();
  CSon();
  HT1632C_Write(0xa0,3);
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

void HT1632C_clr(void)  //Clear function
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

void HT1632C_Init(void) //HT1632C Init Function
{
  gpiobase->OUTSET= 0x00E10000;
  gpiobase->PIN_CNF[HT_CS]= 0x1;
  gpiobase->PIN_CNF[HT_RD]= 0x1;
  gpiobase->PIN_CNF[HT_WR]= 0x1;
  gpiobase->PIN_CNF[HT_DATA]= 0x1;
  gpiobase->OUTSET= 0x00E10000;
  HT1632C_Write_CMD(SYS_DIS);         //Close the HT1632C internal clock
  HT1632C_Write_CMD(COM_OPTION);      //Select HT1632C work mode
  HT1632C_Write_CMD(RC_MASTER_MODE);  //Select internal clock
  HT1632C_Write_CMD(SYS_EN);          //Open the HT1632C internal clock
  HT1632C_Write_CMD(PWM_DUTY);        //Init the PWM Brightness
  HT1632C_Write_CMD(BLINK_OFF);       //Close blink
  HT1632C_Write_CMD(LED_ON);          // Turn on LED display
}

uint16_t HT1632C_Read_DATA(unsigned char Addr)
{
  WRdata();
  CSon();
  HT1632C_Write(0xc0,3);
  HT1632C_Write(Addr<<1,7);
  RDdata();
  uint16_t datum= 0;
  for(unsigned char i=0; i<12; i++) {
    RDon();
    datum<<=1;
    datum|= (gpiobase->IN & (1<<HT_DATA))>>(HT_DATA-4);
    RDoff();
  }
  CSoff();
  return datum;
}

void HT1632C_Write_Pattern(const uint16_t pattern[])
{
  for (int col=0; col<12; col++) {
    HT1632C_Write_DAT(com[col],pattern,col);
  }
}

void HT1632C_Read_Pattern(uint16_t pattern[])
{
  for (int col=0; col<12; col++) {
    pattern[col]= HT1632C_Read_DATA(com[col]);
  }
}
