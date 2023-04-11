#include "personne.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void character_init(Character* character, const char* image_path, int x, int y)
{
    character->image = IMG_Load(image_path);
    character->position.x = x;
    character->position.y = y;
    character->position.w = 32;
    character->position.h = 32;
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
    int t, t_max, v_max, v;
    int x = character->position.x;
    int y = character->position.y;
    int h = 10;
    int g = 9.81;
    t_max = 3;
    v_max = 26;
    for (t = 0; t < t_max; t++)
    {
        v = v_max - g*t;
        y = h - (v*t)/2;
        character->position.x = x;
        character->position.y = y;
        SDL_Delay(10);
    }
    while (character->position.y >= y)
    {
        t++;
        v = v_max - g*t;
        y = h - (v*t)/2;
        character->position.x = x;
        character->position.y = y;
        SDL_Delay(10);
    }
}


