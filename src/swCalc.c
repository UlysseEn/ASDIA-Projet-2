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
    for(size_t i=0; i < mat->w; i++) {
      for(size_t j=0; j < mat->h; j++) {
        if(i==0 || j==0) {
          mat->cells[mat->w * i + j].score = 0;
        }
        else {
          mat->cells[mat->w * i + j].score = 1;
        }
      }
    }
    return mat;
}

void swPrintMat(struct matrix *mat) {
  printf("mat->w = %d\n", mat->w);
  printf("mat->h = %d\n", mat->h);
  printf("\n------- Ma Matrice -------- \n\n");
  for(size_t i=0; i < mat->w; i++) {
    for(size_t j=0; j < mat->h; j++) {
      printf("cells[i,j] = %f\n", mat->cells[mat->w * i + j].score);
    }
  }
}

void swFreeMat(struct matrix *mat){
  free(mat->cells);
  free(mat);
}
