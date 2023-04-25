#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.h"




void initBackground(Background *Backg)
{
  Mix_Music *music;
  Backg->PositionBg.x=0;
  Backg->PositionBg.y=0;

  Backg->positionperso.x=0;
  Backg->positionperso.y=451;

  Backg->camera.x=0;
  Backg->camera.y=0;
  Backg->camera.w = 1080;
  Backg->camera.h = 671;

  Backg->BgImg= SDL_LoadBMP("lvl3.bmp");
  if (Backg->BgImg == NULL)
  {
    printf("Unable to load bitmap: %s\n", SDL_GetError());
  }

  Backg->PersoImg=IMG_Load("perso.png");
  if (Backg->PersoImg == NULL)
  {
    printf("Unable to load bitmap: %s\n", SDL_GetError());
  }

  //son
  if(SDL_Init(SDL_INIT_AUDIO)==-1)
  {
    printf("SDL_Init: %s\n", SDL_GetError());
  }
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
  {
    printf("Mix_OpenAudio: %s\n", Mix_GetError());
  }
  music=Mix_LoadMUS("tt.mp3");
  Mix_PlayMusic(music, -1);
  Mix_AllocateChannels(10);
  Mix_VolumeMusic(MIX_MAX_VOLUME);

  }

void blitting(Background *Backg,SDL_Surface *screen)
{

  SDL_BlitSurface(Backg->BgImg,&(Backg->camera),screen,&(Backg->PositionBg));
  SDL_BlitSurface(Backg->PersoImg,NULL,screen,&(Backg->positionperso));

}

void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->BgImg);
}



void scrolling(Background *Backg, bool b[])
{
  const int speed=5;
  if (b[0])
  {
    if(Backg->positionperso.x<540)
    {
      Backg->positionperso.x+= 2;
    }

    if(Backg->positionperso.x>=540)
    {
      Backg->camera.x += speed;
    }

    if(Backg->camera.x >=2998-1080)
    {
      Backg->positionperso.x+=2;
      Backg->camera.x =2998-1080;
      if(Backg->positionperso.x>1080)
      {
        Backg->camera.x = 0;
        Backg->positionperso.x=0;
      }
    }
  }
  if(b[1])
  {
    if(Backg->positionperso.x<=540)
    {
      Backg->camera.x -= speed;
    }

    if(Backg->camera.x  <= 0)
    {
      Backg->camera.x  = 0;
      Backg->positionperso.x-=2;
    }
    if(Backg->positionperso.x>540)
    {
      Backg->positionperso.x-=2;
    }
  }
  if(b[2])
  {
    Backg->positionperso.y-=10;
    //position->x+=speed;
    if(Backg->positionperso.y<=0)
    {
      Backg->positionperso.y=0;
    }
  }
  if(b[3])
  {
    Backg->positionperso.y+=10;
    if(Backg->positionperso.y>=671)
    {
      Backg->positionperso.y=451;
    }
  }
}
