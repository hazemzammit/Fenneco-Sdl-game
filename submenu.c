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
#include "submenu.h"
#include "game.h"
#include "signin.h"

void initialiser_back_submenu (image *imge)
{
    imge->img=IMG_Load("ressources/signin/fond.png");
    imge->pos_img.x=0;
    imge->pos_img.y=0;
    imge->pos_img.h=SCREEN_H;
    imge->pos_img.w=SCREEN_W;
}

void initialiserSubMenuLoad(SubMenu *subMenu,int num)
{

    subMenu->background.img = IMG_Load("ressources/submenu/submenu.png");
    subMenu->background.pos_img.w = 350;
    subMenu->background.pos_img.h = 282;
    subMenu->background.pos_img.x = (SCREEN_W- subMenu->background.pos_img.w)/2 ;
    subMenu->background.pos_img.y = (SCREEN_H-subMenu->background.pos_img.h)/2;

    switch(num)
    {
    case 0:
        subMenu->button1.normal.img =IMG_Load("ressources/submenu/n0.png");
        subMenu->button1.hover.img = IMG_Load("ressources/submenu/n1.png");
        subMenu->button2.normal.img = IMG_Load("ressources/submenu/l0.png");
        subMenu->button2.hover.img = IMG_Load("ressources/submenu/l1.png");
        break;

    case 1:
        subMenu->button1.normal.img =IMG_Load("ressources/submenu/s0.png");
        subMenu->button1.hover.img = IMG_Load("ressources/submenu/s1.png");
        subMenu->button2.normal.img = IMG_Load("ressources/submenu/r0.png");
        subMenu->button2.hover.img = IMG_Load("ressources/submenu/r1.png");
        break;

    }


    subMenu->button1.normal.pos_img.w =228;
    subMenu->button1.normal.pos_img.h = 62;
    subMenu->button1.normal.pos_img.x = (SCREEN_W- subMenu->button1.normal.pos_img.w)/2;
    subMenu->button1.normal.pos_img.y = (SCREEN_H- subMenu->button1.normal.pos_img.h)/2-45;



    subMenu->button1.hover.pos_img.w =228;
    subMenu->button1.hover.pos_img.h = 62;
    subMenu->button1.hover.pos_img.x = (SCREEN_W- subMenu->button1.hover.pos_img.w)/2;
    subMenu->button1.hover.pos_img.y = (SCREEN_H- subMenu->button1.hover.pos_img.h)/2-45;

    subMenu->button1.state = 0;


    subMenu->button2.normal.pos_img.w =228;
    subMenu->button2.normal.pos_img.h = 62;
    subMenu->button2.normal.pos_img.x = (SCREEN_W- subMenu->button2.normal.pos_img.w)/2;
    subMenu->button2.normal.pos_img.y = (SCREEN_H- subMenu->button2.normal.pos_img.h)/2+40;



    subMenu->button2.hover.pos_img.w =228;
    subMenu->button2.hover.pos_img.h = 62;
    subMenu->button2.hover.pos_img.x =  (SCREEN_W-  subMenu->button2.hover.pos_img.w)/2;
    subMenu->button2.hover.pos_img.y = (SCREEN_H- subMenu->button2.hover.pos_img.h)/2+40;
    subMenu->button2.state = 0;
}

void AfficherSubMenu(SubMenu *subMenu, SDL_Surface *screen)
{
    SDL_BlitSurface(subMenu->background.img, NULL, screen, &subMenu->background.pos_img);

    if (subMenu->button1.state == 0)
    {
        SDL_BlitSurface(subMenu->button1.normal.img, NULL, screen, &subMenu->button1.normal.pos_img);
    }
    else
    {
        SDL_BlitSurface(subMenu->button1.hover.img, NULL, screen, &subMenu->button1.hover.pos_img);
    }

    if (subMenu->button2.state == 0)
    {
        SDL_BlitSurface(subMenu->button2.normal.img, NULL, screen, &subMenu->button2.normal.pos_img);
    }
    else
    {
        SDL_BlitSurface(subMenu->button2.hover.img, NULL, screen, &subMenu->button2.hover.pos_img);
    }

}

void libererSubMenu(SubMenu *subMenu)
{
    SDL_FreeSurface(subMenu->background.img);

    SDL_FreeSurface(subMenu->button1.normal.img);
    SDL_FreeSurface(subMenu->button1.hover.img);
    SDL_FreeSurface(subMenu->button2.normal.img);
    SDL_FreeSurface(subMenu->button2.hover.img);

}




void submenuL(SDL_Surface *screen)
{
    image IMAGE_BACK;
    SubMenu subMenu;
    Mix_Chunk *mus;

    SDL_Event event;
    int boucle=1;




    initialiser_back_submenu(&IMAGE_BACK);

    initialiserSubMenuLoad(&subMenu,0);

    while(boucle)
    {
        afficher_imageBACK(screen,IMAGE_BACK);


        AfficherSubMenu(&subMenu,screen);


        int X_BTN=calcul_XBTN(&subMenu.button1.normal);
        int Y_BTN1=calcul_YBTN(&subMenu.button1.normal);
        int Y_BTN2=calcul_YBTN(&subMenu.button2.normal);


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


                if(event.key.keysym.sym ==SDLK_n)
                {
                    initialiser_audiobref(mus);
                    subMenu.button1.state = 1;
                    signin(screen);
                }

                if(event.key.keysym.sym ==SDLK_l)
                {
                    initialiser_audiobref(mus);
                    subMenu.button2.state = 1;
                    game(screen,1,0);
                }


                break;

            case SDL_MOUSEMOTION:
                if( (event.motion.y<=(Y_BTN1+62) ) && (event.motion.y>=Y_BTN1) && (event.motion.x<=(X_BTN+228)) && (event.motion.x>=X_BTN))
                {
                    initialiser_audiobref(mus);
                    subMenu.button1.state = 1;

                }
                else
                {
                    subMenu.button1.state = 0;
                }
                if( (event.motion.y<=(Y_BTN2+62) ) && (event.motion.y>=Y_BTN2) && (event.motion.x<=(X_BTN+228)) &&(event.motion.x>=X_BTN))
                {
                    initialiser_audiobref(mus);
                    subMenu.button2.state = 1;
                }
                else
                {
                    subMenu.button2.state = 0;
                }

                break;

            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button==SDL_BUTTON_LEFT &&( (event.motion.y<=(Y_BTN1+62) ) && (event.motion.y>=Y_BTN1) && (event.motion.x<=(X_BTN+228)) && (event.motion.x>=X_BTN)))
                {
                    initialiser_audiobref(mus);
                    signin(screen);
                }
                if(event.button.button==SDL_BUTTON_LEFT &&( (event.motion.y<=(Y_BTN2+62) ) && (event.motion.y>=Y_BTN2) && (event.motion.x<=(X_BTN+228)) &&(event.motion.x>=X_BTN)))
                {
                    initialiser_audiobref(mus);
                    game(screen,1,0);
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
    libererSubMenu(&subMenu);


}







void submenuS(SDL_Surface *screen)
{
    image IMAGE_BACK;
    SubMenu subMenu;
    Mix_Chunk *mus;

    SDL_Event event;
    int boucle=1;



    initialiser_back_submenu(&IMAGE_BACK);

    initialiserSubMenuLoad(&subMenu,1);

    while(boucle)
    {
        afficher_imageBACK(screen,IMAGE_BACK);


        AfficherSubMenu(&subMenu,screen);


        int X_BTN=calcul_XBTN(&subMenu.button1.normal);
        int Y_BTN1=calcul_YBTN(&subMenu.button1.normal);
        int Y_BTN2=calcul_YBTN(&subMenu.button2.normal);


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


                if(event.key.keysym.sym ==SDLK_s)
                {
                    initialiser_audiobref(mus);
                    subMenu.button1.state = 1;

                }

                if(event.key.keysym.sym ==SDLK_r)
                {
                    initialiser_audiobref(mus);
                    boucle=0;
                }


                break;

            case SDL_MOUSEMOTION:
                if( (event.motion.y<=(Y_BTN1+62) ) && (event.motion.y>=Y_BTN1) && (event.motion.x<=(X_BTN+228)) && (event.motion.x>=X_BTN))
                {
                    initialiser_audiobref(mus);
                    subMenu.button1.state = 1;

                }
                else
                {
                    subMenu.button1.state = 0;
                }
                if( (event.motion.y<=(Y_BTN2+62) ) && (event.motion.y>=Y_BTN2) && (event.motion.x<=(X_BTN+228)) &&(event.motion.x>=X_BTN))
                {
                    initialiser_audiobref(mus);
                    subMenu.button2.state = 1;
                }
                else
                {
                    subMenu.button2.state = 0;
                }

                break;

            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button==SDL_BUTTON_LEFT &&( (event.motion.y<=(Y_BTN1+62) ) && (event.motion.y>=Y_BTN1) && (event.motion.x<=(X_BTN+228)) && (event.motion.x>=X_BTN)))
                {
                    initialiser_audiobref(mus);

                    boucle=0;
                    menu(screen);
                }
                if(event.button.button==SDL_BUTTON_LEFT &&( (event.motion.y<=(Y_BTN2+62) ) && (event.motion.y>=Y_BTN2) && (event.motion.x<=(X_BTN+228)) &&(event.motion.x>=X_BTN)))
                {
                    initialiser_audiobref(mus);
                    boucle=0;
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
    libererSubMenu(&subMenu);


}



