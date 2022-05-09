
#define _CRT_SECURE_NO_WARNINGS
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


int main(void)
{
	struct PlayerInfo member;

	const int MIN_Nlives = 1, MAX_Nlives = 10;

	int end = 1 ,a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, h = 0, g = 0, play = 0, l = 0, treasurefound = 0, Flag = 0, Moves = 0, Lives = 0, SamePlace = 0, num = 0;
	int* Path = &member.game.PathLength, * NLives = &member.Nlives, * Max_mov = &member.game.MAX_Moves, * Move = &member.game.Moves, * Min_move = &member.game.MIN_Moves, (*Bombs)[MULT_PATH_CALC] = member.game.bombs;
	char* CharSym = &member.CharSym;

	char ruleMajor[MAX_PATH] = { 0 };
	int ruleMinor[MAX_PATH] = { 0 };
	while (end != 0) {

		printf("================================\n");
		printf("         Treasure Hunt!         \n");
		printf("================================\n");
		printf("\nPLAYER Configuration\n");
		printf("--------------------\n");
		printf("Enter a single character to represent the player: ");
		scanf(" %s", &*CharSym);
		while (*NLives <= 0 || *NLives > 10)
		{
			printf("Set the number of lives: ");
			scanf("%d", &*NLives);
			if (*NLives < MIN_Nlives || *NLives > MAX_Nlives)
			{
				printf("     Must be between %d and %d!\n", MIN_Nlives, MAX_Nlives);
			}
		}
		printf("Player configuration set-up is complete\n");
		printf("\n");
		printf("GAME Configuration\n");
		printf("------------------\n");
		while (*Path % MULT_PATH_CALC != 0 || *Path < MIN_PATH || *Path > MAX_PATH)
		{
			printf("Set the path length (a multiple of 5 between %d-%d): ", MIN_PATH, MAX_PATH);
			scanf("%d", &*Path);
			if (*Path % MULT_PATH_CALC != 0 || *Path < MIN_PATH || *Path > MAX_PATH)
			{
				printf("     Must be a multiple of 5 and between %d-%d!!!\n", MIN_PATH, MAX_PATH);
			}
		}
		*Min_move = *NLives;
		*Max_mov = (int)(*Path * 0.75);
		while (*Move < *Min_move || *Move > *Max_mov)
		{
			printf("Set the limit for number of moves allowed: ");
			scanf("%d", &*Move);
			if (*Move < *Min_move || *Move > *Max_mov)
			{
				printf("    Value must be between %d and %d\n", *Min_move, *Max_mov);
			}
		}
		printf("\n");
		printf("BOMB Placement\n");
		printf("--------------\n");
		printf("Enter the bomb positions in sets of %d where a value\n", MULT_PATH_CALC);
		printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
		printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", *Path);
		while (a < *Path)
		{
			printf("   Positions [%2d-%2d]: ", (a + 1), (a + MULT_PATH_CALC));

			for (b = 0; b < MULT_PATH_CALC; b++)
			{
				scanf("%d", &Bombs[c][b]);

			}
			c++;
			a += MULT_PATH_CALC;
		}

		printf("BOMB placement set\n");
		printf("\n");
		printf("TREASURE Placement\n");
		printf("------------------\n");
		printf("Enter the treasure placements in sets of %d where a value\n", MULT_PATH_CALC);
		printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
		printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", *Path);

		while (d < *Path)
		{
			printf("   Positions [%2d-%2d]: ", (d + 1), (d + MULT_PATH_CALC));
			for (e = 0; e < MULT_PATH_CALC; e++)
			{
				scanf("%d", &member.game.treasures[f][e]);
			}
			f++;
			d += MULT_PATH_CALC;
		}
		printf("TREASURE placement set\n");
		printf("\n");
		printf("GAME configuration set-up is complete...\n");
		printf("\n");
		printf("------------------------------------\n");
		printf("TREASURE HUNT Configuration Settings\n");
		printf("------------------------------------\n");
		printf("Player:\n");
		printf("   Symbol     : %c\n", *CharSym);
		printf("   Lives      : %d\n", *NLives);
		printf("   Treasure   : [ready for gameplay]\n");
		printf("   History    : [ready for gameplay]\n");
		printf("\n");
		printf("Game:\n");
		printf("   Path Length: %d\n", *Path);
		printf("   Bombs      : ");
		for (a = 0; a < (*Path / MULT_PATH_CALC); a++)
		{
			for (b = 0; b < MULT_PATH_CALC; b++)
			{
				printf("%d", Bombs[a][b]);
			}
		}
		printf("\n   Treasure   : ");
		for (a = 0; a < (*Path / MULT_PATH_CALC); a++)
		{
			for (b = 0; b < MULT_PATH_CALC; b++)
			{
				printf("%d", member.game.treasures[a][b]);
			}
		}
		printf("\n");
		printf("\n");
		printf("====================================\n");
		printf("~ Get ready to play TREASURE HUNT! ~\n");
		printf("====================================\n");

		Moves = *Move;
		Lives = *NLives;
		for (a = 0; a < *Path; a++)
		{
			for (b = 0; b < MULT_PATH_CALC; b++)
			{
				if (Bombs[a][b] == 0 && member.game.treasures[a][b] == 1)
				{
					member.History[g] = 0; //0 $
				}
				if (Bombs[a][b] == 0 && member.game.treasures[a][b] == 0)
				{
					member.History[g] = 1; //1 .
				}
				if (Bombs[a][b] == 1 && member.game.treasures[a][b] == 1)
				{
					member.History[g] = 2; //2 &
				}
				if (Bombs[a][b] == 1 && member.game.treasures[a][b] == 0)
				{
					member.History[g] = 3;  //3 !
				}
				g++;
			}
			member.game.undiscovery[a] = 177;
		}

		while (Flag != 3 || (Lives > 0 && Moves > 0))
		{
			Flag = 0;
			SamePlace = 0;
			l = 0;
			if (play > 0)
			{
				printf("  ");
				for (a = 0; a < play - 1; a++)
				{
					printf(" ");
				}
				printf("%c", *CharSym);
				for (a = 0; a < (*Path - (play)); a++)
				{
					printf(" ");
				}
				printf("\n");
			}
			else
			{
				printf("\n");
			}
			printf("  ");
			for (a = 0; a < *Path; a++)
			{
				printf("%c", member.game.undiscovery[a]);
			}
			printf("\n");
			printf("  ");
			for (a = 0; a < *Path; a++)
			{
				if (((a + 1) % 10) == 0 && a != 0)
				{
					ruleMajor[a] = 49 + l;
					l++;
				}
				else {
					ruleMajor[a] = '|';
				}
				printf("%c", ruleMajor[a]);
			}
			printf("\n");
			printf("  ");
			for (a = 0; a < *Path; a++)
			{
				if ((a + 1) % 10 == 0 && a != 0)
				{
					ruleMinor[a] = 0;
				}
				else
				{
					if (h == 9)
					{
						h = 0;
					}
					ruleMinor[a] = 1 + h;
					h++;
				}
				printf("%d", ruleMinor[a]);
			}
			printf("\n");
			printf("+---------------------------------------------------+\n");
			printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", Lives, treasurefound, Moves);
			printf("+---------------------------------------------------+\n");
			if (Lives <= 0 || Moves <= 0)
			{
				Flag = 3;
			}
			while (Flag != 1 && Lives > 0 && Moves > 0)
			{
				printf("Next Move [1-%d]: ", *Path);
				scanf("%d", &play);
				if (play <= 0 || play > *Path)
					printf("  Out of Range!!!\n");
				else
				{
					member.game.Plays[num] = play;

					printf("\n");
					for (a = 0; a < *Move; a++)
					{
						if (num != a && play == member.game.Plays[a])
						{
							printf("===============> Dope! You've been here before!\n");
							SamePlace = 1;
						}
					}
					Flag = 1;
				}

				if (SamePlace != 1 && play > 0 && play <= *Path)
				{
					if (member.History[play - 1] == 0)
					{
						member.game.undiscovery[play - 1] = '$';
						printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
						treasurefound++;
					}
					if (member.History[play - 1] == 1)
					{
						member.game.undiscovery[play - 1] = '.';
						printf("===============> [.] ...Nothing found here... [.]\n");
					}
					if (member.History[play - 1] == 2)
					{
						member.game.undiscovery[play - 1] = '&';
						printf("===============> [&] !!! BOOOOOM !!! [&]\n");
						printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
						Lives--;
						treasurefound++;
					}
					if (member.History[play - 1] == 3)
					{
						member.game.undiscovery[play - 1] = '!';
						printf("===============> [!] !!! BOOOOOM !!! [!]\n");
						Lives--;
					}
					Moves--;
				}
				if (Lives == 0)
				{
					printf("\n");
					printf("No more LIVES remaining!\n");
				}
				num++;
			}
			printf("\n");
		}
		printf("##################\n");
		printf("#   Game over!   #\n");
		printf("##################\n");
		printf("\n");
		printf("You should play again and try to beat your score!\n");
		getchar(&CharSym);

		printf("Would you like to try again? (to exit = 0)");
		scanf("%d", &end);
   }
	return 0;
}
