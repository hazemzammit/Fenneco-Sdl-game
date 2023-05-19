#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"
#include "scrolling.h"

void initEnnemi(Ennemi *e)
{
    e->t[0]=IMG_Load("ressources/enemy/waiting/w1.png");
    e->t[1]=IMG_Load("ressources/enemy/waiting/w2.png");
    e->t[2]=IMG_Load("ressources/enemy/following/fl2.png");
    e->t[3]=IMG_Load("ressources/enemy/following/fl1.png");
    e->t[4]=IMG_Load("ressources/enemy/following/fr1.png");
    e->t[5]=IMG_Load("ressources/enemy/following/fr2.png");
    e->t[6]=IMG_Load("ressources/enemy/attacking/al2.png");
    e->t[7]=IMG_Load("ressources/enemy/attacking/al1.png");
    e->t[8]=IMG_Load("ressources/enemy/dead.png");
    e->pos_img.x=800;
    e->pos_img.y=550;
    e->pos_img.w=54;
    e->pos_img.h=46;
    e->direction=1;
    e->current_image=0;
    e->collision=0;
    e->state=WAITING;
}


void afficherEnnemi(Ennemi e,SDL_Surface * screen,int num,int scrolling)
{
    SDL_Rect pos = e.pos_img;
    pos.x -= scrolling;

    if (pos.x + pos.w < 0) 
    {
        return;
    }

    SDL_BlitSurface(e.t[num], NULL, screen, &pos);
}



void animerEnnemi_waiting(Ennemi *e, SDL_Surface *screen,Background Backg)
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
    afficherEnnemi(*e,screen,e->current_image,Backg.camera.x);
}

void animerEnnemi_following(Ennemi *e, SDL_Surface *screen,Background Backg)
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

    int image_num;
    if (e->direction == 0)
    {
        image_num = e->current_image + 4;
    }
    else if (e->direction == -1)
    {
        image_num = e->current_image + 2;
    }
    else
    {
        image_num = e->current_image + 4;
    }
    afficherEnnemi(*e, screen, image_num,Backg.camera.x);
}


void move(Ennemi *e)
{
    static int move_counter = 0;
    if (move_counter >= 50)
    {
        int rand_num = rand() % 2; 
        if (rand_num == 0)
        {
            e->direction = -1; 
        }
        else
        {
            e->direction = 1; 
        }
        move_counter = 0;
    }
    e->pos_img.x += e->direction;
    if (e->pos_img.x < 700)
    {
        e->pos_img.x = 700;
        e->direction = 1;
    }
    else if (e->pos_img.x + e->pos_img.w > 900)
    {
        e->pos_img.x = 900 - e->pos_img.w;
        e->direction = -1;
    }
    move_counter++;
}


void animerEnnemi_attacking(Ennemi *e, SDL_Surface *screen,Background Backg)
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
    int image_num;
    if (e->direction == 0)
    {
        image_num = e->current_image + 4;
    }
    else if (e->direction == -1)
    {
        if (e->current_image >= 2 && e->current_image <= 5)
        {
            image_num = 6;
        }
        else
        {
            image_num = e->current_image + 2;
        }
        e->pos_img.x -= 1.2; 
    }
    else
    {
        if (e->current_image >= 2 && e->current_image <= 5)
        {
            image_num = 7;
        }
        else
        {
            image_num = e->current_image + 4;
        }
    }

    afficherEnnemi(*e, screen, image_num,Backg.camera.x);
}





void collisionBB(Character* c, Ennemi* e, Background Backg)
{
    if (c->invincibility)
    {
      
        c->invincibility_timer--;
        if (c->invincibility_timer <= 0)
        {
         
            c->invincibility = 0;
        }
       
        return;
    }
    SDL_Rect rect_c = {c->position.x + Backg.camera.x, c->position.y, c->image->w/8, c->image->h};
    SDL_Rect rect_e = { e->pos_img.x, e->pos_img.y, e->t[e->current_image]->w, e->t[e->current_image]->h };

    if (rect_c.x + rect_c.w >= rect_e.x && rect_c.x <= rect_e.x + rect_e.w && rect_c.y + rect_c.h >= rect_e.y && rect_c.y <= rect_e.y + rect_e.h)
    {
        c->invincibility = 1;
        c->invincibility_timer = 60; 
        c->life -= 1;
        e->collision= 1;

    }
}



int distance(Ennemi e, Character c)
{
    return e.pos_img.x - c.position.x;
}


void updateEnnemiState (Ennemi* e, int dist)
{
    if (e->collision== 1)
    {
        e->state = DEAD;
    }
    switch (e->state)
    {
    case WAITING:
        if (dist > 600)
        {
            e->state = WAITING;
        }

        if (400 < dist && dist <= 600)
        {
            e->state = FOLLOWING;
        }
        break;
    case FOLLOWING:

        if (400 < dist && dist <= 600)
        {
            e->state = FOLLOWING;
        }

        if (0 < dist && dist <= 400)
        {
            e->state = ATTACKING;
        }
        break;
    case ATTACKING:

        if (0 < dist && dist <= 400)
        {
            e->state = ATTACKING;
        }

        if (dist <= 0)
        {
            e->state = WAITING;
        }
        break;
    }
}



void updateEnnemi(Ennemi* e,Character *character, SDL_Surface* screen,Background Backg)
{
    int dist= distance(*e,*character) ;
    collisionBB(character,e,Backg);
    updateEnnemiState(e,dist);
    switch(e->state)
    {
    case WAITING:
        animerEnnemi_waiting(e,screen,Backg);
        break;

    case FOLLOWING:
        animerEnnemi_following(e,screen,Backg);
        move(e);
        break;

    case ATTACKING:
        animerEnnemi_attacking(e,screen,Backg);
        break;

    case DEAD:
        afficherEnnemi(*e,screen,8, Backg.camera.x);
        break;
    }
}








void liberer_ennemi(Ennemi e)
{
    for (int i = 0; i < 9; i++)
    {
        if (e.t[i] != NULL)
        {
            SDL_FreeSurface(e.t[i]);
        }
    }
}

