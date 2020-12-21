#include <Arduino.h>
#include <FastLED.h>
#include <config.h>

uint32_t lastSampleTime = 0;
uint32_t buffer = 0;

CRGB dots[LED_COUNT];

void setup()
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(dots, LED_COUNT);
  FastLED.setBrightness(LED_BRIGHTNESS);
}

void loop()
{
  uint32_t now = millis();

  if (digitalRead(MIC_PIN) == LOW) {
    buffer++;
  }

  if ((now - lastSampleTime) > SAMPLE_TIME) {
    uint8_t value = map(constrain(buffer, LOUD_MIN, LOUD_MAX), LOUD_MIN, LOUD_MAX, 0, LED_COUNT / 2);
    updateDots(value);

    FastLED.show();

    buffer = 0;
    lastSampleTime = now;
  }
}

void updateDots(char value)
{
  for(uint8_t i = 0; i < LED_COUNT; i++) {
    dots[i] = (animations[value - 1] & (1 << i)) ? CRGB::Red : CRGB::Black;
  }
}