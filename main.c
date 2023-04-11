#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "personne.h"
#include <math.h>
#include "ennemi.h"
#include "image.h"

#define DIR_LEFT         3
#define DIR_RIGHT       1
#define SPRITE_SIZE     32

int main()
{
    SDL_Surface *screen;
    Ennemi e,e1;
    Character character;
    image back;
    SDL_Event event;
    int boucle=1;
    int collision;

    int currentDirection = DIR_RIGHT;
    SDL_Surface *temp, *sprite, *grass ;
    int colorkey;
    int animationFlip = 0;
    image IMAGElevel ;
    int quit = 0;
    int gravity = 1;
    int  isJumping = 0;
    int isBottom = 1;
    int char_y = SCREEN_H - 100;


    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
    {
        printf("Erreur Initialisation SDL %s .\n",SDL_GetError());
        return -1;
    }

    screen=SDL_SetVideoMode(SCREEN_W, SCREEN_H,32,SDL_SWSURFACE|SDL_DOUBLEBUF);

    initialiser_imageBACK(&back);

    SDL_EnableKeyRepeat(10, 10);
    initEnnemi(&e);
    temp   = SDL_LoadBMP("sprite.bmp");
    character.image = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    character.position.y = char_y	;
    character.position.x = 0;
    character.position.y = SCREEN_H -100 ;
    character.dx = 10;
    int velocity = 0;


    colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
    SDL_SetColorKey(character.image, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

    while(boucle)
    {
        afficher_imageBACK(screen,back);
        animerEnnemi(&e,screen);
        move(&e);
        collision=collisionBB(character,e);
        if(collision==1)
        {
            printf("Collision \n");
        }

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_KEYDOWN:
                if(event.key.keysym.sym ==SDLK_ESCAPE)
                {
                    boucle=0;
                }

                if(event.key.keysym.sym ==SDLK_SPACE)
                {
                    if (isBottom && !isJumping)
                    {
                        isJumping = 1;
                        velocity = -15;
                    }
                }

                if(event.key.keysym.sym ==SDLK_RIGHT)
                {
                    move_right(&character);
                    currentDirection = DIR_RIGHT;
                    animationFlip = 1 - animationFlip;
                }

                if(event.key.keysym.sym ==SDLK_LEFT)
                {
                    move_left(&character);
                    currentDirection = DIR_LEFT;
                    animationFlip= 1 - animationFlip;
                }
                break;


            case SDL_QUIT:
                boucle=0;
                break;
            }
        }
        if (character.position.x <= 0)
            character.position.x = 0;
        if (character.position.x >= SCREEN_W - SPRITE_SIZE)
            character.position.x = SCREEN_W - SPRITE_SIZE;

        if (character.position.y <= 0)
            character.position.y = 0;
        if (character.position.y >= SCREEN_H - SPRITE_SIZE)
            character.position.y = SCREEN_H - SPRITE_SIZE;
        {
            SDL_Rect spriteImage;
            spriteImage.y = 0;
            spriteImage.w = SPRITE_SIZE;
            spriteImage.h = SPRITE_SIZE;
            spriteImage.x = SPRITE_SIZE*(2*currentDirection + animationFlip);
            SDL_BlitSurface(character.image, &spriteImage, screen, &character.position);
        }

        if (isJumping)
        {
            character.position.y += velocity;
            velocity += gravity;
            if (character.position.y >= char_y)
            {
                character.position.y = char_y;
                isJumping = 0;
                velocity = 0;
                isBottom = 1;
            }
        }
        else if (!isBottom)
        {
            character.position.y += velocity;
            velocity += gravity;
            if (character.position.y >= char_y)
            {
                character.position.y = char_y;
                velocity = 0;
                isBottom = 1;
            }
        }

        SDL_Flip(screen);
    }

    SDL_FreeSurface(e.t[0]);
    SDL_FreeSurface(e.t[1]);
    SDL_FreeSurface(back.img);
    SDL_Quit();

    return 0;
}
