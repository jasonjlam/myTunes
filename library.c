#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "library.h"
#include <string.h>

struct songNode **addSong(struct songNode *library[27],
                         char paramArtist[100],
                         char paramName[100]){
    // printf("%s\n", paramArtist);
	int position = (int)(paramArtist[0] - 96);
    if (position < 1 || position > 26 ){
        position = 0;
    }
	if(library[position] == NULL){
        // printf("%s\n", paramName);
		library[position] = insertOrder(library[position], paramArtist, paramName);
		return library;
	}

	library[position] = insertOrder(library[position], paramArtist, paramName);
    // printList(library[position]);
	return library;
}

struct songNode **createLibrary(){
	struct songNode **library = (struct songNode**)calloc(sizeof(struct songNode),27);
    // = calloc(sizeof (struct songNode), 27);
	int i = 0;
	for(;i < 27; i++){
		// library[i] = (struct songNode *)malloc(sizeof(struct songNode));
        library[i] = NULL;
	}
	return library;
}

void printLibrary(struct songNode **library) {
    int i = 0;
    printf("Printing out entire library, by each letter\nSTART OF LIBRARY\n");
    if (library == NULL){
        printf("LIBRARY IS EMPTY\n");
        return;
    }
    for ( ;i <27; i++){
        if (library[i] != NULL) {
            printList(library[i]);
        }
    }
    printf("END OF LIBRARY\n");
}

struct songNode *findSongLibrary(struct songNode **library,
                                  char paramArtist[100],
			                      char paramName[100]){
    int position = (int)(paramArtist[0] - 96);
    if (position < 1 || position > 26){
        position = 0;
    }
    // printf("\n%d\n", position);
    // printList(library[position]);
    if(library[position] == NULL){
        printf("Song does not exist(No List)\n");
        return NULL;
    }
    struct songNode *cursor = library[position];
    for(; cursor != NULL; cursor = cursor->next){
        // printf("\n%s", cursor->artist);
        // printf("\n%s\n", paramArtist);
        if(strcmp(cursor->artist, paramArtist) + strcmp(cursor->name, paramName) == 0){
            return cursor;
        }
    }
    printf("Song does not exist(not in loop)\n");
    return NULL;
}

struct songNode *findArtistLibrary(struct songNode **library,
                                   char paramArtist[100]){
    int position = (int)(paramArtist[0] - 96);
    if (position < 1 || position > 26){
        position = 0;
    }

    if(library[position] == NULL){
        printf("Song does not exist(No List)\n");
        return NULL;
    }

    struct songNode *cursor = library[position];
    for(; cursor != NULL; cursor = cursor->next){
        // printf("\n%s", cursor->artist);
        // printf("\n%s\n", paramArtist);
        if(strcmp(cursor->artist, paramArtist) == 0){
            return cursor;
        }
    }
    printf("Song does not exist(not in loop)\n");
    return NULL;
}

void printByLetter(struct songNode **library, char paramLetter) {
    int position = (int)(paramLetter) - 96;
    if (position < 1 || position > 26){
        position = 0;
    }
    // printf("\n%d\n", position);
    // printList(library[position]);

    printf("Printing out entries starting with \"%c\"\n", paramLetter);
    printList(library[position]);
    printf("END\n\n");
}

void printByArtist(struct songNode **library, char paramArtist[100]) {
    int position = (int)(paramArtist[0]) - 96;
    if (position < 1 || position > 26){
        position = 0;
    }
    // printf("\n%d\n", position);
    // printList(library[position]);
    printf("\nPrinting out songs by: \"%s\"\n", paramArtist);
    printf("[\n");
    struct songNode *cursor = library[position];
    if(library[position] == NULL){
        printf("]\n");
        return;
    }
    for (; (cursor != NULL) && (strcmp(cursor->artist, paramArtist) == 0); cursor = cursor->next){
        printf("\t%s: %s\n", cursor->artist, cursor->name);
    }
    printf("]\n");
}

void shuffle(struct songNode **library, int n){
    int i = 0;
    int j = 0;
    int times = 0;
    int librarySize = 0;
    int random = 0;
    struct songNode *song = NULL;
    printf("Shuffling into a playlist of %d songs \n", n );
    for (; i < 27; i++) {
        librarySize += listLength(library[i]);
    }
    printf("Library size: %d \n", librarySize);
    if (librarySize == 0) {
        printf ("There are no songs to shuffle! \n");
        return;
    }
    for (; times < n; times ++) {
        i = 0;
        j = 0;
        random = rand() % librarySize;
        for (; i < 27; j+= listLength(library[i]), i++ ) {
            if (j <= random && random < j + listLength(library[i])) {
                song = randomSong(library[i]);
                printf("%s: %s \n", song->artist , song->name);
            }
        }
    }
}

struct songNode **removeSongLibrary(struct songNode** library,
                           char paramArtist[100],
                           char paramName[100]){
    printf("Removing [%s: %s]\n", paramArtist, paramName);

    int position = (int)(paramArtist[0]) - 96;
    if (position < 1 || position > 26){
       position = 0;
    }
    if(library[position] == NULL){
       printf("Song does not exist");
       return library;
    }
    struct songNode *cursor = library[position];
    library[position] = removeSong(cursor, paramArtist, paramName);
    return library;
}

struct songNode **clearLibrary(struct songNode **library) {
    // struct songNode *songList = ;
    // struct songNode *cursor;
    // for
    int i = 0;
    for(; i < 27; i++){
        freeList(library[i]);
        // free(library[i]);
    }
    free(library);
    return NULL;
}
