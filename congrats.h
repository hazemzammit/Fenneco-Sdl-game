#ifndef CONGRATS_H
#define CONGRATS_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"



typedef struct {
    image background;
    Button button1;
    Button button2;
    Button button3;
} Banner;



void bannerWonLost(SDL_Surface *screen,int num,Score* s,Game* g);


#endif

