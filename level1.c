#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdbool.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <pthread.h>
#include "serie.h"
#include "scrolling.h"
#include "personne.h"
#include "ennemi.h"
#include "obstacle.h"
#include "level1.h"
#include "score.h"
#include "minimap.h"
#include "timer.h"
#include "image.h"
#include "sauvegarde.h"
#include "submenu.h"
#include "signin.h"
#include "game.h"
#include "menu.h"

//manette

char latest_input[1];
pthread_mutex_t input_mutex;

void* read_serial(void* arg)
{
    int fd = *((int*)arg);
    char buffer[1];
    int i;
    for (;;)
    {
        serialport_read_until(fd, buffer, '\r', 99, 10000);

        strcpy(latest_input, buffer);
    }

}


#define DIR_JUMP      2
#define DIR_LEFT         3
#define DIR_RIGHT       1
#define SPRITE_SIZE     70




void level1(SDL_Surface *screen,int num,Game g)
{


    Ennemi e;
    AllObjet trash,key;
    Objet_Door door;
    image_score trsc,keysc,vie;
    Obstacle trc[6];
    TTF_Init();
    SDL_Event event;
    int boucle=1;



    Background Backg;
    const int FPS = 30;
    const int speed = 5;
    Uint32 start;
    int direction;
    initBackground(&Backg);
    bool b[2] = {0,0};


    tim mytime;


    texte score;

    int currentDirection = DIR_RIGHT;

    double animationFlip = 0;
    Character character;

    image imgMiniMap,imgTimer,imgScore;
    Minimap map;
    Score s;





    initialiser_BackMiniMap(&imgMiniMap);
    initialiser_BackTimer(&imgTimer);
    initialiser_BackScore(&imgScore);

    initEnnemi(&e);
    init_AllObjet_trash(&trash);
    init_AllObjet_key(&key);
    init_AllOobstacle_trcan(trc);

    initialiser_score_trash(&trsc);
    initialiser_score_key(&keysc);
    initialiser_score_vie(&vie);

    initObjet_Door(&door);





    initialiser_texteScore(&score);




    init_time(&mytime);



    init_minimap(&map,&Backg,&character, &e,1);



    character_init(screen,&character) ;
    SDL_EnableKeyRepeat(10, 10);
    int velocity = 0;

    if(num!=0)
    {
        load_jeu(&Backg, &e, &character,&trash,&key,&mytime);

        lire_scores("sauvegardeScore.txt",&g, &s);
    }


//manette

    int fd = serialport_init("/dev/ttyUSB0", 9600);
    pthread_t serial_thread;
    pthread_create(&serial_thread, NULL, read_serial, &fd);



    image_level imgLevel;
    initialiser_imageLevels(&imgLevel);
    afficherimgLevel(imgLevel,screen,0);



    while(boucle)
    {

        start = SDL_GetTicks();


        scrolling(&Backg, &character, b);

        blitting(&Backg,screen);


        afficherALLObjets(&trash,character,screen, Backg);
        afficherALLObjets(&key,character,screen, Backg);
        afficherALLObstacles(trc, screen, Backg);



        afficherScore(&trsc,&trash,screen);
        afficherScore(&keysc,&key,screen);
        afficherVie(&vie, & character, screen);



        updateDoor(&door,character,screen, Backg);

        afficher_imageBTN(screen, imgMiniMap);
        afficher_imageBTN(screen, imgTimer);
        afficher_imageBTN(screen, imgScore);

        blit_minimap(&map, screen,&Backg);


        int levelState=isLevelEnded(character, Backg);
        updateGame(&g,levelState,screen,&s);

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_KEYDOWN:
                if(event.key.keysym.sym ==SDLK_ESCAPE)
                {

                    enregistrer_score("sauvegardeScore.txt",  &g,&s);
                    sauvegarde_jeu(Backg, e,character,trash,key,&mytime);
                    submenuS(screen);

                }

                if(event.key.keysym.sym ==SDLK_SPACE)
                {
                    if (currentDirection == DIR_RIGHT)
                    {
                        if(animationFlip == 1)
                        {
                            animationFlip = 0;

                        }
                        currentDirection = DIR_JUMP;
                    }
                    else if (currentDirection == DIR_LEFT)
                    {
                        if(animationFlip == 0)
                        {
                            animationFlip = 1;
                        }
                        currentDirection =DIR_JUMP;
                    }

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
                menu(screen);
                break;
            }


            if(character.life==0)
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

            }



        }


        //manette

        if (latest_input[1] == 'l')
        {
            move_left(&character);
            currentDirection = DIR_LEFT;
            animationFlip = 1 - animationFlip;
            latest_input[1] = 'x';
        }
        else if (latest_input[1] == 'r')
        {
            move_right(&character);
            currentDirection = DIR_RIGHT;
            animationFlip = 1 - animationFlip;
            latest_input[1] = 'x';

        }
        else if (latest_input[1] == 'j')
        {

            character_jump(&character);
            latest_input[1] = 'x';

        }




        for(int i=0; i<6; i++)
        {
            handle_collision(&character, &trc[i],&Backg);
        }


        update_minimap_positions(&map,&Backg, &character,&e);


        animerperso(&character,screen, currentDirection, animationFlip) ;
        update_pos(&character) ;
        updateEnnemi(&e,&character,screen,Backg);


        time_t temps_debut = mytime.t1;
        time_t temps_fin = mytime.t2;

        blit_time(&mytime, screen);

        afficher_score(screen, score, temps_debut, temps_fin,&trash,&key,&s);




        SDL_Flip(screen);



        if(500/FPS > SDL_GetTicks()-start)
        {
            SDL_Delay(500/FPS-(SDL_GetTicks()-start));
        }

    }


    freeBackground(Backg);
    liberer_character(character);
    liberer_ennemi(e);


}

