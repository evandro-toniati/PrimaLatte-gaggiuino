/* 09:32 15/03/2023 - change triggering comment */
#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H

#include "pindef.h"

#if defined SINGLE_BOARD
#include <Adafruit_MAX31855.h>
SPIClass thermoSPI(thermoDI, thermoDO, thermoCLK);
Adafruit_MAX31855 thermocouple(steam_thermoCS, &thermoSPI);
#else
#include <max6675.h>
SPIClass thermoSPI(thermoDI, thermoDO, thermoCLK);
MAX6675 steam_thermocouple(steam_thermoCS, &thermoSPI);
#endif

static inline void steam_thermocoupleInit(void) {
  steam_thermocouple.begin();
}

static inline float steam_thermocoupleRead(void) {
  return steam_thermocouple.readCelsius();
}

#endif
