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

HMC5883L msg;
TinyGPSPlus gps;

// 16 bit ints to track x-y-z position
int16_t mx, my, mz;

// create servo object with var to store servo position for rudder
Servo rudder;
int pos = 0;

void setup() {
  Serial.begin(9600);

  // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();

  Serial.println("Initializing I2C devices...");
    msg.initialize();

    Serial.println("Testing device connections...");
    Serial.println(msg.testConnection() ? "HMC5883L connection successful" : "HMC5883L connection failed");

  // set rudder and propeller pins
  rudder.attach(5);
  pinMode(3, OUTPUT);
  analogWrite(3, 125);
}

void loop() {
  readCompass();
  delay(200);
  displayInfo();
}
