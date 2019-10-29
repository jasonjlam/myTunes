struct songNode{
  char name[100];
  char artist[100];
  struct songNode *next;
};

struct songNode* insert_front(struct songNode* songList, struct songNode* songToInsert);

struct songNode* insert_order(struct songNode* songList, struct songNode* songToInsert);

void print_list(struct songNode* songList);

struct songNode* findSong (struct songNode* songList, struct songNode* songToFind);

struct songNode* findArtistFirst (struct songNode* songList, struct songNode* songToFind);

struct songNode* randomSong (struct songNode* songList);

struct songNode* removeSong (struct songNode* songList, struct songNode* songToRemove);

struct songNode* freeList (struct songNode* songList);
