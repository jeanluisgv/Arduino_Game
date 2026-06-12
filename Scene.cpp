#include "Scene.h"
//#include "SceneLib.h"

Scene::Scene(const uint16_t (*idle)[57600], const uint16_t (*action)[57600], const uint16_t (*menuSprite)[9600])
{
  idleBitmap = idle;
  actionBitmap = action;
  menu = menuSprite;

  currScene = 0;
  currOption = 0;
}


