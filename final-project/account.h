#include "ticket.h"

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#define _CRT_SECURE_NO_WARNINGS

#define MAX_PASSWORD 9
#define MAX_LOGIN_NAME 11
#define MAX_DISPLAY_NAME 31
#define MAX_DISPLAY_COUNTRY 31
#define MAX_AGE 110
#define MIN_AGE 18
#define INIT_DATA_SIZE 5

struct Demographic
{
	int BdayDate;
	double HouseIncome;
	char CountryName[MAX_DISPLAY_COUNTRY];
};

struct UserLogin
{
	char Name[MAX_DISPLAY_NAME];
	char LoginName[MAX_LOGIN_NAME];
	char Password[MAX_PASSWORD];
};

struct Account
{
	int NumCustomer;
	char AccountType;
	struct UserLogin User;
	struct Demographic Demo;
};


//1.Funtion Account type to get the data
//int NumCustomer; number must be a valid Int
//char AccountType; type must be only A or C which A means Agent And C Customer
struct Account GetAccount(struct Account account[], int FreeIndex, int NewAccNum);

//2. Function User Login type to get the Login information
//char LoginName[10];   must have only 10 chars
//char Name[30];  Name of that user must have max 30 char
//char Password[8];  should have ->exactly<- 8 chars
struct UserLogin GetUserLogin(struct Account account[], int FreeIndex);

//03. Function Demographic type
// int BdayDate; age between 18 and 110 (update ever year INPUT: Birth Year
// 	double HouseIncome; a valid positive double floating-point number
// char CountryName[30];  Country name
struct Demographic GetDemographic(struct Account account[], int FreeIndex);


//4.display the update menu option for account until the user whishes to exit
//print at top the number of account and 40 - to separate
//alow modify the 3 parts of user login demografic and account type
//ATENTION: DO NOT CALL THE AGENT MENU TO LEAVE BACK TO MENU AGENT
void updateAccount(struct Account ArrayofData[], int changeIndex);

//5. display's the name, 
//ID member is not modifiable
void updateUserLogin(struct Account ArrayofData[], int changeIndex);

//6.can change the value of household income and country
//NO CALL THE UPDATE ACCOUNT FUNCTION WHEN EXIT
void updateDemographic(struct Account ArrayofData[], int changeIndex);


//7. will select the right number to save the data in get acc base in the next increment of the hightes number found
int NewAccountNumber(const struct AccountTicketingData data);


//8.this function will get the array of characters and verify if there is enogh repetitions base on 3th argument
int CheckIfThereis(char* StringofCHARSTOcompare, char* StringOriginal, int MinRepetition);

//9. Get password with security options
void GetPasswordWithSecurity(struct Account* DataofPassaport);

//10.Function to check the login with security
//three informations must be equal to data base and there is a count to check the attempts
int LoginwithSecurity(const struct AccountTicketingData* data);

//11.Function to open the Account.txt and send to the pointers the information of the accounts
int loadAccounts(struct Account Account_data[], int ACCOUNT_SIZE);

//12.Function to open the Accounts_arc and count how many achievied accounts thare are
int loadAccountsArc(void);


//13.Replace the old file with a updated data
int saveAcc(struct Account DataAcc[], int MaxAccNumber);


//14. This function will add the account that will be deleated in the file account_arc
void appendAcc(struct Account DeletedAcc, char* filename);

#endif