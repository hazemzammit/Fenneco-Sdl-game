#include "personne.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


void character_init(SDL_Surface *screen_surface,Character* character)
{
    int char_y =665 - 100;
    SDL_Surface *temp ;
    int colorkey ;
    /* load sprite */    temp   = SDL_LoadBMP("sprite.bmp");
    character->image = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    character->position.y = char_y	;
    character->position.w = 32;
    character->position.h = 32;
    character->position.x = 0;
    character->position.y = 665 -100 ;
    /* setup sprite colorkey and turn on RLE */
    colorkey = SDL_MapRGB(screen_surface->format, 255, 0, 255);
    SDL_SetColorKey(character->image, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    character->isJumping=0;
    character->isBottom=1;
    character->velocity=0 ;
    character->gravity=1 ;
}
void afficher_perso(SDL_Surface *screen,Character character )
{
    SDL_BlitSurface(character.image, NULL, screen, &character.position);
}


void move_right(Character* character)
{
    character->position.x += 2;

}
void move_left(Character* character)
{
    character->position.x -= 2;

}

void character_jump(Character* character)
{
    if (character->isBottom)   // only jump if character is on the ground
    {
        character->isJumping = 1;
        character->isBottom = 0;
        character->velocity = -15; // set upward velocity for the jump
    }
}



void update_pos(Character* character)
{
    int char_y = 665 - 100;
    if (character->isJumping)
    {
        character->position.y += character->velocity;
        character->velocity += character->gravity;  // update velocity
        if (character->position.y >= char_y)    // character reaches ground
        {
            character->position.y = char_y;
            character->isJumping = 0;
            character->velocity = 0;
            character->isBottom = 1;
        }
    }
    else if (!character->isBottom)
    {
        character->position.y += character->velocity;
        character->velocity += character->gravity;  // update velocity
        if (character->position.y >= char_y)    // character reaches ground
        {
            character->position.y = char_y;
            character->velocity = 0;
            character->isBottom = 1;
        }
    }

}
void animerperso(Character* character,SDL_Surface *screen,int  currentDirection,int animationFlip)
{
    if (character->position.x <= 0)
        character->position.x = 0;
    if (character->position.x >= 1366 - 32)
        character->position.x = 1366 - 32;

    if (character->position.y <= 0)
        character->position.y = 0;
    if (character->position.y >= 665- 32)
        character->position.y = 665 - 32;



    {
        /* Define the source rectangle for the BlitSurface */
        SDL_Rect spriteImage;
        spriteImage.y = 0;
        spriteImage.w = 32;
        spriteImage.h = 32;
        /* choose image according to direction and animation flip: */
        spriteImage.x = 32*(2*currentDirection + animationFlip);

        SDL_BlitSurface(character->image, &spriteImage, screen, &character->position);
    }
}

