/**
* @file ennemi.c
* @brief the ennemy functions.
* @author hazemzammit
* @version 0.1
* @date  09,05, 2023
*
* Testing program for background scrollilng
*
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"
#include "scrolling.h"



/**
* @brief To initialise the ennemi e .
* @param e the Ennemi 
* @return Nothing
*/

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

/**
* @brief To show the ennemi e .
* @param e the Ennemi 
* @param screen the screen 
* @param num the number of the image to show 
* @param scrolling the scrolling of the background 
* @return Nothing
*/
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


/**
* @brief To animate the ennemi e when his state is waiting .
* @param e the Ennemi 
* @param screen the screen 
* @param Backg the background 
* @return Nothing
*/
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


/**
* @brief To animate the ennemi e when his state is following .
* @param e the Ennemi 
* @param screen the screen 
* @param Backg the background 
* @return Nothing
*/
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

/**
* @brief To move the ennemi e  .
* @param e the Ennemi 
* @return Nothing
*/
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

/**
* @brief To animate the ennemi e when his state is attacking .
* @param e the Ennemi 
* @param screen the screen 
* @param Backg the background 
* @return Nothing
*/
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



/**
* @brief To check if there is a collision between the ennemi e and character .
* @param e the Ennemi 
* @param c the Character 
* @return Nothing
*/

void collisionBB(Character c, Ennemi *e)
{
    SDL_Rect rect_c = {c.position.x, c.position.y, c.image->w/8, c.image->h};
    SDL_Rect rect_e = {e->pos_img.x, e->pos_img.y, e->t[e->current_image]->w, e->t[e->current_image]->h};

    if (rect_c.x + rect_c.w >= rect_e.x && rect_c.x <= rect_e.x + rect_e.w && rect_c.y + rect_c.h >= rect_e.y && rect_c.y <= rect_e.y + rect_e.h)
    {
        e->collision = 1;
    }

}


/**
* @brief To calculate the distance between the ennemi e and character .
* @param e the Ennemi 
* @param c the Character 
* @return int
*/

int distance(Ennemi e, Character c)
{
    return e.pos_img.x - c.position.x;
}

/**
* @brief To update the ennemi state .
* @param e the Ennemi 
* @param dist the disctance 
* @return Nothing
*/
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


/**
* @brief To initialise the Objet bottle .
* @param o the Objet 
* @return Nothing
*/
void initObjet_bottle(Objet *o)
{
    o->t[0]=IMG_Load("ressources/collectables/bottle/bt1.png");
    o->t[1]=IMG_Load("ressources/collectables/bottle/bt2.png");
    o->pos_img.x=700;
    o->pos_img.y=400;
    o->pos_img.w=34;
    o->pos_img.h=71;
    o->current_image=0;
    o->collision=0;
}

/**
* @brief To initialise the Objet trash .
* @param o the Objet 
* @return Nothing
*/
void initObjet_trash(Objet *o)
{
    o->t[0]=IMG_Load("ressources/collectables/trash/tr1.png");
    o->t[1]=IMG_Load("ressources/collectables/trash/tr2.png");
    o->pos_img.x=800;
    o->pos_img.y=400;
    o->pos_img.w=39;
    o->pos_img.h=55;
    o->current_image=0;
    o->collision=0;
}

/**
* @brief To initialise the Objet melon .
* @param o the Objet 
* @return Nothing
*/
void initObjet_melon(Objet *o)
{
    o->t[0]=IMG_Load("ressources/collectables/melon/ml1.png");
    o->t[1]=IMG_Load("ressources/collectables/melon/ml2.png");
    o->pos_img.x=900;
    o->pos_img.y=400;
    o->pos_img.w=64;
    o->pos_img.h=84;
    o->current_image=0;
    o->collision=0;
}


/**
* @brief To show the Objet  .
* @param o the Objet 
* @param screen the screen 
* @param num the number of the image to show 
* @param scrolling the scrolling of the background 
* @return Nothing
*/

void afficherObjet(Objet o, SDL_Surface *screen, int num, int scrolling)
{
    SDL_Rect pos = o.pos_img;
    pos.x -= scrolling; 

    if (pos.x + pos.w < 0)   
    {
        return;
    }

    SDL_BlitSurface(o.t[num], NULL, screen, &pos);
}

/**
* @brief To animate the Objet  .
* @param o the Objet 
* @param screen the screen 
* @param Backg the background 
* @return Nothing
*/
void animerObjet(Objet *o,SDL_Surface * screen,Background Backg)
{
    static int frame_counter = 0;
    frame_counter++;
    if (frame_counter >= 50)
    {
        if (o->current_image == 0)
        {
            o->current_image = 1;
        }
        else
        {
            o->current_image = 0;
        }
        frame_counter = 0;
    }
    afficherObjet(*o,screen,o->current_image,Backg.camera.x);
}

/**
* @brief To check if there is a collision between the character e and Objet .
* @param c the character 
* @param o the Objet 
* @return Nothing
*/
void collision_Objet(Character c,Objet *o)
{
    SDL_Rect rect_c = {c.position.x, c.position.y, c.image->w/8, c.image->h};
    SDL_Rect rect_o = {o->pos_img.x, o->pos_img.y, o->t[o->current_image]->w, o->t[o->current_image]->h};

    if (rect_c.x + rect_c.w >= rect_o.x && rect_c.x <= rect_o.x + rect_o.w && rect_c.y + rect_c.h >= rect_o.y && rect_c.y <= rect_o.y + rect_o.h)
    {
        o->collision = 1;
    }
}


/**
* @brief To initialise the Obstacle rocks .
* @param o the Obstacle 
* @return Nothing
*/
void initObstacle_rocks(Obstacle *o)
{
    o->t[0] = IMG_Load("ressources/obstacles/rocks/rk1.png");
    o->t[1] = IMG_Load("ressources/obstacles/rocks/rk2.png");
    o->t[2] = IMG_Load("ressources/obstacles/rocks/rk3.png");

    o->pos_img[0].w = 153;
    o->pos_img[0].h = 82;
    o->pos_img[0].x = 300;
    o->pos_img[0].y = 550;

    o->pos_img[1].w = 127;
    o->pos_img[1].h = 104;
    o->pos_img[1].x = 350;
    o->pos_img[1].y = 550;

    o->pos_img[2].w = 145;
    o->pos_img[2].h = 133;
    o->pos_img[2].x = 400;
    o->pos_img[2].y = 550;

    o->current_image = 0;
}

/**
* @brief To initialise the Obstacle wood .
* @param o the Obstacle 
* @return Nothing
*/
void initObstacle_wood(Obstacle *o)
{
    o->t[0] = IMG_Load("ressources/obstacles/wood/wd1.png");
    o->t[1] = IMG_Load("ressources/obstacles/wood/wd2.png");
    o->t[2] = IMG_Load("ressources/obstacles/wood/wd3.png");

    o->pos_img[0].w = 170;
    o->pos_img[0].h = 61;
    o->pos_img[0].x = 300;
    o->pos_img[0].y = 550;

    o->pos_img[1].w = 178;
    o->pos_img[1].h = 117;
    o->pos_img[1].x = 350;
    o->pos_img[1].y = 550;

    o->pos_img[2].w = 141;
    o->pos_img[2].h = 151;
    o->pos_img[2].x = 400;
    o->pos_img[2].y = 550;

    o->current_image = 0;
}

/**
* @brief To initialise the Obstacle trcan .
* @param o the Obstacle 
* @return Nothing
*/
void initObstacle_trcan(Obstacle *o)
{
    o->t[0] = IMG_Load("ressources/obstacles/trcan/tc11.png");
    o->t[1] = IMG_Load("ressources/obstacles/trcan/tc21.png");
    o->t[2] = IMG_Load("ressources/obstacles/trcan/tc31.png");

    o->pos_img[0].w = 90;
    o->pos_img[0].h = 100;
    o->pos_img[0].x = 400;
    o->pos_img[0].y = 550;

    o->pos_img[1].w = 107;
    o->pos_img[1].h = 119;
    o->pos_img[1].x = 350;
    o->pos_img[1].y = 550;

    o->pos_img[2].w = 128;
    o->pos_img[2].h = 143;
    o->pos_img[2].x = 400;
    o->pos_img[2].y = 550;

    o->current_image = 0;
}



/**
* @brief To show the Obstacle  .
* @param o the Obstacle 
* @param screen the screen 
* @param num the number of the image to show 
* @param scrolling the scrolling of the background 
* @return Nothing
*/
void afficherObstacle(Obstacle o, SDL_Surface *screen, int num, int scrolling)
{
    SDL_Rect pos = o.pos_img[num];
    pos.x -= scrolling; 

    if (pos.x + pos.w < 0)  
    {
        return;
    }

    SDL_BlitSurface(o.t[num], NULL, screen, &pos);
}










/**
* @brief To handle the collision between the character e and Obstacle .
* @param c the character 
* @param o the Obstacle 
* @return Nothing
*/

void handle_collision(Character* character, Obstacle* obstacle)
{

    if (character->position.y == 565 - character->position.h)
    {
        character->isBottom = 1;
    }

    if (character->position.x <= obstacle->pos_img[obstacle->current_image].x + obstacle->t[obstacle->current_image]->w &&
            character->position.x + character->position.w >= obstacle->pos_img[obstacle->current_image].x)
    {

        if (character->position.y + character->position.h >= obstacle->pos_img[obstacle->current_image].y && character->position.y <= obstacle->pos_img[obstacle->current_image].y + obstacle->t[obstacle->current_image]->h)
        {
            if (character->position.y + character->position.h <= obstacle->pos_img[obstacle->current_image].y + 10)
            {

                character->isJumping = 0;
                character->isBottom = 1;
                character->velocity = 0;
                character->position.y = obstacle->pos_img[obstacle->current_image].y - character->position.h;
            }
            else
            {

                if (character->position.x + character->position.w >= obstacle->pos_img[obstacle->current_image].x + obstacle->t[obstacle->current_image]->w)
                {

                    character->position.x = obstacle->pos_img[obstacle->current_image].x + obstacle->t[obstacle->current_image]->w;
                }
                else
                {

                    character->position.x = obstacle->pos_img[obstacle->current_image].x - character->position.w;
                }
                character->velocity = 0;


                if (character->position.y + character->position.h > obstacle->pos_img[obstacle->current_image].y + 10)
                {
                    character->position.y = 565 - character->position.h;
                    character->isJumping = 0;
                    character->isBottom = 1;
                }
            }
        }
    }
}



