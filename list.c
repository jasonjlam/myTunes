#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct songNode{
  char name[100];
  char artist[100];
  struct songNode *next;
};

void printList(struct songNode *songList){
    printf("[\n");
    if (songList == NULL){
        printf("]\n");
    } else {
        struct songNode *cursor = songList;
        for(cursor; cursor != NULL; cursor = cursor->next){
            printf("\t%s: %s\n", cursor->artist, cursor->name);
        }
        printf("]\n");
    }
}

struct songNode * insertFront(struct songNode *songList,
                              char paramArtist[100],
                              char paramName[100]){
    struct songNode *new_head = malloc(sizeof(struct songNode));
    strcpy(new_head->name, paramName);
    strcpy(new_head->artist, paramArtist);
    new_head->next = songList;
    return new_head;
}

struct songNode* insertOrder(struct songNode* songList,
                             char paramArtist[100],
                             char paramName[100]){
    struct songNode *cursor = songList;
    struct songNode *previousNode = NULL;
    for(cursor; cursor != NULL; cursor = cursor->next){
        if(strcmp(cursor->artist, paramName)){
          // stuff
        }
    }
}
