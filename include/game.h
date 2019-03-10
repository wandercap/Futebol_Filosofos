#ifndef _GAME_H_
#define _GAME_H

typedef enum playType {F, O} playType;

typedef struct board {
	char *board;
	int size;
} board_t, *board_p;

typedef struct play {
	char side;
	char play;
	int pos;
} play_t, *play_p;

typedef struct game {
	play_p play;
	board_p board;
} game_t, *game_p;

typedef struct plays {
	int *plays;
	playType type;
	int lenght;
} plays_t, *plays_p;

game_p createGame();
void readMove();
plays_p oPlays(game_p game);
plays_p fPlays(game_p game);
void copyBoard(game_p game, game_p newGame);
int moveB(game_p game, int dest);
int moveF(game_p game, int dest);
void displayGameBoard(game_p game);

#endif
