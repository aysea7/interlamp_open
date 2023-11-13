void fillStripWithColor(const CRGB& color) {
  for (int i = 0; i < LED_COUNT; i++) {
    leds[i] = color;
  }
  FastLED.show();
}

void fillStripWithColorCHSV(uint8_t hue, uint8_t saturation = 255, uint8_t value = 255) {
  for (int i = 0; i < LED_COUNT; i++) {
    leds[i] = CHSV(hue, saturation, value);
  }
  FastLED.show();
}

void clearStrip() {
  FastLED.clear();
  FastLED.show();
}

void twistedFill(uint8_t lowerLimit = 0, uint8_t upperLimit = 255, uint8_t delaySpeed = 30, bool randomColour = true, uint8_t colour = 0) {
  for (int i = 0; i < LED_COUNT; i++) {
    int ledIndex = ledTwistOrder[i];

    if (randomColour) {
        leds[ledIndex] = CHSV(random(lowerLimit, upperLimit), 255, 255);
      } else {
        leds[ledIndex] = CHSV(colour, 255, 255);
    };
    FastLED.show();

    delay(delaySpeed);
  }
}

void loadAnimation(CRGB color) {
  static int8_t dir = 1;
  static uint8_t val = 0;
  static Timer tmr(20);
  if (tmr.period()) {
    val += dir;
    if (val >= 100 || val <= 0) dir = -dir;
    fillStripWithColor(color);
    FastLED.setBrightness(val);
    FastLED.show();
  }
  yield();
}

