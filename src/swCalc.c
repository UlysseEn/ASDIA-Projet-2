#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include "mem.h"
#include "swCalc.h"

struct matrix *swInitMat(char *s1, char *s2) {
    struct matrix *mat = NULL;
    mat = malloc(sizeof(struct matrix));
    mat->w = strlen(s1) + 1;
    mat->h = strlen(s2) + 1;
    mat->cells = malloc(mat->w * mat->h * sizeof(struct cell));
    printf("sizeof = %d\n", sizeof(struct cells*));
    for(size_t i=0; i < mat->w; i++) {
      for(size_t j=0; j < mat->h; j++) {
        if(i==0 || j==0) {
          mat->cells[mat->w * i + j].score = 0;
        }
        /*else {
          mat->cells[mat->w * i + j].score = 1;
        }*/
      }
    }
    return mat;
}

void swFillMat(struct matrix *mat, struct cost *cost, char *s1, char *s2) {
  for(size_t i=1; i < mat->w; i++) {
    for(size_t j=1; j < mat->h; j++) {
      double score1 = mat->cells[mat->w * (i-1) + j].score + cost->indelOpen;
      double score2 = mat->cells[mat->w * i + j-1].score + cost->indelOpen;
      score1 = ((score1 < score2) ? score2 : score1);
      double score3 = mat->cells[mat->w * (i-1) + j-1].score + cost->subst(s1[i-1], s2[j-1]);
      score1 = ((score1 < score3) ? score3 : score1);
      score1 = ((score1 < 0) ? 0 : score1);
      mat->cells[mat->w * i + j].score = score1;
    }
  }
}


void swPrintMat(struct matrix *mat) {
  printf("mat->w = %d\n", mat->w);
  printf("mat->h = %d\n", mat->h);
  printf("\n------- Ma Matrice -------- \n\n");
  for(size_t i=0; i < mat->w; i++) {
    for(size_t j=0; j < mat->h; j++) {
      //printf("cells[%d,%d] = %.0f\n", i, j, mat->cells[mat->w * i + j].score);
      printf("%.0f ", mat->cells[mat->w * i + j].score);
    }
    printf("\n");
  }
}

void swFreeMat(struct matrix *mat){
  free(mat->cells);
  free(mat);
}
