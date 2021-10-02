# eMask

eMask is a simple weareable face mask that provide a feedback while speaking.
It was developed using arduino uno and shrinked to fit ATTinyX5 based boards.

## Configruation

To configure eMask change the define inside the `config.h` file

```cpp
const char animations[5] = {
  0x00, // 0 = [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
  0x18, // 1 = [ ] [ ] [ ] [X] [X] [ ] [ ] [ ]
  0x3C, // 2 = [ ] [ ] [X] [X] [X] [X] [ ] [ ]
  0x7E, // 3 = [ ] [X] [X] [X] [X] [X] [X] [ ]
  0xFF  // 4 = [X] [X] [X] [X] [X] [X] [X] [X]
};
```

```cpp
const char animations[] = {
  0x18, // 1 = [ ] [ ] [ ] [X] [X] [ ] [ ] [ ]
  0x3C, // 2 = [ ] [ ] [X] [ ] [ ] [X] [ ] [ ]
  0x7E, // 3 = [ ] [X] [ ] [ ] [ ] [ ] [X] [ ]
  0xFF  // 4 = [X] [ ] [ ] [ ] [ ] [ ] [ ] [X]
  0x7E, // 5 = [ ] [X] [ ] [ ] [ ] [ ] [X] [ ]
  0x3C, // 6 = [ ] [ ] [X] [ ] [ ] [X] [ ] [ ]
  0x18, // 7 = [ ] [ ] [ ] [X] [X] [ ] [ ] [ ]
};
```

```cpp
const char animations[] = {
  0x18, // 1 = [ ] [ ] [ ] [X] [X] [ ] [ ] [ ]
  0x3C, // 2 = [ ] [ ] [X] [ ] [ ] [X] [ ] [ ]
  0x7E, // 3 = [ ] [X] [ ] [ ] [ ] [ ] [X] [ ]
  0xFF  // 4 = [ ] [X] [ ] [ ] [ ] [ ] [X] [ ]
  0x7E, // 5 = [ ] [X] [ ] [ ] [ ] [ ] [X] [ ]
  0x3C, // 6 = [ ] [ ] [X] [ ] [ ] [X] [ ] [ ]
  0x18, // 7 = [ ] [ ] [ ] [X] [X] [ ] [ ] [ ]
};
```

```cpp
const char animations[] = {
  0x18, // 1 = [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
  0x3C, // 2 = [ ] [ ] [X] [X] [X] [X] [ ] [ ]
  0x7E, // 3 = [ ] [X] [ ] [ ] [ ] [ ] [X] [ ]
  0xFF  // 4 = [X] [X] [ ] [ ] [ ] [ ] [X] [X]
  0x7E, // 5 = [ ] [X] [ ] [ ] [ ] [ ] [X] [ ]
  0x3C, // 6 = [ ] [ ] [X] [X] [X] [X] [ ] [ ]
  0x18, // 7 = [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
};
```

## Requirements

* x1 Stripboard
* x1 Stripboard WS2812 8 dots
* x1 ATTinyX5
* x1 430 ohm resistor
* x1 Mic breakout with max4466
* x1 Battery holder
* x1 Battery 3.7v