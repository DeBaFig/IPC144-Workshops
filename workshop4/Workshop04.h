
#ifndef WORKSHOP4_H_
#define WORKSHOP4_H_

#define MAX_INCOME 400000.00
#define MIN_INCOME 500.00
#define MAX_ITENS 10

#include <stdio.h>

typedef struct
{
	double costs[100];
	int priority[100];
	char Foption[100];
	int Foption1and0[100];
}Wish;
typedef struct
{
	double CostbyP[100];
	int YearbyP[100];
	int MonthbyP[100];
	int FinancialbyP[100];
}Plist;

void wishList(void);

#endif
