![banner](https://user-images.githubusercontent.com/46844031/163574487-8884b2f1-9fcc-400f-a68d-bd2a73e24383.jpg)

<h1 align="center">SENECA WINTER TERM 2021 - WORKSHOPS</h1>

![VS Badge](https://img.shields.io/badge/Visual_Studio-5C2D91?style=for-the-badge&logo=visual%20studio&logoColor=white)   ![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)   ![GitHub last commit](https://img.shields.io/github/last-commit/DeBaFig/1-term)   ![APM](https://img.shields.io/apm/l/vim-mode)

<p>Codes of my workshops and the final project.</p>

<!--ts-->
   * [About](#about)
   * [How to Run](#how-to-run)
   * [Folder Structure](#folder-structure)
      * [Workshop #2](#workshop-2)
      * [Workshop #3](#workshop-3)
      * [Workshop #4](#workshop-4)
      * [Workshop #5](#workshop-5)
      * [Workshop #6](#workshop-6)
      * [Final Project](#final-project)
   * [Technologies](#technologies)
   * [Author](#author)
      
<!--te-->


## About

<p>During the IPC144 course at Seneca College I was able to learn and apply principles of computer programming, with an emphasis on problem solving strategies using structured programming techniques. Using C programming language, which is widely used and forms the syntactical basis for object-oriented languages such as C++, C#, and Java, is used to introduce problem analysis, algorithm design, and program implementation.</p>


## How to Run

Bash:

```bash
mkdir directory-name

cd directory-name

git clone https://github.com/DeBaFig/1-term.git

gcc main.c .\workshop2\w2p2.c .\workshop3\Workshop3.c .\workshop4\Workshop04.c .\workshop5\Workshop5.c  .\workshop6\w6p2.c  .\final-project\account.c .\final-project\accountTicketingUI.c .\final-project\commonHelpers.c .\final-project\ticket.c .\final-project\final_main.c -o 1term -Wall

.\1term.exe

```

## Folder Structure


```PowerShell

C:.  
│   main.c  
│   README.md  
│  
├───final-project  
│       account.c    
│       account.h    
│       accounts.txt    
│       accounts_arc.txt  
│       accountTicketingUI.c  
│       accountTicketingUI.h  
│       commonHelpers.c  
│       commonHelpers.h  
│       final_main.c  
│       ticket.c  
│       ticket.h  
│       tickets.txt  
│       tickets_arc.txt  
│  
├───workshop2  
│       w2p2.c  
│       w2p2.h  
│  
├───workshop3  
│       Workshop03.pdf  
│       Workshop3.c  
│       Workshop3.h  
│
├───workshop4  
│       Workshop04.c  
│       Workshop04.h  
│       Workshop04.pdf  
│
├───workshop5  
│       Workshop05.pdf  
│       Workshop5.c  
│       Workshop5.h  
│
└───workshop6  
        w6p2.c  
        w6p2.h
        Workshop06.pdf

```
### Menu

<p align="center">
  <img src="https://user-images.githubusercontent.com/46844031/167532491-9d81ae18-65ff-4511-837c-c0484905aaea.png" width="600"/>
</p>


After run the exe you can choose one of the options:

### Workshop #2
<p align="center">
  <img src="https://user-images.githubusercontent.com/46844031/163504366-e9dd85ad-9961-469e-8ba5-e3b6f74adc13.gif" width="600"/>
</p>


This program calculates the number of toonies, loonies, quarters, dimes, nickels, and pennies required to dispense the amount due and displays the remaining owed with each coin denomination.

```
Change Maker Machine
====================
Enter dollars and cents amount to convert to coins (0 to exit): $ (TYPE HERE THE AMOUNT)
```

Click enter and see the result:

```
Change Maker Machine
====================
Enter dollars and cents amount to convert to coins (0 to exit): $100
Service fee (5.0 percent): 5.00
Balance to dispense: $95.00

$2.00 Toonies  X 47 (remaining: $1.00)
$1.00 Loonies  X 1 (remaining: $0.00)
```

### Workshop #3

<p align="center">
  <img src="https://user-images.githubusercontent.com/46844031/163491541-3ced595a-db79-4fc8-a08b-9c49e4269925.gif" width="600"/>
</p>

This program gets the input for a specified number (CONST) of days that records the user’s self-diagnosed “wellness” rating for the morning and evening periods of each day. The application will end with a summary of statistics about the data entered.
How to use:

```
General Well-being Log
======================
Set the year and month for the well-being log (YYYY MM): (TYPE HERE THE YEAR AND MONTH OF THE REGISTER)
```

Click enter and add the rating of your day, you can change how many days it would be asked in the CONST variable at the code top page (at moment it is 3 days).

```
2022-JAN-01
   Morning rating (0.0-5.0): 6 <-- your rate
      ERROR: Rating must be between 0.0 and 5.0 inclusive!
   Morning rating (0.0-5.0): 2
   Evening rating (0.0-5.0): 3

2022-JAN-02
   Morning rating (0.0-5.0): 4
   Evening rating (0.0-5.0): 5

2022-JAN-03
   Morning rating (0.0-5.0): 1
   Evening rating (0.0-5.0): 2
```

Finishing with a summary and the average of the rates:

```
Summary
=======
Morning total rating: 7.000
Evening total rating: 10.000
----------------------------
Overall total rating: 17.000

Average morning rating:  2.3
Average evening rating:  3.3
----------------------------
Average overall rating:  2.8
```

### Workshop #4

<p align="center">
  <img src="https://user-images.githubusercontent.com/46844031/163493459-f35ea07a-0f5e-48ec-9168-98e69e699d02.gif" width="600"/>
</p>

The program will ask for the user’s monthly income and then ask for the price and priority of a series of items the user would like to purchase in the future. It will store this information and allow the user to view predictions on how long it will take to save enough money to purchase their wish list items.
How to use:

```
+--------------------------+
+   Wish List Forecaster   |
+--------------------------+

Enter your monthly NET income: $ 1000 <- type the You income
```

**There is a min and max (min: 1000 max 400000)**

```
How many wish list items do you want to forecast?: 5 <- Items in your wish list

Item-1 Details:
   Item cost: $1000 <- do I need to explain?
   How important is it to you? [1=must have, 2=important, 3=want]: 1
   Does this item have financing options? [y/n]: y
```

After there'll be a summary and a menu and you'll be able to see how much money you need.
 
 ```
 Item Priority Financed        Cost
---- -------- -------- -----------
  1      1        y        1000.00
  2      1        y         500.00
  3      3        n        1500.00
  4      2        n        1700.00
  5      3        y        9000.00
---- -------- -------- -----------
                      $   13700.00

How do you want to forecast your wish list?
 1. All items (no filter)
 2. By priority
 0. Quit/Exit
 
 What priority do you want to filter by? [1-3]: 3

====================================================
Filter:   by priority (3)
Amount:   $10500.00
Forecast: 0 years, 11 months
NOTE: Financing options are available on some items.
      You can likely reduce the estimated months.
====================================================
 ```
 
 
### Workshop #5

<p align="center">
  <img src="https://user-images.githubusercontent.com/46844031/163506188-57baccc2-6610-4f39-8429-5ddeb1d8c2f2.gif" width="600"/>
</p>

The game requires the player to enter move location commands to reveal what is hidden at a given position along the path. The object of the game is for the player to find as many treasures as possible before running out of moves or lives. Discovering a bomb will reduce the player’s life count. Discovering a treasure will earn the player treasure points. Discovering both, a treasure with a bomb in the same location will reduce the player’s life count and earn the player treasure points (consider it a life insurance payout). Before playing the game, the program will prompt the user to perform some upfront configurations to the player and the game components – these settings will define how the game is played.

````
PLAYER Configuration
--------------------
Enter a single character to represent the player: D
Set the number of lives: 10
Player configuration set-up is complete

GAME Configuration
------------------
Set the path length (a multiple of 5 between 10-70): 25
Set the limit for number of moves allowed: 17
````

To set the bombs you need to type n rows of 1 and 0 where 1 means there are (bomb or treasure) and 0 means empty.

````
BOMB Placement
--------------
Enter the bomb positions in sets of 5 where a value
of 1=BOMB, and 0=NO BOMB. Space-delimit your input.
(Example: 1 0 0 1 1) NOTE: there are 25 to set!
   Positions [ 1- 5]: 1 0 1 0 0
   Positions [ 6-10]: 0 0 0 0 1
   Positions [11-15]: 1 1 0 0 0
   Positions [16-20]: 1 0 0 0 1
   Positions [21-25]: 1 1 1 0 0
BOMB placement set

TREASURE Placement
------------------
Enter the treasure placements in sets of 5 where a value
of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.
(Example: 1 0 0 1 1) NOTE: there are 25 to set!
   Positions [ 1- 5]: 0 0 0 0 0
   Positions [ 6-10]: 1 0 0 0 1
   Positions [11-15]: 0 0 1 1 0
   Positions [16-20]: 1 0 0 0 0
   Positions [21-25]: 0 0 0 0 1
TREASURE placement set
````

If there is a bomb and a treasure at same number both actions will be count.

````
====================================
~ Get ready to play TREASURE HUNT! ~
====================================

  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
  |||||||||1|||||||||2|||||
  1234567890123456789012345
+---------------------------------------------------+
  Lives: 10  | Treasures:  0  |  Moves Remaining: 17
+---------------------------------------------------+
Next Move [1-25]:
````

You need to select a move and will reveal one of the 4 options:

Explosion:

````
Next Move [1-25]: 1

===============> [!] !!! BOOOOOM !!! [!]

  D
  !▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
  |||||||||1|||||||||2|||||
````

Empty space:

````
Next Move [1-25]: 2

===============> [.] ...Nothing found here... [.]

   D
  !.▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
  |||||||||1|||||||||2|||||
````

Treasure:

````
Next Move [1-25]: 25

===============> [$] $$$ Found Treasure! $$$ [$]

                          D
  !.▒▒▒▒▒▒▒&▒▒▒▒▒▒▒▒▒▒▒▒▒▒$
  |||||||||1|||||||||2|||||
````

Bomb + Treasure:

````
Next Move [1-25]: 10

===============> [&] !!! BOOOOOM !!! [&]
===============> [&] $$$ Life Insurance Payout!!! [&]

           D
  !.▒▒▒▒▒▒▒&▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
  |||||||||1|||||||||2|||||
````

You can not go 2 times at the same place:

````
Next Move [1-25]: 13

===============> Dope! You've been here before!
````

You can get all your treasures and try finishing your movements without losing all your lives.

````
Next Move [1-25]: 19

===============> [.] ...Nothing found here... [.]

                    D
  !.!..$▒▒.&▒▒$$.&▒▒.!!▒!▒$
  |||||||||1|||||||||2|||||
  1234567890123456789012345
+---------------------------------------------------+
  Lives:  3  | Treasures:  6  |  Moves Remaining:  0
+---------------------------------------------------+

##################
#   Game over!   #
##################

You should play again and try to beat your score!
````


### Workshop #6

<p align="center">
  <img src="https://user-images.githubusercontent.com/46844031/163506196-b36d5cb5-bb7b-479f-a0e7-ab06252becfa.gif" width="600"/>
</p>

This program evaluates the cheapest cat food product based on a simple analysis. Data will be entered for three similar products and then displayed back to the user in a tabular table format. The data will be analyzed and displayed with additional calculated information in the form of a formatted table revealing the analysis. The program concludes with the suggested cheapest product.

First, the program will ask about the cat food pieces of information of 3  different options (it can be changed the CONST that save the number of products): 

````
Cat Food Product #1
--------------------
SKU           : 123
PRICE         : $1000
WEIGHT (LBS)  : 1500
CALORIES/SERV.: 100
````

Then, it will provide a summary and suggest the less expencive.

````
SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal
------- ---------- ---------- ---------- --------- -------- -------- ------- -------
0000123    1000.00     1500.0   680.3894    680389      100  10631.1    0.09 0.00094
0001234    1500.00     3000.0  1360.7787   1360778      120  21262.2    0.07 0.00059
0012345     100.00     1000.0   453.5929    453592      100   7087.4    0.01 0.00014 ***

Final Analysis
--------------
Based on the comparison data, the PURRR-fect economical option is:
SKU:0012345 Price: $100.00

Happy shopping!
````


### Final Project

<p align="center">
  <img src="https://user-images.githubusercontent.com/46844031/163506202-1355aeb8-a8cd-451a-bd8e-33958e6380a8.gif" width="600"/>
</p>

This program creates a basic ticketing system, a tracking system for customer-reported problems. When a customer has a problem they will phone or email for support. The person handling the support request will create a ticket for the request that contains the details of the problem and the customer's contact information so that the customer can be notified when there is a solution. 

````
##########################################################################
Starting Account Ticketing System....
   Loading account data... (5 accounts loaded)
   Loading ticket data...  (0 tickets loaded)
##########################################################################
````

Using the text file in the branch ["accounts.txt"](https://github.com/DeBaFig/1st-term/blob/DeBaFig-finalProject/accounts.txt) you use the ADMIN login.

Divided between the Administrator and Customer menu you can create and change tickets and users (limited by a CONST on code).
You can see the menu options below:

-> Administrator Menu

````
Enter the account#: 11111
User Login    : ADMIN
Password      : admin

AGENT: Admin (11111)
==============================================
Account Ticketing System - Agent Menu
==============================================
 1) Add a new account
 2) Modify an existing account
 3) Remove an account
 4) List accounts: summary view
 5) List accounts: detailed view
----------------------------------------------
 6) List new tickets
 7) List active tickets
 8) List closed tickets
 9) Manage a ticket
10) Archive closed tickets
----------------------------------------------
11) View archived account statistics
12) View archived tickets statistics
----------------------------------------------
0) Logout
````

-> Customer Menu

````
Enter the account#: 82045
User Login    : De
Password      : 12**ooOO

CUSTOMER: Denize (82045)
==============================================
Customer Main Menu
==============================================
1) View your account detail
2) Create a new ticket
3) Modify an active ticket
4) List my tickets
----------------------------------------------
0) Logout
````

This program has implementations to create persistent storage of the account and ticketing data. The system load account and ticket information from files, save account and ticket information to files, and finally archive data that will no longer be actively used in the system.

````
Saving session modifications...
   6 account saved.
   1 tickets saved.
### LOGGED OUT ###
````

## Technologies

All workshops/projects were developed in C.

- [C](https://devdocs.io/c/)

All readmes were built using HTML and Markdown

- [HTML](https://devdocs.io/html/)
- [Markdown](https://devdocs.io/markdown/)

These workshops were developed by the Seneca College professors, and the code by me. [IPC144](https://github.com/Seneca-144100/IPC-Workshops) is a course of [Computer Programming Program](https://www.senecacollege.ca/programs/fulltime/CPP.html). 

### Author

**Denize**

It is not luck, it is hard work!

<img style="border-radius: 50%;" src="https://user-images.githubusercontent.com/46844031/163518939-915f6e15-200a-4e9c-9f54-9bee6beec89b.jpg" width="100px;" alt=""/>

Where to find me:

[![Twitter Badge](https://img.shields.io/badge/Twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/Dbassi91)   [![Linkedin Badge](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/dbfigueiredo/)   [![Gmail Badge](	https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:denize.f.bassi@gmail.com)   [![CodePen](https://img.shields.io/badge/Codepen-000000?style=for-the-badge&logo=codepen&logoColor=white)](https://codepen.io/debafig)   
[![Facebook Badge](https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white)](https://www.facebook.com/d.bassi91/)   [![GitHub Badge](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/DeBaFig)   [![Instagram Badge](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/bassidenize/)   [![website Badge](https://img.shields.io/badge/website-000000?style=for-the-badge&logo=About.me&logoColor=white)](https://debafig.github.io/me/)   [![Whatsapp](https://img.shields.io/badge/WhatsApp-25D366?style=for-the-badge&logo=whatsapp&logoColor=white)](https://whatsa.me/5547988184372)
