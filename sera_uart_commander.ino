/*
 * 
 */
#include <DS3231.h>
#include <Wire.h>

DS3231 clock;

bool h12Flag;
bool pmFlag;
bool dayTime = 0;

bool isDayTime(int hour) {
  if (hour >= 9 && hour < 17)
    return true;
  else
    return false;
}

void setup() {
  // Start the I2C interface
  Wire.begin();

  // Start the serial interface
  Serial.begin(9600);
}

void loop() {



  //Serial.println(clock.getHour(h12Flag, pmFlag)); //prints the hour
  dayTime = isDayTime(clock.getHour(h12Flag, pmFlag));  //evaluates if datime by checking hour


  if (dayTime) {
    Serial.print("S:20.0");  //set temp to 20 degrees in daytime
  } else {
    Serial.print("S:11.0");  //set temp to 11 degrees while nighttime
  }

  delay(1200000);  //20 minutes until next check
}
