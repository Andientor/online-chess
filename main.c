#include <stdio.h>
#include <stdint.h>
#include "board.h"

extern void resetBoard();

void printTitle(){
	printf("\n----------------------------\n");
	printf("  Welcome to online chess!  \n");
	printf("----------------------------\n\n");

	printf("What do you want to do? [Enter number to progress]\n");
	printf("1. Play locally vs AI\n");
	printf("2. Play locally vs Human\n");
	printf("3. Play online\n\n");
	printf("Enter your choice: ");
}

int main(){
	printTitle();

	struct Board gameBoard;
	resetBoard(gameBoard.board);

	printf("%c", gameBoard.board[0][0]);

	return 0;
}
