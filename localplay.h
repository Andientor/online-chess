#pragma once

void grabInput(int8_t input[255]);

int8_t parseInput(int8_t input[255], int8_t coords[4]);

void playLocal(struct Board gameBoard, int8_t mode);
