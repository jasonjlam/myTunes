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
    char currentSong[200];
    char paramSong[200];
    strcat(paramSong, paramArtist);
    strcat(paramSong, " ");
    strcat(paramSong, paramName);
    struct songNode *cursor = songList;
    struct songNode *previous = NULL;
    for(cursor; cursor != NULL; previous = cursor, cursor = cursor->next){
      strcat(currentSong, cursor->artist);
      strcat(currentSong, " ");
      strcat(currentSong, cursor->name);
      // printf("\n%s\n", currentSong);

      if(strcmp(currentSong, paramSong) > 0){
        return insertHere(songList, previous, paramArtist, paramName);
      }
    }
    return insertHere(songList, previous, paramArtist, paramName);
    // struct songNode *cursor = songList;
    // if(strcmp(cursor->artist, paramArtist) > 0){
    //     return insertFront(songList, paramArtist, paramName);
    // }
    // if(songList == NULL){
    //     return insertFront(songList, paramArtist, paramName);
    // }
    //
    // for(cursor; cursor->next->next != NULL; cursor = cursor->next){
    //     if(strcmp(cursor->next->artist, paramArtist) > 0){
    //         return insertHere(songList, cursor, paramArtist, paramName);
    //     } else if(strcmp(cursor->next->artist, paramArtist) == 0){
    //         return insertIntoArtist(songList, paramArtist, paramName);
    //     } else {}
    // }
    // if(strcmp(cursor->next->artist, paramArtist) > 0){
    //     return insertHere(songList, cursor, paramArtist, paramName);
    // } else {
    //     return insertHere(songList, cursor->next, paramArtist, paramName);
    //
    //
}

struct songNode *insertHere(struct songNode *songList,
                            struct songNode *before,
                            char paramArtist[100],
                            char paramName[100]){
    struct songNode *after = before->next;
    struct songNode *toInsert = calloc(sizeof(struct songNode), 1);
    strcpy(toInsert->artist, paramArtist);
    strcpy(toInsert->name, paramName);
    if(after == NULL){
        toInsert->next = NULL;
        before->next = toInsert;
    }
    toInsert->next = after;
    before->next = toInsert;
    return songList;
}

// Deprecated
// struct songNode *insertIntoArtist(struct songNode *songList,
//                                   char paramArtist[100],
//                                   char paramName[100]){
//     struct songNode *nameCursor = findFirstArtist(songList, paramArtist);
//     if(strcmp(nameCursor->name, paramName) > 0){
//         return insertHere(songList, nameCursor, paramArtist, paramName);
//     }
//     for(nameCursor; strcmp(nameCursor->next->next->name, paramName) == 0;
//                             nameCursor = nameCursor->next){
//         if(strcmp(nameCursor->next->name, paramName) > 0){
//             return insertHere(songList, nameCursor, paramArtist, paramName);
//         } else if(strcmp(nameCursor->next->name, paramName) == 0){
//             return insertHere(songList, nameCursor, paramArtist, paramName);
//         } else {}
//     }
//     if(strcmp(nameCursor->next->name, paramName) > 0){
//         return insertHere(songList, nameCursor, paramArtist, paramName);
//     } else {
//         return insertHere(songList, nameCursor->next, paramArtist, paramName);
//     }
//
// }
//
struct songNode *findFirstArtist(struct songNode *songList, char paramArtist[100]){
    struct songNode *cursor = songList;
    for(cursor; cursor != NULL; cursor = cursor->next){
        if(strcmp(cursor->artist, paramArtist) == 0){
            return cursor;
        }
    }
    return NULL;
}
