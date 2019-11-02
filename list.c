#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"

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

struct songNode *insertFront(struct songNode *songList,
                             char paramArtist[100],
                             char paramName[100]){
    struct songNode *new_head = malloc(sizeof(struct songNode));
    strcpy(new_head->name, paramName);
    strcpy(new_head->artist, paramArtist);
    new_head->next = songList;
    return new_head;
}

struct songNode *insertOrder(struct songNode* songList,
                             char paramArtist[100],
                             char paramName[100]){
    char currentSong[250] = "";
    char paramSong[250]="";
    strcat(paramSong, paramArtist);
    strcat(paramSong, " ");
    strcat(paramSong, paramName);
    struct songNode *cursor = songList;
    struct songNode *previous = NULL;
    for(; cursor != NULL; previous = cursor, cursor = cursor->next){
        strcpy(currentSong, "");
        strcat(currentSong, cursor->artist);
        strcat(currentSong, " ");
        strcat(currentSong, cursor->name);
        // printf("\n%s\n", currentSong);
        // printf("compared: %d \n", strcmp(currentSong, paramSong));
        // printf("comparison: %d\n", strcmp(currentSong, paramSong) );
        if(strcmp(currentSong, paramSong) >= 0){
        // printf ("inserted at %s \n", previous->name );
            return insertHere(songList, previous, cursor, paramArtist, paramName);
      }
    }
    return insertHere(songList, previous, cursor, paramArtist, paramName);
}

struct songNode *insertHere(struct songNode * songList,
                            struct songNode *before,
                            struct songNode *after,
                            char paramArtist[100],
                            char paramName[100]){
    struct songNode *toInsert = calloc(sizeof(struct songNode), 1);
    // printf("%s: %s \n", paramArtist, paramName);
    strcpy(toInsert->artist, paramArtist);
    strcpy(toInsert->name, paramName);
    if(before == NULL) {
        // printf("NULL! \n");
      toInsert->next = after;
      return toInsert;
    }
    toInsert->next = after;
    before->next = toInsert;
    return songList;
}

struct songNode *findFirstArtist(struct songNode *songList, char paramArtist[100]){
    struct songNode *cursor = songList;
    for(cursor; cursor != NULL; cursor = cursor->next){
        if(strcmp(cursor->artist, paramArtist) == 0){
            return cursor;
        }
    }
    return NULL;
}

struct songNode *findSong(struct songNode *songList, char paramArtist[100], char paramSong[100]) {
    struct songNode *cursor = songList;
    for(cursor; cursor != NULL; cursor = cursor->next){
        // printf("Comp: %d, %d \n", strcmp(cursor->artist, paramArtist), strcmp(cursor->name, paramSong));
        if((strcmp(cursor->artist, paramArtist) == 0)&& strcmp(cursor->name, paramSong) == 0){
            return cursor;
        }
    }
    return NULL;
}

struct songNode* randomSong (struct songNode* songList) {
    struct songNode *cursor = songList;
    int i = listLength(songList);
    int random = rand() % i;
    // printf("%d \n", random);
    int d = 0;
    cursor = songList;
    for (d; d != random; cursor = cursor->next, d++) {
        // printf("%d \n", d);
        }
    return cursor;
}

struct songNode * removeSong(struct songNode *songList, char paramArtist[100], char paramSong[100]){
    if((strcmp(songList->artist, paramArtist)== 0) &&  (strcmp(songList->name, paramSong) == 0)){
        // printf("ruh roh \n");
        struct songNode *nextSong = songList->next;
        free(songList);
        return nextSong;
    }
    else {
        struct songNode *cursor = songList;
        for(cursor; cursor->next != NULL; cursor = cursor->next){
            // printf("%d, %d \n", strcmp(cursor->next->artist, paramArtist), strcmp(cursor->next->name, paramSong));
            if((strcmp(cursor->next->artist, paramArtist) == 0) && (strcmp(cursor->next->name, paramSong) == 0)){
                struct songNode *nextSong = cursor->next->next;
                free(cursor->next);
                cursor->next = nextSong;
                return songList;
            }
        }
        return songList;
    }
}

struct songNode * freeList(struct songNode * songList){
    struct songNode *nextSong = songList;
    struct songNode *cursor;
    for(nextSong; nextSong != NULL; nextSong = cursor){
        cursor = nextSong->next;
        // printf("...> Freeing song %s: %s\n", nextSong->artist, nextSong->name);
        free(nextSong);
    }
    return NULL;
}

int listLength(struct songNode *songList){
    struct songNode *cursor = songList;
    int i = 0;
    for (i; cursor !=NULL; cursor = cursor->next, i++) {
    }
    return i;
}
