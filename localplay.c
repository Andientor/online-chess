#include <stdint.h>
#include <stdio.h>
#include "board.h"
#include "localplay.h"

void grabInput(int8_t input[255]){

	if(fgets((char*) input, 255, stdin)){
		printf("%s\n", input);
	}

}

void playLocal(struct Board gameBoard, int8_t mode){

	printf("%c %c\n", mode, gameBoard.board[0][0]);

}
