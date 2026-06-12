#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Scene.h"
#include "Mascot.h"
#include "Scene.h"

struct GameState
{
  explicit GameState();

  Scene scene;
  Mascot mascot;

  bool idle; //is it in idle or action

  uint8_t getScene();
  uint8_t getOption();

  const uint16_t* getMenu();
  const uint16_t* getIdle(uint8_t i);

  bool updateScene();

  void nextOption();
  void prevOption();
};

#endif