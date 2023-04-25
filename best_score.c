#include "best_score.h"
#include <string.h>

#define NBSCORES 3


void sauvgarder(char nomfich[], char nomjoueur[], int score) {
    FILE* f = fopen(nomfich, "ab");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nomfich);
        return;
    }
    Score s = {0};
    strncpy(s.nom, nomjoueur, sizeof(s.nom) - 1);
    s.score = score;
    fwrite(&s, sizeof(s), 1, f);
    fclose(f);
}

void meilleurs(char nomfich[], char Nomjoueur[], int* score) {
    int i = 0;
    Score scores[NBSCORES] = {0};
    Score score_actuel = {0};
    FILE* f = fopen(nomfich, "rb");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nomfich);
        return;
    }

    strncpy(score_actuel.nom, Nomjoueur, sizeof(score_actuel.nom) - 1);
    score_actuel.score = *score;
    fread(scores, sizeof(Score), NBSCORES, f);
    fclose(f);

   

    while (i < NBSCORES && score_actuel.score <= scores[i].score) {
        i++;
    }
    if (i < NBSCORES) {
        for (int j = NBSCORES - 1; j > i; j--) {
            scores[j] = scores[j - 1];
        }
        scores[i] = score_actuel;
    }


    f = fopen(nomfich, "wb");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nomfich);
        return;
    }
    fwrite(scores, sizeof(Score), NBSCORES, f);
    fclose(f);
}

int best_scr(char bestnom[], int bscr) {
    Score scores[NBSCORES] = {0};
    FILE* f = fopen(bestnom, "rb");
    if (f == NULL) {
        return bscr;
    }
   
    fread(scores, sizeof(Score), NBSCORES, f);
    fclose(f);
    if (bscr > scores[0].score) {
        return bscr;
    } else {
        return scores[0].score;
    }
}
