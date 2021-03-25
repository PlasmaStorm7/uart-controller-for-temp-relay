/*
 * 
 */
#include <DS3231.h>
#include <Wire.h>

DS3231 clock;

bool h12Flag;
bool pmFlag;
int dayTime=0;
int previousDT=1;

int isDayTime(int hour){
  if(hour>=10 && hour<16)
    return 1;
  else 
    return 0;
}

void setup() {
	// Start the I2C interface
	Wire.begin();
 
	// Start the serial interface
	Serial.begin(9600);
 previousDT=!dayTime;
}

void loop() {
	
  
	
  //Serial.println(clock.getHour(h12Flag, pmFlag)); //prints the hour
	dayTime=isDayTime(clock.getHour(h12Flag, pmFlag)); //evaluates if datime by checking hour
      
  	if(!(dayTime==previousDT)){ //only change if it's not already
      if(dayTime){
        Serial.print("S:20.0");   //set temp to 20 degrees in daytime     
      }
      else
      {
        Serial.print("S:16.0"); //set temp to 16 degrees while nighttime
      }
  	}
   previousDT=dayTime;
   delay(1200000);//20 minutes until next check
	
}
