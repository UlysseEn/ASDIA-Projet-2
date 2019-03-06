#include <stdio.h>
#include <stdlib.h>

#include "mem.h"
#include "swOut.h"
#include "swCalc.h"



int maxValue(struct matrix *mat) {
    size_t size;
    size = mat->w * mat->h;
    int maxValue = mat->cells[0].score;
    int index = 0;

    for (size_t i = 1; i < size; ++i) {
        if ( mat->cells[i].score > maxValue ) {
            maxValue = mat->cells[i].score;
            index = i;
        }
    }
    return index;
}

void printBestAlis(struct matrix *mat, struct cost *cost, char *s1, char *s2){
  int index = maxValue(mat);
  char *out = NULL;
  out = malloc(index * sizeof(char));

  char *out_cur = out + index - 1;
  *out_cur = '\0' ;

  while (mat->cells[index].score >0){
    *(--out_cur) = s1[index%mat->w - 1];
    index = index - mat->w - 1;
  }
  printf("out %s\n", out_cur);
}
