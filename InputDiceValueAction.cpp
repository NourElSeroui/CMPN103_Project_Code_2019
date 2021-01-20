#include "InputDiceValueAction.h"

#include "Grid.h"
#include "Player.h"

//Instead of generating a random value for the dice, ask the user to insert a value and then do the necessary actions similar to rolling a dice.

InputDiceValueAction::~InputDiceValueAction(void)
{}
InputDiceValueAction::InputDiceValueAction(ApplicationManager *pApp) : Action(pApp)
{
}
void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid=pManager->GetGrid();
	Output* pOut=pGrid->GetOutput();
	Input* pIn=pGrid->GetInput();
	pOut->PrintMessage("Please Insert a Dice Value between 1-6 to Roll the Dice ..");
	DiceValue=pIn->GetInteger(pOut);
	while (DiceValue<1 || DiceValue>6)
	{
		pOut->PrintMessage("Invalid! Please Insert a Dice Value between 1-6 ..");
		DiceValue=pIn->GetInteger(pOut);
	}
	pOut->ClearStatusBar();
}
void InputDiceValueAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==
	Grid *pGrid=pManager->GetGrid();
	Player *CurrPlayer;
	CurrPlayer=pGrid->GetCurrentPlayer();
	int Currplayernum=CurrPlayer->GetPlayernum();
	int x,y;
	Output* pOut=pGrid->GetOutput();
	Input* pIn=pGrid->GetInput();
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame()==true)
	{
		pOut->PrintMessage("The Game has Ended");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		return;
	}
	// -- If not ended, do the following --:
	bool PR = CurrPlayer->GetisPrevented();
	bool FR = CurrPlayer->GetisFreezed();
	if (PR == true) 
	{
		pOut->PrintMessage("You Are Prevented To Move This Turn. (Click to continue....)");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		CurrPlayer->SetisPrevented(false);
		DiceValue=0;
	}
	if(FR == true)
	{
		CurrPlayer->SetturnsToFreeze(CurrPlayer->GetturnsToFreeze() - 1);
		pOut->PrintMessage("You Are Freezed ! You Can't Move. (Click to continue....)");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		DiceValue=0;
	}
	if(CurrPlayer->GetturnsToFreeze() == 0)
	{
		CurrPlayer->SetisFreezed(false);
	}

	if(DiceValue>0)
	{
		pOut->PrintMessage("Player "+std::to_string(Currplayernum)+" Rolled the Dice with value: "+std::to_string(DiceValue)+" Click to Continue...");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
	}
	// 3- Get the "current" player from pGrid

	// 4- Move the currentPlayer using function Move of class player
	CurrPlayer->Move(pGrid,DiceValue);
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
}

/*
ReadActionParameters();
	Player *pPlayer;

	Grid* pGrid=pManager->GetGrid();
	Output* pOut=pGrid->GetOutput();
	Input* pIn=pGrid->GetInput();

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame()==true)
		return;
	// -- If not ended, do the following --:
*/