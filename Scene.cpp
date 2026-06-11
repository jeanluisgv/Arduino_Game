#include "Scene.h"
#include "SceneLib.h"

Scene::Scene()
{
  idle = idle0;
  action = action0;
  menu = menuSprite;

  currScene = 0;
  currOption = 0;
}

bool Scene::updateScene(uint8_t id)
{
  switch(id)
  {
    case 0:
      if(id == currScene){break;}
      idle = idle0;
      action = action0;
      return true;
    default:
      return false;
  }
  return false;
}

bool Scene::updateOption(uint8_t dir)
{
  switch (dir)
  {
    case 0:
      if(currOption == 0){currOption = 5;}
      else {currOption--;}
      return true;
    case 1:
      if(currOption == 5){currOption = 0;}
      else {currOption++;}
      return true;
  }

  return false;
}

