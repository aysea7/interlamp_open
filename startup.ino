void startup() {
  delay(1000);
  Serial.begin(115200);

  // FastLED setup
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
  FastLED.setBrightness(255);

  // intro animation
  twistedFill(120, 220, 50);

  // WiFi startup
  WiFi.begin(ssid, password);
  int i = 0;
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(50);
  }
  delay(100);
  twistedFill(70, 120, 20);

  btn.setButtonLevel(BUTTON_LEVEL);

  // firmware update
  OTADRIVE.setInfo("info", version);
  OTADRIVE.updateFirmware();

  while (1==1) {
    loadAnimation(CRGB::Green);
  };
}
