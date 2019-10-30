#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int main(){
  struct songNode * testList = NULL;
  printList(testList);
  testList = insertFront(testList, "Pink Floyd", "Money");

  printf("\n");
  printList(testList);
  return 0;
}
