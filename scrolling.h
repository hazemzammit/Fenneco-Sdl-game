#ifndef SCROLLING_H_INCLUDED
#define SCROLLING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
  SDL_Surface *BgImg;
  SDL_Surface *PersoImg;
  SDL_Rect PositionBg;
  SDL_Rect positionperso;
  SDL_Rect camera;
}Background;



void initBackground(Background *Backg);
void freeBackground(Background *Backg);
void blitting(Background *Backg,SDL_Surface *screen);
void scrolling(Background *Backg, bool b[]);

#endif
