// report heading results for debugging purposes
void readCompass() {
  Serial.print("Heading");

  msg.getHeading(&mx, &my, &mz);

  Serial.print("X:"); Serial.println(mx);
  Serial.print("Y :"); Serial.println(my);
  Serial.print("Heading: "); Serial.println(heading());
}

// read compass and correct for bad data/angles
float heading() {
  float heading = atan2(my, mx); // 0 = north

  if (heading < 0)
    heading += 2 * M_PI;

  return heading * 180 / M_PI;
}
