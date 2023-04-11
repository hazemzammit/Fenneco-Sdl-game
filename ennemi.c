#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"

void initEnnemi(Ennemi *e)
{
    e->t[0]=IMG_Load("e0.png");
    e->t[1]=IMG_Load("e1.png");
    e->pos_img.x=500;
    e->pos_img.y=350;
    e->pos_img.w=123;
    e->pos_img.h=101;
    e->direction=1;
    e->current_image=0;
}


void afficherEnnemi(Ennemi e,SDL_Surface * screen,int num)
{
    SDL_BlitSurface (e.t[num], NULL,screen,&e.pos_img) ;
}


void animerEnnemi(Ennemi *e, SDL_Surface *screen)
{
    static int frame_counter = 0;
    frame_counter++;
    if (frame_counter >= 50)
    {
        if (e->current_image == 0)
        {
            e->current_image = 1;
        }
        else
        {
            e->current_image = 0;
        }
        frame_counter = 0;
    }
    afficherEnnemi(*e,screen,e->current_image);
}


void move(Ennemi *e)
{
    static int move_counter = 0;
    srand(time(0));
    if (move_counter >= 50)
    {
        e->direction = (rand() % 2 == 0) ? 1 : -1;
        move_counter = 0;
    }
    e->pos_img.x += e->direction;

    if (e->pos_img.x < 300)
    {
        e->pos_img.x = 300;
        e->direction = 1;
    }
    else if (e->pos_img.x + e->pos_img.w > 700)
    {
        e->pos_img.x = 700 - e->pos_img.w;
        e->direction = -1;
    }
    move_counter++;
}


int collisionBB(Character c, Ennemi e)
{
    int collision = 0;

    SDL_Rect rect_c = {c.position.x, c.position.y, c.image->w/8, c.image->h};
    SDL_Rect rect_e = {e.pos_img.x, e.pos_img.y, e.t[e.current_image]->w, e.t[e.current_image]->h};

    if (rect_c.x + rect_c.w >= rect_e.x && rect_c.x <= rect_e.x + rect_e.w && rect_c.y + rect_c.h >= rect_e.y && rect_c.y <= rect_e.y + rect_e.h)
    {
        collision = 1;
    }

    return collision;
}






