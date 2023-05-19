#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "scrolling.h"
#include "personne.h"
#include "ennemi.h"
#include "obstacle.h"
#include "score.h"
#include "timer.h"
#include "minimap.h"






void sauvegarde_jeu(Background bg, Ennemi ennemi, Character character,AllObjet obj1,AllObjet obj2, tim* mytime)
{
    FILE* fichier = fopen("sauvegarde.txt", "w");

    if (fichier != NULL)
    {
        fprintf(fichier, "%d %d\n", bg.PositionBg.x, bg.PositionBg.y);
        fprintf(fichier, "%d %d %d %d %d %d\n", ennemi.pos_img.x, ennemi.pos_img.y, ennemi.direction, ennemi.current_image, ennemi.collision, ennemi.state);
        fprintf(fichier, "%d %d %d %d %d %d %d\n", character.position.x, character.position.y, character.isJumping, character.isBottom, character.velocity, character.gravity, character.life);

        fprintf(fichier, "%d %d\n", obj1.score_obj,obj2.score_obj);


        fprintf(fichier, "%ld %ld\n", mytime->t1,mytime->t2);


        fclose(fichier);
    }
}



void load_jeu(Background *bg, Ennemi *ennemi, Character *character,AllObjet *obj1,AllObjet *obj2, tim* mytime)
{
    FILE* fichier = fopen("sauvegarde.txt", "r");

    if (fichier != NULL)
    {
        fscanf(fichier, "%hd %hd\n", &bg->PositionBg.x, &bg->PositionBg.y);

        fscanf(fichier, "%hd %hd %d %d %d %u\n", &ennemi->pos_img.x, &ennemi->pos_img.y, &ennemi->direction, &ennemi->current_image, &ennemi->collision, &ennemi->state);

        fscanf(fichier, "%hd %hd %d %d %d %d %d\n", &character->position.x, &character->position.y, &character->isJumping, &character->isBottom, &character->velocity, &character->gravity, &character->life);

        fscanf(fichier, "%d %d\n", &obj1->score_obj, &obj2->score_obj);

        fscanf(fichier, "%ld %ld\n", &mytime->t1,&mytime->t2);

        fclose(fichier);
    }
}



