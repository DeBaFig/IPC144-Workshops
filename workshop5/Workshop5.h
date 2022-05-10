#ifndef WORKSHOP5_H_
#define WORKSHOP5_H_

#include <stdio.h>
#define MAX_PATH 70
#define MIN_PATH 10
#define MULT_PATH_CALC 5

struct GameInfo
{
	int MIN_Moves;
	int MAX_Moves;
	int Moves;
	int PathLength;
	int bombs[MAX_PATH / MULT_PATH_CALC][MULT_PATH_CALC];
	int treasures[MAX_PATH / MULT_PATH_CALC][MULT_PATH_CALC];
	char undiscovery[MAX_PATH];
	int Plays[MAX_PATH];
};

struct PlayerInfo
{
	int Nlives;
	char CharSym;
	int NTreasureF;
	int History[MAX_PATH];
	struct GameInfo game;
};


void game_main(void);


#endif
