#include "GameState.h"
#include "SceneLib.h"

GameState::GameState() : mascot(), scene(idle0, action0, menuSprite), idle(true){}

uint8_t GameState::getOption(){return scene.currOption;}
uint8_t GameState::getScene(){return scene.currScene;}

//this will be only done once we have secured that the user can change and has changed the option therefore we dont need 
// to be given anything
bool GameState::updateScene()
{
  switch(scene.currOption)
  {
    case 0:
      if(scene.currOption == scene.currScene){return false;}
      scene.idleBitmap = idle0;
      scene.actionBitmap = action0;
      break;
    default:
      return false;
  }

  scene.currScene = scene.currOption;
  return true;
}

const uint16_t* GameState::getMenu(){return scene.menu[scene.currOption];}

const uint16_t* GameState::getIdle(uint8_t i){return scene.idleBitmap[i];}

void GameState::nextOption()
{
  if(scene.currOption >= 5){scene.currOption = 0;}
  scene.currOption++;
}

void GameState::prevOption()
{
  if(scene.currOption <= 0){scene.currOption = 5;}
  scene.currOption--;
}