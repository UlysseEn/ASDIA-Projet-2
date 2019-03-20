#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
  int index2 = index;
  double valMax = mat->cells[index].scoreD;

  char *out_s1 = NULL;
  char *out_s2 = NULL;
  out_s1 = malloc(index * sizeof(char));
  out_s2 = malloc(index * sizeof(char));

  char* out_cur = out_s1 + index - 1;
  *out_cur = '\0';

  char* out_cur2 = out_s2 + index - 1;
  *out_cur2 = '\0';
  uint8_t test = 0;
  while (mat->cells[index].scoreD >0){
  /*  //vertical
    if (mat->cells[index-mat->w].scoreD + cost->indelOpen == mat->cells[index].scoreD){
      *(--out_cur) = '-';
      *(--out_cur2) = tolower(s2[index/mat->w - 1]);
      index = index - mat->w;
    }
    //horizontal
    else if(mat->cells[index-1].scoreD + cost->indelOpen == mat->cells[index].scoreD) {
      *(--out_cur) = tolower(s1[index%mat->w - 1]);
      *(--out_cur2) = '-';
      index = index - 1;
    }
    //diagonal
    else {
      if (mat->cells[index].scoreD > mat->cells[index - mat->w - 1].scoreD){
        *(--out_cur) = s1[index%mat->w - 1];
        *(--out_cur2) = s2[index/mat->w - 1];
      }
      else {
        *(--out_cur) = tolower(s1[index%mat->w - 1]);
        *(--out_cur2) = tolower(s2[index/mat->w - 1]);
      }
      index = index - mat->w - 1; */
      //diagonal

      if(mat->cells[index].prevsD - 4 >= 0) {
        if (mat->cells[index].scoreD > mat->cells[index - mat->w - 1].scoreD){
          *(--out_cur) = s1[index%mat->w - 1];
          *(--out_cur2) = s2[index/mat->w - 1];
        }
        else {
          *(--out_cur) = tolower(s1[index%mat->w - 1]);
          *(--out_cur2) = tolower(s2[index/mat->w - 1]);
        }
        index = index - mat->w - 1;
        if(mat->cells[index].prevsD - 4 > 0) {
          mat->cells[index].prevsD -= 4;
          test = 1;
        }
      }
      else if(mat->cells[index].prevsD - 2 >= 0) {
        *(--out_cur) = tolower(s1[index%mat->w - 1]);
        *(--out_cur2) = '-';
        index = index - 1;
        if(mat->cells[index].prevsD - 2 > 0) {
          mat->cells[index].prevsD -= 2;
          test = 1;
        }
      }
      else if(mat->cells[index].prevsD - 1 >= 0) {
        *(--out_cur) = '-';
        *(--out_cur2) = tolower(s2[index/mat->w - 1]);
        index = index - mat->w;
      }
    }

    /*if(test == 1) {
      printBestAlis(mat, cost, s1, s2);
    }

    mat->cells[index2].scoreD = 0;
    if(mat->cells[maxValue(mat)].scoreD == valMax) {
      printBestAlis(mat, cost, s1, s2);
    }*/

    printf("s1 %s\n", out_cur);
    printf("s2 %s\n", out_cur2);
    printf("\n");
    free(out_s1);
    free(out_s2);
}

void printBestAlisAffine(struct matrix *mat, char *s1, char *s2){
  int index = maxValue(mat);
  char *out_s1 = NULL;
  char *out_s2 = NULL;
  out_s1 = malloc(index * sizeof(char));
  out_s2 = malloc(index * sizeof(char));

  char *out_cur = out_s1 + index - 1;
  *out_cur = '\0';

  char *out_cur2 = out_s2 + index - 1;
  *out_cur2 = '\0';

  //D = 1; V = 2; H = 3
  uint8_t current = 1;

  while (mat->cells[index].scoreD >0 || current != 1){
    if(current == 1){
      *(--out_cur) = s1[index%mat->w - 1];
      *(--out_cur2) = s2[index/mat->w - 1];
      if(mat->cells[index].prevsD % 2 == 1){
        current = 1;
      }
      else if(mat->cells[index].prevsD % 4 == 2 || mat->cells[index].prevsD % 4 == 3){
        current = 2;
      }
      else{
        current = 3;
      }
      index = index - mat->w - 1;
    }
    else if(current == 2){
      *(--out_cur) = '-';
      *(--out_cur2) = tolower(s2[index/mat->w - 1]);
      if(mat->cells[index].prevsV % 2 == 1){
        current = 1;
      }
      else if(mat->cells[index].prevsV % 4 == 2 || mat->cells[index].prevsV % 4 == 3){
        current = 2;
      }
      else{
        current = 3;
      }
      index = index - mat->w;
    }
    else{
      *(--out_cur) = tolower(s1[index%mat->w - 1]);
      *(--out_cur2) = '-';
      if(mat->cells[index].prevsH % 2 == 1){
        current = 1;
      }
      else if(mat->cells[index].prevsH % 4 == 2 || mat->cells[index].prevsH % 4 == 3){
        current = 2;
      }
      else{
        current = 3;
      }
      index = index - 1;
    }
  }
  printf("s1 %s\n", out_cur);
  printf("s2 %s\n", out_cur2);

  free(out_s1);
  free(out_s2);
}
