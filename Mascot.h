#ifndef MASCOT_H
#define MASCOT_H

#include <Arduino.h>

struct Mascot
{
  explicit Mascot();

  uint8_t health;
  uint8_t happiness;
  uint8_t form;
  uint8_t hunger;

  void exercise();
  void workout();
  void eat();
};

#endif