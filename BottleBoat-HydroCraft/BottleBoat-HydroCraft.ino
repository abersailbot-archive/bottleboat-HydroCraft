#include <TinyGPS++.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <HMC5883L.h>
#include <Servo.h>


/*
Program for the bottle-boat designed by group HydroCraft, under robotics team Aber Sailbot
at Aberystwyth University. Aber SailBot website available at: http://abersailbot.co.uk/

Created October 28th by Jack Morgan (jam30@aber.ac.uk)
Project repository available at: https://github.com/abersailbot/bottleboat-HydroCraft
*/

// Latest change: moved my funcs beneath Arduino funcs (setup & loop) and improved commenting

HMC5883L msg;
int16_t mx, my, mz;

// set up communication with bottle-boat servos
Servo rudder;
int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT); rudder.attach(5);
  analogWrite(3, 125); rudder.write(60);
}

void loop() {
  readCompass();
  delay(200);
}

void readCompass() {
  Serial.print("Heading");
  
  msg.getHeading(&mx, &my, &mz);

  // report getHeading results for debugging purposes
  Serial.print("X:"); Serial.println(mx);
  Serial.print("Y :"); Serial.println(my);
  Serial.print("Heading: "); Serial.println(heading());
}

float heading() {
  // read compass and correct for bad data, then return result
  // 0 = north
  float heading = atan2(my, mx);

  if (heading < 0)
    heading += 2 * M_PI;

  return heading * 180 / M_PI;
}
