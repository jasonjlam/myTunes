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
	for(i ;i < 27; i++){
		library[i] = (struct songNode *)malloc(sizeof(struct songNode));
        library[i] = NULL;
	}
	return library;
}

void printLibrary(struct songNode **library) {
    int i = 0;
    printf("Printing out entire library, by each letter\nSTART OF LIBRARY\n");
    for (i; i <27; i++){
        // if (library[i] != NULL) {
            printList(library[i]);
        // }
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
    }
    for(; (strcmp(cursor->artist, paramArtist) == 0) && (cursor != NULL); cursor = cursor->next){
        printf("\t%s: %s\n", cursor->artist, cursor->name);
    }
    printf("]\n");
}
