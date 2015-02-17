//#define	PHILLIPS
#define	EPSON

#ifdef __cplusplus
extern "C" {
#endif

//********************************************************************
//
//				General Function Definitions
//
//********************************************************************
void LCDCommand(unsigned char data);
void LCDData(unsigned char data);
void LCDInit(void);
void LCDClear(int color);
void LCDPrintLogo(int color);
void LCDContrast(char setting);
void LCDSetPixel(int color, unsigned char x, unsigned char y);
void ioinit(void);
void LCDSetLine(int x0, int y0, int x1, int y1, int color);
void LCDSetRect(int x0, int y0, int x1, int y1, unsigned char fill, int color);
void LCDPutChar(char c, int x, int y, int fColor, int bColor);
void LCDPutStr(char *pString, int x, int y, int fColor, int bColor);
void LCDContrast(char setting);
void LCDDrawCircle (int xCenter, int yCenter, int radius, int color, int circleType);

//********************************************************************
//
//					LCD Dimension Definitions
//
//********************************************************************
#define ROW_LENGTH	132
#define COL_HEIGHT	132
#define ENDPAGE     132
#define ENDCOL      130

//********************************************************************
//
//			PHILLIPS Controller Definitions
//
//********************************************************************
//LCD Commands
//*	Apr  4,	2010	<MLS> see definitions below, 
#if 0
	#define	NOPP		0x00	// nop 
	#define	BSTRON		0x03	
	#define SLEEPIN         0x10	
	#define	SLEEPOUT	0x11	
	#define	NORON		0x13	
	#define	INVOFF		0x20	
	#define INVON      	0x21	
	#define	SETCON		0x25	
	#define DISPOFF         0x28	
	#define DISPON          0x29	
	#define CASETP          0x2A	
	#define PASETP          0x2B	
	#define RAMWRP          0x2C	
	#define RGBSET	        0x2D	
	#define	MADCTL		0x36	
	#define	COLMOD		0x3A	
	#define DISCTR          0xB9	
	#define	EC	        0xC0	
#endif

//*************************************************************************************
//	LCD Include File for Philips PCF8833 STN RGB- 132x132x3 Driver 
// 
//		Taken from Philips data sheet Feb 14, 2003 
//*************************************************************************************
//*	I changed them to P_ for Philips
//*	many of these commands are not used but I wanted them all listed in case
//*	anyone wants to write more features
//	Philips PCF8833 LCD controller command codes 
#define	P_NOP			0x00	// nop 
#define	P_SWRESET		0x01	// software reset 
#define	P_BSTROFF		0x02	// booster voltage OFF 
#define	P_BSTRON		0x03	// booster voltage ON 
#define	P_RDDIDIF		0x04	// read display identification 
#define	P_RDDST			0x09	// read display status 
#define	P_SLEEPIN		0x10	// sleep in 
#define	P_SLEEPOUT		0x11	// sleep out 
#define	P_PTLON			0x12	// partial display mode 
#define	P_NORON			0x13	// display normal mode 
#define	P_INVOFF		0x20	// inversion OFF 
#define	P_INVON			0x21	// inversion ON 
#define	P_DALO			0x22	// all pixel OFF 
#define	P_DAL			0x23	// all pixel ON 
#define	P_SETCON		0x25	// write contrast 
#define	P_DISPOFF		0x28	// display OFF 
#define	P_DISPON		0x29	// display ON 
#define	P_CASET			0x2A	// column address set 
#define	P_PASET			0x2B	// page address set 
#define	P_RAMWR			0x2C	// memory write 
#define	P_RGBSET		0x2D	// colour set 
#define	P_PTLAR			0x30	// partial area 
#define	P_VSCRDEF		0x33	// vertical scrolling definition 
#define	P_TEOFF			0x34	// test mode 
#define	P_TEON			0x35	// test mode 
#define	P_MADCTL		0x36	// memory access control 
#define	P_SEP			0x37	// vertical scrolling start address 
#define	P_IDMOFF		0x38	// idle mode OFF 
#define	P_IDMON			0x39	// idle mode ON 
#define	P_COLMOD		0x3A	// interface pixel format 
#define	P_SETVOP		0xB0	// set Vop
#define	P_BRS			0xB4	// bottom row swap 
#define	P_TRS			0xB6	// top row swap 
#define	P_DISCTR		0xB9	// display control 
#define	P_DOR			0xBA	// data order 
#define	P_TCDFE			0xBD	// enable/disable DF temperature compensation 
#define	P_TCVOPE		0xBF	// enable/disable Vop temp comp 
#define	P_EC			0xC0	// internal or external oscillator 
#define	P_SETMUL		0xC2	// set multiplication factor 
#define	P_TCVOPAB		0xC3	// set TCVOP slopes A and B 
#define	P_TCVOPCD		0xC4	// set TCVOP slopes c and d 
#define	P_TCDF			0xC5	// set divider frequency 
#define	P_DF8COLOR		0xC6	// set divider frequency 8-color mode 
#define	P_SETBS			0xC7	// set bias system 
#define	P_RDTEMP		0xC8	// temperature read back 
#define	P_NLI			0xC9	// n-line inversion 
#define	P_RDID1			0xDA	// read ID1 
#define	P_RDID2			0xDB	// read ID2 
#define	P_RDID3			0xDC	// read ID3 
 

//*******************************************************
//				12-Bit Color Definitions
//*******************************************************
#define WHITE	0x000
#define BLACK	0xFFF
#define RED	0x0FF
#define	GREEN	0xF0F
#define BLUE	0xFF0
#define CYAN	0xF00
#define MAGENTA	0x0F0
#define YELLOW	0x00F
#define BROWN	0x4DD
#define ORANGE	0x05F
#define PINK	0x095

typedef struct
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} RGBColor;


#ifdef __cplusplus
}
#endif

//*******************************************************
//				Button Pin Definitions
//*******************************************************
#define	kSwitch1_PIN	3
#define	kSwitch2_PIN	4
#define	kSwitch3_PIN	5

//*******************************************************
//                              Circle Definitions
//*******************************************************
#define FULLCIRCLE 1
#define OPENSOUTH  2
#define OPENNORTH  3
#define OPENEAST   4
#define OPENWEST   5
#define OPENNORTHEAST 6
#define OPENNORTHWEST 7
#define OPENSOUTHEAST 8
#define OPENSOUTHWEST 9
