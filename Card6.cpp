#include "Card6.h"

Card6::Card6(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6here)
	pFreezed =NULL;

}
Card6::~Card6(void)
{
}

void Card6::ReadCardParameters(Grid* pGrid)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->ClearStatusBar();
	// 2- Read the parameters from the current player first read whether he chooses odd or even
	// then he chooses the number of turns to freeze the players in odd or even cells
	Player* Currplayer = pGrid->GetCurrentPlayer();
	Pnum = Currplayer->GetPlayernum();
	pOut->PrintMessage("Now choose the cells to freeze players at:please type yes for odd cells and no for even cells");
	string oe= pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	//validation check of odd or even cells
	if(oe=="yes") {OE = true;}
	else if (oe == "no") {OE = false;}
	while(oe!="no" && oe!="yes" && oe !="No" && oe != "Yes")
	{
		pGrid->PrintErrorMessage("Invalid please type yes or no");
		oe = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();
	}
   //now we nove to the turns part
	pOut->PrintMessage("Now choose the number of turns you want to freeze other players");
	 turns = pIn->GetInteger(pOut);
	 pOut->ClearStatusBar();
	 //validation check
	 while (turns > 99 || turns < 0)
	 {
		 pGrid->PrintErrorMessage("Invalid please type a valid number");
		 turns = pIn->GetInteger(pOut);
		 pOut->ClearStatusBar();
	 }
	// [ Note ]:
	// In Card6, we only need parameters OE and turns to work on them
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void Card6::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Freeze all players on cells from movinf for a certain no of turns
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (i != Pnum)
		{
			pFreezed = pGrid->GetOtherPlayer(i);
			cFreeze = pFreezed->GetCell();
			cFreezed = cFreeze->GetCellPosition();
			int cellNum = cFreezed.GetCellNumFromPosition(cFreezed);
			if (cellNum % 2 != 0 && OE == true)//check for odd
			{
				pGrid->FreezePlayer(pFreezed, turns);
			}
			else if (cellNum % 2 == 0 && OE == false)//check for even
			{
				pGrid->FreezePlayer(pFreezed, turns);
			}
		}
	}
	if (pFreezed = NULL);
	{
		pGrid->PrintErrorMessage("Sorry there are no players you can freeze");
	}
}

void Card6::Save(ofstream& SaveAction, int type)
{
	if (type == 4)
	{
		SaveAction << cardNumber << " " << position.GetCellNum() << " " << OE << " " << turns <<  endl;
	}
	else
	{
		return;
	}
}

void Card6::Load(ifstream& openFile, int type)
{
	int cellNum;
	if (type == 4)
	{
		openFile >> cellNum >> OE >> turns;
		if (cellNum > 0 && cellNum < 99)
		{
			position = position.GetCellPositionFromNum(cellNum);
		}
	}
	else
	{
		return;
	}
}
