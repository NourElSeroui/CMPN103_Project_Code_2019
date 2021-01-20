#include "Card5.h"

Card5::Card5(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
	pFired = NULL;
	Pnum = 0;
	cFire = NULL;
	v = 0;
	h = 0;

}
Card5::~Card5(void)
{
}

void Card5::ReadCardParameters(Grid* pGrid)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	}

void Card5::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	int x,y;
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	CellPosition gnd(8,0);
	pOut->ClearStatusBar();
	// 2- Read the coordinates of the current player
	pOut->PrintMessage("we are now firing all players that are on same row or column with the current player. (Click to continue....)");
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
	Player* Currplayer = pGrid->GetCurrentPlayer();
	Cell* CurrCell = Currplayer->GetCell();
	CellPosition Currp = CurrCell->GetCellPosition();
	Pnum = Currplayer->GetPlayernum();
	v = Currp.VCell();
	h = Currp.HCell();
	// [ Note ]:
	// In Card5, we don't need no parameters because we can access the parameters of the current player already
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action
	// 3- Clear the status bar
	pOut->ClearStatusBar();
	// 4- Prevent the other player on same row or column from moving
	//checking on all players
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (i != Pnum)
		{
			pFired = pGrid->GetOtherPlayer(i);
			cFire = pFired->GetCell();
			cFired = cFire->GetCellPosition();
			int V = cFired.VCell();
			int H = cFired.HCell();
			if (V == v || H == h)//check for horizontal and vertical cells on the same axis
			{
				pGrid->UpdatePlayerCell(pFired, gnd); //moving fired player to cell1
				int Fwallet = pFired->GetWallet();
				pFired->SetWallet(Fwallet / 2);// decreamenting his wallet by half its value
			}


		}
	}
	if (pFired == NULL);
	{
		pGrid->PrintErrorMessage("Sorry there are no players you can fire");
	}
}

void Card5::Save(ofstream& SaveAction, int type)
{
	if (type == 4)
	{
		SaveAction << cardNumber << " " << position.GetCellNum() << endl;
	}
	else
	{
		return;
	}
}

void Card5::Load(ifstream& openFile, int type)
{
	int cellNum;
	if (type == 4)
	{
		openFile >> cellNum;
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
