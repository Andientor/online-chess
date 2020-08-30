#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "board.h"
#include "localplay.h"

const int8_t correctMovement[2][2] = {{'A', 'H'}, {'1', '8'}};

void grabInput(int8_t input[255]){

	printf("Enter your move: ");

	if(!fgets((char*) input, 255, stdin)){
		printf("Error getting input!\n");
	}

}

int8_t parseInput(int8_t input[255], int8_t coords[4]){
	
	if(!strcmp((char*) input, "exit\n")){
		printf("Exiting\n");	
		return 21;
	}	

	//movement
	if(strlen((char*) input) > 5){
		printf("Invalid move: too long\n");
		return -1;
	}

	//make letters uppercase
	input[0] &= ~(1 << 5);
	input[2] &= ~(1 << 5);

	//verify that characters are within their limits then convert to int
	for(uint8_t i = 0; i < 4; i++){
		int8_t loc = i;
		if(i > 1){
			loc -= 2;
		}

		if(input[i] < correctMovement[loc][0] || input[i] > correctMovement[loc][1]){
			printf("Invalid move: %c\n", input[i]);
			return -1;
		}

		//to int then reverse for board coords. ex 1 -> 7
		coords[i] = input[i] - correctMovement[loc][0];
		if(loc){ //reverse only for num not letters
			coords[i] = 7 - coords[i];
		}
		
	}

	return 1;
}

void playLocal(struct Board gameBoard, int8_t mode){

	int8_t input[255];
	int8_t coords[4];
	int8_t running = 1;

	input[200] = mode;

	while (running){
		int8_t code;
	
		grabInput(input);
		code = parseInput(input, coords);
		if(code > 0) {
		
			if(code == 21){
				running = 0;
				break;
			}

			movePiece(gameBoard.board, coords);
			printBoard(gameBoard, 2, coords);
		}
		
	}

}
