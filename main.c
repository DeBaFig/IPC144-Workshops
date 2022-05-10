#define _CRT_SECURE_NO_WARNINGS
#include "workshop2/w2p2.h"
#include "workshop3/Workshop3.h"
#include "workshop4\Workshop04.h"
#include "workshop5\Workshop5.h"
#include "workshop6\w6p2.h"
#include "final-project\accountTicketingUI.h"
#include "final-project\commonHelpers.h"

int main(void)
{
   int selection = 0, done = 1;
   while (done == 1)
   {
      int flag = 0;
          printf("Welcome to my IPC144 Workshop menu:\n"
             "1) Change Maker Machine\n"
                 "2) General Well-being Log\n"
                 "3) Wish List Forecaster\n"
                 "4) TREASURE HUNT!\n"
                 "5) Cat Food Analysis\n"
                 "6) Account Ticketing System\n"
                 "0) Done\n");
      printf("Selection: ");
      selection = getIntFromRange(0, 6);
      printf("\n");
      while (flag == 0)
      {
         switch (selection)
         {
         case 1:
            coin_main();
            break;
         case 2:
            wellBeing_main();
            break;
         case 3:
            wishList_main();
            break;
         case 4:
            game_main();
            break;
         case 5:
            foodCost_main();
            break;
         case 6:
            ticketing_main();
            break;
         case 0:
            done = 0;
            break;
         }
         flag = 1;
      }
   }

   return 0;
}
