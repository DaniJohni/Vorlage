// File Name: main.c 
// Author:	Daniel Dienemann
// Date:		xx.xx.20xx

//=========================================================
//Includes
//=========================================================
#include "mcc_generated_files/mcc.h"
#include "zyklus.h"

//=========================================================
//Defines
//=========================================================
//Define Ports
#define LED PORTA
#define BUTTON PORTC

//TimerNames for blink
#define getBlink get_Zyklus() 			//Used for blink 1

#define resetBlink reset_Zyklus() 	//Used for blink 1

//Standard
#define TRUE 1
#define FALSE 0
#define ON 1
#define OFF 0
#define LEFT 1
#define RIGHT 0

//Project specific

//=========================================================
//Global Variables
//=========================================================
//Standard
unsigned char copyOutput = 0;
unsigned char copyInput = 0;

//Project specific		!!BE CAUTIOUS OF CHAR VS INT!!


//=========================================================
//Prototypes
//=========================================================
void readInput();
void process();
void writeOutput();

unsigned char blink(unsigned int tOn, unsigned int tOff);

//Project specific

//=========================================================
//Name: initializing
//Function: Initialise the MicroController and System.
//Return Value: None
//=========================================================
void initializing()
{
	SYSTEM_Initialize(); //Initialise uC
	ZYKLUS_Initialize(); //Initialise Timer
	
	//Call function blink, reset_Zyklus & get_Zyklus to avoid warnings if they aren't used.
	//These functions are used for timing and blinking
	get_Zyklus();
	get_Zyklus1();
	get_Zyklus2();
	reset_Zyklus();
	reset_Zyklus1();
	reset_Zyklus2();


	//Project specific
	
}

//=========================================================
//Name: main
//Function: main function
//Return Value: None
//=========================================================
void main()
{
	initializing();
	while(1)
	{
		readInput();
		process();
		writeOutput();
	}
}
	
//=========================================================
//Name: readInput
//Function:Read Input from Switches (P2)
//Return Value: None
//=========================================================
void readInput()
{	
	copyInput = BUTTON; //Create Copy of Buttons/Switches
}

//=========================================================
//Name: process
//Function: Process the main Code
//Return Value: None
//=========================================================
void process()
{
    if(copyInput == 0x01)
    {
        copyOutput = blink(123, 456);
    }
    
    if(copyInput != 0x01)
    {
        copyOutput = copyInput;
    }

}

//=========================================================
//Name: writeOutput
//Function: Write Output to LED (P1)
//Return Value: None
//=========================================================
void writeOutput()
{
	//Project specific
	
	LED = copyOutput; //Write Copy to the LEDs
}

//=========================================================
//Name: functions
//Function: process the functions
//Return Value: depending on the function
//=========================================================

unsigned char blink(unsigned int tOn, unsigned int tOff)
{
		unsigned int status = 0;
		
		if(getBlink <= tOn)
		{	
			status = ON;
		}
		
		if(getBlink >= tOn)
		{
			status = OFF;
		}
		
		if(getBlink >= tOn + tOff)
		{
			resetBlink;
		}
	return status;
}