#include <Wire.h>
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

//#include "Scene.h"
#include "GameState.h"

#define LEFT_BUTTON 40
#define RIGHT_BUTTON 41
#define SELECT_BUTTON 39

#define SPRITE_FPS 300
#define BUTTON_DELAY 50
#define ACTION_TOTAL_TIME 5000

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft); //sprite
// TFT_eSprite menuSprite = TFT_eSprite(&tft);

unsigned long lastDebounceTime = 0;
unsigned long idleRunTime = 0;
unsigned long last = 0;

int i = 0;

GameState game;

const int left_btn = LEFT_BUTTON;
const int right_btn = RIGHT_BUTTON;
const int select_btn = SELECT_BUTTON;

bool selected;

int standLeftState = LOW;
int lastLeftState = LOW;
int currLeftState;

int standRightState = LOW;
int lastRightState = LOW;
int currRightState;

int standSelectState = LOW;
int lastSelectState = LOW;
int currSelectState;

// ---------------------------------------------------------------------
// setup
// -----
// ---------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Starting test of the graphics library");

  tft.init();

  pinMode(left_btn, INPUT);
  pinMode(right_btn, INPUT);
  pinMode(select_btn, INPUT);

  sprite.createSprite(TFT_WIDTH, TFT_HEIGHT);

  game = GameState();

  Serial.println("Starting loop");
}

// ---------------------------------------------------------------------
// loop
// -----
// ---------------------------------------------------------------------
void loop(void) {
  unsigned long now = millis();

  currLeftState = digitalRead(left_btn);
  currRightState = digitalRead(right_btn);
  currSelectState = digitalRead(select_btn);

  //Debounce logic
  if(currLeftState != lastLeftState || currRightState != lastRightState || currSelectState != lastSelectState){lastDebounceTime = millis();}
  
  if(millis() - lastDebounceTime > BUTTON_DELAY){

    //TODO: Check what happens when all buttons are pressed at the same time
    if(currLeftState != standLeftState){
      standLeftState = currLeftState;
      if(currLeftState == HIGH){game.scene.updateOption(0);}
    }
    if(currRightState != standRightState){
      standRightState = currRightState;
      if(currRightState == HIGH){game.scene.updateOption(1);}
    }
    if(currSelectState != standSelectState){
      standSelectState = currRightState;
      if(currSelectState == HIGH)
      {selected = true;}
    }

  }

  if(selected && game.currScene == game.currOption && game.idle){
    //play action
    //make idle false
  }

  if(selected && game.currScene != game.currOption){
    //play new idle
  }

  if(now - last >= SPRITE_FPS)
  {
    //For now making action last 5 sec
    
    sprite.pushImage(0,200, 240, 40, game.scene.menu[game.scene.currOption]);
    
    sprite.pushImage(0,0,240,200,game.scene.idle[i]);

    sprite.pushSprite(0,0);
  
    i++;
    if(i >= 5) i = 0;

    last = now;
  }



  
  lastLeftState = currLeftState;
  lastRightState = currRightState;
  // delay(2000);
  // tft.fillScreen(TFT_GREEN);
  // delay(2000);
  // tft.fillScreen(TFT_BLUE);
  // delay(2000);
}

