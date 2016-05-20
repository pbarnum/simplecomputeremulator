// Main file for Simple Computer

// Include files
#include "emuHeader.h"


void main(void)
{
  /*
  Simple Computer Emulator
  Program created by Patrick Barnum
  11/15/07
  Instructor: Chris Carroll
  */
   
  // Program start
  int choice;
  bool quit = false;
  
  Header();
  cout << "Hello and welcome to the Simple Computer.\n\n";
  
  do
  {
  	cout << "What would you like to do?\n"
  			 << "1) Create a new emulation.\n"
			 	 << "2) Open emulation file.\n"
			 	 << "3) Help!\n"
			 	 << "4) Quit program.\n\n";
		cin >> choice;
		
		switch(choice)
		{
			case 1 : Header();
							 CreateNewSC();
							 break;
							 
			case 2 : Header();
							 OpenSC();
							 break;
							 
			case 3 : Header();
							 HelpSC();
							 break;
							 
			case 4 : Header();
							 cout << "Good bye.";
							 quit = true;
							 break;
							 
			default : cout << "Please enter a valid option.\n\n";
								break;
		}
	}while(quit == false);
}
