#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.h"




void initBackground(Background *Backg)
{
    Backg->PositionBg.x=0;
    Backg->PositionBg.y=0;
    
    Backg->camera.x=0;
    Backg->camera.y=0;
    Backg->camera.w = 1366;
    Backg->camera.h = 665;

    Backg->BgImg= IMG_Load("ressources/background_levels/city.jpg");
    if (Backg->BgImg == NULL)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
    }

}



void initBackground_beach(Background *Backg)
{
    Backg->PositionBg.x=0;
    Backg->PositionBg.y=0;
    
    Backg->camera.x=0;
    Backg->camera.y=0;
    Backg->camera.w = 1366;
    Backg->camera.h = 665;

    Backg->BgImg= IMG_Load("ressources/background_levels/beach.jpg");
    if (Backg->BgImg == NULL)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
    }

}


void initBackground_forest(Background *Backg)
{
    Backg->PositionBg.x=0;
    Backg->PositionBg.y=0;
    
    Backg->camera.x=0;
    Backg->camera.y=0;
    Backg->camera.w = 1366;
    Backg->camera.h = 665;

    Backg->BgImg= IMG_Load("ressources/background_levels/forest.jpg");
    if (Backg->BgImg == NULL)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
    }

}

void blitting(Background *Backg,SDL_Surface *screen)
{

    SDL_BlitSurface(Backg->BgImg,&(Backg->camera),screen,&(Backg->PositionBg));
}

void freeBackground(Background Backg)
{
    SDL_FreeSurface(Backg.BgImg);
}

void scrolling(Background *Backg, Character *character, bool b[])
{
    const int speed = 5;
    const int center_x = SCREEN_W / 2 - character->position.w / 2;
    if (b[0])
    {
        if(character->position.x < center_x)
        {
            character->position.x += 2;
        }

        if(character->position.x >= center_x)
        {
            Backg->camera.x += speed;
        }

        if(Backg->camera.x >= 4000 - SCREEN_W)
        {
            character->position.x += 2;
            Backg->camera.x = 4000 - SCREEN_W;
            if(character->position.x > SCREEN_W)
            {
                Backg->camera.x = 0;
                character->position.x = 0;
            }
        }
    }
    if(b[1])
    {
        if(character->position.x > center_x)
        {
            character->position.x -= 2;
        }

        if(Backg->camera.x <= 0)
        {
            Backg->camera.x = 0;
        }
        else
        {
            Backg->camera.x -= speed;
        }
    }

}



int isLevelEnded(Character character, Background background)
{
    if (character.life <= 0)
    {
        return 1;
    }
    
    if (character.position.x >= 4000 - character.position.w-background.camera.x)
    {
        return 2;
    }
    

    return 0;
}


