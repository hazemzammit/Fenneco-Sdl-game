#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "xo.h"

void initialiserTic(tic *t)
{
    t->Bgimg= IMG_Load("ressources/xo/tictac.png");
    t->cross = IMG_Load("ressources/xo/x.png");
    t->circle = IMG_Load("ressources/xo/o.png");
    for (int i = 0; i < 9; i++)
    {
        t->tabsuivi[i] = 0;
    }
    t->pos_x = 400;
    t->pos_y = 200;

    t->joueur = 1;

    t->tour = 0;

    TTF_Init();
    t->police = TTF_OpenFont("ressources/font/angelina.TTF", 30);
    t->color.r = 255;
    t->color.g = 255;
    t->color.b = 255;
    t->text_rect.x = 500;
    t->text_rect.y = 20;
}

void afficherTic(tic t, SDL_Surface* screen)
{

    SDL_BlitSurface(t.Bgimg, NULL, screen, NULL);
    SDL_Rect rect = { t.pos_x, t.pos_y, 0, 0 };
    SDL_Rect position_case;

    for (int i = 0; i < 9; i++)
    {
        position_case.x = (i % 3) * LARGEUR_CASE+70;
        position_case.y = (i / 3) * HAUTEUR_CASE+25;
        if (t.tabsuivi[i] == 1)
        {
            SDL_BlitSurface(t.cross, NULL, screen, &position_case);
        }
        else if (t.tabsuivi[i] == -1)
        {
            SDL_BlitSurface(t.circle, NULL, screen, &position_case);

        }
    }
    SDL_Flip(screen);
}

int atilganer(int tabsuivi[])
{
    int lignes_gagnantes[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};

    for (int i = 0; i < 8; i++)
    {
        if (tabsuivi[lignes_gagnantes[i][0]] == tabsuivi[lignes_gagnantes[i][1]] &&
                tabsuivi[lignes_gagnantes[i][1]] == tabsuivi[lignes_gagnantes[i][2]])
        {
            return tabsuivi[lignes_gagnantes[i][0]];
        }
    }
    return 0;
}



void Resultat(int *tabsuivi, SDL_Surface *screen)
{
    SDL_Surface *message = NULL;
    SDL_Rect position;

    TTF_Font *police = TTF_OpenFont("ressources/font/angelina.TTF", 30);

    if (police == NULL)
    {
        printf("Erreur lors du chargement de la police : %s\n", TTF_GetError());
        return;
    }


    char texte[50];
    if (atilganer(tabsuivi) == 1)
        sprintf(texte, "Defaite,L'ordinateur a gagner");
    else if (atilganer(tabsuivi) == -1)
        sprintf(texte, "Bravo!vous avez gagner!");
    else
        sprintf(texte, "Match nul!");

    SDL_Color couleur = {255, 255, 255};
    message = TTF_RenderText_Blended(police, texte, couleur);

    if (message == NULL)
    {
        printf("Erreur lors de la création du message : %s\n", TTF_GetError());
        TTF_CloseFont(police);
        return;
    }

    position.x = (screen->w - message->w) / 2;
    position.y = (screen->h - message->h) / 2;

    SDL_BlitSurface(message, NULL, screen, &position);
    SDL_Flip(screen);

    SDL_FreeSurface(message);
    TTF_CloseFont(police);
}
int minimax(int tabsuivi[9],int joueur)
{
    int gagnant=atilganer (tabsuivi);
    if (gagnant!=0)
        return gagnant*joueur;
    int coup=-1;
    int score=-2;
    int i;
    for (i=0; i<9; ++i)
    {
        if(tabsuivi [i]==0)
        {
            tabsuivi[i]=joueur;
            int mmscore=-minimax(tabsuivi, joueur * -1) ;
            if (mmscore>score)
            {
                score=mmscore;
                coup=i;
            }
            tabsuivi[i]=0;
        }
    }
    if(coup==-1)
        return 0;
    return score;
}
void calcul_coup(int tabsuivi [9])
{
    int coup=-1;
    int score=-2;
    int i;
    for (i=0; i<9; ++i)
    {
        if(tabsuivi[i]==0)
        {
            tabsuivi[i]=1;
            int mmscore=-minimax(tabsuivi,-1);
            tabsuivi[i]=0;
            if(mmscore>score)
            {
                score=mmscore;
                coup=i;
            }
        }
    }
    tabsuivi [coup]=1;
}


int xogame(SDL_Surface *screen)
{
    tic t;
    TTF_Init();
    SDL_Event event;
    int x, y, coup, joueur;
    int tabsuivi[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    int running = 1;
    initialiserTic(&t);
    t.joueur = 1;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = 0;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if ((t.tour + t.joueur) % 2 == 1)
                {
                    x = event.button.x / LARGEUR_CASE;
                    y = event.button.y / HAUTEUR_CASE;
                    coup = 3 * y + x;
                    if (t.tabsuivi[coup] == 0)
                    {
                        t.tabsuivi[coup] = -1;
                        t.tour++;
                    }
                }
                break;
            default:
                break;
            }
        }

        afficherTic(t, screen);

        if (t.tour < 9 && atilganer(t.tabsuivi) == 0)
        {
            if ((t.tour + t.joueur) % 2 == 0)
            {
                calcul_coup(t.tabsuivi);
                SDL_Delay(1000);

                t.tour++;
            }
        }
        else
        {
            Resultat(t.tabsuivi, screen);
            SDL_Delay(4000);
            running = 0;
        }

        SDL_Flip(screen);
    }

    SDL_FreeSurface(t.Bgimg);
    TTF_Quit();
    return atilganer(t.tabsuivi);
}


