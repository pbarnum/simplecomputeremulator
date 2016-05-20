// Implementation file for emuHeader

// Include files
#include "emuHeader.h"

SimpleComputer :: SimpleComputer() : accumulator(0),
																		 ir(0),
																		 pc(0)
{
	memCells[0] = 001;
	for(int i = 1; i < 100; ++i)
		memCells[i] = 0;

	for(int j = 0; j < 100; ++j)
		inpCells[j] = 0;

	for(int k = 0; k < 100; ++k)
		outCells[k] = 0;
}

int SimpleComputer :: getMemory(int i)
{
  return memCells[i];
}

int SimpleComputer :: getInput(int i)
{
  return inpCells[i];
}

int SimpleComputer :: getOutput(int i)
{
  return outCells[i];
}

int SimpleComputer :: getAccum()
{
  return accumulator;
}

int SimpleComputer :: getIR()
{
  return ir;
}

int SimpleComputer :: getPC()
{
  return pc;
}

void SimpleComputer :: setAccum(int a)
{
	accumulator = a;
}

void SimpleComputer :: setIR(int i)
{
	ir = i;
}

void SimpleComputer :: setPC(int p)
{
  pc = p;
}

void SimpleComputer :: setMemCells(int cn, int cv)
{
	memCells[cn] = cv;
}

void SimpleComputer :: setInpCells(int cn, int cv)
{
	inpCells[cn] = cv;
}

void SimpleComputer :: setOutCells(int cn, int cv)
{
	outCells[cn] = cv;
}

void SimpleComputer :: clearMem()
{
	memCells[0] = 1;

	for(int i = 1; i < 100; ++i)
		memCells[i] = 0;
}

void SimpleComputer :: clearInp()
{
	for(int j = 0; j < 100; ++j)
		inpCells[j] = 0;
}

void SimpleComputer :: clearOut()
{
	for(int k = 0; k < 100; ++k)
		outCells[k] = 0;
}

void SimpleComputer :: clearCPU()
{
	accumulator = 0;
	ir = 0;
	pc = 0;
}


// FUNCTION
// The header that shows throughout run time of the program

void Header()
{
	clrscr();
	cout << "****************************************\n"
	"****************************************\n"
	"***   THE SIMPLE COMPUTER EMULATOR   ***\n"
	"***                                  ***\n"
	"***            WRITTEN BY:           ***\n"
	"***          PATRICK BARNUM          ***\n"
	"***                                  ***\n"
	"***        Computer Science 3A       ***\n"
	"***         Fall Semester 2007       ***\n"
	"****************************************\n"
	"****************************************\n\n";
}


// FUNCTION
// Creates a new SC emulation
void CreateNewSC()
{
	SimpleComputer temp;
	bool exist = true;

	cout << "Created a new emulation!\n\n";

	EmulationMenu(temp, exist);
}


// FUNCTION
// This opens a file containing a SC program

void OpenSC()
{
	SimpleComputer temp;
	bool exist = true;
	int tempValue;
	string fileName;
	ifstream file;

	Header();

	cin.ignore(10, '\n');
	cout << "What file would you like to open? ";
	getline(cin, fileName);

	file.open(fileName.c_str());

	Header();

	cout << "OPENED the file \"" << fileName << "\"\n\n";

	file >> tempValue;
	temp.setAccum(tempValue);
	file >> tempValue;
	temp.setIR(tempValue);
	file >> tempValue;
	temp.setPC(tempValue);

	for(int i = 1; i < 100; ++i)
	{
		file >> tempValue;
		temp.setMemCells(i, tempValue);
	}

	for(int j = 0; j < 100; ++j)
	{
		file >> tempValue;
		temp.setInpCells(j, tempValue);
	}

	for(int k = 0; k < 100; ++k)
	{
		file >> tempValue;
		temp.setOutCells(k, tempValue);
	}

	file.close();

	EmulationMenu(temp, exist);
}


// FUNCTION
// This saves the SC program currently being worked on

void SaveSC(SimpleComputer& t)
{
	ofstream file;
	string fileName;

	Header();

	cin.ignore(10, '\n');
	cout << "Enter in new file name: ";
	getline(cin, fileName);

	file.open(fileName.c_str());

	file << t.getAccum() << endl;
	file << t.getIR() << endl;
	file << t.getPC() << endl << endl;

	for(int i = 1; i < 100; ++i)
		file << t.getMemory(i) << endl;

	file << endl;

	for(int j = 0; j < 100; ++j)
		file << t.getInput(j) << endl;

	file << endl;

	for(int k = 0; k < 100; ++k)
		file << t.getOutput(k) << endl;

	file.close();

	Header();

	cout << "File \"" << fileName << "\" has been saved!\n\n";
}

// FUNCTION
// This is the menu for doing anything with the emulation
// Called after the first menu from the main function

void EmulationMenu(SimpleComputer t, bool exist)
{
	int menu;
	char newSave, newOpen;
  bool quit = false;

	do
	{
		cout << "What would you like to do?\n"
				 << "1) Create a new emulation.\n"
				 << "2) Open existing emulation.\n"
				 << "3) Edit existing emulation.\n"
				 << "4) Output existing emulation.\n"
				 << "5) Save existing emulation.\n"
				 << "6) Run program.\n"
				 << "7) Help!\n"
				 << "8) Main menu.\n\n";
		cin >> menu;

		switch(menu)
		{
			case 1 : if(exist == true)
							 {
							 	 Header();
							 	 do
							 	 {
								   cout << "Emulation already exists!\n"
								   			<< "Save existing and create a new emulation?(Y/N) ";
								   cin >> newSave;

								   switch(toupper(newSave))
								   {
								   	 case 'Y' : Header();
								   	 						SaveSC(t);
								   	 						CreateNewSC();
								   	 						break;

								   	 case 'N' : Header();
								   	 						CreateNewSC();
								   	 						break;

								   	 default : Header();
								   	 					 cout << "\n\nType \"Y\" if you are done, otherwise type \"N\"";
								   	 					 break;
								   }
								 }while(toupper(newSave) != 'Y' && toupper(newSave) != 'N');
							 }
							 else
							 {
							   Header();
							   CreateNewSC();
							   break;
							 }

			case 2 : if(exist == true)
							 {
							 	 Header();
							 	 do
							 	 {
								   cout << "Emulation already exists!\n"
								   			<< "Save existing and create a new emulation?(Y/N) ";
								   cin >> newOpen;

								   switch(toupper(newOpen))
								   {
								   	 case 'Y' : Header();
								   	 						SaveSC(t);
								   	 						OpenSC();
								   	 						break;

								   	 case 'N' : Header();
								   	 						OpenSC();
								   	 						break;

								   	 default : Header();
								   	 					 cout << "\n\nType \"Y\" if you are done, otherwise type \"N\"";
								   	 					 break;
								   }
								 }while(toupper(newOpen) != 'Y' && toupper(newOpen) != 'N');
							 }
							 else
							 {
							   Header();
							   OpenSC();
							   break;
							 }

			case 3 : if(exist == true)
							 {
							   Header();
							 	 EditSC(t);
							   break;
							 }
							 else
							 {
							 	 Header();
								 cout << "Create or open an emulation.\n\n";
							 	 break;
							 }

			case 4 : if(exist == true)
							 {
							 	 Header();
							   OutputSC(t);
							   break;
							 }
							 else
							 {
							 	 Header();
								 cout << "Create or open an emulation.\n\n";
							   break;
							 }

			case 5 : if(exist == true)
							 {
							 	 Header();
								 SaveSC(t);;
							   break;
							 }
							 else
							 {
							 	 Header();
							   cout << "Create or open an emulation.\n\n";
							   break;
							 }

			case 6 : if(exist == true)
							 {
							   Header();
							 	 RunSC(t);
							   break;
							 }
							 else
							 {
							 	 Header();
								 cout << "Create or open an emulation.\n\n";
							 	 break;
							 }

			case 7 : Header();
							 HelpSC();
							 break;

			case 8 : Header();
							 quit = true;
							 break;

			default : Header();
								cout << "Please enter a valid option.\n\n";
								break;
		}
	}while(quit == false);
}


// FUNCTION
// This will edit either the existing emulation or will
// open a file containing a SC program

void EditSC(SimpleComputer& t)
{
	int option;
	bool returnTo = false;

	do
	{
		cout << "What would you like to edit?\n"
				 << "1) Program Counter\n"
				 << "2) Memory\n"
				 << "3) Input Card\n"
				 << "4) Clear Options\n"
				 << "5) Output emulation\n"
				 << "6) Save emulation\n"
				 << "7) Help!\n"
				 << "8) Return to the previous menu\n\n";

		cin >> option;

		switch(option)
		{
			case 1 : int pC;
							 cout << "\nWhat value would you like to set "
											 "the program counter at? ";
							 cin >> pC;
							 t.setPC(pC);
							 Header();
							 cout << "Program counter set to " << pC << ".\n\n";
							 break;

			case 2 : Header();
							 EditMemory(t);
							 Header();
							 break;

			case 3 : Header();
							 EditInput(t);
							 Header();
							 break;

			case 4 : Header();
							 ClearMenu(t);
							 Header();
							 break;

			case 5 : Header();
							 OutputSC(t);
							 break;

			case 6 : Header();
							 SaveSC(t);
							 break;

			case 7 : Header();
							 HelpSC();
							 break;

			case 8 : Header();
							 returnTo = true;
							 break;

			default : Header();
								cout << "Please enter a valid option.\n\n";
								break;
		}
	}while(returnTo == false);
}


// FUNCTION
// This will edit the memory of the SC emulation

void EditMemory(SimpleComputer& t)
{
	int cellNumber, cellValue;
	bool done = false;
	char another;

	cout << "Do you want to be prompted for the next cell? ";
	cin >> another;
	if(toupper(another) == 'Y')
	{
		while(done == false)
		{
			do
			{
				cout << "Please enter in the cell number you wish to change: ";
				cin >> cellNumber;

				if(cellNumber == 0) cout << "\n\nCell 0 is protected and cannot be changed!\n";
			}while(cellNumber < 1 || cellNumber > 99);

			do
			{
				cout << "Please enter in the value (can include a negative): ";
				cin >> cellValue;

				if(cellValue < -999 || cellValue > 999)
					cout << "\n\nPlease enter a value between -999 and 999.\n";

			}while(cellValue < -999 || cellValue > 999);

			// Actually changing the value of the cell
			t.setMemCells(cellNumber, cellValue);

			do
			{
				cout << "\nWould you like to edit another?(Y/N) ";
				cin >> another;
				switch(toupper(another))
				{
					case 'Y' : break;

					case 'N' : done = true;
									   break;

					default : cout << "\n\nType \"Y\" if you are done, otherwise type \"N\"";
										break;
				}
			}while(toupper(another) != 'Y' && toupper(another) != 'N');
		}
	}
	else
	{
		do
			{
				cout << "Please enter in the cell number you wish to change: ";
				cin >> cellNumber;

				if(cellNumber == 0) cout << "\n\nCell 0 is protected and cannot be changed!\n";
			}while(cellNumber < 1 || cellNumber > 99);

		while(done == false)
		{
			cout << "\n\nEditing cell number " << cellNumber;
			do
			{
				cout << "\nPlease enter in the value (can include a negative): ";
				cin >> cellValue;

				if(cellValue < -999 || cellValue > 999)
					cout << "\n\nPlease enter a value between -999 and 999.\n";

			}while(cellValue < -999 || cellValue > 999);

			// Actually changing the value of the cell
			t.setMemCells(cellNumber, cellValue);
			++cellNumber;

			do
			{
				cout << "\nWould you like to edit another?(Y/N) ";
				cin >> another;
				switch(toupper(another))
				{
					case 'Y' : break;

					case 'N' : done = true;
									   break;

					default : cout << "\n\nType \"Y\" if you are done, otherwise type \"N\"";
										break;
				}
			}while(toupper(another) != 'Y' && toupper(another) != 'N');
		}
	}
}


// FUNCTION
// This will edit the input of the SC emulation

void EditInput(SimpleComputer& t)
{
	int cellNumber, cellValue;
	bool done = false;
	char another;

	cout << "Do you want to be prompted for the next input number? ";
	cin >> another;
	if(toupper(another) == 'Y')
	{
		while(done == false)
		{
			do
			{
				cout << "Please enter in the input number you wish to change: ";
				cin >> cellNumber;
			}while(cellNumber < 0 || cellNumber > 99);

			do
			{
				cout << "Please enter in the value (can include a negative): ";
				cin >> cellValue;

				if(cellValue < -999 || cellValue > 999)
					cout << "\n\nPlease enter a value between -999 and 999.\n";

			}while(cellValue < -999 || cellValue > 999);

			// Actually changing the value of the cell
			t.setInpCells(cellNumber - 1, cellValue);

			do
			{
				cout << "\nWould you like to edit another?(Y/N) ";
				cin >> another;
				switch(toupper(another))
				{
					case 'Y' : break;

					case 'N' : done = true;
									   break;

					default : cout << "\n\nType \"Y\" if you are done, otherwise type \"N\"";
										break;
				}
			}while(toupper(another) != 'Y' && toupper(another) != 'N');
		}
	}
	else
	{
		do
			{
				cout << "Please enter in the input number you wish to change: ";
				cin >> cellNumber;
			}while(cellNumber < 0 || cellNumber > 99);

		while(done == false)
		{
			cout << "\n\nEditing input number " << cellNumber;
			do
			{
				cout << "\nPlease enter in the value (can include a negative): ";
				cin >> cellValue;

				if(cellValue < -999 || cellValue > 999)
					cout << "\n\nPlease enter a value between -999 and 999.\n";

			}while(cellValue < -999 || cellValue > 999);

			// Actually changing the value of the cell
			t.setInpCells(cellNumber - 1, cellValue);
			++cellNumber;

			do
			{
				cout << "\nWould you like to edit another?(Y/N) ";
				cin >> another;
				switch(toupper(another))
				{
					case 'Y' : break;

					case 'N' : done = true;
									   break;

					default : cout << "\n\nType \"Y\" if you are done, otherwise type \"N\"";
										break;
				}
			}while(toupper(another) != 'Y' && toupper(another) != 'N');
		}
	}
}


// FUNCTION
// This outputs the Simple Computer when ever called

void OutputSC(SimpleComputer t)
{
	//Outputting Accumulator, IR and PC
	cout << "Accumulator     IR      PC\n" << "        "
			 << setfill('0') << setw(3) << t.getAccum() << "    "
			 << setfill('0') << setw(3) << t.getIR() << "      "
			 << setfill('0') << setw(2) << t.getPC();

	//Outputting Memory
	cout << "\n\nMemory\n";
	for(int i = 0; i < 20; ++i)
	{
		// This if helps output a "0" if its a single digit
		if(i < 10) cout << "0";

		cout << i << ": " << setfill('0') << setw(3) << t.getMemory(i) << "  "
				 << i + 20 << ": " << setfill('0') << setw(3) << t.getMemory(i + 20) << "  "
				 << i + 40 << ": " << setfill('0') << setw(3) << t.getMemory(i + 40) << "  "
				 << i + 60 << ": " << setfill('0') << setw(3) << t.getMemory(i + 60) << "  "
				 << i + 80 << ": " << setfill('0') << setw(3) << t.getMemory(i + 80) << "  "
				 << "\n";
	}

	//Outputting Input and Output cards
	cout << "\nInput Card" << setfill(' ') << setw(15) << "Output Card\n";
	for(int i = 0; i < 15; ++i)
	{
		cout << setfill(' ') << setw(5) << i + 1 << ": " << setfill('0') << setw(3) << t.getInput(i)
				 << setfill(' ') << setw(9) << i + 1 << ": " << setfill('0') << setw(3) << t.getOutput(i) << "\n";
	}
	cout << "\n";
}


// FUNCTION
// This runs the actual SC program and outputs the rest

void RunSC(SimpleComputer& t)
{
	char choice1, choice2, stepChar;
	int tempPC, tempIR, i;
	bool stepBool = false;
	bool run = true;
	bool errorMsg = false;
	// Remembers where the input card is left
	int inpCtr = 0;
	int outCtr = 0;

	// Step check (asking if user wants to step through the program.
	do
	{
		cout << "Would you like to step through the program?(Y/N) ";
		cin >> stepChar;

		switch(toupper(stepChar))
		{
			case 'Y' : stepBool = true;
							   break;

			case 'N' : break;

			default : cout << "\n\nType \"Y\" if you are done, otherwise type \"N\"";
								break;
		}
	}while(toupper(stepChar) != 'Y' && toupper(stepChar) != 'N');

	// Program counter check
	do
	{
		cout << "\nWould you like to change the program counter?(Y/N) ";
		cin >> choice1;

		switch(toupper(choice1))
		{
			case 'Y' : cout << "\nWhat would you like to set it to? ";
								 cin >> tempPC;
								 t.setPC(tempPC);
							   break;

			case 'N' : tempPC = t.getPC();
								 break;

			default : cout << "\n\nType \"Y\" if you are done, otherwise type \"N\"";
								break;
		}
	}while(toupper(choice1) != 'Y' && toupper(choice1) != 'N');

	// Output card check
	for(int i = 0; i < 20; ++i)
	{
		if(t.getOutput(i) != 0)
		{
			do
			{
				cout << "\nWould you like to clear the output card before run?(Y/N) ";
				cin >> choice2;

				switch(toupper(choice2))
				{
					case 'Y' : t.clearOut();
									   break;

					case 'N' : break;

					default : cout << "\n\nType \"Y\" if you are done, otherwise type \"N\"";
										break;
				}
			}while(toupper(choice2) != 'Y' && toupper(choice2) != 'N');
			i = 19;
		}
	}

	// Now the SC is ran
	while(t.getMemory(tempPC) > 0 && t.getMemory(tempPC) < 900)
	{
		if(stepBool == true)
		{
			Header();
			OutputSC(t);

			cout << "\nPress enter to continue. ";
			cin.ignore(20, '\n');
			cin.get();
		} // end if

		tempIR = t.getMemory(tempPC);
		i = tempIR;
		i *= .01;
		SCFunctions(t, tempPC, inpCtr, outCtr, errorMsg);

		if(i == 6)
			t.setIR(tempIR);
		else
			t.setIR(t.getMemory(tempPC));

		++tempPC;
		t.setPC(tempPC);
	} // end while

	if(t.getMemory(tempPC) == 900)
			tempPC = 0;

	t.setPC(tempPC);

	Header();
	OutputSC(t);
	if(errorMsg == true)
		cout << "Error! Cannot change the contents of cell 00.\n\n";
}


// FUNCTION
// This houses all of the SC functions and rules to run the program

void SCFunctions(SimpleComputer& t, int& tempPC, int& inpCtr, int& outCtr, bool& errorMsg)
{
	int getMem, x, y, cellNumber, funcNumber, shift;
	getMem = t.getMemory(tempPC);
	funcNumber = getMem * .01;

	if(getMem == 0)
		cellNumber = 99;
	else
	{
		if(getMem < 100)
			cellNumber = getMem;
		else
		{
			if(getMem > 100)
				cellNumber = getMem - (funcNumber * 100);
		}
	}

	if(funcNumber == 0) // INP - Stores the input card into the given cell
	{
		if(t.getInput(inpCtr) == 0 && t.getInput(inpCtr + 1) == 0 && t.getInput(inpCtr + 2) == 0)
			tempPC = 899;
		else
			t.setMemCells(getMem, t.getInput(inpCtr));
		++inpCtr;
	}

	if(funcNumber == 1) // OUT - Takes contents of the given cell number and
											// 			 puts it into the output card
	{
		t.setOutCells(outCtr, t.getMemory(cellNumber));
		++outCtr;
	}

	if(funcNumber == 2) // ADD - Adds the given cell number to the accumulator
	{
		t.setAccum(t.getMemory(cellNumber) + t.getAccum());
	}

	if(funcNumber == 3) // SUB - Subtracts the given cell number from the accumulator
	{
		t.setAccum(t.getAccum() - t.getMemory(cellNumber));
	}

	if(funcNumber == 4) // LDA - Loads the accumulator to the given cell number
	{
		t.setAccum(t.getMemory(cellNumber));
	}

	if(funcNumber == 5) // STA - Stores the accumulator in the given cell number
	{
		if(cellNumber != 0)
			t.setMemCells(cellNumber, t.getAccum());
		else
		{
			errorMsg = true;
			tempPC = 899;
		}
	}

	if(funcNumber == 6) // JMP - Places the program counter to the cell number
	{
		t.setPC(cellNumber);
		t.setMemCells(99, ++tempPC);
		tempPC = --cellNumber;
	}

	if(funcNumber == 7) // TAC - Tests the accumulator to see if it is a negative.
											//			 If negative, sets the program counter to the cell
											//			 number
	{
		if(t.getAccum() < 0)
		{
			t.setPC(cellNumber);
			tempPC = --cellNumber;
		}
	}

	if(funcNumber == 8) // SHF - Shifts the accumulator left x times and then shifts
											//			 it right y times
	{
		x = (cellNumber) / 10;
		y = (cellNumber % 10);

		int tho = 0;
		int hun = (t.getAccum()) / 100;
		int ten = (t.getAccum() % 100) / 10;
		int one = (t.getAccum() %100) % 10;

		for(int i = 0; i < x; ++i)
		{
			tho = hun;
			hun = ten;
			ten = one;
			one = 0;
		}

		shift = (tho * 1000) + (hun * 100) + (ten * 10) + one;
		t.setAccum(shift);

		for(int i = 0; i < y; ++i)
		{
			one = ten;
			ten = hun;
			hun = tho;
			tho = 0;
		}

		shift = (tho * 1000) + (hun * 100) + (ten * 10) + one;
		t.setAccum(shift);
	}
}


// FUNCTION
// This is the menu that can clear the memory, input card, output card
// or all of the things in the SC

void ClearMenu(SimpleComputer& t)
{
	int choice;
	bool quit = false;

	do
	{
		cout << "What would you like to clear?\n"
		 		 << "1) Memory\n"
		 		 << "2) Input Card\n"
		 		 << "3) Output Card\n"
		 		 << "4) CPU\n"
		 	 	 << "5) Clear All\n"
		 	 	 << "6) Output All\n"
		 		 << "7) Return to previous menu\n\n";

		cin >> choice;

		switch(choice)
		{
			case 1 : Header();
							 t.clearMem();
							 cout << "Cleared the memory\n\n";
							 break;

			case 2 : Header();
							 t.clearInp();
							 cout << "Cleared the input card\n\n";
							 break;

			case 3 : Header();
							 t.clearOut();
							 cout << "Cleared the output card\n\n";
							 break;

			case 4 : Header();
							 t.clearCPU();
							 cout << "Cleared the CPU\n\n";
							 break;

			case 5 : Header();
							 t.clearMem();
							 t.clearInp();
							 t.clearOut();
							 t.clearCPU();
							 cout << "Cleared everything\n\n";
							 break;

			case 6 : Header();
							 OutputSC(t);
							 break;

			case 7 : Header();
							 quit = true;
							 break;

			default : Header();
								cout << "Please enter a valid option\n\n";
							  break;
		}
	}while(quit == false);
}


// FUNCTION
// This will show the vocabulary for the Simple Computer.

void HelpSC()
{
  cout << "0_ _"
 			 << "  INP"
 			 << "  INPut - Copy the input card into cell number\n "
 			 << "          _ _ , and advance the input device to the next\n "
 			 << "          card. If the input card is blank,\n "
 			 << "          then advance the input device, set the contents of the program\n "
 			 << "          counter to 00, and halt the SC processor.\n\n"
 			 << "1_ _"
 			 << "  OUT"
 			 << "  OUTput - Copy the contents of cell number _ _ onto the output\n "
 			 << "          card and advance the output device one card.\n\n"
 			 << "2_ _"
 			 << "  ADD"
 			 << "  ADD - Add the contents of cell number _ _ to the value of the\n "
 			 << "          accumulator.\n\n"
 			 << "3_ _"
 			 << "  SUB"
 			 << "  SUBtract - Subtract the contents of cell number _ _ from the value of\n "
 			 << "          the accumulator.\n\n"
 			 << "4_ _"
 			 << "  LDA"
 			 << "  LoaD Accumulator - Clear the accumulator and copy the contents of\n "
 			 << "          cell number_ _ into the accumulator.\n\n"
 			 << "5_ _"
 			 << "  STA"
 			 << "  STore Accumulator - Copy the least significant three digits of the\n "
 			 << "          accumulator into cell number _ _ .\n\n"
 			 << "6_ _"
 			 << "  JMP"
 			 << "  JuMP - Place the present value of the program counter into cell 99.\n "
 			 << "          Then, change the value of the program counter to correspond to\n "
 			 << "          cell number _ _ .\n\n"
 			 << "7_ _"
 			 << "  TAC"
 			 << "  Test ACcumulator - If the value of the accumulator is negative, change\n "
 			 << "          the value of the program counter to correspond to that of cell\n "
 			 << "          number _ _ .\n\n"
 			 << "8xy "
 			 << "  SHF"
 			 << "  SHiFt - Shift the accumulator left x digits, and then shift the result\n "
 			 << "          right y digits. With all left shifts, zeros enter the accumulator\n "
 			 << "          on the right. Similarly, with right shifts, zeros will enter the\n "
 			 << "          accumulator on the left.\n\n"
 			 << "9_ _"
 			 << "  HLT"
 			 << "  HaLT - Replace the value of the program counter with cell number _ _ and\n "
 			 << "          then halt the SC processor.\n\n";
}
