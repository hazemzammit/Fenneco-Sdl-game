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
    temp   = SDL_LoadBMP("ressources/sprite.bmp");
    character->image = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    character->position.y = char_y	;
    character->position.w = 32;
    character->position.h = 32;
    character->position.x = 0;
    character->position.y = 665 -100 ;
    colorkey = SDL_MapRGB(screen_surface->format, 0, 0, 0);
    SDL_SetColorKey(character->image, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    character->isJumping=0;
    character->isBottom=1;
    character->velocity=0 ;
    character->gravity=1 ;
    character->life=3 ;
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
    if (character->isBottom)
    {
        character->isJumping = 1;
        character->isBottom = 0;
        character->velocity = -18;
    }
}



void update_pos(Character* character)
{
    int char_y = 665 - 140;
    if (character->isJumping)
    {
        character->position.y += character->velocity;
        character->velocity += character->gravity;
        if (character->position.y >= char_y)
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
        spriteImage.w = 70;
        spriteImage.h = 70;
        /* choose image according to direction and animation flip: */
        spriteImage.x = 70*(2*currentDirection + animationFlip);

        SDL_BlitSurface(character->image, &spriteImage, screen, &character->position);
    }
}


void Perso_Dead(Character* character,SDL_Surface *screen,int  currentDirection,double animationFlip)
{
    if (currentDirection == 1)
    {
        if(animationFlip == 1)
        {
            animationFlip = 0;

        }
        currentDirection = 0;
    }
    else if (currentDirection == 3)
    {
        if(animationFlip == 0)
        {
            animationFlip = 1;
        }
        currentDirection = 0;
    }

    SDL_Rect spriteImage;
    spriteImage.y = 0;
    spriteImage.w = 70;
    spriteImage.h = 70;
    spriteImage.x =  70*(2*currentDirection + animationFlip);

    SDL_BlitSurface(character->image, &spriteImage, screen, &character->position);
}


void liberer_character(Character character)
{
    SDL_FreeSurface(character.image);
}



