#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.h"
#include "personne.h"
#include <math.h>
#include "ennemi.h"
#include "level1.h"
#include "level2.h"
#include "score.h"
#include "signin.h"
#include "congrats.h"
#include "xo.h"



void updateGame(Game* g,int levelState,SDL_Surface *screen,Score *s)
{
    int gameResult = 0;
    switch(levelState)
    {
    case 1:
        gameResult = xogame(screen);
        if (gameResult != 0)
        {
            game(screen,1,g->num_level);
        }
        else
        {
          game(screen,1,g->num_level);
        }

        break;
    case 2:
        bannerWonLost(screen,0,s,g);

        break;
    }

}

void game(SDL_Surface *screen,int isNew,int numLevel )
{

    Game g;
    Score score;

    if(isNew==0) 
    {

        char username[99];
        strcpy(g.username, Getusername());
        g.num_level=1;


        level1(screen,0,g);
    }
    else
    {
        if(numLevel==0)
        {
            lire_scores("sauvegardeScore.txt",&g, &score);
            printf("UsernameGame: %s\n", g.username);
            printf("num level: %d\n", g.num_level);
            switch(g.num_level)
            {
            case 1:
                level1(screen,1,g); 
                break;
            case 2:
                level2(screen,1,g); 
                break;
            case 3:
                level3(screen,1,g);
                break;
            }

        }
        else
        {

            char username[99];
            strcpy(g.username, Getusername());

            switch(numLevel)
            {
            case 1:
                g.num_level=1;
                level1(screen,0,g);
                break;
            case 2:
                g.num_level=2;
                level2(screen,0,g); 
                break;
            case 3:
                g.num_level=3;
                level3(screen,0,g);
                break;
            }

        }
    }



}








void initialiser_imageLevels(image_level *A)
{
    A->t[0] = IMG_Load("ressources/levels/1.png");
    A->t[1] = IMG_Load("ressources/levels/2.png");
    A->t[2] = IMG_Load("ressources/levels/3.png");
    A->pos_img.x = 0;
    A->pos_img.y = 0;
    A->pos_img.w=SCREEN_W;
    A->pos_img.h=SCREEN_H;
}



void afficherimgLevel(image_level A,SDL_Surface *screen,int num)
{
    SDL_BlitSurface(A.t[num],NULL, screen, &A.pos_img);
    SDL_Flip(screen);
    SDL_Delay(5000);
}



