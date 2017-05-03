/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "dollars.h"   // used to handle currency
//TODO add back in queue #include "queue.h"     // for QUEUE
#include <queue>
using namespace std;

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   string instruction;
   char token;
   int shares;
   string stringDollars;
   cin >> instruction;
   while (instruction != "quit")
   {
	   int i = 0;
	   switch (token)
	  {
		   case 'b':
			   i + 4;
			   break;
		   case 's':
			   i + 5;
		   break;
	   }
	   if (i == 4)
	   {
		   while (isalnum(instruction[i]))
		   {
			   numberOfShares.append(1, instruction[i]);
			   i++;
		   }
		   while (i < instruction.length())
		   {
			   stringDollars.append(1, instruction[i]);
			   i++;
		   }
	   }
	   else if (i == 5)
	   {

	   }
   }
}

// TODO delete main
int main()
{
	return 0;
};


