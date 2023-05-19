#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "obstacle.h"
#include "scrolling.h"
#include "score.h"



void initObjet_trash(Objet *o, int x, int y)
{
    o->t[0] = IMG_Load("ressources/collectables/trash/tr1.png");
    o->t[1] = IMG_Load("ressources/collectables/trash/tr2.png");
    o->pos_img.x = x;
    o->pos_img.y = y;
    o->pos_img.w = 39;
    o->pos_img.h = 55;
    o->current_image = 0;
    o->collision = 0;
}

void init_AllObjet_trash(AllObjet *trash)
{
    initObjet_trash(&trash->o[0], 100, 500);
    initObjet_trash(&trash->o[1], 200, 400);
    initObjet_trash(&trash->o[2], 400, 450);
    initObjet_trash(&trash->o[3], 1500, 400);
    initObjet_trash(&trash->o[4], 1800, 450);
    initObjet_trash(&trash->o[5], 2000, 400);
    initObjet_trash(&trash->o[6], 2400, 450);
    initObjet_trash(&trash->o[7], 2600, 400);

    trash->nbr_obj=8;
    trash->score_obj=0;
}




void initObjet_key(Objet *o, int x, int y)
{
    o->t[0] = IMG_Load("ressources/key/key1.png");
    o->t[1] = IMG_Load("ressources/key/key2.png");
    o->pos_img.x = x;
    o->pos_img.y = y;
    o->pos_img.w = 70;
    o->pos_img.h = 81;
    o->current_image = 0;
    o->collision = 0;
}




void init_AllObjet_key(AllObjet *key)
{
    initObjet_key(&key->o[0], 3500, 400);
    key->nbr_obj=1;
    key->score_obj=0;
}



void initObjet_bottle(Objet *o, int x, int y)
{
    o->t[0]=IMG_Load("ressources/collectables/bottle/bt1.png");
    o->t[1]=IMG_Load("ressources/collectables/bottle/bt2.png");
    o->pos_img.x=x;
    o->pos_img.y=y;
    o->pos_img.w=34;
    o->pos_img.h=71;
    o->current_image=0;
    o->collision=0;
}


void init_AllObjet_bottle(AllObjet *bottle)
{
    initObjet_bottle(&bottle->o[0], 100, 500);
    initObjet_bottle(&bottle->o[1], 200, 400);
    initObjet_bottle(&bottle->o[2], 400, 450);
    initObjet_bottle(&bottle->o[3], 1500, 400);
    initObjet_bottle(&bottle->o[4], 1800, 450);
    initObjet_bottle(&bottle->o[5], 2000, 400);
    initObjet_bottle(&bottle->o[6], 2400, 450);
    initObjet_bottle(&bottle->o[7], 2600, 400);

    bottle->nbr_obj=8;
    bottle->score_obj=0;
}


void initObjet_melon(Objet *o, int x, int y)
{
    o->t[0]=IMG_Load("ressources/collectables/melon/ml1.png");
    o->t[1]=IMG_Load("ressources/collectables/melon/ml2.png");
    o->pos_img.x=x;
    o->pos_img.y=y;
    o->pos_img.w=38;
    o->pos_img.h=46;
    o->current_image=0;
    o->collision=0;
}

void init_AllObjet_melon(AllObjet *melon)
{
    initObjet_melon(&melon->o[0], 100, 500);
    initObjet_melon(&melon->o[1], 200, 400);
    initObjet_melon(&melon->o[2], 400, 450);
    initObjet_melon(&melon->o[3], 1500, 400);
    initObjet_melon(&melon->o[4], 1800, 450);
    initObjet_melon(&melon->o[5], 2000, 400);
    initObjet_melon(&melon->o[6], 2400, 450);
    initObjet_melon(&melon->o[7], 2600, 400);

    melon->nbr_obj=8;
    melon->score_obj=0;
}

void afficherObjet(Objet o, SDL_Surface *screen, int num, int scrolling)
{
    SDL_Rect pos = o.pos_img;
    pos.x -= scrolling;
    SDL_BlitSurface(o.t[num], NULL, screen, &pos);
}


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


int collision_Objet(Character c, Objet *o, Background b)
{
    SDL_Rect rect_c = {c.position.x + b.camera.x, c.position.y, c.image->w/8, c.image->h};
    SDL_Rect rect_o = {o->pos_img.x, o->pos_img.y, o->t[o->current_image]->w, o->t[o->current_image]->h};

    if (rect_c.x + rect_c.w >= rect_o.x && rect_c.x <= rect_o.x + rect_o.w && rect_c.y + rect_c.h >= rect_o.y && rect_c.y <= rect_o.y + rect_o.h)
    {
        o->collision = 1;
    }
    return o->collision;
}





void afficherALLObjets(AllObjet *trash, Character character, SDL_Surface *screen, Background Backg)
{

    for (int i = 0; i < trash->nbr_obj; i++)
    {

        if (trash->o[i].collision == 1)
            continue;


        if (collision_Objet(character, &trash->o[i], Backg) == 0)
        {

            animerObjet(&trash->o[i], screen, Backg);
        }
        else
        {

            trash->o[i].collision = 1;
            trash->score_obj++;
        }
    }
}



void initObstacle_rocks(Obstacle *o,int num,int x,int y)
{

    char filename[100];
    sprintf(filename, "ressources/obstacles/rocks/rk%d.png", num);
    o->img = IMG_Load(filename);


    switch(num)
    {
    case 1 :
        o->pos_img.w = 153;
        o->pos_img.h= 82;
        break;

    case 2 :
        o->pos_img.w = 127;
        o->pos_img.h= 104;
        break;

    case 3 :
        o->pos_img.w = 145;
        o->pos_img.h= 133;
        break;

    }
    o->pos_img.x = x;
    o->pos_img.y = y-o->pos_img.h;

}


void init_AllOobstacle_rocks(Obstacle rocks[])
{

    initObstacle_rocks(&rocks[0],1,900,660);
    initObstacle_rocks(&rocks[1],2,1100,660);
    initObstacle_rocks(&rocks[2],3,1300,660);
    initObstacle_rocks(&rocks[3],1,1800,660);
    initObstacle_rocks(&rocks[4],2,2200,660);
    initObstacle_rocks(&rocks[5],3,2400,660);

}



void initObstacle_wood(Obstacle *o,int num,int x,int y)
{

    char filename[100];
    sprintf(filename, "ressources/obstacles/wood/wd%d.png", num);
    o->img = IMG_Load(filename);


    switch(num)
    {
    case 1 :
        o->pos_img.w = 170;
        o->pos_img.h= 61;
        break;

    case 2 :
        o->pos_img.w = 178;
        o->pos_img.h= 117;
        break;

    case 3 :
        o->pos_img.w = 141;
        o->pos_img.h= 151;
        break;

    }
    o->pos_img.x = x;
    o->pos_img.y = y-o->pos_img.h;

}


void init_AllOobstacle_wood(Obstacle wood[])
{

    initObstacle_wood(&wood[0],1,900,660);
    initObstacle_wood(&wood[1],2,1100,660);
    initObstacle_wood(&wood[2],3,1300,660);
    initObstacle_wood(&wood[3],1,1800,660);
    initObstacle_wood(&wood[4],2,2200,660);
    initObstacle_wood(&wood[5],3,2400,660);

}



void initObstacle_trcan(Obstacle *o,int num,int x,int y)
{

    char filename[100];
    sprintf(filename, "ressources/obstacles/trcan/tc%d.png", num);
    o->img = IMG_Load(filename);


    switch(num)
    {
    case 1 :
        o->pos_img.w = 90;
        o->pos_img.h= 100;
        break;

    case 2 :
        o->pos_img.w = 107;
        o->pos_img.h= 119;
        break;

    case 3 :
        o->pos_img.w = 128;
        o->pos_img.h= 143;
        break;

    }
    o->pos_img.x = x;
    o->pos_img.y = y-o->pos_img.h;

}


void init_AllOobstacle_trcan(Obstacle trc[])
{

    initObstacle_trcan(&trc[0],1,900,660);
    initObstacle_trcan(&trc[1],2,1100,660);
    initObstacle_trcan(&trc[2],3,1300,660);
    initObstacle_trcan(&trc[3],1,1800,660);
    initObstacle_trcan(&trc[4],2,2200,660);
    initObstacle_trcan(&trc[5],3,2400,660);

}


void afficherObstacle(Obstacle o, SDL_Surface *screen, int scrolling)
{
    SDL_Rect pos = o.pos_img;
    pos.x -= scrolling;

    if (pos.x + pos.w < 0)
    {
        return;
    }

    SDL_BlitSurface(o.img, NULL, screen, &pos);
}

void afficherALLObstacles(Obstacle trc[], SDL_Surface *screen, Background Backg)
{
    for(int i=0; i<6; i++)
    {
        afficherObstacle(trc[i], screen, Backg.camera.x);
    }
}


void handle_collision(Character* character, Obstacle* obstacle, Background* background)
{

    SDL_Rect obstacle_pos = obstacle->pos_img;
    obstacle_pos.x -= background->camera.x;


    if (((character->position.x + character->position.w > obstacle_pos.x &&
            character->position.x < obstacle_pos.x) ||
            (character->position.x < obstacle_pos.x + obstacle_pos.w &&
             character->position.x + character->position.w > obstacle_pos.x + obstacle_pos.w))
            && character->position.y + character->position.h >= obstacle_pos.y - 10 // adjust range as needed
            && character->position.y <= obstacle_pos.y + obstacle_pos.h)
    {


        character->velocity = 0;
        if (character->position.x + character->position.w > obstacle_pos.x &&
                character->position.x < obstacle_pos.x)
        {
            character->position.x = obstacle_pos.x - character->position.w;
        }
        else
        {
            character->position.x = obstacle_pos.x + obstacle_pos.w;
        }
    }


    if (!character->isJumping)
    {
        return;
    }


    obstacle_pos = obstacle->pos_img;
    obstacle_pos.x -= background->camera.x;
    obstacle_pos.y -= background->camera.y;


    if (character->position.y + character->position.h <= obstacle_pos.y)
    {
        return;
    }


    if (character->position.y >= obstacle_pos.y + obstacle_pos.h)
    {
        return;
    }

    if (character->position.x + character->position.w <= obstacle_pos.x)
    {
        return;
    }


    if (character->position.x >= obstacle_pos.x + obstacle_pos.w)
    {
        return;
    }


    if (character->position.y + character->position.h >= obstacle_pos.y &&
            character->velocity > 0 &&
            ((character->position.x + character->position.w > obstacle_pos.x &&
              character->position.x + character->position.w < obstacle_pos.x + obstacle_pos.w) ||
             (character->position.x >= obstacle_pos.x &&
              character->position.x < obstacle_pos.x + obstacle_pos.w)))
    {


        character->position.y = obstacle_pos.y - character->position.h;
        character->isBottom = 1;
        character->isJumping = 0;
    }

    else if (
        (character->position.x + character->position.w <= obstacle_pos.x ||
         character->position.x >= obstacle_pos.x + obstacle_pos.w))
    {
        character->isBottom =1;
        update_pos(character);
    }

}







void liberer_objet(Objet o)
{
    for (int i = 0; i < 2; i++)
    {
        if (o.t[i] != NULL)
        {
            SDL_FreeSurface(o.t[i]);
        }
    }
}


void liberer_obstacle(Obstacle o)
{
    SDL_FreeSurface(o.img);
}




void initObjet_Door(Objet_Door *o)
{
    for(int i=0; i<5; i++)
    {
        char filename[100];
        sprintf(filename, "ressources/door/door%d.png", i);
        o->t[i] = IMG_Load(filename);
    }

    o->pos_img.w=163;
    o->pos_img.h=148;
    o->pos_img.x=4000-o->pos_img.w;
    o->pos_img.y=665-o->pos_img.h;

    o->collision=0;
}

void afficherObjet_Door(Objet_Door o, SDL_Surface *screen, int num,int scrolling)
{
    SDL_Rect pos = o.pos_img;
    pos.x -= scrolling;

    if (pos.x + pos.w < 0)
    {
        return;
    }

    SDL_BlitSurface(o.t[num], NULL, screen, &pos);
}





int checkCollision(Character c, Objet_Door* o, Background b)
{
    SDL_Rect rect_c = {c.position.x + b.camera.x, c.position.y, c.image->w/8, c.image->h};
    SDL_Rect rect_o = {o->pos_img.x, o->pos_img.y, o->t[0]->w, o->t[0]->h};

    if (rect_c.x + rect_c.w >= rect_o.x && rect_c.x <= rect_o.x + rect_o.w && rect_c.y + rect_c.h >= rect_o.y && rect_c.y <= rect_o.y + rect_o.h)
    {
        o->collision = 1;
    }
    return o->collision;
}


void updateDoor(Objet_Door *o, Character character, SDL_Surface *screen, Background Backg)
{
    static Uint32 last_time = 0;
    static int frame = 0;
    static bool is_animating = false;

    Uint32 current_time = SDL_GetTicks();

    if (checkCollision(character, o, Backg))
    {
        if (!is_animating)
        {
            if (current_time - last_time >= 100)
            {

                afficherObjet_Door(*o, screen, frame, Backg.camera.x);
                frame++;
                last_time = current_time;

                if (frame == 4)
                {
                    is_animating = true;
                }
            }
        }
        else
        {

            afficherObjet_Door(*o, screen, 4, Backg.camera.x);
            last_time = current_time;
        }
    }
    else
    {

        afficherObjet_Door(*o, screen, 0, Backg.camera.x);
        frame = 0;
        is_animating = false;
        last_time = current_time;
    }
}


