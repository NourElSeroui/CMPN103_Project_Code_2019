#include "CoinSet.h"

CoinSet::~CoinSet(void)
{}
CoinSet::CoinSet(const CellPosition & pos) : GameObject(pos)
{}
void CoinSet::Draw(Output* pOut) const
{
	pOut->DrawCoinSet(position);
}
void CoinSet::Apply(Grid* pGrid, Player* pPlayer)
{
	Output *pOut=pGrid->GetOutput();
	Input *pIn=pGrid->GetInput();
	int x,y;
	pOut->PrintMessage("You have reached a CoinSet with Value:"+to_string(Amount) +", Click to continue ... ");
	pIn->GetPointClicked(x,y);
	pPlayer->SetWallet(pPlayer->GetWallet() + Amount);
	pOut->ClearStatusBar();
}
int CoinSet::GetCoinsetNumber()
{
	return 16;
}
//readparameters to get user input coinset value :todo
void CoinSet::ReadCoinSetParameters(Grid * pGrid)
{
	Input *pIn;
	Output *pOut;
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	pOut->PrintMessage("New CoinSet: Enter its amount ...");
	Amount=pIn->GetInteger(pOut);
	while (Amount<0)
	{
		pGrid->PrintErrorMessage("Invalid Wallet Amount please Enter A Valid Amount!");
		Amount=pIn->GetInteger(pOut);
	}
	pOut->ClearStatusBar();
}

void CoinSet::Save(ofstream & SaveAction,int type)
{
	if(type==3)
	{
		SaveAction << position.GetCellNum() << " " << Amount << endl;
	}
	else
	{
		return;
	}
}

void CoinSet::Load(ifstream & openFile,int type)
{
	int cellNum;
	if(type==3)
	{
		openFile >> cellNum >> Amount ;
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