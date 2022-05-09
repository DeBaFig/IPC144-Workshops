#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "commonHelpers.h"
#include "account.h"  
#include "accountTicketingUI.h"
#include "ticket.h"



//1.Funtion Account type to get the data
//int NumCustomer; number must be a valid Int
//char AccountType; type must be only A or C which A means Agent And C Customer
struct Account GetAccount(struct Account account[], int FreeIndex, int NewAccNum)
{
	printf("New Account Data (Account#:%05d)\n", NewAccNum);
	printChar('-', 40);
	account[FreeIndex].NumCustomer = NewAccNum;
	fflush(stdin);
	printf("Enter the account type (A=Agent | C=Customer): ");
	account[FreeIndex].AccountType = getCharOption("AC");
	printf("\n");
	GetUserLogin(account, FreeIndex);
	GetDemographic(account, FreeIndex);
	return account[FreeIndex];
}


//2. Function User Login type to get the Login information
//char LoginName[10];   must have only 10 chars
//char Name[30];  Name of that user must have max 30 char
//char Password[8];  should have ->exactly<- 8 chars
struct UserLogin GetUserLogin(struct Account account[], int FreeIndex)
{
	char buffer[MAX_DISPLAY_NAME*2];
	int valid = 0;
	printf("User Login Data Input\n");
	printChar('-', 40);
	//check if there is white space in login
	while (valid == 0)
	{
		printf("Enter user login (%d chars max): ", (MAX_LOGIN_NAME - 1));
		getCString(buffer, 2, (MAX_LOGIN_NAME - 1));
		valid = CheckIfThereis(" ", buffer, 0);
		if (valid == 0) {
			printf("ERROR:  The user login must NOT contain whitespace characters.\n");
		}
	}
	strcpy(account[FreeIndex].User.LoginName, buffer);
	printf("Enter the display name (%d chars max): ", (MAX_DISPLAY_NAME - 1));
	getCString(buffer, 2, (MAX_DISPLAY_NAME - 1));
	strcpy(account[FreeIndex].User.Name, buffer);
	fflush(stdin);
	GetPasswordWithSecurity(&account[FreeIndex]);
	//strcpy(account[FreeIndex].User.Password, buffer);
	printf("\n");
	return account[FreeIndex].User;

}

//03. Function Demographic type
// int BdayDate; age between 18 and 110 (update ever year INPUT: Birth Year
// 	double HouseIncome; a valid positive double floating-point number
// char CountryName[30];  Country name
struct Demographic GetDemographic(struct Account account[], int FreeIndex)
{
	char buffer[MAX_DISPLAY_NAME * 2];
	int a;
	printf("Demographic Data Input\n");
	printChar('-', 40);
	//clearStandardInputBuffer();
	int MinAge = currentYear() - MAX_AGE, MaxAge = currentYear() - MIN_AGE;
	printf("Enter birth year (current age must be between %d and %d): ", MIN_AGE, MAX_AGE);
	account[FreeIndex].Demo.BdayDate = getIntFromRange(MinAge, MaxAge);
	printf("Enter the household Income: $");
	account[FreeIndex].Demo.HouseIncome = getPositiveDouble();
	printf("Enter the country (%d chars max.): ", (MAX_DISPLAY_COUNTRY - 1));
	getCString(buffer, 1, MAX_DISPLAY_COUNTRY-1);
	//convert the result in UPPERCASE:
	strcpy(account[FreeIndex].Demo.CountryName, buffer);
	for (a = 0; a < strlen(account[FreeIndex].Demo.CountryName); a++) {
		account[FreeIndex].Demo.CountryName[a] = toupper(account[FreeIndex].Demo.CountryName[a]);
		//printf("%c\n",toupper(account[FreeIndex].Demo.CountryName[a]) );
		//printf("%s\n",account[FreeIndex].Demo.CountryName);

	}
	//strcpy(account[FreeIndex].Demo.CountryName, buffer);
	printf("\n");
	return account[FreeIndex].Demo;
}


//4.display the update menu option for account until the user whishes to exit
//print at top the number of account and 40 - to separate
//alow modify the 3 parts of user login demografic and account type
//ATENTION: DO NOT CALL THE AGENT MENU TO LEAVE BACK TO MENU AGENT
void updateAccount(struct Account ArrayofData[], int changeIndex)
{
	printf("Enter the account type (A=Agent | C=Customer): ");
	ArrayofData[changeIndex].AccountType = getCharOption("AC");
}

//5. display's the name, 
//ID member is not modifiable
void updateUserLogin(struct Account ArrayofData[], int changeIndex)
{
	int selection = 0, done = 1;
	while (done == 1)
	{
		int flag = 0;
		printf("User Login: %s - Update Options\n", ArrayofData[changeIndex].User.LoginName);
		printChar('-', 40);
		printf("1) Display name (current value: %s)\n", ArrayofData[changeIndex].User.Name);
		printf("2) Password\n"
			"0) Done\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 2);
		printf("\n");
		while (flag == 0)
		{
			switch (selection)
			{
			case 1:
				printf("Enter the display name (%d chars max): ", (MAX_DISPLAY_NAME - 1));
				getCString(ArrayofData[changeIndex].User.Name, 1, (MAX_DISPLAY_NAME - 1));
				printf("\n");
				break;
			case 2:
				GetPasswordWithSecurity(&ArrayofData[changeIndex]);
				printf("\n");
				break;
			case 0:
				done = 0;
				break;
			}
			flag = 1;
		}
	}
}

//6.can change the value of household income and country
//NO CALL THE UPDATE ACCOUNT FUNCTION WHEN EXIT
void updateDemographic(struct Account ArrayofData[], int changeIndex)
{
	int selection = 0, done = 1;
	while (done == 1)
	{
		int flag = 0, a;

		printf("Demographic Update Options\n");
		printChar('-', 40);
		printf("1) Household Income (current value: $%.2lf)\n", ArrayofData[changeIndex].Demo.HouseIncome);
		printf("2) Country (current value: %s)\n"
			"0) Done\n", ArrayofData[changeIndex].Demo.CountryName);
		printf("Selection: ");
		selection = getIntFromRange(0, 2);
		printf("\n");
		while (flag == 0)
		{
			switch (selection)
			{
			case 1:
				//printf("\n");
				printf("Enter the household Income: $");
				ArrayofData[changeIndex].Demo.HouseIncome = getPositiveDouble();
				printf("\n");
				break;
			case 2:

				printf("Enter the country (%d chars max.): ", (MAX_DISPLAY_COUNTRY - 1));
				getCString(ArrayofData[changeIndex].Demo.CountryName, 1, MAX_DISPLAY_COUNTRY);
				for (a = 0; a < strlen(ArrayofData[changeIndex].Demo.CountryName); a++) {
					ArrayofData[changeIndex].Demo.CountryName[a] = toupper(ArrayofData[changeIndex].Demo.CountryName[a]);
				}
				printf("\n");
				break;
			case 0:
				done = 0;
				break;
			}
			flag = 1;

		}

	}
}

//7. will select the right number to save the data in get acc base in the next increment of the hightes number found
int NewAccountNumber(const struct AccountTicketingData data) {
	int  a = 0, highestID = data.accounts[a].NumCustomer;
	for (a = 0; a < data.ACCOUNT_MAX_SIZE; a++) {
		if (highestID < data.accounts[a].NumCustomer)
			highestID = data.accounts[a].NumCustomer;
	}
	return highestID + 1;
}

// 8.this function will get the array of characters and verify if there is enogh repetitions base on 3th argument
int CheckIfThereis(char* StringofCHARSTOcompare, char* StringOriginal, int MinRepetition) {
	int a, b, ok = 1, repetion = 0;
	for (a = 0; a < (strlen(StringofCHARSTOcompare)); a++)
	{
		for (b = 0; b <= (strlen(StringOriginal)); b++) {
			if (StringOriginal[b] == StringofCHARSTOcompare[a])
				repetion++;
		}
	}
	if (MinRepetition == repetion)
		ok = 1;
	else
		ok = 0;

	return ok;

}

//9. function to check security rules created 2 lower case 2 upcase 2 symbols and 2 digits
int SecurityRUles(char* StringOriginal, int MinRepetition) {
	int CheckSymbol = CheckIfThereis("!@#$%^&*", StringOriginal, 2);
	int   CheckDigit = CheckIfThereis("0123456789", StringOriginal, 2);
	int  CheckUPcase, CheckLOWcase, a, repetition = 0, repetition2 = 0;
	//printf("Check symbol: %d\n", CheckSymbol);
	//printf("Check digit %d\n", CheckDigit);

	//check if there are two LOWERCASE
	for (a = 0; a < strlen(StringOriginal); a++) {
		if (islower(StringOriginal[a]))
			repetition++;
	}
	if (MinRepetition == repetition)
		CheckLOWcase = 1;
	else
		CheckLOWcase = 0;
	//check if there are two UPPERCASE
	//printf("strlen: %zu\n", strlen(StringOriginal));

	for (a = 0; a < strlen(StringOriginal); a++) {
		if (isupper(StringOriginal[a]))
			repetition2++;
		//printf("string char a:%d %c\n", a, StringOriginal[a]);
		//printf("is upper? a:%d %d\n", a, isupper(StringOriginal[a]));

	}
	if (MinRepetition == repetition2)
		CheckUPcase = 1;
	else
		CheckUPcase = 0;
	//printf("Up case %d\n", CheckUPcase);
	//printf("lower case %d\n", CheckLOWcase);

	//conclusion if all requirement were fulfull
	if (CheckSymbol == 1 && CheckDigit == 1 && CheckUPcase == 1 && CheckLOWcase == 1)
		return 1;
	else
		return 0;
}

//9. Get password with security options
void GetPasswordWithSecurity(struct Account* DataofPassaport) {
	int valid = 0;
	char symbol[] = "!@#$%^&*";
	//check if there is 2 special characters 2 lower case, 2 uppercase and 2 numbers
	while (valid == 0)
	{
		printf("Enter the password (must be %d chars in length): ", (MAX_PASSWORD - 1));
		getCString(DataofPassaport->User.Password, (MAX_PASSWORD - 1), (MAX_PASSWORD - 1));
		valid = SecurityRUles(DataofPassaport->User.Password, 2);
		if (valid == 0) {
			printf("SECURITY: Password must contain 2 of each:\n"
				"          Digit: 0-9\n"
				"          UPPERCASE character\n"
				"          lowercase character\n"
				"          symbol character: %s\n", symbol

			);
		}
	}
}

//10.Function to check the login with security
//three informations must be equal to data base and there is a count to check the attempts
int LoginwithSecurity(const struct AccountTicketingData* data) {
	int index = -1, TempAcc = 0, CheckLogin = 0, CheckPassword = 0, Attempt = 3;
	char Login[MAX_LOGIN_NAME], Password[MAX_PASSWORD], LoginTemp[30], PasswordTemp[30];
	while (Attempt != 0) {
		printf("Enter the account#: ");
		TempAcc = getInteger();
		index = findAccountIndexByAcctNum(0, data, TempAcc);
		strcpy(Login, data->accounts[index].User.LoginName);
		strcpy(Password, data->accounts[index].User.Password);
		printf("User Login    : ");
		scanf("%[^\n]s%*c", LoginTemp);
		printf("Password      : ");
		clearStandardInputBuffer();
		scanf("%[^\n]s%*c", PasswordTemp);
		CheckLogin = strcmp(Login, LoginTemp);
		CheckPassword = strcmp(Password, PasswordTemp);
		if (CheckLogin != 0 || CheckPassword != 0) {
			Attempt--;
			printf("INVALID user login/password combination! [attempts remaining:%d]\n\n", Attempt);
		}
		else {
			return index;
		}
	}
	if (Attempt == 0) {
		printf("ERROR:  Login failed!\n\n");
		pauseExecution();
		printf("\n");
	}
	return -1;
}

//11.Function to open the Account.txt and send to the pointers the information of the accounts
int loadAccounts(struct Account Account_data[], int ACCOUNT_SIZE) {
	int a = 0, flag = 1;
	FILE* fp = fopen("accounts.txt", "r");
	if (fp != NULL) {
		while (a <= ACCOUNT_SIZE && flag == 1)
		{
			fscanf(fp, "%d~%c~%[^~]~%[^~]~%[^~]~%d~%lf~%[^\n]", &Account_data[a].NumCustomer, &Account_data[a].AccountType, Account_data[a].User.Name, Account_data[a].User.LoginName, Account_data[a].User.Password, &Account_data[a].Demo.BdayDate, &Account_data[a].Demo.HouseIncome, Account_data[a].Demo.CountryName);
			if (Account_data[a].NumCustomer != 0)
				a++;
			else
				flag = 0;
		}
		fclose(fp);
		fp = NULL;
	}
	else
	{
		printf("Testando\n");
	}
	return a-1;
}

//12.Function to open the Accounts_arc and count how many achievied accounts thare are
int loadAccountsArc(void) {
	int a = 0, flag = 1, buffer = 0;
	char ch[MAX_DISPLAY_NAME + MAX_LOGIN_NAME + MAX_DISPLAY_COUNTRY + MAX_PASSWORD + MAX_SUBJECT];
	FILE* fp = fopen("accounts_arc.txt", "r");
	if (fp != NULL) {
		while (flag == 1)
		{
			fscanf(fp, "%d~%[^\n]", &buffer, &ch[0]);
			if (buffer != 0) {
				a++;
				buffer = 0;
			}
			else {
				fclose(fp);
				fp = NULL;
				flag = 0;
			}

		}
	}
	else
	{
		printf("Testando\n");
	}
	printf("There are %d account(s) currently archived.\n\n", a);
	return a;
}

//13.Replace the old file with a updated data
int saveAcc(struct Account DataAcc[], int MaxAccNumber) {
	int a = 0, Updates = 0;
	FILE* fp = fopen("accounts.txt", "w");
	if (fp != NULL) {
		for (a = 0; a < MaxAccNumber; a++) {
			if (DataAcc[a].NumCustomer != 0) {
				fprintf(fp, "%d~%c~%s~%s~%s~%d~%.2lf~%s\n", DataAcc[a].NumCustomer, DataAcc[a].AccountType, DataAcc[a].User.Name, DataAcc[a].User.LoginName, DataAcc[a].User.Password, DataAcc[a].Demo.BdayDate, DataAcc[a].Demo.HouseIncome, DataAcc[a].Demo.CountryName);
				Updates++;
				//printf("%d~%c~%s~%s~%s~%d~%.2lf~%s\n", DataAcc[a].NumCustomer, DataAcc[a].AccountType, DataAcc[a].User.Name, DataAcc[a].User.LoginName, DataAcc[a].User.Password, DataAcc[a].Demo.BdayDate, DataAcc[a].Demo.HouseIncome, DataAcc[a].Demo.CountryName);
			}
		}
		fclose(fp);
		fp = NULL;
	}
	return Updates;
}

//14. This function will add the account that will be deleated in the file account_arc
void appendAcc(struct Account DeletedAcc, char* filename) {
	FILE* fp = fopen(filename, "a");
	if (fp != NULL) {
		fprintf(fp, "%d~%c~%s~%s~%s~%d~%.2lf~%s\n", DeletedAcc.NumCustomer, DeletedAcc.AccountType, DeletedAcc.User.Name, DeletedAcc.User.LoginName, DeletedAcc.User.Password, DeletedAcc.Demo.BdayDate, DeletedAcc.Demo.HouseIncome, DeletedAcc.Demo.CountryName);
	}
	fclose(fp);
	fp = NULL;
}
