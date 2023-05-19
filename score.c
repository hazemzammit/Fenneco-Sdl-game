#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include "obstacle.h"
#include "score.h"
#include "image.h"
#include "texte.h"
#include "game.h"


void initialiser_score_trash(image_score *A)
{
    A->num_images = 10;
    A->t = malloc(sizeof(SDL_Surface*) * A->num_images);

    for(int i = 0; i < A->num_images; i++)
    {
        char filename[100];
        sprintf(filename, "ressources/progress_bars/score_trash/%d.png", i);
        A->t[i] = IMG_Load(filename);
    }

    A->pos_img.w = 89;
    A->pos_img.h = 48;
    A->pos_img.x = 1250;
    A->pos_img.y = 10;
}


void initialiser_score_melon(image_score *A)
{
    A->num_images = 10;
    A->t = malloc(sizeof(SDL_Surface*) * A->num_images);

    for(int i = 0; i < A->num_images; i++)
    {
        char filename[100];
        sprintf(filename, "ressources/progress_bars/score_melon/%d.png", i);
        A->t[i] = IMG_Load(filename);
    }

    A->pos_img.w = 89;
    A->pos_img.h = 48;
    A->pos_img.x = 1250;
    A->pos_img.y = 10;
}



void initialiser_score_bottle(image_score *A)
{
    A->num_images = 10;
    A->t = malloc(sizeof(SDL_Surface*) * A->num_images);

    for(int i = 0; i < A->num_images; i++)
    {
        char filename[100];
        sprintf(filename, "ressources/progress_bars/score_bottle/%d.png", i);
        A->t[i] = IMG_Load(filename);
    }

    A->pos_img.w = 89;
    A->pos_img.h = 48;
    A->pos_img.x = 1250;
    A->pos_img.y = 10;
}




void initialiser_score_key(image_score *A)
{
    A->num_images = 2;
    A->t = malloc(sizeof(SDL_Surface*) * A->num_images);

    A->t[0] = IMG_Load("ressources/progress_bars/key/key0.png");
    A->t[1] = IMG_Load("ressources/progress_bars/key/key1.png");


    A->pos_img.w = 89;
    A->pos_img.h = 48;
    A->pos_img.x = 1250;
    A->pos_img.y = 65;
}



void initialiser_score_vie(image_score *A)
{
    A->num_images = 4;
    A->t = malloc(sizeof(SDL_Surface*) * A->num_images);

    for(int i = 0; i < A->num_images; i++)
    {
        char filename[100];
        sprintf(filename, "ressources/progress_bars/vie/%d.png", i);
        A->t[i] = IMG_Load(filename);
    }

    A->pos_img.w = 144;
    A->pos_img.h = 41;
    A->pos_img.x = 270;
    A->pos_img.y = 70;
}





void afficherScore(image_score *A, AllObjet *o, SDL_Surface *screen)
{
    SDL_BlitSurface(A->t[o->score_obj], NULL, screen, &A->pos_img);
}



void afficherVie(image_score *A, Character *c, SDL_Surface *screen)
{
    if(c->life>=0)
        SDL_BlitSurface(A->t[c->life], NULL, screen, &A->pos_img);
}




double score1 = 0;
double score2 = 0;
double score3 = 0;
double score4 = 0;



double calculer_score(int temps_ecoule)
{
    double score = 0;

    if (temps_ecoule < 30)
    {
        score1 = temps_ecoule * 50;
    }
    else if (temps_ecoule >= 30 && temps_ecoule < 60)
    {
        score2 = (temps_ecoule - 30) * 2;
    }
    else if (temps_ecoule >= 60 && temps_ecoule < 90)
    {
        score3 = (temps_ecoule - 60);
    }
    else
    {
        score4 -= 0.7;
    }

    score = score1 + score2 + score3 + score4;
    return score;
}



void initialiser_BackScore(image *A)
{
    A->img=IMG_Load("ressources/progress_bars/score.png");
    A->pos_img.w=200;
    A->pos_img.h=48;
    A->pos_img.x=440;
    A->pos_img.y=12;
}



void initialiser_texteScore(texte *txte)
{
    TTF_Init();
    txte->police = TTF_OpenFont ("ressources/font/Candara.ttf", 18);
    txte->color_txt.r=255;
    txte->color_txt.g=255;
    txte->color_txt.b=255;
    txte->pos_txt.x=530;
    txte->pos_txt.y=25;
}



void afficher_score(SDL_Surface *screen, texte txte, time_t temps_debut, time_t temps_fin, AllObjet *o,AllObjet *o1, Score *score)
{
    char texte_score[50];
    int temps_ecoule = (int) difftime(temps_fin, temps_debut);
    score->score_temps = calculer_score(temps_ecoule);
    score->score_objet1 = calculScore(o);
    score->score_objet2 = calculScore(o1);
    score->score_total = score->score_temps + score->score_objet1 + score->score_objet2;
    sprintf(texte_score, "%.2f", score->score_total);
    txte.txt = TTF_RenderText_Blended(txte.police, texte_score, txte.color_txt);
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);
    SDL_FreeSurface(txte.txt);
}




double calculScore(AllObjet *o)
{
    double score;
    score=(o->score_obj)*10;
    return score;
}





void enregistrer_score(char* nom_fichier, Game *game, Score* s)
{
    FILE* fichier = fopen(nom_fichier, "a");
    if (fichier == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", nom_fichier);
        return;
    }

    fprintf(fichier, "%s %d %lf %lf %lf %lf\n", game->username, game->num_level, s->score_total, s->score_temps, s->score_objet1, s->score_objet2);
    fclose(fichier);
}

void lire_scores(char* nom_fichier, Game* game, Score* s)
{
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", nom_fichier);
        return;
    }

    char line[100];
    char last_line[100];
    while (fgets(line, sizeof(line), fichier) != NULL)
    {
        strncpy(last_line, line, sizeof(last_line));
    }

    sscanf(last_line, "%s %d %lf %lf %lf %lf", game->username, &game->num_level, &s->score_total, &s->score_temps, &s->score_objet1, &s->score_objet2);

    fclose(fichier);
}




double meilleurs_scores(char* nom_fichier, int num_level)
{
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", nom_fichier);
        return 0.0;
    }

    double score_total;
    char username[99];
    int level;

    double best_score_total = 0;


    while (fscanf(fichier, "%s %d %lf", username, &level, &score_total) != EOF)
    {
        if (level == num_level)
        {
            if (score_total > best_score_total)
            {
                best_score_total = score_total;
            }
        }
    }

    fclose(fichier);

    return best_score_total;
}

