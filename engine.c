#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "board.h"

int8_t validateMove(int8_t board[8][8], int8_t coords[4]){
	
	int8_t piece, rawPiece;
	int8_t horiMove = 0, vertMove = 0, dir;

	for(int8_t i = 0; i < 4; i++){
		if(coords[i] < 0 || coords[i] > 7){
			printf("Location out of bounds!\n");
			return -1;
		}
	}
       
	piece = board[coords[1]][coords[0]];
	rawPiece = piece;

	if(piece == ' '){
		printf("Not a valid piece!\n");
		return -1;
	}

	//upper
	piece &= ~(1 << 5);

	horiMove = coords[2] - coords[0];
	vertMove = coords[3] - coords[1];

	//make sure not same color piece
	if(rawPiece & (1 << 5) && board[coords[3]][coords[2]]){
		printf("Invalid move!\n");
		return -1;
	}

	switch (piece){
		
		case 'K':
			if(abs(horiMove) > 1 || abs(vertMove) > 1){
				printf("Invalid move!\n");
				return -1;
			}
			
			return 1;

		case 'Q':
			if(abs(vertMove) != abs(horiMove)){
				if(vertMove != 0 && horiMove != 0){
					printf("Invalid move!\n");
					return -1;
				}
			}

			break;
			
		case 'B':
			if(abs(vertMove) != abs(horiMove)){
				printf("Invalid move!\n");
				return -1;
			}

			break;

		case 'R':
			if(vertMove != 0 && horiMove != 0){
				printf("Invalid move!\n");
				return -1;
			}

			break;

		case 'N':
			if(abs(horiMove) + abs(vertMove) != 3 || !horiMove || !vertMove){
				printf("Invalid move!\n");
				return -1;
			}

			break;

		case 'P':
			dir = -1;

			if(rawPiece == 'p'){
				dir *= -1;
			}

			if(!vertMove || abs(vertMove) > 2 || vertMove * dir < 0){
				printf("Invalid Move!\n");
				return -1;
			}

			if(horiMove != 0){
				if(abs(vertMove) > 1 || board[coords[3]][coords[2]] == ' '){
					printf("Invalid Move!\n");
					return -1;
				}
			} else {
				if(board[coords[3]][coords[2]] != ' '){
					printf("Invalid Move!\n");
					return -1;
				}
			}

			if(abs(vertMove) == 2 && coords[1] != 1 && coords[1] != 6){
				printf("Invalid Move!\n");
				return -1;
			}

			break;

	}

	return 1;

}
