#include <stdlib.h>
#include <stdio.h>
#include "../include/game.h"

game_p createGame(int size){
	game_p newGame = (game_p)malloc(sizeof(game_t));
	newGame->play = (play_p)malloc(sizeof(play_t));
	newGame->board = (board_p)malloc(sizeof(board_t));

	newGame->play->side = 'n';
	newGame->board->size = size;
	newGame->board->size+=2;		//aumenta duas posições para GOL
	newGame->board->board = (char*)malloc(newGame->board->size*(sizeof(char)));

	newGame->board->board[0] = newGame->board->board[newGame->board->size-1] = 'G';
	for (int i=1; i<newGame->board->size-1; i++) {
		newGame->board->board[i] = '.';
	}
	newGame->board->board[newGame->board->size/2] = 'o';

	return newGame;
}

void readMove(){
	// le jogada
	// modifica board->board
}

plays_p oPlays(game_p game) {
	plays_p newPlays = (plays_p)malloc(sizeof(plays_t));


	return newPlays;
}

plays_p fPlays(game_p game) {
	plays_p newPlays = (plays_p)malloc(sizeof(plays_t));


	return newPlays;
}

void copyBoard(game_p game, game_p newGame) {

}

int moveB(game_p game, int dest){
	int src, add,i;

	if((dest >= game->board->size)||(dest <= 0))   // se posição dest não existe
		return -1;
	if(game->board->board[dest]!= '.')	     // se posição já está ocupada
		return -1;

	for(i=0,src=-1; (i<game->board->size)&&(src==-1) ; i++){
		if(game->board->board[i]=='o') {
			src = i;
			if((src > dest && game->board->board[src-1]!= 'f') || (src < dest && game->board->board[src+1]!= 'f'))
				return -1;
			
		}

	}

	if(src<dest)add=1;else add=-1;

	for(i = src; i!=dest; i+=add ){	
		if(game->board->board[i]!= 'f' && game->board->board[i+add]!= 'f')
			return -1;
	}

	game->board->board[dest]='o';

	for(i = src; i!=dest; i+=add ){	// troca os f por '.'
		game->board->board[i]='.';
	}
	return 1;
}

int moveF(game_p game, int dest){
	if((dest >= game->board->size)||(dest <= 0))   // se posição dest não existe
		return -1;
	if(game->board->board[dest]!= '.')	     // se posição já está ocupada
		return -1;
	game->board->board[dest] = 'f';
	return 1;
}

void displayGameBoard(game_p game){
	printf("===Game Board==========\n");
	for(int i=0;i<game->board->size;i++){
		printf("%c", game->board->board[i]);
	}
	printf("\n");
}

//========================
//======teste game========
//========================
// int main(){
// 	game_p  game = createGame();
// 	moveB(game,1);
// 	displayboard->board(game);
// 	moveF(game,1); 
// 	moveF(game,3);
// 	displayboard->board(game);
// 	return 0;
// }
