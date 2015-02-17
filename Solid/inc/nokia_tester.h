void delay_us(int x);
void ioinit(void);
void reset(void);




// New
//************************************************************************
//*	adapted for Arduino and Mega by Mark Sproul
//*	Pin definitions
//*		RES	Reset			Digital Pin 8
//*		CS	Chip Select		Digital Pin 9
//*		DIO	Data I/O		Digital Pin 11
//*		SCK	Serial Clock	Digital Pin 13
//************************************************************************
//*		At first I tried to port it to the Arduino pin model, i.e. digitalWrite.
//*		As I feared, it introduced a noticeable decrease in speed.  For the LCD
//*		interface it needs to stay as it was. I now have it fully working on the
//*		mega utilizing the original code. This was done by modifying the pin
//*		definitions in the .h file.  Very straight forward and very clean. In fact
//*		it worked first shot on the Mega.
//************************************************************************
//*	these define the PORT and BIT number for each control pin
#define _USE_ARDUINO_FOR_NOKIEA_

//*	Arduino pin number defs
#define	RES_PIN		8
#define	CS_PIN		9
#define	DIO_PIN		11
#define	SCK_PIN		13


