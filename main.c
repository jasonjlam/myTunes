#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include <string.h>

int main(){
  struct songNode * testList = NULL;
  printList(testList);
  testList = insertFront(testList, "Pink Floyd", "Money");
  testList = insertFront(testList, "Aerosmith", "Sweet Emotion");
  testList = insertOrder(testList, "Boston", "More Than A Feeling");
  testList = insertOrder(testList, "Abba", "Dancing Queen");
  testList = insertOrder(testList, "ZZ Top", "Sharp Dressed Man");
  testList = insertOrder(testList, "21 Pilots", "Stressed Out");
  testList = insertOrder(testList, "Styx", "Come Sail Away");
  testList = insertOrder(testList, "Styx", "Renegade");
  testList = insertOrder(testList, "Led Zeppelin", "Sharp Dressed Man");
  testList = insertOrder(testList, "Eric Clapton", "Down and Out");
  testList = insertOrder(testList, "Eric Clapton", "Layla");
  testList = insertOrder(testList, "Eric Clapton", "Tears In Heaven");
  testList = insertOrder(testList, "Eric Clapton", "My Fathers Eyes");



  printf("\n");
  printList(testList);
  return 0;
}
