struct songNode{
  char name[100];
  char artist[100];
  struct songNode *next;
};

struct songNode* insertFront(struct songNode* songList,
                             char paramArtist[100],
                             char paramName[100]);

struct songNode* insertOrder(struct songNode* songList, struct songNode* songToInsert);

void printList(struct songNode* songList);

struct songNode* findSong (struct songNode* songList, struct songNode* songToFind);

struct songNode* findArtistFirst (struct songNode* songList, struct songNode* songToFind);

struct songNode* randomSong (struct songNode* songList);

struct songNode* removeSong (struct songNode* songList, struct songNode* songToRemove);

struct songNode* freeList (struct songNode* songList);
