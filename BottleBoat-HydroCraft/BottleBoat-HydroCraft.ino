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

HMC5883L msg;
int16_t mx, my, mz;

// set up communication with bottle-boat servos
Servo rudder;
int pos = 0;

void setup() {
  rudder.attach(5);
  pinMode(3,OUTPUT);
  analogWrite(3, 125);
  rudder.write(60);
}

void readCompass() {
  msg.getHeading(&mx, &my, &mz);

  // report getHeading results for debugging purposes
  Serial.print("X:");
  Serial.println(mx);
  Serial.print("Y :");
  Serial.println(my);
  Serial.print("Heading: ");
  Serial.println(getHeading());
}

float getHeading() {

  // read compass and check for bad data
  float heading = atan2(my, mx); // 0 = north

  if (heading < 0)
    heading += 2 * M_PI;

  return heading * 180 / M_PI;
}

void loop() {
  readCompass();
  delay(200);
}

