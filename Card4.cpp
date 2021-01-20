#include "Card4.h"

Card4::Card4(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (4 here)
	pPrevented=NULL;
}
Card4::~Card4(void)
{
}

void Card4::ReadCardParameters(Grid* pGrid)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read a cellPosition from the user using the Input class and set the cPrevented,pPrevented parameters with it
	//    Don't forget to first print to a descriptive message to the user like:"New PreventCard4: Click on prevented player cell ..."
}

void Card4::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Player * Currplayer = pGrid->GetCurrentPlayer();
	int x, y;
	Card::Apply(pGrid, pPlayer);
	pOut->PrintMessage("Choose other player to be prevented from rolling the dice by clicking on its cell");
	cPrevented= pIn->GetCellClicked();
	pOut->ClearStatusBar();
	for (int i=0;i<MaxPlayerCount;i++)
	{
		if(pGrid->GetOtherPlayer(i) != Currplayer)
		{
			if(cPrevented.GetCellNumFromPosition(cPrevented) == pGrid->GetOtherPlayer(i)->GetCell()->GetCellPosition().GetCellNum())
			{
				pOut->PrintMessage("OPTION : Player : " +to_string(pGrid->GetOtherPlayer(i)->GetPlayernum()) + " (Y/N) ");
				decision = "x";
				while (decision != "Y" && decision != "y" && decision != "N" && decision != "n")
				{
					decision=pIn->GetSrting(pOut);
					if(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
					{
						pOut->PrintMessage("ERROR ! You Entered A Wrong Character. Re-enter : ");
					}
				}
				if(decision == "Y" || decision == "y")
				{
					pPrevented = pGrid->GetOtherPlayer(i);	
					pGrid->PreventPlayer(pPrevented);
					pOut->PrintMessage("You Chose To Prevent Player : " +to_string(pPrevented->GetPlayernum())+ " From Moving. (Click to continue....)");
					pIn->GetPointClicked(x,y);
					pOut->ClearStatusBar();
					return;
				}
			}
		}
	}
	while(pPrevented==NULL)
	{
		pGrid->PrintErrorMessage("Invalid Cell. Please Re-Click on a cell....");
		cPrevented = pIn->GetCellClicked();
		pOut->ClearStatusBar();
		for (int i=0;i<MaxPlayerCount;i++)
		{
			if(pGrid->GetOtherPlayer(i) != Currplayer)
			{
				if(cPrevented.GetCellNumFromPosition(cPrevented) == pGrid->GetOtherPlayer(i)->GetCell()->GetCellPosition().GetCellNum())
				{
					pOut->PrintMessage("OPTION : Player : " +to_string(pGrid->GetOtherPlayer(i)->GetPlayernum()) + " (Y/N) ");
					decision = "x";
					while (decision != "Y" && decision != "y" && decision != "N" && decision != "n")
					{
						decision=pIn->GetSrting(pOut);
						if(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
						{
							pOut->PrintMessage("ERROR ! You Entered A Wrong Character. Re-enter : ");
						}
					}
					if(decision == "Y" || decision == "y")
					{
						pPrevented = pGrid->GetOtherPlayer(i);
						pGrid->PreventPlayer(pPrevented);
						pOut->PrintMessage("You Chose To Prevent Player : " +to_string(pPrevented->GetPlayernum())+ " From Moving. (Click to continue....)");
						pIn->GetPointClicked(x,y);
						pOut->ClearStatusBar();
						return;
					}
				}
			}
		}
	}
	// [ Note ]:
	// In Card4, the only parameter of Card4 is the "prevented player cell position" 
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();

	// 2- Prevent the other player from moving
}

void Card4::Save(ofstream & SaveAction,int type)
{
	if(type==4)
	{
		SaveAction << cardNumber << " " << position.GetCellNum() << endl;
	}
	else
	{
		return;
	}
}

void Card4::Load(ifstream & openFile,int type)
{
	int cellNum;
	if(type==4)
	{
		openFile >> cellNum;
		if(cellNum > 0 && cellNum < 99)
		{
			position=position.GetCellPositionFromNum(cellNum);
		}
	}
	else
	{
		return;
	}
}
