

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "commonHelpers.h"
#include "account.h"  
#include  "accountTicketingUI.h"
#include "ticket.h"

//function provide for me
//1. Get the current 4 digit year from the system
int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

//2. Empty the standard input buffer
void clearStandardInputBuffer(void)
{
	while (getchar() != '\n');
}

//3. get a valid integer from the keyboard, and display an error if an invalid value is entered
int getInteger(void)
{
	int num;
	char line;
	scanf("%d%c", &num, &line);
	while (line != '\n')
	{
		printf("ERROR: Value must be an integer: ");
		clearStandardInputBuffer();
		scanf("%d%c", &num, &line);
	}
	return num;
}

//4. get a valid integer and validate if the number if more then 0, and display an erro if an invalid value is entered
int getPositiveInteger(void)
{
	int a = -1;
	while (a < 0)
	{
		a = getInteger();
		if (a < 0)
			printf("ERROR: Value must be positive or zero: ");
	}
	return a;
}

//5. get a valid double and return in the funtion, if an invalid number was typed an erro will be displayed
double getDouble(void)
{
	double num;
	char line;
	scanf("%lf%c", &num, &line);
	while (line != '\n')
	{
		printf("ERROR: Value must be a double floating-point number: ");
		clearStandardInputBuffer();
		scanf("%lf%c", &num, &line);
	}
	return num;
}

//6.get a valid double from the  and return in the funtion, if an invalid number was typed an erro will be displayed
double getPositiveDouble(void)
{
	double a = 0;
	while (a <= 0)
	{
		a = getDouble();
		if (a <= 0)
			printf("ERROR: Value must be a positive double floating-point number: ");
	}
	return a;
}

//7. Get the argument 1 and set as a min value to a integer and argument 2 max value to a integer return the number if the input is correct, else show a error messenge
int getIntFromRange(int lowerNumber, int highestNumber)
{
	int num = getInteger();
	while (!(num >= lowerNumber && num <= highestNumber))
	{
		printf("ERROR: Value must be between %d and %d inclusive: ", lowerNumber, highestNumber);
		fflush(stdin);
		num = getInteger();
	}
	return num;
}

//8. Return a single valid char value and receives one argument which is the strig with the valid options to type 
char getCharOption(char* ArrayofvalidArgument)
{
	char letter = '0';
	int a, valid = 0;
	scanf("%c%*c", &letter);
	while (valid != 1)
	{
		for (a = 0; ArrayofvalidArgument[a] != '\0'; a++)
		{
			if (letter == ArrayofvalidArgument[a]) {
				return letter;
				valid = 1;
			}
		}
		printf("ERROR: Character must be one of [%s]: ", ArrayofvalidArgument);
		fflush(stdin);
		scanf("%c%*c", &letter);
	}
	return letter;
}

//9. obtain the user input for a String with the number max and min of chars allowed
void getCString(char* Cstring, int min_NumberChar, int max_NumberChar)
{
	int valid = 0;
	char line = 'x';
	fflush(stdin);
	scanf("%[^\n]%c", Cstring, &line);
	while (valid == 0 || line != '\n')
	{
		if ((strlen(Cstring) < min_NumberChar || strlen(Cstring) > max_NumberChar) && strlen(Cstring) != 0 )
		{
			if (min_NumberChar == max_NumberChar)
				printf("ERROR: String length must be exactly %d chars: ", max_NumberChar);
			else
			{
				if (strlen(Cstring) > max_NumberChar)
					printf("ERROR: String length must be no more than %d chars: ", max_NumberChar);
				if (strlen(Cstring) < min_NumberChar)
					printf("ERROR: String length must be between %d and %d chars: ", min_NumberChar, max_NumberChar);
			}
			fflush(stdin);
			scanf("%[^\n]%c", Cstring, &line);

		}
		else
			valid = 1;
	}
}

//10. printchar to print the lines
void printChar(char simbol, int xTimes) {
	int a;
	for (a = 0; a < xTimes; a++)
		printf("%c", simbol);
	printf("\n");
}
