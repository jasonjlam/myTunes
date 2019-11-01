
struct songNode *addSong(struct songNode *library,
                         char paramArtist[100],
                         char paramName[100]);

struct songNode *findSongLibrary(struct songNode* library,
                           char paramArtist[100],
                           char paramName[100]);

struct songNode *findArtistLibrary(struct songNode* library,
                           char paramArtist[100]);

void printLetter(struct songNode *library, char letter);

void printArtist(struct songNode *library, char paramArtist[100]);

void printLibrary(struct songNode *library);

void shuffle(struct songNode *library, int n);

struct songNode *removeSongLibrary(struct songNode* library,
                           char paramArtist[100],
                           char paramName[100]);

struct songNode *clearLibrary(struct songNode *library);
