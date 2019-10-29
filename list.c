#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct songNode{
  char name[100];
  char artist[100];
  struct songNode *next;
};
