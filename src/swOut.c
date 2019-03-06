#include <stdio.h>
#include <stdlib.h>

#include "mem.h"
#include "swOut.h"
#include "swCalc.h"



int maxValue(struct matrix *mat) {
    size_t size;
    size = mat->w * mat->h;
    int maxValue = mat[0];
    int index = 0;

    for (int i = 1; i < size; ++i) {
        if ( mat[i] > maxValue ) {
            maxValue = mat[i];
            index = i;
        }
    }
    return index;
}

void printBestAlis(struct matrix *mat, struct cost *cost, char *s1, char *s2){
  int index = maxValue(*mat);
  char error = "Erreur";
  char *out = NULL;
  out = mallocOrDie(sizeof(index), &error);

  char *out_cur = out + index - 1;
  *out_cur = '\0' ;

  int i = 0;

  while (mat[index] >0){
    *(--out_cur) = s1[index%mat->w - 1];
    index = index - mat->w - 1;
  }
  printf("out %s\n", out_cur);
  return();
}
