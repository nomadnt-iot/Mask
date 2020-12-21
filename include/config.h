#define LED_PIN        4
#define MIC_PIN        8

#define LED_COUNT      8
#define LED_BRIGHTNESS 10
#define SAMPLE_TIME    10
#define LOUD_MIN       0
#define LOUD_MAX       800

const char animations[5] = {
  0x00, // 0 = [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
  0x18, // 1 = [ ] [ ] [ ] [X] [X] [ ] [ ] [ ]
  0x3C, // 2 = [ ] [ ] [X] [X] [X] [X] [ ] [ ]
  0x7E, // 3 = [ ] [X] [X] [X] [X] [X] [X] [ ]
  0xFF  // 4 = [X] [X] [X] [X] [X] [X] [X] [X]
};

void updateDots(char value);