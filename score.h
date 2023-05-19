#ifndef SCORE_H 
#define SCORE_H
#include <SDL/SDL.h>
#include "texte.h"
#include "game.h"
#include "obstacle.h"


typedef struct
{
    SDL_Surface **t; // pointer to an array of SDL surfaces
    int num_images; // number of images in the array
    SDL_Rect pos_img;
} image_score;

typedef struct Score {
    double score_total;
    double score_temps;
    double score_objet1;
    double score_objet2;
} Score;


void initialiser_score_trash(image_score *A);
void initialiser_score_melon(image_score *A);
void initialiser_score_bottle(image_score *A);
void initialiser_score_key(image_score *A);
void initialiser_score_vie(image_score *A);

void initialiser_BackScore(image *A);

double calculScore(AllObjet *o);


void initialiser_texteScore(texte *txte);
double calculer_score(int temps_ecoule);
void afficher_score(SDL_Surface *screen, texte txte, time_t temps_debut, time_t temps_fin, AllObjet *o,AllObjet *o1, Score *score);

void afficherScore(image_score *A, AllObjet *o, SDL_Surface *screen);
void afficherVie(image_score *A, Character *c, SDL_Surface *screen);

void enregistrer_score(char* nom_fichier, Game *game, Score* s) ;
void lire_scores(char* nom_fichier, Game* game, Score* s);
double meilleurs_scores(char* nom_fichier, int num_level);


#endif

