#include "RollDiceAction.h"
#include <time.h> // used to in srand to generate random numbers with different seed

#include "Grid.h"
#include "Player.h"

#include "Card.h"
#include "Ladder.h"

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp) // Initializes the pManager pointer of Action with the passed pointer
{}
RollDiceAction::~RollDiceAction()
{}
void RollDiceAction::ReadActionParameters()
{// no parameters to read from user
}
void RollDiceAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	//ReadActionParameters();

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
	//1- we here need to check if the player is prevented or frozen
	bool PR = CurrPlayer->GetisPrevented();
	bool FR = CurrPlayer->GetisFreezed();
	int no = CurrPlayer->GetturnsToFreeze();

	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
	if(PR == true) 
	{
		CurrPlayer->SetisPrevented(false);
		pOut->PrintMessage("You Are Prevented To Move This Turn. (Click to continue....)");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		diceNumber=0;
	}
	if(FR == true)
	{
		CurrPlayer->SetturnsToFreeze(no - 1);
		pOut->PrintMessage("You Are Freezed ! You Can't Move. (Click to continue....)");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		diceNumber=0;
	}
	if(CurrPlayer->GetturnsToFreeze() == 0)
	{
		CurrPlayer->SetisFreezed(false);
	}
	if(diceNumber>0)
	{
		pOut->PrintMessage("Player "+std::to_string(Currplayernum)+" Rolled the Dice with value: "+std::to_string(diceNumber)+" Click to Continue...");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
	}
	// 3- Get the "current" player from pGrid
	CurrPlayer=pGrid->GetCurrentPlayer();
	// 4- Move the currentPlayer using function Move of class player
	CurrPlayer->Move(pGrid,diceNumber);
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	
}
/*
Ladder* ladder;
	
	if (1) //reaches a start of a ladder
	{
		pOut->PrintMessage("You have reached a Ladder. Click to continue...");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		CurrPlayer=pGrid->GetCurrentPlayer();
		CurrPlayer->Move(pGrid,diceNumber);
		pGrid->AdvanceCurrentPlayer(); // Move to the top of the ladder
		ladder->Apply(pGrid,CurrPlayer);
	}
	if (1) //reaches a start of a snake
	{
		pOut->PrintMessage("You have reached a Snake. Click to continue...");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		pGrid->AdvanceCurrentPlayer(); // Move to the bottom of the snake
	}
	if (1 && CurrPlayer->GetWallet()) //reaches a card of monopoly that has not been bought yet and cuurrent player have enough money
	{
		pOut->PrintMessage("You have reached a City. Do you want to buy it? (y/n)");
		string option=pIn->GetSrting(pOut);
		if (option=="y" || option=="Y")
		{
			//If the user chooses to buy, deduct the amount of money from his wallet and assign all the cells that contain this city to him.
			//Card::Apply(pGrid,CurrPlayer);
		}
		else if (option=="n" || option=="N")
		{
			pOut->PrintMessage("Invalid Character");
		}
		else 
		//pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
	}
	if (1) //reaches a card of monopoly that is bought by another player
	{
		pOut->PrintMessage("You have reached a bought city. Click to continue...");
		pIn->GetPointClicked(x,y);
		//Deduct the amount of fees from his wallet, Add the amount of fees to the owner’s wallet.
		pOut->ClearStatusBar();
	}
	if (1) //reaches a card of any other type
	{
		pOut->PrintMessage("You have reached a cardN. Click to continue..."); //cardN is card name
		pIn->GetPointClicked(x,y);
		//wait for user click, perform necessary actions and print appropriate messages
		pOut->ClearStatusBar();
	}
*/