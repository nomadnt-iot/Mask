#include <Arduino.h>
#include <FastLED.h>
#include <config.h>
// add power lib support to shutdown after a while

CRGB dots[LED_COUNT];

void setup()
{
  DEBUG_BEGIN(9600);
  DEBUG_PRINTLN(F("Initializing..."));
  pinMode(MIC_PIN, INPUT);

  // we need to disable all the other input to save battery
  FastLED.addLeds<WS2812, LED_PIN, GRB>(dots, LED_COUNT);
  FastLED.setBrightness(LED_BRIGHTNESS);

  // testing leds
  for(uint8_t j = 0; j < 2; j++) {
    for(uint8_t i = 0; i < LED_COUNT; i++) {
      dots[i] = (j == 0) ? CRGB::Red : CRGB::Black;
      FastLED.show();
      delay(50);
    }
  }
}

void loop()
{
  peak();
  // amplitude();
}

void updateDots(unsigned char value)
{
  for(uint8_t i = 0; i < LED_COUNT; i++) {
    dots[i] = (animations[value] & (1 << i)) ? CRGB::Red : CRGB::Black;
  }

  FastLED.show();
}

#if defined(MAX4466)
unsigned int sample;

void peak()
{
  unsigned long startMillis= millis();  // Start of sample window
  unsigned int peakToPeak = 0;          // peak-to-peak level

  unsigned int signalMax = LOUD_MIN;
  unsigned int signalMin = LOUD_MAX;

  // collect data for 50 mS
  while (millis() - startMillis < SAMPLE_WINDOW)
  {
    sample = analogRead(A0);
    if (sample < LOUD_MAX)  // toss out spurious readings
    {
      if (sample > signalMax)
      {
        signalMax = sample;  // save just the max levels
      }
      else if (sample < signalMin)
      {
        signalMin = sample;  // save just the min levels
      }
    }
  }
  
  peakToPeak = signalMax - signalMin;            // max - min = peak-peak amplitude
  double volts = (peakToPeak * 5.0) / LOUD_MAX;  // convert to volts

  Serial.println(volts);
}
#endif

#if defined(MAX4466)
uint32_t lastSampleTime = 0;
uint32_t buffer = 0;

void amplitude()
{
  uint32_t now = millis();

  if (digitalRead(MIC_PIN) == LOW) {
    buffer++;
  }

  if ((now - lastSampleTime) > SAMPLE_WINDOW) {
    uint8_t value = map(constrain(buffer, LOUD_MIN, LOUD_MAX), LOUD_MIN, LOUD_MAX, 0, LED_COUNT / 2);
    updateDots(value);

    buffer = 0;
    lastSampleTime = now;
  }
}
#endif