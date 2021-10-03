#define LED_COUNT      8
#define LED_BRIGHTNESS 10
#define MAX4466

#if defined(MAX4466)
  #define SAMPLE_WINDOW  50 // sample window width in mS (50 mS = 20Hz)
  #define LOUD_MIN       0
  #define LOUD_MAX       1024
#else
  #define SAMPLE_WINDOW  10 // on attiny85 8 mhz is not working as expected
  #define LOUD_MIN       0
  #define LOUD_MAX       800
#endif

#if defined (ARDUINO_AVR_ATTINYX5) || defined (ARDUINO_AVR_TRINKET3)
  #define LED_PIN        1
  #define MIC_PIN        0
#elif defined (ARDUINO_AVR_ATmega328P) || defined (ARDUINO_AVR_UNO)
  #define LED_PIN        4
  // #define MIC_PIN        8  // use this when you are using simple mic sensor
  #define MIC_PIN        A0
  #define DEBUG
#endif

#if defined(DEBUG)
  #define DEBUG_BEGIN(baudrate) Serial.begin(baudrate);
  #define DEBUG_PRINT(msg) Serial.print(msg);
  #define DEBUG_PRINTLN(msg) Serial.println(msg);
#else
  #define DEBUG_BEGIN(baudrate)
  #define DEBUG_PRINT(msg)
  #define DEBUG_PRINTLN(msg)
#endif

const unsigned char animations[LED_COUNT + 1] = {
  0x00, // 0 = [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
  0x18, // 1 = [ ] [ ] [ ] [X] [X] [ ] [ ] [ ]
  0x3C, // 2 = [ ] [ ] [X] [X] [X] [X] [ ] [ ]
  0x7E, // 3 = [ ] [X] [X] [X] [X] [X] [X] [ ]
  0xFF  // 4 = [X] [X] [X] [X] [X] [X] [X] [X]
};

/**
 * update leds
 */
void updateDots(unsigned char value);

#if defined(MAX4466)
void amplitude();
#else
void peak();
#endif