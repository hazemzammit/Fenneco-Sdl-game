/**
* @file main.c
* @brief our main.
* @author hazemzammit
* @version 0.1
* @date  09,05, 2023
*
* Testing program for background scrollilng
*
*/



#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.h"
#include "personne.h"
#include <math.h>
#include "ennemi.h"


#define DIR_LEFT         3
#define DIR_RIGHT       1
#define SPRITE_SIZE     32


/**
* @brief The main function .
* @param Nothing 
* @return Nothing
*/

int main()
{
    SDL_Surface *screen;
    Ennemi e;
    Objet bottle,trash,melon;
    Obstacle rocks,trcan,wood;
    SDL_Event event;
    int boucle=1;


    Background Backg;
    const int FPS = 30;
    const int speed = 5;
    Uint32 start;
    int direction;
    initBackground(&Backg);
    bool b[2] = {0,0};


    int currentDirection = DIR_RIGHT;

    int animationFlip = 0;
    Character character;


    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
    {
        printf("Erreur Initialisation SDL %s .\n",SDL_GetError());
        return -1;
    }

    screen=SDL_SetVideoMode(SCREEN_W, SCREEN_H,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);


    initEnnemi(&e);
    initObjet_bottle(&bottle);
    initObjet_trash(&trash);
    initObjet_melon(&melon);

    initObstacle_rocks(&rocks);
    initObstacle_wood(&wood);
    initObstacle_trcan(&trcan);




    character_init(screen,&character) ;
    SDL_EnableKeyRepeat(10, 10);
    int velocity = 0;

    while(boucle)
    {
        start = SDL_GetTicks();


        scrolling(&Backg, &character, b);

        blitting(&Backg,screen);

        collision_Objet(character,&bottle);
        if(bottle.collision==0)
        {
            animerObjet(&bottle,screen,Backg);
        }
        collision_Objet(character,&trash);
        if(trash.collision==0)
        {
            animerObjet(&trash,screen,Backg);
        }
        collision_Objet(character,&melon);
        if(melon.collision==0)
        {
            animerObjet(&melon,screen,Backg);
        }

        afficherObstacle(wood, screen, 0, Backg.camera.x);

        int dist= distance(e,character) ;
        updateEnnemiState(&e,dist);
        collisionBB(character,&e);





        switch(e.state)
        {
        case WAITING:
            animerEnnemi_waiting(&e,screen,Backg);
            break;

        case FOLLOWING:
            animerEnnemi_following(&e,screen,Backg);
            move(&e);
            break;

        case ATTACKING:
            animerEnnemi_attacking(&e,screen,Backg);
            break;

        case DEAD:
            afficherEnnemi(e,screen,8, Backg.camera.x);
            break;
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
                    SDL_EnableKeyRepeat(10, 10);
                    character_jump(&character);
                }

                if(event.key.keysym.sym ==SDLK_RIGHT)
                {
                    move_right(&character);
                    currentDirection = DIR_RIGHT;
                    animationFlip = 1 - animationFlip;

                    b[0] = 1;

                }

                if(event.key.keysym.sym ==SDLK_LEFT)
                {
                    move_left(&character);
                    currentDirection = DIR_LEFT;
                    animationFlip= 1 - animationFlip;

                    b[1] = 1;

                }

                if(event.key.keysym.sym ==SDLK_UP)
                {

                    b[2]=1;

                }

                if(event.key.keysym.sym ==SDLK_DOWN)
                {
                    b[3]=1;

                }


                break;


            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    b[0] = 0;
                    break;
                case SDLK_LEFT:
                    b[1] = 0;
                    break;

                }
                break;


            case SDL_QUIT:
                boucle=0;
                break;
            }

        }

        
                handle_collision(&character, &wood) ;
        animerperso(&character,screen, currentDirection, animationFlip) ;
        update_pos(&character) ;

        SDL_Flip(screen);

        if(1000/FPS > SDL_GetTicks()-start)
        {
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }

    }


    freeBackground(&Backg);
    SDL_FreeSurface(e.t[0]);
    SDL_FreeSurface(e.t[1]);

    SDL_Quit();

    return 0;
}

