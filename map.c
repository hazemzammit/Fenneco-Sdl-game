#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "map.h"
void initmap(minimap*min)
{
  min->PositionBg.x=0;
  min->PositionBg.y=0;
  min->Bgimg= SDL_LoadBMP("lvl3.bmp");
  if (min->Bgimg == NULL)
  {
    printf("Unable to load bitmap: %s\n", SDL_GetError());
  }

  

}
void blitting(SDL_Surface *screen,minimap *min)
{
SDL_BlitSurface(min->Bgimg,NULL,screen,&(min->PositionBg));
}

void freebackground(minimap *min)
{
SDL_FreeSurface(min->Bgimg);
}












