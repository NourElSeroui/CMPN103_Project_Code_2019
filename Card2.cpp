#include "Card2.h"
#include"Ladder.h"
#include "Snake.h"
#include "CoinSet.h"
#include "Card.h"

Card2::Card2(const CellPosition & pos) : Card(pos)
{
	cardNumber=2;
}

void Card2::Apply(Grid* pGrid,Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	int x,y;
	Input* pIn= pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int type=0;
	pOut->PrintMessage("Enter A Number To Choose A Game Object To Go To. (1 -> Ladder)/(2 -> Snake)/(3->CoinSet)/(4->Cards)....");
	type=pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
	Ladder* l=pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	Snake* s=pGrid->GetNextSnake(pPlayer->GetCell()->GetCellPosition());
	CoinSet* c=pGrid->GetNextCoinSet(pPlayer->GetCell()->GetCellPosition());
	int cellNum=(pPlayer->GetCell()->GetCellPosition().GetCellNum());
	cellNum++;
	CellPosition pos(cellNum);
	Card* cr=pGrid->GetNextCard(pos,0); //0 means ANY next card possible, unlike defining cardNumber with a number to go to a specific card.
	switch (type)
	{
	case 1:

		if(l)
		{
			pGrid->UpdatePlayerCell(pPlayer,l->GetPosition());
			l->Apply(pGrid,pPlayer);
		}
			else
		{
			pOut->PrintMessage("No ladders found... (click to continue)");
			pIn->GetPointClicked(x,y);
			pOut->ClearStatusBar();
			return;
		}
		break;
	case 2:

		if(s)
		{
			pGrid->UpdatePlayerCell(pPlayer,s->GetPosition());
			s->Apply(pGrid,pPlayer);
		}
			else
		{
			pOut->PrintMessage("No snakes found... (click to continue)");
			pIn->GetPointClicked(x,y);
			pOut->ClearStatusBar();
			return;
		}
		break;
	case 3:
		if(c)
		{
			pGrid->UpdatePlayerCell(pPlayer,c->GetPosition());
			c->Apply(pGrid,pPlayer);
		}
		else
		{
			pOut->PrintMessage("No coinSet found... (click to continue)");
			pIn->GetPointClicked(x,y);
			pOut->ClearStatusBar();
			return;
		}
		break;
	case 4:
		if(cr)
		{
			pGrid->UpdatePlayerCell(pPlayer,cr->GetPosition());
			cr->Apply(pGrid,pPlayer);
		}
		else
		{
			pOut->PrintMessage("No cards found... (click to continue)");
			pIn->GetPointClicked(x,y);
			pOut->ClearStatusBar();
			return;
		}
		break;
	default:
		break;
}
}

void Card2::Save(ofstream& SaveAction,int type)
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

void Card2::Load(ifstream & openFile,int type)
{
	int cellNum;
	if(type==4)
	{
		openFile >> cardNumber >> cellNum; 
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

Card2::~Card2(void)
{
}