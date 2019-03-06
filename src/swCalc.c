#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include "mem.h"
#include "swCalc.h"

struct matrix *swInitMat(char *s1, char *s2) {
    struct matrix *mat = NULL;
    mat = malloc(sizeof(struct matrix*));
    mat->w = strlen(s1);
    mat->h = strlen(s2);
    mat->cells = malloc(mat->w * mat->h * sizeof(struct cells*));
    for(size_t i=0; i <= mat->w; i++) {
      for(size_t j=0; j <= mat->h; j++) {
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
  for(size_t i=1; i <= mat->w; i++) {
    for(size_t j=1; j <= mat->h; j++) {
      double score1 = mat->cells[w * (i-1) + j] + cost->indelOpen;
      double score2 = mat->cells[w * i + j-1] + cost->indelOpen;
      double score3 = mat->cells[w * (i-1) + j-1] + cost->subst(s1[i], s2[j])
      mat->cells[w * i + j] = min(score1, score2, score3); //A coder
    }
  }
}


void swPrintMat(struct matrix *mat) {
  printf("mat->w = %d\n", mat->w);
  printf("mat->h = %d\n", mat->h);
  printf("\n------- Ma Matrice -------- \n\n");
  for(size_t i=0; i < mat->w; i++) {
    for(size_t j=0; j < mat->h; j++) {
      printf("cells[%d,%d] = %.0f\n", i, j, mat->cells[mat->w * i + j].score);
    }
  }
}
