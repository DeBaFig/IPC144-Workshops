
#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM_PRODUCTS 3
#define SERVING 64

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
	int skuID;
	double prices;
	double weight_lbs;
	int calories;
}Items, * ItemsP;

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
}Data,* DataP;

// ----------------------------------------------------------------------------
// function prototypes


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* PNumber);
int askINTnumber(void);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* DoublePositive);
double askDnumber(void);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int NumberOfItens);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData(struct CatFoodInfo Itens);




// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* poundsTOkg, double* ResultConvertion);

// 9. convert lbs: g
int convertLbsG(const double* poundsTOg, int* ResultConvertion);

// 10. convert lbs: kg / g
void convertLbs(const double* Lbs, double* KG, int* G);

// 11. calculate: servings based on gPerServ
double calculateServings(int sevingGramsperPortion, const int TOTALGramsProduct, double* NumServing);

// 12. calculate: cost per serving
double calculateCostPerServing(const double ProductPrice, const double TotalServings, double* COSTserving);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double PricePerServings, const double Calories, double* COSTcalories);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo ItemProduct);

//14.5 find the cheapest product
int CheaspestProduct(int* CheapIndexResult);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData DisplayData, const int CheapProduct);

// 17. Display the findings (cheapest)

void displayReportData(const struct ReportData DisplayData, const int CheapProduct);
// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);