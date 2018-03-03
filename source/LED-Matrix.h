void HT1632C_Write(unsigned char Data, unsigned char cnt);     //MCU向HT1632C写数据函数，高位在前/MCU writes the data to ht1632c, and the high position is in front
void HT1632C_Write_CMD(unsigned char cmd);                    //MCU向HT1632c写命令/MCU writes commands to ht1632c
void HT1632C_Write_DAT(unsigned char Addr, const uint16_t data[], unsigned char num);
void HT1632C_clr(void); //清屏函数/Clear function
void HT1632C_Init(void);                //HT1632C初始化函数/HT1632C Init Function
void HT1632C_Read_DATA(unsigned char Addr);
void HT1632C_Write_Pattern(const uint16_t pattern[]);
void HT1632C_Read_Pattern(uint16_t pattern[]);
