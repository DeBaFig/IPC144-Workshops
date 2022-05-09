// ===================================================================================
//
//  Assignment:  2
//  Milestone:   3
//  Description: Main logic/tester
//	Full Name: Denize Bassi Figueiredo
//	Student ID: 111288205
//	E-mail: dbassi-figueiredo@myseneca.ca
//	Section: ZDD
// +---------------------------------------------------------+

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "commonHelpers.h"
#include "account.h"  
#include "accountTicketingUI.h"
#include "ticket.h"



//1. funtion with the basic information about te account 
void displayAccountSummaryHeader(void)
{
	printf("Acct# Acct.Type Birth\n");
	printf("----- --------- -----\n");
}

//2.function that will display the summary record provide by user has as argument the struct account
void displayAccountSummaryRecord(const struct Account* data)
{
	int AgentResult = 0;
	if (data->AccountType == 'A')
	{
		AgentResult = 1;
	}
	printf("%05d %-9s %5d\n", data->NumCustomer, (AgentResult ? "AGENT" : "CUSTOMER"), data->Demo.BdayDate);
}

//3. Display the Account details  record with the password partially hidden with * 
void displayAccountDetailRecord(const struct Account* data)
{
	int AgentResult = 0;
	char hidePassword[MAX_PASSWORD] = { '\0' };
	if (data->AccountType == 'A')
	{
		AgentResult = 1;
	}
	hidethePassword(&data->User, hidePassword);
	printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s ", data->NumCustomer, (AgentResult ? "AGENT" : "CUSTOMER"), data->Demo.BdayDate, data->Demo.HouseIncome, data->Demo.CountryName, data->User.Name, data->User.LoginName);
	printf("%8s\n", hidePassword);

}

//4. display the head of Accound detail
void displayAccountDetailRecordHead(void)
{
	printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
	printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");
}

//5. Funtion to hide the password with * where should have one letter and then on *
//get the original string and do a for only with odd numbers to change to *
void hidethePassword(const struct UserLogin* data, char* hidePassword)
{
	int a;
	for (a = 0; a < MAX_PASSWORD - 1; a++)
	{
		if (a % 2 != 0)
			hidePassword[a] = 42;
		else
			hidePassword[a] = data->Password[a];
	}

}

//6. Application startup, Active the menu, if the logged is a Customer the app should display a specify message 
void applicationStartup(struct AccountTicketingData* data) {
	int index = -1;
	
	while (index == -1)
	{
		index = menuLogin(data);
		if (index != -1) {
			if (data->accounts[index].AccountType == 'C') {
				printf("\n");
				menuCustomer(data, index);
				index = -1;
			}
			else
			{
				printf("\n");
				menuAgent(data, index);
				index = -1;
			}
		}

	}


}

//7. Menu login
//first show the option to login the number to login should be the same register as acc number
// loop to compare the int typed and the data in the array, must return the index of user
int menuLogin(const struct AccountTicketingData* data) {
	int selection = 5, index = -1, flag = 0, cancel = 0;
	printChar('=', 46);
	printf("Account Ticketing System - Login\n");
	printChar('=', 46);
	printf("1) Login to the system\n");
	printf("0) Exit application\n");
	printChar('-', 46);
	printf("\n");
	printf("Selection: ");
	selection = getIntFromRange(0, 1);
	while (flag == 0)
	{
		switch (selection)
		{
		case 1:
			printf("\n");
			index = LoginwithSecurity(data);
			break;
		case 0:
			printf("\n");

			printf("Are you sure you want to exit? ([Y]es|[N]o): ");
			cancel = getCharOption("yYnN");
			printf("\n");
			if (cancel == 'Y' || cancel == 'y')
			{
				printChar('=', 46);
				printf("Account Ticketing System - Terminated\n");
				printChar('=', 46);
				printf("\n");
				exit(0);
			}
			
			break;
		}
		flag = 1;

	}

	return index;
}

//8.Display the agent main menu
//show the name and the number of the agent on the top
void menuAgent(struct AccountTicketingData* data, int indexOfLogin) {
	int selection = -1, flag = 0, logged = 1, UpdateACC = 0, UpdateTicket = 0, a = 0, count = 0;
	while (logged == 1)
	{
		int Freeindex = 0, TicketIndex = -3;
		int Changeindex = 0;
		flag = 0;
		int TicketManage = 0;
		printf("AGENT: %s (%d)\n", data->accounts[indexOfLogin].User.Name, data->accounts[indexOfLogin].NumCustomer);
		printChar('=', 46);
		printf("Account Ticketing System - Agent Menu\n");
		printChar('=', 46);
		printf(" 1) Add a new account\n"
			" 2) Modify an existing account\n"
			" 3) Remove an account\n"
			" 4) List accounts: summary view\n"
			" 5) List accounts: detailed view\n");
		printChar('-', 46);
		printf(" 6) List new tickets\n"
			" 7) List active tickets\n"
			" 8) List closed tickets\n"
			" 9) Manage a ticket\n"
			"10) Archive closed tickets\n");
		printChar('-', 46);
		printf("11) View archived account statistics\n"
			"12) View archived tickets statistics\n");
		printChar('-', 46);
		printf("0) Logout\n");
		putchar('\n');
		printf("Selection: ");
		selection = getIntFromRange(0, 12);
		printf("\n");
		while (flag == 0)
		{
			switch (selection)
			{
			case 1:
				Freeindex = emptyIndex(data);
				if (Freeindex != -1) {
					//GetAccount(data->accounts, Freeindex, NewAccountNumber(*data));
					saveAcc(data->accounts, data->ACCOUNT_MAX_SIZE);
					appendAcc(GetAccount(data->accounts, Freeindex, NewAccountNumber(*data)), "accounts.txt");
					printf("*** New account added! ***\n\n");
					//clearStandardInputBuffer();
				}
				pauseExecution();
				//printf("\n");
				break;
			case 2:
				printf("Enter the account#: ");
				Changeindex = findAccountIndexByAcctNum(0, data, 0);
				printf("\n");
				if (Changeindex != -1)
					menuUpdateOptions(data->accounts, Changeindex);
				break;
			case 3:
				removeaccount(data, data->accounts[indexOfLogin].NumCustomer);
				break;
			case 4:
				displayAllAccountSummaryRecords(data->accounts, data->ACCOUNT_MAX_SIZE);
				break;
			case 5:
				displayAllAccountDetailRecords(data->accounts, data->ACCOUNT_MAX_SIZE);
				break;
			case 6:
				while (TicketIndex != -2) {
					PrintTicketsAgent(data->tickets, 1, data->TICKET_MAX_SIZE, 1);
					TicketIndex = findTicketNumber(data->tickets, data->TICKET_MAX_SIZE, 0);
					if (TicketIndex >= 0)
						MessageTicketRead(data->tickets[TicketIndex]);

					if (TicketIndex != -2)
						pauseExecution();
				}
				printf("\n");
				break;
			case 7:
				while (TicketIndex != -2) {
					PrintTicketsAgent(data->tickets, 0, data->TICKET_MAX_SIZE, 1);
					TicketIndex = findTicketNumber(data->tickets, data->TICKET_MAX_SIZE, 0);
					if (TicketIndex >= 0) {
						MessageTicketRead(data->tickets[TicketIndex]);
					}

					if (TicketIndex != -2)
						pauseExecution();
				}
				printf("\n");
				break;
			case 8:
				while (TicketIndex != -2) {
					PrintTicketsAgent(data->tickets, 0, data->TICKET_MAX_SIZE, 0);
					TicketIndex = findTicketNumber(data->tickets, data->TICKET_MAX_SIZE, 0);
					if (TicketIndex >= 0) {
						MessageTicketRead(data->tickets[TicketIndex]);
					}

					if (TicketIndex != -2)
						pauseExecution();
				}
				printf("\n");
				break;
			case 9:
				printf("Enter ticket number: ");
				TicketManage = getPositiveInteger();
				printf("\n");
				TicketManage = findTicketNumber(data->tickets, data->TICKET_MAX_SIZE, TicketManage);
				if (TicketManage >= 0) {
					ModifyTicketAgentMenu(&data->tickets[TicketManage], data->accounts[indexOfLogin]);
				}
				if (TicketManage != -2)
				break;
			case 10:
				printf("Are you sure? This action cannot be reversed. ([Y]es|[N]o): ");
				selection = getCharOption("YN");
				if (selection == 'Y') {
					for (a = 0; a < data->TICKET_MAX_SIZE; a++) {
						if (data->tickets[a].Status == 0) {
							appendTicketArc(data->tickets[a]);
							data->tickets[a].TicketID = 0;
							count++;
						}

					}
					printf("\n*** %d tickets archived ***\n\n", count -1);
				}
				else {
					printf("No changes was made\n");
				}
				pauseExecution();
				break;
			case 11:
				loadAccountsArc();
				pauseExecution();
				break;
			case 12:
				loadTicketsArc();
				pauseExecution();
				break;
			case 0:
				UpdateACC = saveAcc(data->accounts, data->ACCOUNT_MAX_SIZE);
				UpdateTicket = saveTicket(data->tickets, data->TICKET_MAX_SIZE);
				printf("Saving session modifications...\n");
				printf("   %d account saved.\n", UpdateACC);
				printf("   %d tickets saved.\n", UpdateTicket);
				printf("### LOGGED OUT ###\n");
				printf("\n");
				logged = 0;
				break;
			}
			flag = 1;
		}
	}

}


//9. return an integer representing the array index of Account
// search the arg1 in the array of arg2
//if the arg4 =0 will use the arg1 to looking for the user
//if arg4 != 0 will appear a scanf to add a number to looking for
// return -1 if do not found a user or the index of array if found
int findAccountIndexByAcctNum(int NumberTypetoLookingFor, const struct AccountTicketingData* data, int zeroORnot) {
	int accountNumber = 0, a, index = -1;
	if (NumberTypetoLookingFor == 0 && zeroORnot == 0) {
		accountNumber = getPositiveInteger();
		for (a = 0; a < data->ACCOUNT_MAX_SIZE ; a++)
		{
			if (accountNumber == data->accounts[a].NumCustomer) {
				index = a;
				return index;
			}
		}
	}
	else
	{
		for (a = 0; a < data->ACCOUNT_MAX_SIZE; a++)
		{
			if (zeroORnot == data->accounts[a].NumCustomer) {
				index = a;
				return index;
			}
		}
		
	}
	return index;
}

//10.display the summary of all valids accounts(which is all than account number is greater than 0
void displayAllAccountSummaryRecords(const struct Account data[], int maxNumberofElements) {
	int i = 0;
	displayAccountSummaryHeader();
	while (i < maxNumberofElements)
	{
		if (data[i].NumCustomer != 0)
			displayAccountSummaryRecord(&data[i]);
		i++;
	}
	printf("\n");
	pauseExecution();
}

//11. display a detailed view of all valid account records(which is all than account number is greater than 0
void displayAllAccountDetailRecords(const struct Account data[], int maxNumberofElements) {
	int i = 0;
	displayAccountDetailRecordHead();
	while (i < maxNumberofElements)
	{
		if (data[i].NumCustomer != 0)
			displayAccountDetailRecord(&data[i]);

		i++;
	}
	printf("\n");
	pauseExecution();
}

//12. Function provided for me
//pause the application
void pauseExecution(void) {
	printf("<< ENTER key to Continue... >>");
	clearStandardInputBuffer();
	putchar('\n');
}

//13. loop to find an empyt acocunt to add info
int emptyIndex(const struct AccountTicketingData* data) {
	int i= 0;
	while (data->accounts[i].NumCustomer != 0 && i <= data->ACCOUNT_MAX_SIZE)
		i++;
	if (i >= data->ACCOUNT_MAX_SIZE) {
		printf("ERROR: Account listing is FULL, call ITS Support!\n\n");
		return -1;
	}
	else
		return i;

}

//14. Menu To update Options of accounts only on MenuAgent
void menuUpdateOptions(struct Account data[], int ChangeIndex) {
	int selection = 0, done = 1;
	while (done == 1) {
		int flag = 0;
		printf("Account: %05d - Update Options\n", data[ChangeIndex].NumCustomer);
		printChar('-', 40);
		printf("1) Update account type (current value: %c)\n", data[ChangeIndex].AccountType);
		printf("2) Login\n"
			"3) Demographics\n"
			"0) Done\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 3);
		printf("\n");
		while (flag == 0)
		{
			switch (selection)
			{
			case 1:
				updateAccount(data, ChangeIndex);
				//printf("\n");
				break;
			case 2:
				updateUserLogin(data, ChangeIndex);
				break;
			case 3:
				updateDemographic(data, ChangeIndex);
				break;
			case 0:
				done = 0;
				break;
			}
			flag = 1;
		}


	}
}

//15.delete the account puttin the number account = 0 but do not allow delete if you try delete the logged account
void removeaccount(struct AccountTicketingData* data, int currentLogin) {
	int delete = 0, current = 0, a;
	char final = 'x';

	printf("Enter the account#: ");
	current = findAccountIndexByAcctNum(0, data, currentLogin);
	delete = findAccountIndexByAcctNum(0, data, 0);
	if (delete == -1)
		printf("\nAccount not founded! \n\n");
	if (delete == current) {
		printf("\n");
		printf("ERROR: You can't remove your own account!\n");
		printf("\n");
		pauseExecution();
	}
	else
	{
		if (delete != -1) {
			displayAccountDetailRecordHead();
			displayAccountDetailRecord(&data->accounts[delete]);
			printf("\n");
			printf("Are you sure you want to remove this record? ([Y]es|[N]o): ");
			final = getCharOption("YN");
			printf("\n");
			if (final == 'Y' || final == 'y') {
				for (a = 0; a < data->TICKET_MAX_SIZE; a++) {
					if (data->tickets[a].CustomerAcc == data->accounts[delete].NumCustomer && data->tickets[a].TicketID > 0) {
						//appendTicketArc(data->tickets[a]);
						data->tickets[a].TicketID = 0;
					}
				}
				appendAcc(data->accounts[delete], "accounts_arc.txt");
				data->accounts[delete].NumCustomer = 0;
				printf("*** Account Removed! ***\n\n");
				pauseExecution();

			}
			else {
				printf("*** No changes made! ***\n\n");
				pauseExecution();
				printf("\n");


			}
		}
	}

}


//16.New menu customer (just alow see your own informations and created ticket
void menuCustomer(struct AccountTicketingData* data, int indexOfLogin) {
	int selection = -1, flag = 0, logged = 1, TicketIndex = -3, TicketNum =0, TicketIndexFree = -3, Updates=0;
	while (logged == 1)
	{
		TicketNum = 0;
		TicketIndexFree = -3;
		flag = 0;
		TicketIndex = -3;
		printf("CUSTOMER: %s (%d)\n", data->accounts[indexOfLogin].User.Name, data->accounts[indexOfLogin].NumCustomer);
		printChar('=', 46);
		printf("Customer Main Menu\n");
		printChar('=', 46);
		printf("1) View your account detail\n"
			"2) Create a new ticket\n"
			"3) Modify an active ticket\n"
			"4) List my tickets\n");
		printChar('-', 46);
		printf("0) Logout\n");
		putchar('\n');
		printf("Selection: ");
		selection = getIntFromRange(0, 4);
		printf("\n");
		while (flag == 0)
		{
			switch (selection)
			{
			case 1:
				displayAccountDetailRecordHead();
				displayAccountDetailRecord(&data->accounts[indexOfLogin]);
				printf("\n");
				pauseExecution();
				break;
			case 2:
				TicketNum = NewTicketNumber(data->tickets, data->TICKET_MAX_SIZE);
				TicketIndexFree = FreeIndexTicket(data->tickets, data->TICKET_MAX_SIZE);
				if (TicketIndexFree != -1) {
					data->tickets[TicketIndexFree].TicketID = TicketNum;
					printf("New Ticket (Ticket#:%06d)\n", TicketNum);
					printChar('-', 40);
					NewTicket(&data->tickets[TicketIndexFree], data->accounts[indexOfLogin], data->TICKET_MAX_SIZE);
				}
				pauseExecution();
				break;
			case 3:
				printf("Enter ticket number: ");
				TicketNum = getInteger();
				printf("\n");
				TicketIndex = findTicketNumber(data->tickets, data->TICKET_MAX_SIZE, TicketNum);
				if (data->tickets[TicketIndex].CustomerAcc == data->accounts[indexOfLogin].NumCustomer) {
					ModifyTicketCustomerMenu(&data->tickets[TicketIndex], data->accounts[indexOfLogin]);
				}
				else {
					printf("ERROR: Invalid ticket number - you may only modify your own ticket.\n\n");
				}
				pauseExecution();
				break;
			case 4:
				while(TicketIndex != -2){
					PrintTicketsCustomer(data->tickets,data->TICKET_MAX_SIZE ,data->accounts[indexOfLogin].NumCustomer);
					TicketIndex = findTicketNumber(data->tickets, data->TICKET_MAX_SIZE, 0);
					if(TicketIndex >= 0 && data->tickets[TicketIndex].CustomerAcc == data->accounts[indexOfLogin].NumCustomer){
						MessageTicketRead(data->tickets[TicketIndex]);	
					}
					else{
						if(data->tickets[TicketIndex].CustomerAcc != data->accounts[indexOfLogin].NumCustomer && TicketIndex != -2)
							printf("\nERROR: Invalid ticket number - you may only access your own tickets.\n\n");
					}
					if(TicketIndex != -2)
						pauseExecution();
				}
				printf("\n");
				break;
			case 0:
				printf("Saving session modifications...\n");
				Updates = saveTicket(data->tickets, data->TICKET_MAX_SIZE);
				printf("   %d tickets saved.\n", Updates);
				printf("### LOGGED OUT ###\n");
				printf("\n");
				logged = 0;
				break;
			}
			flag = 1;
		}
	}

}

