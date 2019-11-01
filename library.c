#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "library.h"
#include <string.h>

struct songNode *addSong(struct songNode *library[27],
                         char paramArtist[100],
                         char paramName[100]){
	int position = (int)(paramArtist[0] - 96);

	if(library[position] == NULL){
		library[position] = insertFront(library[position], paramArtist, paramName);
		return library;
	}

	insertOrder(library[position], paramArtist, paramName);
	return library;
}

struct songNode *createLibrary(){
	struct songNode *library[27];
	int i = 0;
	for(;i < 27; i++){
		library[i] = malloc(sizeof(struct songNode));
	}
	return library;
}
