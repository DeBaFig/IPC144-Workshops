
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


//1. Header for ticket agent
void PrintTicketsAgentheader(void) {
	printf("------ ----- --------------- ------ ------------------------------ --------\n"
		"Ticket Acct# Display Name    Status Subject                        Messages\n"
		"------ ----- --------------- ------ ------------------------------ --------\n"
	);
}

//2. print the tickets in the Agent menu if the argument 2 is = 0 will print all open tickets is = 1 just the new ones
void PrintTicketsAgent(struct Ticket tickets[], int NewTicket, int Max_Ticket_NUM, int Status) {
	int a;
	PrintTicketsAgentheader();
	if (NewTicket == 0) {
		for (a = 0; a < Max_Ticket_NUM; a++) {
			if (tickets[a].Status == Status && tickets[a].TicketID != 0) {
				printf("%06d %05d %-15s %-6s %-30s %5d\n", tickets[a].TicketID, tickets[a].CustomerAcc, tickets[a].Messege[0].NameUser, (tickets[a].Status ? "ACTIVE" : "CLOSED"), tickets[a].Subject, tickets[a].MessengeNumber);
			}
		}
	}
	else {
		for (a = 0; a < Max_Ticket_NUM; a++) {
			if (tickets[a].Status == 1 && tickets[a].MessengeNumber == 1 && tickets[a].TicketID != 0) {
				printf("%06d %05d %-15s %-6s %-30s %5d\n", tickets[a].TicketID, tickets[a].CustomerAcc, tickets[a].Messege[0].NameUser, (tickets[a].Status ? "ACTIVE" : "CLOSED"), tickets[a].Subject, tickets[a].MessengeNumber);
			}
		}
	}
	printf("------ ----- --------------- ------ ------------------------------ --------\n\n");

}

//3.read the messages but only 5 each time, use pause application function to wait and than show more 5
void MessageTicketRead(struct Ticket tickets) {
	int a = 0, AccType = 0, b = 0;
	printf("\n");
	printChar('=', 80);
	printf("%06d (%s) Re: %s\n", tickets.TicketID, (tickets.Status ? "ACTIVE" : "CLOSED"), tickets.Subject);
	printChar('=', 80);
	for (a = 0; a < MAX_MESSEGES; a++) {
		if (b % 5 == 0 && b != 0 && tickets.Messege[a].MessageDetails[0] != '\0')
			pauseExecution();
		//printf("Teste\n");
		if (tickets.Messege[a].AccType == 'A')
		{
			AccType = 1;
		}
		else {
			AccType = 0;
		}
		if (tickets.Messege[a].MessageDetails[0] != '\0') {
			printf("%s (%s):\n", (AccType ? "AGENT" : "CUSTOMER"), tickets.Messege[a].NameUser);
			printf("   %s\n\n", tickets.Messege[a].MessageDetails);
			b++;
		}

	}
}

//4.prompt the question to get a ticket number if a wrong number is typed return -2 if do not return nothing retun -1 and 0 or more is the index of the ticket
int findTicketNumber(struct Ticket tickets[], int MAX_Ticket_NUM, int ticketNumTofind) {
	int TicketNum = 0, a, finded = -1;
	if (ticketNumTofind == 0) {
		printf("Enter the ticket number to view the messages or\n"
			"0 to return to previous menu: ");
		TicketNum = getPositiveInteger();
	}
	else
		TicketNum = ticketNumTofind;

	if (TicketNum != 0) {
		for (a = 0; a < MAX_Ticket_NUM; a++) {
			if (tickets[a].TicketID == TicketNum)
				finded = a;
		}
		if (finded == -1 && ticketNumTofind == 0) {
			printf("\nERROR: Invalid ticket number.\n\n");
			return -1;
		}
		return finded;
	}
	else
		return -2;
	//return finded;
}

//5. header to print ticket of customer
void PrintTicketsCuustomerheader(void) {
	printf("------ ------ ------------------------------ --------\n"
		"Ticket Status Subject                        Messages\n"
		"------ ------ ------------------------------ --------\n"
	);
}

//6.Print the ticket referent to a only a the logged customer
void PrintTicketsCustomer(struct Ticket tickets[], int Max_Ticket_size, int CustomerLogged) {
	PrintTicketsCuustomerheader();
	int a;
	for (a = 0; a < Max_Ticket_size; a++) {
		//printf("%06d %-6s %-30s %5d\n", tickets[a].TicketID, (tickets[a].Status ? "ACTIVE" : "CLOSED"), tickets[a].Subject, tickets[a].MessengeNumber);
		if (tickets[a].CustomerAcc == CustomerLogged)
		{
			printf("%06d %-6s %-30s %5d\n", tickets[a].TicketID, (tickets[a].Status ? "ACTIVE" : "CLOSED"), tickets[a].Subject, tickets[a].MessengeNumber);
		}
	}
	printf("------ ------ ------------------------------ --------\n\n");
}

//7. Find a number to create a new ticket the number is +1 the highest number find in the array
int NewTicketNumber(struct Ticket Tickets[], int Max_Ticket_size) {
	int  a = 0, highestTICKET = Tickets[0].TicketID;
	for (a = 0; a < Max_Ticket_size; a++) {
		if (highestTICKET < Tickets[a].TicketID)
			highestTICKET = Tickets[a].TicketID;
	}
	return highestTICKET + 1;
}

//8.Find an empty index to create a new ticket
int FreeIndexTicket(struct Ticket Tickets[], int Max_ticket_size) {
	int FreeIndex = 0;
	while (Tickets[FreeIndex].TicketID > 0) {
		FreeIndex++;
	}
	if (FreeIndex >= Max_ticket_size) {
		printf("ERROR: Ticket listing is FULL, call ITS Support!\n\n");
		return -1;
	}
	else
		return FreeIndex;
}



//9.Create a new ticket prompting to get the informations use the function to find a free index and use the informations of the logged user
void NewTicket(struct Ticket* TicketsFreeIndex, struct Account LoggedUser, int Max_Ticket_size) {

	//Informations about the user and ticket number

	TicketsFreeIndex->CustomerAcc = LoggedUser.NumCustomer;
	TicketsFreeIndex->Status = 1;
	//subject typed
	printf("Enter the ticket SUBJECT (%d chars. maximum): ", MAX_SUBJECT - 1);
	getCString(TicketsFreeIndex->Subject, 1, MAX_SUBJECT - 1);

	TicketsFreeIndex->MessengeNumber = 1;
	//details of messages:
	//clearStandardInputBuffer();
	TicketsFreeIndex->Messege[0].AccType = 'C';
	strcpy(TicketsFreeIndex->Messege[0].NameUser, LoggedUser.User.Name);
	printf("\nEnter the ticket message details (%d chars. maximum). Press the ENTER key to submit:\n", MAX_MESSANGER_CHARS - 1);
	getCString(TicketsFreeIndex->Messege->MessageDetails, 1, MAX_MESSANGER_CHARS - 1);
	//clearStandardInputBuffer();
	printf("\n*** New ticket created! ***\n\n");
}

//10.Modify a ticket menu the options only to customers
void ModifyTicketCustomerMenu(struct Ticket* TicketsSelectedIndex, struct Account AccLogged) {
	int selection = 0, flag = 0, done = 1;
	if (TicketsSelectedIndex->Status == 0)
		printf("ERROR: Ticket is closed - changes are not permitted.\n\n");
	while (done == 1 && TicketsSelectedIndex->Status == 1) {
		flag = 0;
		printChar('-', 40);
		printf("Ticket %06d - Update Options\n", TicketsSelectedIndex->TicketID);
		printChar('-', 40);
		printf("Status  : %s\n", (TicketsSelectedIndex->Status ? "ACTIVE" : "CLOSED"));
		printf("Subject : %s\n", TicketsSelectedIndex->Subject);
		printChar('-', 40);
		printf("1) Modify the subject\n"
			"2) Add a message\n"
			"3) Close ticket\n");
		printf("0) Done\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 3);
		printf("\n");
		while (flag == 0)
		{
			switch (selection)
			{
			case 1:
				printf("Enter the revised ticket SUBJECT (%d chars. maximum): ", MAX_SUBJECT - 1);
				getCString(TicketsSelectedIndex->Subject, 1, MAX_SUBJECT - 1);
				fflush(stdin);
				printf("\n");
				break;
			case 2:
				GetMessage(TicketsSelectedIndex, AccLogged);
				printf("\n");
				break;
			case 3:
				ClosingTIcket(TicketsSelectedIndex, AccLogged);
				done = 0;
				break;
			case 0:
				done = 0;
				break;
			}
			flag = 1;
		}
	}

}

//11. loop to find if there is a space to create a new message
int FindMessageFreeIndex(struct Ticket* TicketsSelectedIndexFromMENU, int DOnotShowMsg) {
	int a = 0;
	while (TicketsSelectedIndexFromMENU->Messege[a].MessageDetails[0] != '\0') {
		a++;
	}
	if (a > MAX_MESSEGES - 1 && DOnotShowMsg == 0) {
		printf("ERROR: Message limit has been reached, call ITS Support!\n");
		return -1;
	}
	else
	{
		if (a > MAX_MESSEGES - 1)
			return -1;
		else
			return a;
	}
}

//12. close ticket check, and there is a option to send a final message if there is a free index to do that...
void ClosingTIcket(struct Ticket* TicketsSelectedIndex, struct Account AccLogged) {
	char selection = 'x';
	int SpaceMassageFinal = 0;
	if (TicketsSelectedIndex->Status == 1) {
		SpaceMassageFinal = FindMessageFreeIndex(TicketsSelectedIndex, 1);
		printf("Are you sure you CLOSE this ticket? ([Y]es|[N]o): ");
		selection = getCharOption("YN");
		if (selection == 'Y') {
			if (SpaceMassageFinal != -1) {
				printf("\nDo you want to leave a closing message? ([Y]es|[N]o): ");
				selection = getCharOption("YN");
				if (selection == 'Y') {
					printf("\n");

					GetMessage(TicketsSelectedIndex, AccLogged);
					//clearStandardInputBuffer();
				}
			}
			TicketsSelectedIndex->Status = 0;
			printf("\n*** Ticket closed! ***\n\n");
		}
		else
			printf("ERROR: Ticket is already active!\n");
	}
	else
		printf("ERROR: Ticket is already closed!\n\n");

}

//13. This function find the index of the free massage index and if there is space alow to create and add a message to ticket adding the information of the person who sent
void GetMessage(struct Ticket* TicketsSelectedIndex, struct Account AccLogged) {
	int indexMessage = -1;
	indexMessage = FindMessageFreeIndex(TicketsSelectedIndex, 0);
	if (indexMessage != -1 && TicketsSelectedIndex->Status == 1) {
		printf("Enter the ticket message details (%d chars. maximum). Press the ENTER key to submit:\n", MAX_MESSANGER_CHARS - 1);
		getCString(TicketsSelectedIndex->Messege[indexMessage].MessageDetails, 1, MAX_MESSANGER_CHARS - 1);
		TicketsSelectedIndex->MessengeNumber++;
		TicketsSelectedIndex->Messege[indexMessage].AccType = AccLogged.AccountType;
		strcpy(TicketsSelectedIndex->Messege[indexMessage].NameUser, AccLogged.User.Name);
	}
	if (indexMessage != -1 && TicketsSelectedIndex->Status == 0)
		printf("ERROR: Ticket is closed - new messages are not permitted.\n");

}

//14 special menu only to agents with options to modify tickets
void ModifyTicketAgentMenu(struct Ticket* TicketsSelectedIndex, struct Account AccLogged) {
	int selection = 0, flag = 0, done = 1;
	char YN = 'x';
	while (done == 1) {
		flag = 0;
		printChar('-', 40);
		printf("Ticket %06d - Update Options\n", TicketsSelectedIndex->TicketID);
		printChar('-', 40);
		printf("Status  : %s\n", (TicketsSelectedIndex->Status ? "ACTIVE" : "CLOSED"));
		printf("Subject : %s\n", TicketsSelectedIndex->Subject);
		printf("Acct#   : %d\n", TicketsSelectedIndex->CustomerAcc);
		printf("Customer: %s\n", TicketsSelectedIndex->Messege[0].NameUser);
		printChar('-', 40);
		printf("1) Add a message\n"
			"2) Close ticket\n"
			"3) Re-open ticket\n");
		printf("0) Done\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 3);
		printf("\n");
		while (flag == 0)
		{
			switch (selection)
			{
			case 1:
				GetMessage(TicketsSelectedIndex, AccLogged);
				printf("\n");
				break;
			case 2:
				ClosingTIcket(TicketsSelectedIndex, AccLogged);
				break;
			case 3:
				if (TicketsSelectedIndex->Status == 0) {
					printf("Are you sure you RE-OPEN this closed ticket? ([Y]es|[N]o): ");
					YN = getCharOption("YN");
					if (YN == 'Y') {
						TicketsSelectedIndex->Status = 1;
						printf("\n*** Ticket re-opened! ***\n");
					}
					printf("\n");
				}
				else
					printf("ERROR: Ticket is already active!\n\n");

				break;
			case 0:
				done = 0;
				break;
			}
			flag = 1;
		}
	}

}

//15. Function to open the file of tickets and sent to pointers the information of all ticket on that file
int loadTickets(struct Ticket tickets_data[], int TICKET_SIZE) {
	int a = 0, b = 0, c = 0, flag = 1;
	char ch[(MAX_DISPLAY_NAME * MAX_MESSANGER_CHARS * MAX_MESSEGES) + 3];
	char* result = NULL;
	FILE* fp = fopen("tickets.txt", "r");

	if (fp != NULL) {
		while (a < TICKET_SIZE && flag == 1)
		{
			b = 0;
			fscanf(fp, "%d|%d|%d|%[^|]|%d|%[^\n]", &tickets_data[a].TicketID, &tickets_data[a].CustomerAcc, &tickets_data[a].Status, tickets_data[a].Subject, &tickets_data[a].MessengeNumber, ch);

			result = strtok(ch, "|");
			while (result != NULL)
			{

				//result = strtok(NULL, "|");
				while (result != NULL)
				{
					if (c == 0)
						tickets_data[a].Messege[b].AccType = result[0];
					if (c == 1)
						strcpy(tickets_data[a].Messege[b].NameUser, result);
					if (c == 2)
						strcpy(tickets_data[a].Messege[b].MessageDetails, result);
					c++;

					if (c == 3 && b < tickets_data[a].MessengeNumber)
					{
						/*		printf("\n");
								printChar('-', 50);
								printf("%c\n", tickets_data[a].Messege[b].AccType);
								printf("%s\n", tickets_data[a].Messege[b].NameUser);
								printf("%s\n", tickets_data[a].Messege[b].MessageDetails);
								printChar('-', 50);*/

						c = 0;
						b++;
					}

					result = strtok(NULL, "|");
				}

				fflush(stdin);
			}
			if (tickets_data[a].TicketID != 0)
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

	return a;
}

//16. Function to load the tickets archieved to count the total number of messages, and tickets 
int loadTicketsArc(void) {
	int a = 0, flag = 1;
	char ch[((MAX_DISPLAY_NAME + MAX_MESSANGER_CHARS) * MAX_MESSEGES) + 3];
	int buffer = 0, NumberOfMessages = 0, total = 0;
	FILE* fp = fopen("tickets_arc.txt", "r");

	if (fp != NULL) {
		while (flag == 1)
		{
			fscanf(fp, "%d|%d|%d|%[^|]|%d|%[^\n]", &buffer, &buffer, &buffer, ch, &NumberOfMessages, ch);
			total += NumberOfMessages;

			fflush(stdin);
			if (NumberOfMessages != 0) {
				a++;
				NumberOfMessages = 0;
			}
			else {
				flag = 0;
				fclose(fp);
				fp = NULL;
			}
		}


	}
	else
	{
		printf("Testando\n");
	}
	printf("There are %d ticket(s) and a total of %d message(s) archived.\n\n", a, total);
	return a;
}

//17. Function to save replace all tickets with the new data
int saveTicket(struct Ticket DataOfTickets[], int Max_N_Tickets) {
	int a, b, flag = 1;
	FILE* fp = fopen("tickets.txt", "w");
	if (fp != NULL) {
		for (a = 0; a < Max_N_Tickets && flag == 1; a++) {
			if (DataOfTickets[a].TicketID != 0) {
				fprintf(fp, "%d|%d|%d|%s|%d|", DataOfTickets[a].TicketID, DataOfTickets[a].CustomerAcc, DataOfTickets[a].Status, DataOfTickets[a].Subject, DataOfTickets[a].MessengeNumber);
				for (b = 0; b < DataOfTickets[a].MessengeNumber; b++) {
					if (b == DataOfTickets[a].MessengeNumber - 1) {
						fprintf(fp, "%c|%s|%s|\n", DataOfTickets[a].Messege[b].AccType, DataOfTickets[a].Messege[b].NameUser, DataOfTickets[a].Messege[b].MessageDetails);
					}
					else {
						fprintf(fp, "%c|%s|%s|", DataOfTickets[a].Messege[b].AccType, DataOfTickets[a].Messege[b].NameUser, DataOfTickets[a].Messege[b].MessageDetails);
					}

				}
			}
			else
			{
				flag = 0;
			}
		}
		fclose(fp);
		fp = NULL;
	}
	return a;
}

//18. Function to add the tickets from a deleted account (just the close ones) and in 
//the option 10 of Menu Agent allow to archive all closed tickets
void appendTicketArc(struct Ticket SpecificTicketIndex) {
	int b;
	FILE* fp = fopen("tickets_arc.txt", "a");
	if (fp != NULL) {

		fprintf(fp, "%d|%d|%d|%s|%d|", SpecificTicketIndex.TicketID, SpecificTicketIndex.CustomerAcc, SpecificTicketIndex.Status, SpecificTicketIndex.Subject, SpecificTicketIndex.MessengeNumber);
		for (b = 0; b < SpecificTicketIndex.MessengeNumber; b++) {
			if (b == SpecificTicketIndex.MessengeNumber - 1) {
				fprintf(fp, "%c|%s|%s|\n", SpecificTicketIndex.Messege[b].AccType, SpecificTicketIndex.Messege[b].NameUser, SpecificTicketIndex.Messege[b].MessageDetails);
			}
			else {
				fprintf(fp, "%c|%s|%s|", SpecificTicketIndex.Messege[b].AccType, SpecificTicketIndex.Messege[b].NameUser, SpecificTicketIndex.Messege[b].MessageDetails);
			}

		}
	}
	fclose(fp);
	fp = NULL;
}
