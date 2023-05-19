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
#include "signin.h"
#include "game.h"
#include "submenu.h"


void initialiserSignIn(SignIn *signIn)
{

    signIn->background.img = IMG_Load("ressources/signin/signin.png");
    signIn->background.pos_img.w = 484;
    signIn->background.pos_img.h = 356;
    signIn->background.pos_img.x = (SCREEN_W- signIn->background.pos_img.w)/2 ;
    signIn->background.pos_img.y = (SCREEN_H-signIn->background.pos_img.h)/2;


    signIn->button1.normal.img =IMG_Load("ressources/signin/cl0.png");
    signIn->button1.normal.pos_img.w =147;
    signIn->button1.normal.pos_img.h = 50;
    signIn->button1.normal.pos_img.x = (SCREEN_W- signIn->button1.normal.pos_img.w)/2-95;
    signIn->button1.normal.pos_img.y = (SCREEN_H- signIn->button1.normal.pos_img.h)/2+( signIn->background.pos_img.h/2);


    signIn->button1.hover.img = IMG_Load("ressources/signin/cl1.png");
    signIn->button1.hover.pos_img.w =147;
    signIn->button1.hover.pos_img.h = 50;
    signIn->button1.hover.pos_img.x = (SCREEN_W- signIn->button1.hover.pos_img.w)/2-95;
    signIn->button1.hover.pos_img.y = (SCREEN_H- signIn->button1.hover.pos_img.h)/2+( signIn->background.pos_img.h/2);

    signIn->button1.state = 0;

    signIn->button2.normal.img = IMG_Load("ressources/signin/cm0.png");
    signIn->button2.normal.pos_img.w =147;
    signIn->button2.normal.pos_img.h = 50;
    signIn->button2.normal.pos_img.x = (SCREEN_W- signIn->button2.normal.pos_img.w)/2+95;
    signIn->button2.normal.pos_img.y = (SCREEN_H- signIn->button2.normal.pos_img.h)/2+( signIn->background.pos_img.h/2);


    signIn->button2.hover.img = IMG_Load("ressources/signin/cm1.png");
    signIn->button2.hover.pos_img.w =147;
    signIn->button2.hover.pos_img.h = 50;
    signIn->button2.hover.pos_img.x =  (SCREEN_W-  signIn->button2.hover.pos_img.w)/2+95;
    signIn->button2.hover.pos_img.y = (SCREEN_H- signIn->button2.hover.pos_img.h)/2+( signIn->background.pos_img.h/2);
    signIn->button2.state = 0;
}

void AfficherSignIn(SignIn *signIn, SDL_Surface *screen)
{
    SDL_BlitSurface(signIn->background.img, NULL, screen, &signIn->background.pos_img);
    if (signIn->button1.state == 0)
    {
        SDL_BlitSurface(signIn->button1.normal.img, NULL, screen, &signIn->button1.normal.pos_img);
    }
    else
    {
        SDL_BlitSurface(signIn->button1.hover.img, NULL, screen, &signIn->button1.hover.pos_img);
    }

    if (signIn->button2.state == 0)
    {
        SDL_BlitSurface(signIn->button2.normal.img, NULL, screen, &signIn->button2.normal.pos_img);
    }
    else
    {
        SDL_BlitSurface(signIn->button2.hover.img, NULL, screen, &signIn->button2.hover.pos_img);
    }

}

void libererSignIn(SignIn *signIn)
{
    SDL_FreeSurface(signIn->background.img);

    SDL_FreeSurface(signIn->button1.normal.img);
    SDL_FreeSurface(signIn->button1.hover.img);
    SDL_FreeSurface(signIn->button2.normal.img);
    SDL_FreeSurface(signIn->button2.hover.img);

}


Game g;

char* Getusername()
{
    char username[99];
    strcpy(username, g.username);
}

void signin(SDL_Surface *screen)
{
    image IMAGE_BACK;
   
    SignIn signIn;
    Mix_Chunk *mus;

    SDL_Event event;



    TTF_Font* font;
    SDL_Surface* textSurface;
    SDL_Rect textRect;
    SDL_Color textColor = {255, 255, 255};
    char username[90] = {0};

    int cursor = 0;
    int inputWidth = 0;


    TTF_Init();

    font = TTF_OpenFont("ressources/font/Candara.ttf", 21);
    if (font == NULL)
    {
        printf("TTF_OpenFont error: %s\n", TTF_GetError());
        exit(1);
    }

    initialiser_back_submenu(&IMAGE_BACK);
    initialiserSignIn(&signIn);

    int boucle=1;
    while(boucle)
    {


        afficher_imageBACK(screen,IMAGE_BACK);

        int X_BTN1=calcul_XBTN(&signIn.button1.normal);
        int X_BTN2=calcul_XBTN(&signIn.button2.normal);
        int Y_BTN=calcul_YBTN(&signIn.button1.normal);



        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_KEYDOWN:



                if (event.key.keysym.sym == SDLK_BACKSPACE && cursor > 0)
                {
                    username[cursor - 1] = '\0';
                    cursor--;
                }
                else if (event.key.keysym.sym == SDLK_RETURN)
                {
                    strcpy(g.username,username);
                    game(screen,0,1);
                }
                else if (event.key.keysym.sym >= SDLK_SPACE && event.key.keysym.sym <= SDLK_z && inputWidth < SCREEN_W - 21)
                {
                    username[cursor] = (char) event.key.keysym.sym;
                    cursor++;
                    inputWidth += 21;
                }

                if(event.key.keysym.sym ==SDLK_ESCAPE)
                {
                    initialiser_audiobref(mus);
                    boucle=0;
                }


                break;

            case SDL_MOUSEMOTION:
                if( (event.motion.y<=(Y_BTN+50) ) && (event.motion.y>=Y_BTN) && (event.motion.x<=(X_BTN1+147)) && (event.motion.x>=X_BTN1))
                {
                    initialiser_audiobref(mus);
                    signIn.button1.state = 1;

                }
                else
                {
                    signIn.button1.state = 0;
                }
                if( (event.motion.y<=(Y_BTN+50) ) && (event.motion.y>=Y_BTN) && (event.motion.x<=(X_BTN2+147)) &&(event.motion.x>=X_BTN2))
                {
                    initialiser_audiobref(mus);
                    signIn.button2.state = 1;
                }
                else
                {
                    signIn.button2.state = 0;
                }

                break;

            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button==SDL_BUTTON_LEFT &&( (event.motion.y<=(Y_BTN+50) ) && (event.motion.y>=Y_BTN) && (event.motion.x<=(X_BTN1+147)) && (event.motion.x>=X_BTN1)))
                {
                    initialiser_audiobref(mus);
                    boucle = 0;

                }
                if(event.button.button==SDL_BUTTON_LEFT &&( (event.motion.y<=(Y_BTN+50) ) && (event.motion.y>=Y_BTN) && (event.motion.x<=(X_BTN2+147)) &&(event.motion.x>=X_BTN2)))
                {
                    initialiser_audiobref(mus);
                    strcpy(g.username,username);
                    game(screen,0,1);

                }

                break;

            case SDL_QUIT:
                boucle = 0;
                break;
            }


        }


        AfficherSignIn(&signIn,screen);

        SDL_FillRect(screen, &textRect, SDL_MapRGBA(screen->format, 255, 255, 255, 0));


        if (cursor < strlen(username))
        {
            textSurface = TTF_RenderText_Solid(font, username, textColor);
            SDL_Rect textRect = {560, 375, 0, 0}; 
            SDL_BlitSurface(textSurface, NULL, screen, &textRect);
            SDL_FreeSurface(textSurface);


        }
        else
        {
            strcat(username, " ");
            textSurface = TTF_RenderText_Solid(font, username, textColor);
            SDL_Rect textRect = {560, 375, 0, 0}; 
            SDL_BlitSurface(textSurface, NULL, screen, &textRect);
            SDL_FreeSurface(textSurface);



            username[cursor] = '\0';
            inputWidth = 21 * strlen(username);
        }


        SDL_Flip(screen);


    }


    liberer_musiquebref(mus);
    libererSignIn(&signIn);




}





