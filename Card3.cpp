#include "Card3.h"

#include"Ladder.h"
#include "Snake.h"
#include "CoinSet.h"

Card3::Card3(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; //set the inherited cardNumber data member with the card number
	BackDiceVal=0;
}
Card3::~Card3(void)
{}
void Card3::Apply(Grid* pGrid,Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);

	BackDiceVal=pPlayer->GetjustRolledDiceNum();
	int x,y;
	Output* pOut=pGrid->GetOutput();
	Input* pIn=pGrid->GetInput();
	pOut->PrintMessage("Card3: Backward Card: All other players will move backward the amount of current player dice roll. Click to continue...");
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Other Players will move "+std::to_string(BackDiceVal)+" cells backward...(click to continue)");
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
	int CurrentPlayerNumber=pPlayer->GetPlayernum();
	int OriginCellnum=1;
	Player *OtherPlayer;
	Cell *CurrentOtherPlayerCell;
	CellPosition CurrentOtherPlayerPosition; 	
	for (int i=0;i<MaxPlayerCount;i++)
	{
		if (CurrentPlayerNumber != i) //current player will not move, only other players will move
		{
			OtherPlayer=pGrid->GetOtherPlayer(i);
			CurrentOtherPlayerCell=OtherPlayer->GetCell();

			if(CurrentOtherPlayerCell->GetCellPosition().GetCellNum()==OriginCellnum)
			{
				 //dont do anything if all players or any player still at origin
			}
			else
			{
				OtherPlayer->Move(pGrid,-BackDiceVal);
			}
		}
	}
	pOut->ClearStatusBar();
}

void Card3::Save(ofstream& SaveAction,int type)
{
	if(type==4)
	{
		SaveAction << cardNumber << " " <<position.GetCellNum()<<endl;
	}
	else
	{
		return;
	}
}

void Card3::Load(ifstream & openFile,int type)
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