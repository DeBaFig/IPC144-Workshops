#ifndef WORKSHOP6_H_
#define WORKSHOP6_H_

#include <stdio.h>

#define MAX_NUM_PRODUCTS 3
#define SERVING 64


struct CatFoodInfo
{
	int skuID;
	double prices;
	double weight_lbs;
	int calories;
};

struct ReportData
{
	int skuID;
	double prices;
	int calories;
	double weight_lbs;
	double weight_kg;
	int weight_g;
	double TotalServings;
	double CostperCalories;
	double CostperServing;
};


int getIntPositive(int* PNumber);
int askINTnumber(void);

double getDoublePositive(double* DoublePositive);
double askDnumber(void);

void openingMessage(void);

struct CatFoodInfo getCatFoodInfo(int NumberOfItens);

void displayCatFoodHeader(void);

void displayCatFoodData(struct CatFoodInfo Itens);

double convertLbsKg(const double* poundsTOkg, double* ResultConvertion);

int convertLbsG(const double* poundsTOg, int* ResultConvertion);

void convertLbs(const double* Lbs, double* KG, int* G);

double calculateServings(int sevingGramsperPortion, const int TOTALGramsProduct, double* NumServing);

double calculateCostPerServing(const double ProductPrice, const double TotalServings, double* COSTserving);

double calculateCostPerCal(const double PricePerServings, const double Calories, double* COSTcalories);

struct ReportData calculateReportData(const struct CatFoodInfo ItemProduct);

int CheaspestProduct(int* CheapIndexResult);

void displayReportHeader(void);

void displayReportData(const struct ReportData DisplayData, const int CheapProduct);


void displayReportData(const struct ReportData DisplayData, const int CheapProduct);
// ----------------------------------------------------------------------------

void foodCost_main(void);

#endif