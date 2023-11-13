void buttonTick() {
  btn.tick();


  switch (btn.hasClicks()) {
    case 1:
      Serial.print("1");
      fillStripWithColor(CRGB::Indigo);
      break;
    case 2:
    Serial.print("2");
      fillStripWithColor(CRGB::Gold);
      break;
    case 3:
    Serial.print("3");
      fillStripWithColor(CRGB::Green);
      break;
  }


  if (btn.step()) {
    if (hue == 255) {
        hue = 0;
      } else {
        hue += 5;
      };
    twistedFill(0, 0, 10, false, hue);
  };

  if (btn.releaseStep()) {
    delay(1);
  }
}
