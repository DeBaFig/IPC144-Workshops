
#define _CRT_SECURE_NO_WARNINGS
#include "Workshop04.h"

void wishList_main(void)
{
	int MIN_COST = 100;

	int keep = 0, Nlist = 0, i, j, v = 0, b, k, MonthCopy, TotalYear = 0, TotalMonth = 0, Mflag = 1, Mselect, Pselect;
	double NetMonthly, SumT = 0;

	Wish itens[50] = { {{ 0 }} };
	Plist onlyP[50] = { {{ 0 }} };
	int digits[50] = { 0 };

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	while (keep == 0)
	{
		printf("\n");
		printf("Enter your monthly NET income: $");
		scanf("%lf", &NetMonthly);
		if (NetMonthly < MIN_INCOME || NetMonthly > MAX_INCOME) {
			if (NetMonthly < MIN_INCOME)
				printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
			else
				printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		}
		if (NetMonthly >= MIN_INCOME && NetMonthly < MAX_INCOME)
			keep = 1;
	}
	while (keep == 1)
	{
		printf("\n");
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &Nlist);
		if (Nlist <= 0 || Nlist > MAX_ITENS) {
			printf("ERROR: List is restricted to between 1 and %d items.\n", MAX_ITENS);
		}
		else {
			keep = 2;
		}

	}
	for (i = 0; i < Nlist; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);

		while (keep == 2)
		{
			printf("   Item cost: $");
			scanf("%lf", &itens[i].costs[i]);
			if (itens[i].costs[i] < MIN_COST) {
				printf("      ERROR: Cost must be at least $%.2lf\n", (float)MIN_COST);
			}
			else {
				SumT += itens[i].costs[i];
				keep = 3;
			}

		}
		while (keep == 3)
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &itens[i].priority[i]);
			if (itens[i].priority[i] < 4 && itens[i].priority[i] > 0) {
				keep = 4;
			}
			else {
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		}

		while (keep == 4)
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%s", &itens[i].Foption[i]);
			if ((itens[i].Foption[i] == 'y') || (itens[i].Foption[i] == 'n'))
			{
				if (itens[i].Foption[i] == 'y') {
					itens[i].Foption1and0[i] = 1;
				}
				if (itens[i].Foption[i] == 'n')
				{
					itens[i].Foption1and0[i] = 0;
				}
				keep = 2;
			}
			else {
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		}
		
	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (j = 0; j < Nlist; j++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", j + 1, itens[j].priority[j], itens[j].Foption[j], itens[j].costs[j]);
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", SumT);
	while (v < 3)
	{
		for (b = 0; b < Nlist; b++)
		{
			if (itens[b].priority[b] == v + 1)
			{
				onlyP[v].CostbyP[v] += itens[b].costs[b];
				if (itens[b].Foption1and0[b] == 1)
				{
					onlyP[v].FinancialbyP[v] = 1;
				}
			}
		}
		onlyP[v].YearbyP[v] = (int)((onlyP[v].CostbyP[v] / NetMonthly) / 12);
		onlyP[v].MonthbyP[v] = (int)(((onlyP[v].CostbyP[v] / NetMonthly) / 12) * 100);

		MonthCopy = onlyP[v].MonthbyP[v];
		for (k = 0; MonthCopy > 0; k++)
		{
			digits[k] = MonthCopy % 10; 
			MonthCopy /= 10;
		}
		onlyP[v].MonthbyP[v] = ((((digits[1] * 10) + (digits[0] + 3)) / 8));

		TotalMonth += onlyP[v].MonthbyP[v];

		v++;
	}

	TotalYear = (int)((SumT / NetMonthly) / 12);
	if (TotalMonth >= 12)
	{
		TotalMonth = (TotalMonth % 12) - 1;

	}


	while (Mflag != 0)
	{
		printf("\n");
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &Mselect);
		printf("\n");
		if (Mselect < 0 || Mselect >= 3)
		{
			printf("ERROR: Invalid menu selection.\n");
		}
		if (Mselect == 1)
		{
			printf("====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%.2lf\n", SumT);
			printf("Forecast: %d years, %d months\n", TotalYear, TotalMonth);
			if (onlyP[0].FinancialbyP[0] == 1 || onlyP[0].FinancialbyP[1] == 1 || onlyP[0].FinancialbyP[2] == 1)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");


			}
			printf("====================================================\n");

		}
		if (Mselect == 2)
		{
			printf("What priority do you want to filter by? [1-3]: ");
			scanf("%d", &Pselect);
			printf("\n");

			if (Pselect >= 0 || Pselect <= 4) {


				printf("====================================================\n");
				printf("Filter:   by priority (%d)\n", Pselect);
				printf("Amount:   $%.2lf\n", onlyP[Pselect - 1].CostbyP[Pselect - 1]);
				printf("Forecast: %d years, %d months\n", onlyP[Pselect - 1].YearbyP[Pselect - 1], onlyP[Pselect - 1].MonthbyP[Pselect - 1]);
				if (onlyP[Pselect - 1].FinancialbyP[Pselect - 1] == 1)
				{
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");

				}
				printf("====================================================\n");
				Mselect = 1;
			}
			else
			{
				printf(" ERROR: Invalid priority selection.");
			}
		}
		if (Mselect == 0)
		{
			printf("Best of luck in all your future endeavours!\n");
			Mflag = 0;
		}

	}

}
