


#ifndef TICKET_H_
#define TICKET_H_

#define MAX_LOGIN_NAME 11
#define MAX_SUBJECT 31
#define MAX_DISPLAY_NAME 31
#define MAX_MESSANGER_CHARS 151
#define MAX_MESSEGES 20

struct Message
{
	char AccType;
	char NameUser[MAX_DISPLAY_NAME];
	char MessageDetails[MAX_MESSANGER_CHARS];
};

struct Ticket
{
	int TicketID;
	int CustomerAcc;
	int Status;
	char Subject[MAX_SUBJECT];
	int MessengeNumber;
	struct Message Messege[MAX_MESSEGES];
};

struct AccountTicketingData {
	struct Account* accounts;
	const int ACCOUNT_MAX_SIZE;
	struct Ticket* tickets;
	const int TICKET_MAX_SIZE;
};



//1. Header for ticket agent
void PrintTicketsAgentheader(void);

//2. print the tickets in the Agent menu if the argument 2 is = 0 will print all open tickets is = 1 just the new ones
void PrintTicketsAgent(struct Ticket tickets[], int NewTicket, int Max_ACC_NUM, int Status);

//3.read the messages but only 5 each time, use pause application function to wait and than show more 5
void MessageTicketRead(struct Ticket tickets);

//4.prompt the question to get a ticket number  typed is 0 return -2 if do not return nothing searching between the numbers of the tickets retun -1 and 0 or more is the index of the ticket
int findTicketNumber(struct Ticket tickets[], int MAX_Ticket_NUM, int ticketNumTofind);

//5. header to print ticket of customer
void PrintTicketsCuustomerheader(void);

//6.Print the ticket referent to a only a the logged customer
void PrintTicketsCustomer(struct Ticket tickets[], int Max_Ticket_size, int CustomerLogged);

//7. Find a number to create a new ticket, the number is +1 the highest number find in the array
int NewTicketNumber(struct Ticket Tickets[], int Max_Ticket_size);


//8.Find an empty index to create a new ticket
int FreeIndexTicket(struct Ticket Tickets[], int Max_ticket_size);


//9.Create a new ticket prompting to get the informations use the function to find a free index and use the informations of the logged user
void NewTicket(struct Ticket* TicketsFreeIndex, struct Account LoggedUser, int Max_Ticket_size);

//10.Modify a ticket menu
void ModifyTicketCustomerMenu(struct Ticket* TicketsSelectedIndex, struct Account AccLogged);

//11. loop to find if there is a space to create a new message
int FindMessageFreeIndex(struct Ticket* TicketsSelectedIndexFromMENU, int DOnotShowMsg);

//12. close ticket check, and there is a option to send a final message if there is a free index to do that...
void ClosingTIcket(struct Ticket* TicketsSelectedIndex, struct Account AccLogged);

//13. This function find the index of the free massage index and if there is space alow to create and add a message to ticket adding the information of the person who sent
void GetMessage(struct Ticket* TicketsSelectedIndex, struct Account AccLogged);

//14 special menu only to agents with options to modify tickets
void ModifyTicketAgentMenu(struct Ticket* TicketsSelectedIndex, struct Account AccLogged);

//15. Function to open the file of tickets and sent to pointers the information of all ticket on that file
int loadTickets(struct Ticket tickets_data[], int TICKET_SIZE);

//16. Function to load the tickets archieved to count the total number of messages, and tickets 
int loadTicketsArc(void);


//17. Function to save replace all tickets with the new data
int saveTicket(struct Ticket DataOfTickets[], int Max_N_Tickets);

//18. Function to add the tickets from a deleted account (just the close ones)
//and in the option 10 of Menu Agent allow to archive all closed tickets
void appendTicketArc(struct Ticket SpecificTicketIndex);



#endif