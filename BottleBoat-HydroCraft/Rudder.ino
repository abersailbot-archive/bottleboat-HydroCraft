void rudderSweep() {
  // sweep left
  for (pos = 0; pos <= 180; pos += 1) {
    rudder.write(pos);
    delay(15);
  }

  // sweep right
  for (pos = 180; pos >= 0; pos -= 1) {
    rudder.write(pos);
    delay(15);
  }
}
