/*
*********************************************************************
Patrick Barnum
CS 3A
Fall 2007
File Name: emuHeader.h
This is the specification file for class SimpleComputer and remaining
functions
The Simple Computer Emulator Project
*********************************************************************


*********************************************************************
Member function SimpleComputer (the constructor)
Preconditions: The first function that is called

Postconditions: sets all instance variables to 0
*********************************************************************
SimpleComputer();


*********************************************************************
Member function getMemory
Preconditions: Instance variable memCells[100] has been filled

Postconditions: Returns the array sub the user specified
*********************************************************************
getMemory(int i);


*********************************************************************
Member function getInput
Preconditions: Instance variable inpCells[100] has been filled

Postconditions: Returns the array sub the user specified
*********************************************************************
getInput(int i);


*********************************************************************
Member function getOutput
Preconditions: Instance variable outCells[100] has been filled

Postconditions: Returns the array sub the user specified
*********************************************************************
getOutput(int i);


*********************************************************************
Member function getAccum
Preconditions: Instance variable accumulator has been filled

Postconditions: Returns the number stored in accumulator
*********************************************************************
getAccum();


*********************************************************************
Member function getIR
Preconditions: Instance variable ir has been filled

Postconditions: Returns the number stored in ir
*********************************************************************
getIR();


*********************************************************************
Member function getPC
Preconditions: Instance variable pc has been filled

Postconditions: Returns the number stored in pc
*********************************************************************
getPC();


*********************************************************************
Member function setAccum
Preconditions: Instance variable accumulator has been filled

Postconditions: Changes accumulator to what the user specified
*********************************************************************
setAccum(int a);


*********************************************************************
Member function setIR
Preconditions: Instance variable ir has been filled

Postconditions: Changes ir to what the user specified
*********************************************************************
setIR(int i);


*********************************************************************
Member function setPC
Preconditions: Instance variable pc has been filled

Postconditions: Changes pc to what the user specified
*********************************************************************
setPC(int p);


*********************************************************************
Member function setMemCells
Preconditions: Instance variable memCells[100] has been filled

Postconditions: Changes the variable' sub to what the user specified
*********************************************************************
setMemCells(int cc, int cv);


*********************************************************************
Member function setInpCells
Preconditions: Instance variable inpCells[100] has been filled

Postconditions: Changes the variable' sub to what the user specified
*********************************************************************
setInpCells(int cn, int cv);


*********************************************************************
Member function setOutCells
Preconditions: Instance variable outCells[100] has been filled

Postconditions: Changes the variable' sub to what the user specified
*********************************************************************
setOutCells(int cn, int cv);


*********************************************************************
Member function clearMem
Preconditions: Instance variable memCells[100] has been filled

Postconditions: Sets the variable back to 0
*********************************************************************
clearMem();


*********************************************************************
Member function clearInp
Preconditions: Instance variable inpCells[100] has been filled

Postconditions: Sets the variable back to 0
*********************************************************************
clearInp();


*********************************************************************
Member function clearOut
Preconditions: Instance variable outCells[100] has been filled

Postconditions: Sets the variable back to 0
*********************************************************************
clearOut();


*********************************************************************
Member function clearCPU
Preconditions: Instance variables accumulator, ir and pc has been
							 filled

Postconditions: Sets the variables back to 0
*********************************************************************
clearCPU();


*********************************************************************
Function Header
Preconditions: User input

Postconditions: Erases everything on the screen and reloads the
								header
*********************************************************************
Header();


*********************************************************************
Function CreateNewSC
Preconditions: User input

Postconditions: New Simple Computer class has been made
*********************************************************************
CreateNewSC();


*********************************************************************
Function OpenSC
Preconditions: User input

Postconditions: New Simple Computer class has been made and all
								information from the specified file has filled in 
								the new class
*********************************************************************
OpenSC();


*********************************************************************
Function SaveSC
Preconditions: The Simple Computer class is filled

Postconditions: The information from the class has been written to
								a specified file
*********************************************************************
SaveSC(SimpleComputer& t);


*********************************************************************
Function EmulationMenu
Preconditions: The Simple Computer class is filled

Postconditions: Directs user to specified option
*********************************************************************
EmulationMenu(SimpleComputer t, bool exist);


*********************************************************************
Function EditSC
Preconditions: The Simple Computer class is filled

Postconditions: Directs user to specified option
*********************************************************************
EditSC(SimpleComputer& t);


*********************************************************************
Function EditMemory
Preconditions: The Simple Computer class is filled

Postconditions: The class' instance variable memCells[100] has been
								changed
*********************************************************************
EditMemory(SimpleComputer& t);


*********************************************************************
Function EditInput
Preconditions: The Simple Computer class is filled

Postconditions: The class' instance variable inpCells[100] has been
								changed
*********************************************************************
EditInput(SimpleComputer& t);


*********************************************************************
Function OutputSC
Preconditions: The Simple Computer class is filled

Postconditions: The class is now displayed in a neat table format
*********************************************************************
OutputSC(SimpleComputer t);


*********************************************************************
Function RunSC
Preconditions: The Simple Computer class is filled

Postconditions: The class is now displayed in a neat table format
								with newly changed instance variables
*********************************************************************
RunSC(SimpleComputer& t);


*********************************************************************
Function SCFunctions
Preconditions: The Simple Computer class is filled

Postconditions: Determined what process needs to happen with the
								information given from the instance variables pc,
								memCells[100] and inpCells[100]
*********************************************************************
SCFunctions(SimpleComputer& t, int& tempPC, int& inpCtr, int& outCtr, bool& errorMsg);


*********************************************************************
Function ClearMenu
Preconditions: The Simple Computer class is filled

Postconditions: Directs user to specified option
*********************************************************************
ClearMenu(SimpleComputer& t);


*********************************************************************
Function HelpSC
Preconditions: User input

Postconditions: The Simple Computer operation codes have been 
								displayed
*********************************************************************
HelpSC();	
*/ 

//// Include files ////
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <winsioux.h>

using namespace std;

///// Classes /////
/* 
	 SimpleComputer class

   This is to be called when creating a new simple computer.
   
   Each newly created simple computer will be a temp and can be saved at a later
   time.
*/

class SimpleComputer
{
public:
	SimpleComputer();
	int getMemory(int i);
	int getInput(int i);
	int getOutput(int i);
  int getAccum();
  int getIR();
  int getPC();
  void setAccum(int a);
  void setIR(int i);
  void setPC(int p);
  void setMemCells(int cc, int cv);
  void setInpCells(int cn, int cv);
  void setOutCells(int cn, int cv);
  void clearMem();
  void clearInp();
  void clearOut();
  void clearCPU();

private:
  int memCells[100];
  int inpCells[100];
  int outCells[100];
  int accumulator;
  int ir;
  int pc;
};

/////// Functions ///////
void Header();
void CreateNewSC();
void OpenSC();
void SaveSC(SimpleComputer& t);
void EmulationMenu(SimpleComputer t, bool exist);
void EditSC(SimpleComputer& t);
void EditMemory(SimpleComputer& t);
void EditInput(SimpleComputer& t);
void OutputSC(SimpleComputer t);
void RunSC(SimpleComputer& t);
void SCFunctions(SimpleComputer& t, int& tempPC, int& inpCtr, int& outCtr, bool& errorMsg);
void ClearMenu(SimpleComputer& t);
void HelpSC();
