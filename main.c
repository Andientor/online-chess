#include <stdio.h>
#include <stdint.h>
#include "board.h"

extern void resetBoard();

void initMode(int8_t mode){
	int8_t option[255];

	printf("\n----------------------------\n");
	printf("  Welcome to online chess!  \n");
	printf("----------------------------\n\n");

	printf("What do you want to do? [Enter number to progress]\n");
	printf("1. Play locally vs AI\n");
	printf("2. Play locally vs Human\n");
	printf("3. Play online\n\n");
	printf("Enter your choice: ");
	fgets((char*) option, 255, stdin);
	mode = option[0] - 48;

	while(mode <= 0 || mode >= 4){
		printf("Incorrect option!\n");
		printf("Enter your choice: ");
		fgets((char*) option, 255, stdin);
		mode = option[0] - 48;
	}
}

int main(){
	int8_t mode = 0;
	struct Board gameBoard;
	
	initMode(mode);

	resetBoard(gameBoard.board);

	return 0;
}
