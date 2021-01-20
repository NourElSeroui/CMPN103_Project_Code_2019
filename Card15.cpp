#include "Card15.h"


Card15::Card15(CellPosition & pos) :Card(pos)
{
	cardNumber=15;
	pOwner=NULL;
	InputTurns=0;
	IsApplied=false;
}

void Card15::ReadCardParameters(Grid * pGrid)
{
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	pOut->PrintMessage("Enter The Number Of Turns To Take Fees From All Cities....");
	while(InputTurns<1)
	{
		InputTurns=pIn->GetInteger(pOut);
		if(InputTurns<1)
		{
			pOut->PrintMessage("ERROR ! Number Of Turns Must Be Greater Than 1. Re-enter The Number Of Turns....  ");
		}
	}
}

void Card15::Apply(Grid * pGrid,Player * pPlayer)
{
	int a,b;
	if(!IsApplied)
	{
		Card::Apply(pGrid,pPlayer);
		pOwner=pPlayer;
		pOwner->setHasBenefitAll(true);
		pOwner->setMaxCount(InputTurns);
		IsApplied=true;
	}
	else
	{
		pOut->PrintMessage("No Effect On Player : " +to_string(pPlayer->GetPlayernum())+ " Because Another Player Is Already Taking The Benefits. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
	}
}

void Card15::setInputTurns(int it)
{
	InputTurns=it;
}

int Card15::getInputTurns() const
{
	return InputTurns;
}


void Card15::Save(ofstream & SaveAction,int type)
{
	if(type==4)
	{
		SaveAction << cardNumber << " " << position.GetCellNum() << " " << InputTurns << endl;
	}
}

void Card15::Load(ifstream & openFile,int type)
{
	int cellNum;
	if(type==4)
	{
		openFile >> cellNum >> InputTurns;
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


Card15::~Card15()
{
}
