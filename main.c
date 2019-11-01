#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include <string.h>

int main(){
    srand (time(NULL));
    struct songNode * testList = NULL;
    printList(testList);
    testList = insertFront(testList, "Pink Floyd", "Money");
    testList = insertFront(testList, "Aerosmith", "Sweet Emotion");
    testList = insertOrder(testList, "Boston", "More Than A Feeling");
    testList = insertOrder(testList, "Abba", "Dancing Queen");
    testList = insertOrder(testList, "Imagine Dragons", "Warriors");
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

    printf("\nTesting findFirstArtist (testList, \"Eric Clapton\")\n");
    printf("Should return a pointer to the first Eric Clapton song, Down and Out \n");
    printList(findFirstArtist(testList, "Eric Clapton"));

    printf("\nTesting findSong (testList, \"Styx\", \"Renegade\") \n");
    printf("Should return a pointer to Styx, Renegade \n");
    printList(findSong(testList, "Styx", "Renegade"));

    printf("\nTesting findSong(testList, \"Jay-Z\", \"Renegade\") \n");
    printf("Should return a null pointer if the song is not in the list \n");
    printList(findSong(testList, "Jay-Z", "Renegade"));

    printf("\nTesting randomSong(testList) * 3 \n");
    printf("Should return pointers to three random songs \n");
    printList(randomSong(testList));
    printList(randomSong(testList));
    printList(randomSong(testList));

    printf("\nTesting removeSong(testList, \"Abba\", \"Dancing Queen\")\n");
    printf("Should return the list without Abba, Dancing Queen\n");
    printList(removeSong(testList, "Abba", "Dancing Queen"));

    printf("\nTesting removeSong(testList, \"Imagine Dragons\", \"Warriors\")\n");
    printf("Should return the list without Imagine Dragons, Warriors\n");
    printList(removeSong(testList, "Imagine Dragons", "Warriors"));

    printf("\nTesting removeSong(testList, \"ZZ Top\", \"Sharp Dressed Man\")\n");
    printf("Should return the list without ZZ Top, Sharp Dressed Man\n");
    printList(removeSong(testList, "ZZ Top", "Sharp Dressed Man"));

    printf("\nTesting freeList(testList)\n");
    printf("Should clear the list and return a null pointer\n");
    printList(freeList(testList));
    return 0;
}
