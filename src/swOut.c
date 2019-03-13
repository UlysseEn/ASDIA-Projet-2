#include <stdio.h>
#include <stdlib.h>

#include "mem.h"
#include "swOut.h"
#include "swCalc.h"



int maxValue(struct matrix *mat) {
    size_t size;
    size = mat->w * mat->h;
    int maxValue = mat->cells[0].scoreD;
    int index = 0;
    for (size_t i = 1; i < size; ++i) {
        if ( mat->cells[i].scoreD > maxValue ) {
            maxValue = mat->cells[i].scoreD;
            index = i;
        }
    }
    return index;
}

void printBestAlis(struct matrix *mat, struct cost *cost, char *s1, char *s2){
  int index = maxValue(mat);
  char *out_s1 = NULL;
  char *out_s2 = NULL;
  out_s1 = malloc(index * sizeof(char));
  out_s2 = malloc(index * sizeof(char));

  char *out_cur = out_s1 + index - 1;
  *out_cur = '\0';

  char *out_cur2 = out_s2 + index - 1;
  *out_cur2 = '\0';
  
  while (mat->cells[index].score >0){
    if (mat->cells[index].score > mat->cells[index - mat->w - 1].score){
      *(--out_cur) = s1[index%mat->w - 1];
      *(--out_cur2) = s2[index/mat->w - 1];
    }
    else {
      *(--out_cur) = tolower(s1[index%mat->w - 1]);
      *(--out_cur2) = tolower(s2[index/mat->w - 1]);
    }
    index = index - mat->w - 1;
  }

  printf("s1 %s\n", out_cur);
  printf("s2 %s\n", out_cur2);

  free(out_s1);
  free(out_s2);
}
