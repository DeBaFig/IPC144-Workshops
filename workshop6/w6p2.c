

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM_PRODUCTS 3
#define SERVING 64

#include <stdio.h>
#include "w6p2.h" 

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* PNumber) {
	if (PNumber > 0) {
		*PNumber = askINTnumber();
		return *PNumber;
	}
	else
		return askINTnumber();
}
int askINTnumber(void)
{
	int positive = 0, value[MAX_NUM_PRODUCTS] = { 0 }, a = 0;
	while (value[a] <= 0)
	{
		scanf("%d", &value[a]);
		if (value[a] > 0)
		{
			positive = value[a];
			return positive;
		}
		else
		{
			printf("ERROR: Enter a positive value: ");
		}
		a++;
	}
	return positive;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* DoublePositive) {
	if (DoublePositive > 0)
	{
		*DoublePositive = askDnumber();
		return *DoublePositive;
	}
	else
	{
		return askDnumber();
	}

}
double askDnumber(void)
{
	int a = 0;
	double value[MAX_NUM_PRODUCTS] = { 0.0 }, PositiveD = 0.0;
	while (value[a] <= 0)
	{
		scanf("%lf", &value[a]);
		if (value[a] > 0)
		{
			PositiveD = value[a];
			return PositiveD;
		}
		else
		{
			printf("ERROR: Enter a positive value: ");
		}
		a++;
	}
	return PositiveD;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(void) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_NUM_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n", SERVING);
	printf("\n");

}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int NumberOfItens) {
	struct CatFoodInfo Item, * ItemP;
	ItemP = &Item;
	printf("Cat Food Product #%d\n", NumberOfItens + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	ItemP->skuID = getIntPositive(NULL);
	printf("PRICE         : $");
	ItemP->prices = getDoublePositive(NULL);
	printf("WEIGHT (LBS)  : ");
	ItemP->weight_lbs = getDoublePositive(NULL);
	printf("CALORIES/SERV.: ");
	ItemP->calories = getIntPositive(NULL);
	printf("\n");
	return *ItemP;
}
// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(struct CatFoodInfo Itens) {
	printf("%07d %10.2lf %10.1lf %8d\n", Itens.skuID, Itens.prices, Itens.weight_lbs, Itens.calories);
}



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* poundsTOkg, double* ResultConvertion)
{
	double Result = 0;
	if (ResultConvertion > 0)
	{
		*ResultConvertion = *poundsTOkg / 2.20462;
		return *ResultConvertion;
	}
	else
	{
		Result = *poundsTOkg / 2.20462;
		return Result;
	}

}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* poundsTOg, int* ResultConvertionGrams)
{
	if (ResultConvertionGrams > 0)
	{
		*ResultConvertionGrams = convertLbsKg(poundsTOg, NULL) * 1000;
		return *ResultConvertionGrams;
	}
	else
		return convertLbsKg(poundsTOg, NULL) * 1000;
}

// 10. convert lbs: kg and g
void convertLbs(const double* Lbs, double* KG, int* G)
{
	*KG = convertLbsKg(Lbs, NULL);
	*G = convertLbsG(Lbs, NULL);
}

// 11. calculate: servings based on gPerServ
double calculateServings(int sevingGramsperPortion, const int TOTALGramsProduct, double* NumServing)
{
	if (NumServing > 0)
	{
		*NumServing = TOTALGramsProduct / (double)sevingGramsperPortion;
		return* NumServing;
	}
	else
		return  TOTALGramsProduct / sevingGramsperPortion;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double ProductPrice, const double TotalServings, double* COSTserving)
{
	if (COSTserving > 0)
	{
		*COSTserving = ProductPrice / TotalServings;
		return* COSTserving;
	}

	else
		return  ProductPrice / TotalServings;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double PricePerServings, const double Calories, double* COSTcalories)
{
	if (COSTcalories > 0)
	{	
		*COSTcalories = PricePerServings / Calories;
		return* COSTcalories;
	}
	else
		return PricePerServings / Calories;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo ItemProduct)
{
	struct ReportData S, * Sp;
	Sp = &S;
	Sp->skuID = ItemProduct.skuID;
	Sp->prices = ItemProduct.prices;
	Sp->weight_lbs = ItemProduct.weight_lbs;
	Sp->calories = ItemProduct.calories;
	convertLbsKg(&ItemProduct.weight_lbs, &Sp->weight_kg);
	convertLbsG(&ItemProduct.weight_lbs, &Sp->weight_g);
	calculateServings(SERVING, Sp->weight_g, &Sp->TotalServings);
	calculateCostPerServing(ItemProduct.prices, Sp->TotalServings, &Sp->CostperServing);
	calculateCostPerCal(Sp->CostperServing, ItemProduct.calories, &Sp->CostperCalories);

	return *Sp;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData DisplayData, const int CheapProduct)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", DisplayData.skuID, DisplayData.prices, DisplayData.weight_lbs, DisplayData.weight_kg, DisplayData.weight_g, DisplayData.calories, DisplayData.TotalServings, DisplayData.CostperServing, DisplayData.CostperCalories);
	if (CheapProduct == 1)
		printf(" ***\n");
	else
		printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct ReportData DisplayData)
{
	printf("\n");
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", DisplayData.skuID, DisplayData.prices);
	printf("\n");
	printf("Happy shopping!\n");

}//----------------------------------------------------------------------------


// 7. Logic entry point
void start(void)
{

	struct CatFoodInfo Items[MAX_NUM_PRODUCTS];
	struct ReportData Data[MAX_NUM_PRODUCTS];
	int a = 0, CheapIndex = 0, end =1;
	double small = 0;
	while (end != 0) {
		openingMessage();
		for (a = 0; a < MAX_NUM_PRODUCTS; a++)
			Items[a] = getCatFoodInfo(a);
		displayCatFoodHeader();
		for (a = 0; a < MAX_NUM_PRODUCTS; a++)
			displayCatFoodData(Items[a]);
		for (a = 0; a < MAX_NUM_PRODUCTS; a++)
			Data[a] = calculateReportData(Items[a]);
		printf("\n");
		displayReportHeader();
		for (a = 0; a < MAX_NUM_PRODUCTS; a++)
			Data[a] = calculateReportData(Items[a]);
		small = Data[0].CostperServing;
		for (a = 0; a < MAX_NUM_PRODUCTS; a++)
		{
			if (Data[a].CostperServing < small)
			{
				small = Data[a].CostperServing;
				CheapIndex = a;
			}
		}
		for (a = 0; a < MAX_NUM_PRODUCTS; a++)
		{
			if (CheapIndex == a)
				displayReportData(Data[a], 1);
			else
				displayReportData(Data[a], 0);
		}
		displayFinalAnalysis(Data[CheapIndex]);

		printf("Would you like to do other comparison? (0 = exit)");
		scanf("%d", &end);
	}
	

}
