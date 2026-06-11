#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Scene.h"
#include "Mascot.h"

struct GameState
{
  explicit GameState();

  Scene scene;
  Mascot mascot;

  bool idle;
};

#endif