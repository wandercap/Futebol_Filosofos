#include <stdlib.h>
#include <stdio.h>
#include "../include/graph.h"
#include "../include/util.h"

int main(int argc, char **argv) {
    game_p  game = createGame(7);
 	displayGameBoard(game);
    moveB(game,6);
 	displayGameBoard(game);
 	moveF(game,2);
    displayGameBoard(game);
 	moveF(game,3);
 	displayGameBoard(game);
    moveB(game,1);
 	displayGameBoard(game);
    moveF(game,2);
    moveF(game,5);
    displayGameBoard(game);
    moveB(game,3);
 	displayGameBoard(game);
    moveB(game,4);
 	displayGameBoard(game);
    //graph_p graph = createGraph(0);

    return 0;
}