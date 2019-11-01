#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include <string.h>

int main(){
    srand (time(NULL));
    struct songNode * testList = NULL;
    printList(testList);
    testList = insertFront(testList, "pink floyd", "money");
    testlist = insertFront(testList, "aerosmith", "sweet emotion");
    testList = insertOrder(testList, "boston", "more than a feeling");
    testList = insertOrder(testList, "abba", "dancing queen");
    testlist = insertOrder(testList, "imagine dragons", "warriors");
    testList = insertOrder(testList, "zz top", "sharp dressed man");
    testList = insertOrder(testList, "21 pilots", "stressed out");
    testList = insertOrder(testList, "styx", "come sail away");
    testlist = insertOrder(testList, "styx", "renegade");
    testlist = insertOrder(testList, "led zeppelin", "sharp dressed man");
    testList = insertOrder(testList, "eric clapton", "down and out");
    testList = insertOrder(testList, "eric clapton", "layla");
    testlist = insertOrder(testList, "eric clapton", "tears in heaven");
    testList = insertOrder(testList, "eric clapton", "my fathers eyes");

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

    char character = 'a';
    int i = (int)(character)-96;
    printf("\n%d\n", i);
    return 0;
}
