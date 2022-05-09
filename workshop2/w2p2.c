#define _CRT_SECURE_NO_WARNINGS
#include "w2p2.h"

void coin_main(void)
{
	printf("Change Maker Machine\n");
	printf("====================\n");

	int rounding, fee, tax, firstDigit, secondDigit, balance, i, j;
	int count[7] = { 0, 0, 0, 0, 0 , 0, 0 };
	int value[7] = { 200, 100, 25, 10, 5, 1 };
	double M, IntM;
	printf("Enter dollars and cents amount to convert to coins (0 to exit): $");
	scanf("%lf", &M);
	while (M != 0) {
		IntM = M * 100;
		fee = (int)IntM * 5;
		firstDigit = fee / 1000;
		secondDigit = (fee % 1000) / 100;
		rounding = fee % 100;
		if (rounding < 50) {
			tax = (firstDigit * 10) + secondDigit + 0;
		}
		else {
			tax = (firstDigit * 10) + secondDigit + 1;
		}
		balance = (int)IntM - tax;
		printf("Service fee (5.0 percent): %1.2lf\n", (double)tax / 100);
		printf("Balance to dispense: $%1.2lf\n", (double)balance / 100);
		printf("\n");

		if (balance > 0) {
			for (i = 0; balance > 0 || (balance >= value[i] && i < 6); i++) {
				for (j = 0; balance >= value[i]; j++) {
					balance = balance - value[i];
					count[i]++;
				}
				switch (i)
				{
				case 0:
					printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", count[0], (double)balance / 100);
					break;
				case 1:
					printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", count[1], (double)balance / 100);
					break;
				case 2:
					printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", count[2], (double)balance / 100);
					break;
				case 3:
					printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", count[3], (double)balance / 100);
					break;
				case 4:
					printf("$0.05 NIckels  X %d (remaining: $%.2lf)\n", count[4], (double)balance / 100);
					break;
				case 5:
					printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", count[5], (double)balance / 100);
					break;
				}
			}
			printf("\n");
			printf("All coins dispensed!");
		}
		printf("Enter dollars and cents amount to convert to coins (0 to exit): $");
		scanf("%lf", &M);
	}
	
}



