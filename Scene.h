#ifndef SCENE_H
#define SCENE_H

#include <Arduino.h>
// ALL idles will be even, ALL action of idles will be the following odd
//
//At least 64 bits / 8 bytes
struct Scene
{
    explicit Scene();

    bool updateScene(uint8_t id);
    bool updateOption(uint8_t dir);

    uint8_t currScene;
    uint8_t currOption;
    
    const uint16_t (*action)[57600]; //action sprite pointer
    const uint16_t (*idle)[57600]; //idle sprite pointer
    
    const uint16_t (*menu)[9600];
};
#endif