/************************************************************
* gpiofile.c : Accessing the GPIO directly from C
*************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "gpiofile.h"

#define MODE_FILE_FORMAT "/sys/devices/virtual/misc/gpio/mode/gpio%d"
#define PIN_FILE_FORMAT  "/sys/devices/virtual/misc/gpio/pin/gpio%d"

int ModeFile[14] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
int ValFile[14] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

void _set_GPIO_mode(int pin, char* io);
void _set_GPIO_val(int pin, char *val);

void initAltOutputHandling(int pins[], int count)
{
	int i;
	int pin;
	
	for (i = 0; i < count; i++)
	{
		  pin = pins[i];
		  	
		  if (ModeFile[pin] == -1)
		  {
			char buffer[128];
			
			sprintf(buffer,MODE_FILE_FORMAT,pin);
			ModeFile[pin] = open(buffer,O_WRONLY,0666);
			if(ModeFile[pin] == -1)
			{
			  printf("Unable to open mode file: %s\n",buffer);
			}
		  }
		  
		  if (ValFile[pin] == -1)
		  {
			  char buffer[128];

			  sprintf(buffer,PIN_FILE_FORMAT,pin);
			  ValFile[pin] = open(buffer,O_WRONLY,0666);
			  if(ValFile[pin] == -1)
			  {
				printf("Unable to open pin file: %s\n",buffer);
			  }
		  }
	}
}

void pinModeAlt(int pin, int mode)
{
	char buffer[2];
	sprintf(buffer, "%d", mode);
	
	_set_GPIO_mode(pin, buffer);
}

void digitalWriteAlt(int pin, int val)
{
	char buffer[2];
	sprintf(buffer, "%d", val);
	
	_set_GPIO_val(pin, buffer);
}

/* ----------------------------------------------------------------------*/

void _set_GPIO_mode(int pin, char* io)
{
  if (ModeFile[pin] != -1)
  {
	  /* Set the pin mode (input="0" or output="1" */
	  write(ModeFile[pin],io,1);
  }
}

void _set_GPIO_val(int pin, char *val)
{
  if (ValFile[pin] != -1)
  {
	  /* Set the pin HIGH="1" or LOW="0" */
	  write(ValFile[pin],val,1);
  }
}
