// [DEV-JACK]: Problem with HMC5883L.h library? "fatal error: I2Cdev.h: No such file or directory #include "I2Cdev.h""
// #include <HMC5883L.h> 
#define fanMotor 3
#define rudder 5

/*
Program for the bottle-boat designed by group HydroCraft, under robotics team Aber Sailbot
at Aberystwyth University. Aber SailBot website available at: http://abersailbot.co.uk/

Created October 28th by Jack Morgan (jam30@aber.ac.uk)
Project repository available at: https://github.com/abersailbot/bottleboat-HydroCraft
*/

void setup() {

  // [DEV-JACK]: Haven't used structs nor double floats before, need help on this
  // vars to store 4 GPS waypoints
  struct GPS {
    double float w;
    double float x;
    double float y;

    // a backup waypoint; to head for home etc.
    double float z;
  }

  // fan motor
  pinMode(fanMotor, OUTPUT);

  // rudder
  pinMode(rudder, OUTPUT);
}

void loop() {
}

void propeller(){
  // [DEV-JACK]: code to control propeller here(?)
}

void rudder(){
  // [DEV-JACK]: code to control rudder here(?)
}

