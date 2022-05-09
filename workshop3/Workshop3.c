
#define _CRT_SECURE_NO_WARNINGS
#include "Workshop3.h"

void wellBeing_main(void)
{
	int const JAN = 1, DEC = 12;
	int month = 0, year = 0, KeepGoing = 1, day = 1, i, tryagainM = 0, tryagainE = 0, end = 1;
	double morning_rate, evening_rate, sum_M = 0, sum_E = 0;
	printf("General Well-being Log\n");
	printf("======================\n");

	while (end != 0) {
		while (KeepGoing == 1)
		{
			printf("Set the year and month for the well-being log (YYYY MM): ");
			scanf("%d %d", &year, &month);

			if (year < MIN_YEAR || year > MAX_YEAR)
			{
				printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR , MAX_YEAR);
			}
			if (month < JAN || month > DEC)
			{
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
			}
			if ((year >= MIN_YEAR && year <= MAX_YEAR && month >= JAN) && month <= DEC)
			{

				printf("\n");
				printf("*** Log date set! ***\n");

				KeepGoing = 0;
			}
		}
		if (KeepGoing == 0)
		{
			for (i = 1; i <= LOG_DAYS; i++)
			{
				printf("\n");
				if (i <= LOG_DAYS) {
					tryagainM = 0;
					tryagainE = 0;
					if (LOG_DAYS > 28)
					{
						if (month == 1 && day >= 32) {
							month = 2;
							day = 1;
						}
						if (month == 2 && day >= 29) {
							month = 3;
							day = 1;
						}
						if (month == 3 && day >= 32) {
							month = 4;
							day = 1;
						}
						if (month == 4 && day >= 32) {
							month = 5;
							day = 1;
						}
						if (month == 5 && day >= 32) {
							month = 6;
							day = 1;
						}
						if (month == 6 && day >= 31) {
							month = 7;
							day = 1;
						}
						if (month == 7 && day >= 32) {
							month = 4;
							day = 1;
						}
						if (month == 8 && day >= 32) {
							month = 4;
							day = 1;
						}
						if (month == 9 && day >= 31) {
							month = 4;
							day = 1;
						}
						if (month == 10 && day >= 32) {
							month = 4;
							day = 1;
						}
						if (month == 11 && day >= 31) {
							month = 4;
							day = 1;
						}
						if (month == 12 && day >= 32) {
							month = 1;
							day = 1;
							year++;
						}

					}
				}

				printf("%d-", year);
				if (month == 1)
					printf("JAN-%02d\n", day);
				if (month == 2)
					printf("FEB-%02d\n", day);
				if (month == 3)
					printf("MAR-%02d\n", day);
				if (month == 4)
					printf("APR-%02d\n", day);
				if (month == 5)
					printf("MAY-%02d\n", day);
				if (month == 6)
					printf("JUN-%02d\n", day);
				if (month == 7)
					printf("JUL-%02d\n", day);
				if (month == 8)
					printf("AUG-%02d\n", day);
				if (month == 9)
					printf("SET-%02d\n", day);
				if (month == 10)
					printf("OCT-%02d\n", day);
				if (month == 11)
					printf("NOV-%02d\n", day);
				if (month == 12)
					printf("DEC-%02d\n", day);

				while (tryagainM == 0)
				{
					printf("   Morning rating (0.0-5.0): ");
					scanf("%lf", &morning_rate);

					if (morning_rate < 0.0 || morning_rate > 5.0)
					{
						printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
					}
					else
					{
						tryagainM = 1;
						sum_M = morning_rate + sum_M;

					}

				}

				while (tryagainE == 0)
				{
					printf("   Evening rating (0.0-5.0): ");
					scanf("%lf", &evening_rate);

					if (evening_rate < 0.0 || evening_rate > 5.0)
					{
						printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
					}
					else
					{
						tryagainE = 1;

						sum_E = evening_rate + sum_E;
						day++;
					}

				}
			}
		}
		printf("\n");
		printf("Summary\n");
		printf("=======\n");
		printf("Morning total rating: %.3lf\n", sum_M);
		printf("Evening total rating: %.3lf\n", sum_E);
		printf("----------------------------\n");
		printf("Overall total rating: %.3lf\n", sum_E + sum_M);
		printf("\n");
		printf("Average morning rating:  %.1lf\n", sum_M / LOG_DAYS);
		printf("Average evening rating:  %.1lf\n", sum_E / LOG_DAYS);
		printf("----------------------------\n");
		printf("Average overall rating:  %.1lf\n", ((sum_E / LOG_DAYS) + (sum_M / LOG_DAYS)) / 2);
		printf("\n"); 
		
		printf("Are you done? 0 = Yes: ");
		scanf("%d", &end);

	}


}
