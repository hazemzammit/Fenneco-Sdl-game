#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "audio.h"
#include "image.h"
#include "texte.h"
#include "menu.h"
#include "score.h"
#include "game.h"
#include "congrats.h"
#include "level2.h"


void initialiserBanner(Banner *ban,int num)
{

    switch(num)
    {
    case 0:
        ban->background.img = IMG_Load("ressources/WinLose/won.png");
        break;

    case 1:
        ban->background.img = IMG_Load("ressources/WinLose/lose.png");

        break;

    }

    ban->background.pos_img.w = 260;
    ban->background.pos_img.h = 286;
    ban->background.pos_img.x = (SCREEN_W- ban->background.pos_img.w)/2 ;
    ban->background.pos_img.y = (SCREEN_H-ban->background.pos_img.h)/2;


    ban->button1.normal.img =IMG_Load("ressources/WinLose/m0.png");

    ban->button1.normal.pos_img.w =35;
    ban->button1.normal.pos_img.h = 35;
    ban->button1.normal.pos_img.x = (SCREEN_W- ban->button1.normal.pos_img.w)/2+62;
    ban->button1.normal.pos_img.y = (SCREEN_H-ban->background.pos_img.h)/2+215;


    ban->button1.hover.img = IMG_Load("ressources/WinLose/m1.png");
    ban->button1.hover.pos_img.w =35;
    ban->button1.hover.pos_img.h = 35;
    ban->button1.hover.pos_img.x = (SCREEN_W- ban->button1.hover.pos_img.w)/2+62;
    ban->button1.hover.pos_img.y = (SCREEN_H-ban->background.pos_img.h)/2+215;

    ban->button1.state = 0;

    ban->button2.normal.img = IMG_Load("ressources/WinLose/n0.png");

    ban->button2.normal.pos_img.w =71;
    ban->button2.normal.pos_img.h = 35;
    ban->button2.normal.pos_img.x = (SCREEN_W- ban->button2.normal.pos_img.w)/2;
    ban->button2.normal.pos_img.y = (SCREEN_H-ban->background.pos_img.h)/2+215;


    ban->button2.hover.img = IMG_Load("ressources/WinLose/n1.png");
    ban->button2.hover.pos_img.w =71;
    ban->button2.hover.pos_img.h = 35;
    ban->button2.hover.pos_img.x =  (SCREEN_W-  ban->button2.hover.pos_img.w)/2;
    ban->button2.hover.pos_img.y = (SCREEN_H-ban->background.pos_img.h)/2+215;
    ban->button2.state = 0;


    ban->button3.normal.img =IMG_Load("ressources/WinLose/r0.png");

    ban->button3.normal.pos_img.w =35;
    ban->button3.normal.pos_img.h = 35;
    ban->button3.normal.pos_img.x = (SCREEN_W- ban->button3.normal.pos_img.w)/2-62;
    ban->button3.normal.pos_img.y = (SCREEN_H-ban->background.pos_img.h)/2+215;


    ban->button3.hover.img = IMG_Load("ressources/WinLose/r1.png");
    ban->button3.hover.pos_img.w =35;
    ban->button3.hover.pos_img.h = 35;
    ban->button3.hover.pos_img.x = (SCREEN_W- ban->button3.hover.pos_img.w)/2-62;
    ban->button3.hover.pos_img.y = (SCREEN_H-ban->background.pos_img.h)/2+215;

    ban->button3.state = 0;

}

void AfficherBanner(Banner *ban, SDL_Surface *screen)
{

    SDL_BlitSurface(ban->background.img, NULL, screen, &ban->background.pos_img);
    if (ban->button1.state == 0)
    {
        SDL_BlitSurface(ban->button1.normal.img, NULL, screen, &ban->button1.normal.pos_img);
    }
    else
    {
        SDL_BlitSurface(ban->button1.hover.img, NULL, screen, &ban->button1.hover.pos_img);
    }

    if (ban->button2.state == 0)
    {
        SDL_BlitSurface(ban->button2.normal.img, NULL, screen, &ban->button2.normal.pos_img);
    }
    else
    {
        SDL_BlitSurface(ban->button2.hover.img, NULL, screen, &ban->button2.hover.pos_img);
    }

    if (ban->button3.state == 0)
    {
        SDL_BlitSurface(ban->button3.normal.img, NULL, screen, &ban->button3.normal.pos_img);
    }
    else
    {
        SDL_BlitSurface(ban->button3.hover.img, NULL, screen, &ban->button3.hover.pos_img);
    }
}

void libererBanner(Banner *ban)
{
    SDL_FreeSurface(ban->background.img);
    SDL_FreeSurface(ban->button1.normal.img);
    SDL_FreeSurface(ban->button1.hover.img);
    SDL_FreeSurface(ban->button2.normal.img);
    SDL_FreeSurface(ban->button2.hover.img);
    SDL_FreeSurface(ban->button3.normal.img);
    SDL_FreeSurface(ban->button3.hover.img);

}



void initialiser_texteBestScore(texte *txte)
{
    TTF_Init();
    txte->police = TTF_OpenFont ("ressources/font/Candara.ttf", 14);
    txte->color_txt.r=0;
    txte->color_txt.g=0;
    txte->color_txt.b=0;
    txte->pos_txt.x=1366/2+8;
    txte->pos_txt.y=357;
}



void afficher_BestScore(SDL_Surface *screen, texte txte)
{
    char texte_score[50];
    double bestScore =  meilleurs_scores("sauvegardeScore.txt", 1);
    sprintf(texte_score, "%.2f",bestScore);
    txte.txt = TTF_RenderText_Blended(txte.police, texte_score, txte.color_txt);
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);
    SDL_FreeSurface(txte.txt);
}

void initialiser_texteYourScore(texte *txte)
{
    TTF_Init();
    txte->police = TTF_OpenFont ("ressources/font/Candara.ttf", 14);
    txte->color_txt.r=0;
    txte->color_txt.g=0;
    txte->color_txt.b=0;
    txte->pos_txt.x=1366/2+8;
    txte->pos_txt.y=327;
}


void afficher_YourScore(SDL_Surface *screen, texte txte,Score *s)
{
    char texte_score[50];
    sprintf(texte_score, "%.2f",s->score_total);
    txte.txt = TTF_RenderText_Blended(txte.police, texte_score, txte.color_txt);
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);
    SDL_FreeSurface(txte.txt);
}




void bannerWonLost(SDL_Surface *screen,int num,Score* s,Game* g) // num (0won / 1lost)
{
    image IMAGE_BACK;
    Banner ban;
    Mix_Chunk *mus;

    SDL_Event event;
    int boucle=1;

    texte yourScore,bestscore;

    initialiserBanner(&ban,num);
    initialiser_texteYourScore(&yourScore);
    initialiser_texteBestScore(&bestscore);


    while(boucle)
    {
     
        AfficherBanner(&ban,screen);
        afficher_BestScore(screen,bestscore);
        afficher_YourScore(screen,yourScore,s);


        int X_BTN1=calcul_XBTN(&ban.button1.normal);
        int X_BTN2=calcul_XBTN(&ban.button2.normal);
        int X_BTN3=calcul_XBTN(&ban.button3.normal);
        int Y_BTN=calcul_YBTN(&ban.button1.normal);


        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_KEYDOWN:


                if(event.key.keysym.sym ==SDLK_ESCAPE)
                {
                    initialiser_audiobref(mus);
                    boucle=0;
                }


                if(event.key.keysym.sym ==SDLK_m)
                {
                    initialiser_audiobref(mus);
                    ban.button1.state = 1;
                    menu(screen);

                }

                if(event.key.keysym.sym ==SDLK_n)
                {
                    initialiser_audiobref(mus);
                    ban.button2.state = 1;
                    switch(num)
                    {
                    case 0:
                        game(screen,1,g->num_level+1); 
                        break;
                    case 1:
                        game(screen,1,g->num_level);
                        break;
                    }

                }


                if(event.key.keysym.sym ==SDLK_r)
                {
                    initialiser_audiobref(mus);
                    ban.button3.state = 1;
                    game(screen,1,g->num_level);
                }


                break;

            case SDL_MOUSEMOTION:
                if( (event.motion.y<=(Y_BTN+35) ) && (event.motion.y>=Y_BTN) && (event.motion.x<=(X_BTN1+35)) && (event.motion.x>=X_BTN1))
                {
                    initialiser_audiobref(mus);
                    ban.button1.state = 1;

                }
                else
                {
                    ban.button1.state = 0;
                }
                if( (event.motion.y<=(Y_BTN+35) ) && (event.motion.y>=Y_BTN) && (event.motion.x<=(X_BTN2+48)) && (event.motion.x>=X_BTN2))
                {
                    initialiser_audiobref(mus);
                    ban.button2.state = 1;
                }
                else
                {
                    ban.button2.state = 0;
                }

                if( (event.motion.y<=(Y_BTN+35) ) && (event.motion.y>=Y_BTN) && (event.motion.x<=(X_BTN3+35)) && (event.motion.x>=X_BTN3))
                {
                    initialiser_audiobref(mus);
                    ban.button3.state = 1;
                }
                else
                {
                    ban.button3.state = 0;
                }

                break;

            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button==SDL_BUTTON_LEFT &&( (event.motion.y<=(Y_BTN+35) ) && (event.motion.y>=Y_BTN) && (event.motion.x<=(X_BTN1+35)) && (event.motion.x>=X_BTN1)))
                {
                    initialiser_audiobref(mus);
                    menu(screen);


                }
                if(event.button.button==SDL_BUTTON_LEFT &&( (event.motion.y<=(Y_BTN+35) ) && (event.motion.y>=Y_BTN) && (event.motion.x<=(X_BTN2+48)) && (event.motion.x>=X_BTN2)))
                {
                    initialiser_audiobref(mus);
                    switch(num)
                    {
                    case 0:
                        game(screen,1,g->num_level+1);
                        break;
                    case 1:
                        game(screen,1,g->num_level); 
                        break;
                    }
                }

                if(event.button.button==SDL_BUTTON_LEFT &&( (event.motion.y<=(Y_BTN+35) ) && (event.motion.y>=Y_BTN) && (event.motion.x<=(X_BTN3+35)) && (event.motion.x>=X_BTN3)))
                {
                    initialiser_audiobref(mus);
                    game(screen,1,g->num_level);
                }

                break;


            case SDL_QUIT:
                boucle=0;
                break;
            }


            SDL_Flip(screen);
        }

    }


    liberer_image(IMAGE_BACK);
    liberer_musiquebref(mus);
    libererBanner(&ban);

}







