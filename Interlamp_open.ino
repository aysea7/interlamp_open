#include <otadrive_esp.h>
#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <EncButton.h>
#include "Timer.h"

#define LED_PIN D2
#define LED_COUNT 20
#define TOUCH_BUTTON_PIN D5
#define BUTTON_LEVEL 1


CRGB leds[LED_COUNT];
EncButton<EB_TICK, TOUCH_BUTTON_PIN> btn;
int ledTwistOrder[LED_COUNT] = {0, 1, 2, 9, 10, 17, 18, 19, 15, 14, 5, 4, 3, 8, 11, 16, 13, 6, 7, 12};
bool stripFilled = false;
uint8_t hue = 0;
volatile bool buttonState = false;
const char* version = "v@1.0.42";
const char* ssid = "ssid";
const char* password = "password";

void setup()
{
  startup();
}

void loop()
{
  buttonTick();
}

