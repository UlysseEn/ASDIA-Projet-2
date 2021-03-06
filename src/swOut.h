#ifndef _SWOUT_H_
#define _SWOUT_H_

#include "swCalc.h"
#include "swCost.h"

/*
  Find the highest number in mat, return its index
*/

int maxValue(struct matrix *mat) ;

/* Find highest scoring local alignment(s) in mat, and print to stdout
   the corresponding best alignments.
   mat must have been filled with scores and prevs.
   cost is provided so mismatches with negative scores can be lowercased.
*/
void printBestAlis(struct matrix *mat, char *s1, char *s2) ;
void printBestAlisAffine(struct matrix *mat, char *s1, char *s2) ;

#endif
