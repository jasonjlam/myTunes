#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "library.h"
#include <string.h>

int main(){
    srand (time(NULL));

    // struct songNode * testList = NULL;
    // printList(testList);
    // testList = insertFront(testList, "pink floyd", "money");
    // testList = insertFront(testList, "aerosmith", "sweet emotion");
    // testList = insertOrder(testList, "boston", "more than a feeling");
    // testList = insertOrder(testList, "abba", "dancing queen");
    // testList = insertOrder(testList, "imagine dragons", "warriors");
    // testList = insertOrder(testList, "zz top", "sharp dressed man");
    // testList = insertOrder(testList, "21 pilots", "stressed out");
    // testList = insertOrder(testList, "styx", "come sail away");
    // testList = insertOrder(testList, "styx", "renegade");
    // testList = insertOrder(testList, "led zeppelin", "sharp dressed man");
    // testList = insertOrder(testList, "eric clapton", "down and out");
    // testList = insertOrder(testList, "eric clapton", "layla");
    // testList = insertOrder(testList, "eric clapton", "tears in heaven");
    // testList = insertOrder(testList, "eric clapton", "my fathers eyes");
    //
    // printf("\n");
    // printList(testList);
    //
    // printf("\nTesting findFirstArtist (testList, \"eric clapton\")\n");
    // printf("Should return a pointer to the first eric clapton song, down and out \n");
    // printList(findFirstArtist(testList, "eric clapton"));
    //
    // printf("\nTesting findSong (testList, \"styx\", \"renegade\") \n");
    // printf("Should return a pointer to styx, renegade \n");
    // printList(findSong(testList, "styx", "renegade"));
    //
    // printf("\nTesting findSong(testList, \"jay-z\", \"renegade\") \n");
    // printf("Should return a null pointer if the song is not in the list \n");
    // printList(findSong(testList, "jay-Z", "renegade"));
    //
    // printf("\nTesting randomSong(testList) * 3 \n");
    // printf("Should return pointers to three random songs \n");
    // printList(randomSong(testList));
    // printList(randomSong(testList));
    // printList(randomSong(testList));
    //
    // printf("\nTesting removeSong(testList, \"abba\", \"dancing queen\")\n");
    // printf("Should return the list without abba, dancing queen\n");
    // printList(removeSong(testList, "abba", "dancing queen"));
    //
    // printf("\nTesting removeSong(testList, \"imagine dragons\", \"warriors\")\n");
    // printf("Should return the list without imagine dragons, warriors\n");
    // printList(removeSong(testList, "imagine dragons", "warriors"));
    //
    // printf("\nTesting removeSong(testList, \"zz top\", \"sharp dressed man\")\n");
    // printf("Should return the list without zz top, sharp dressed man\n");
    // printList(removeSong(testList, "zz top", "sharp dressed man"));
    //
    // printf("\nTesting freeList(testList)\n");
    // printf("Should clear the list and return a null pointer\n");
    // printList(freeList(testList));

	struct songNode **library;
	library = createLibrary();
	printLibrary(library);

    printf("Adding songs to the library");
    library = addSong(library, "50 cent", "wanksta");
    library = addSong(library, "against the current", "legends never die");
    library = addSong(library, "ac/dc", "thunderstruck");
    library = addSong(library, "ac/dc", "highway to hell");
    library = addSong(library, "trick trick", "who want it");
    library = addSong(library, "nate dogg", "backdoor");
    library = addSong(library, "nas", "ether");
    library = addSong(library, "jay-z", "takeover");
    library = addSong(library, "bastille", "pompeii");
    library = addSong(library, "tove lo", "stay high");
    library = addSong(library, "eminem", "lose yourself");
    library = addSong(library, "eminem", "dead and gone");
    library = addSong(library, "onerepublic", "wherever i go");
    library = addSong(library, "dr. dre", "the next episode");
    library = addSong(library, "bon jovi", "livin' on a prayer");
    printLibrary(library);

    printf("\n---------- FIND SONG FROM LIBRARY ----------");
    printf("\nFinding \"nas: ether\"\n");
    printList(findSongLibrary(library, "nas", "ether"));

    printf("\nFinding \"50 cent: wanksta\"\n");
    printList(findSongLibrary(library, "50 cent", "wanksta"));

    printf("\nFinding \"renegade: ether\"\n");
    printList(findSongLibrary(library, "renegade", "ether"));

    printf("\nFinding \"nas: livin' on a prayer\"\n");
    printList(findSongLibrary(library, "nas", "livin' on a prayer"));

    printf("\n---------- FIND ARTIST FROM LIBRARY ----------");
    printf("\nFinding \"ac/dc\"\n");
    printList(findArtistLibrary(library, "ac/dc"));

    printf("\nFinding \"eminem\"\n");
    printList(findArtistLibrary(library, "eminem"));

    printf("\nFinding \"nate dogg\"\n");
    printList(findArtistLibrary(library, "nate dogg"));

    printf("\n---------- PRINT BY LETTER ----------");
    printByLetter(library, 'a');
    printByLetter(library, 'n');
    printByLetter(library, 'z');

    printf("\n---------- PRINT BY ARTIST ----------\n");
    printByArtist(library, "ac/dc");
    printByArtist(library, "nas");
    printByArtist(library, "zed");
    return 0;
}
