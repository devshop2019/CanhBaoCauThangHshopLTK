
/*
 *	Copyright:	DFRobot
 *	name:		DFPlayer_Mini_Mp3 sample code
 *	Author:		lisper <lisper.li@dfrobot.com>
 *	Date:		2014-05-30
 *	Description:	connect DFPlayer Mini by SoftwareSerial, this code is test on Uno
 *			Note: the mp3 files must put into mp3 folder in your tf card 
 *     
 *      sd:\mp3\000x.mp3
 *      
 *      Can co 2 bai 0001.mp3, 0002.mp3 de test
 */
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

#define RX_DF_PLAYER        12 // D6 - NodeMCU
#define TX_DF_PLAYER        14 // D5 - NodeMCU

SoftwareSerial mySerial(TX_DF_PLAYER, RX_DF_PLAYER, false, 256); // RX, TX

void setup () {
	Serial.begin (9600);
	mySerial.begin (9600);
	mp3_set_serial (mySerial);	//set softwareSerial for DFPlayer-mini mp3 module 
	mp3_set_volume (30);
}


//
void loop () {        
	mp3_play (1);
	delay (90000);
	mp3_next ();
	delay (60000);
	mp3_prev ();
	delay (60000);
	mp3_play (2);
	delay (60000);
}

/*
   mp3_play ();		//start play
   mp3_play (5);	//play "mp3/0005.mp3"
   mp3_next ();		//play next 
   mp3_prev ();		//play previous
   mp3_set_volume (uint16_t volume);	//0~30
   mp3_set_EQ ();	//0~5
   mp3_pause ();
   mp3_stop ();
   void mp3_get_state (); 	//send get state command
   void mp3_get_volume (); 
   void mp3_get_u_sum (); 
   void mp3_get_tf_sum (); 
   void mp3_get_flash_sum (); 
   void mp3_get_tf_current (); 
   void mp3_get_u_current (); 
   void mp3_get_flash_current (); 
   void mp3_single_loop (boolean state);	//set single loop 
   void mp3_DAC (boolean state); 
   void mp3_random_play (); 
 */

