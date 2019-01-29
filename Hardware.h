#ifndef ARDUINO_HARDWARE_H
#define ARDUINO_HARDWARE_H

#include <Arduino.h>

#define SLEEP_DURATION 5 * 60 * 1000 * 1000

void  HWInit();
void  HWRestart();
void  HWSleep();
float HWGetTempString(uint8_t id, char* tempBuf);
void  HWLoop();

#endif /* ARDUINO_HARDWARE_H */
