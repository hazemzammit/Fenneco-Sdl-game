#ifndef SCROLLING_H_INCLUDED
#define SCROLLING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include "personne.h"
#define SCREEN_H 665
#define SCREEN_W 1366


typedef struct
{
  SDL_Surface *BgImg;
  SDL_Rect PositionBg;
  SDL_Rect positionperso;
  SDL_Rect camera;
}Background;



void initBackground(Background *Backg);
void freeBackground(Background *Backg);
void blitting(Background *Backg,SDL_Surface *screen);
void scrolling(Background *Backg, Character *character, bool b[]);

#endif
