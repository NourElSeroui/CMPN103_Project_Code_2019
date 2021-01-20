#include "Card12.h"

Card12::Card12(CellPosition & pos) :Card(pos)
{
	cardNumber=12;
	whichCard=0;
	pOwner=NULL;
}

void Card12::ReadCardParameters(Grid * pGrid)
{
}

void Card12::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	int count=0;
	bool f=1;
	int a,b;
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	while(f==1)
	{
		pOut->PrintMessage("Enter the name of the city to take.... ");
		z=pIn->GetSrting(pOut);
		if(z=="Cairo" || z=="cairo")
		{
			whichCard=1;
			pOut->PrintMessage("You chose Cairo. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			CellPosition poCard(8,0);
			Cairo= dynamic_cast<Card7 *>(pGrid->GetNextCard(poCard,7));
			if(Cairo)
			{
				exist=1;
			}
			else
			{
				exist=0;
			}

			while(f==1)
			{
				if(!exist)
				{
					pOut->PrintMessage("ERROR ! The entered city does not exist. Please re-enter. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					f=1;
				}
				else
				{
					f=0;
					count++;
				}
			}
		}
		if(z=="Alex" || z=="alex")
		{
			whichCard=2;
			pOut->PrintMessage("You chose Alex. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			CellPosition poCard(8,0);
			Alex= dynamic_cast<Card8 *>(pGrid->GetNextCard(poCard,8));
			if(Alex)
			{
				exist=1;
			}
			else
			{
				exist=0;
			}

			while(exist==1)
			{
				if(!exist)
				{
					pOut->PrintMessage("ERROR ! The entered city does not exist. Please re-enter. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					f=1;
				}
				else
				{
					f=0;
					count++;
				}
			}
		}
		if(z=="Aswan" || z=="aswan")
		{
			whichCard=3;
			pOut->PrintMessage("You chose Aswan. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			CellPosition poCard(8,0);
			Aswan= dynamic_cast<Card9 *>(pGrid->GetNextCard(poCard,9));
			if(Aswan)
			{
				exist=1;
			}
			else
			{
				exist=0;
			}

			while(exist==1)
			{
				if(!exist)
				{
					pOut->PrintMessage("ERROR ! The entered city does not exist. Please re-enter. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					f=1;
				}
				else
				{
					f=0;
					count++;
				}
			}
		}
		if(z=="Luxor" || z=="luxor")
		{
			whichCard=4;
			pOut->PrintMessage("You chose Luxor. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			CellPosition poCard(8,0);
			Luxor= dynamic_cast<Card10 *>(pGrid->GetNextCard(poCard,10));
			if(Luxor)
			{
				exist=1;
			}
			else
			{
				exist=0;
			}

			while(exist==1)
			{
				if(!exist)
				{
					pOut->PrintMessage("ERROR ! The entered city does not exist. Please re-enter. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					f=1;
				}
				else
				{
					f=0;
					count++;
				}
			}
		}
		if(z=="Hurghada" || z=="hurghada")
		{
			whichCard=5;
			pOut->PrintMessage("You chose Hurghada. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			CellPosition poCard(8,0);
			Hurghada= dynamic_cast<Card11 *>(pGrid->GetNextCard(poCard,11));
			if(Hurghada)
			{
				exist=1;
			}
			else
			{
				exist=0;
			}

			while(exist==1)
			{
				if(!exist)
				{
					pOut->PrintMessage("ERROR ! The entered city does not exist. Please re-enter. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					f=1;
				}
				else
				{
					f=0;
					count++;
				}
			}
		}
		else
		{
			if(count == 0)
			{
				pOut->PrintMessage("ERROR ! The entered characters doesn't match any city !! Please re-enter.. (Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				f=1;
			}
		}
	}
	pOwner = pGrid->GetCurrentPlayer();
	switch(whichCard)
	{
	case 1: 
		Cairo->SetCityOwner(pOwner);
		Cairo->SetBought(true);
		Cairo->SetisOwned(true);
		pOut->PrintMessage("This city is now owned by player " + to_string(pOwner->GetPlayernum()) + "(Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		break;
	case 2:
		Alex->SetCityOwner(pOwner);
		Alex->SetBought(true);
		Alex->SetisOwned(true);
		pOut->PrintMessage("This city is now owned by player " + to_string(pOwner->GetPlayernum()) + "(Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		break;
	case 3:
		Aswan->SetCityOwner(pOwner);
		Aswan->SetBought(true);
		Aswan->SetisOwned(true);
		pOut->PrintMessage("This city is now owned by player " + to_string(pOwner->GetPlayernum()) + "(Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		break;
	case 4: 
		Luxor->SetCityOwner(pOwner);
		Luxor->SetBought(true);
		Luxor->SetisOwned(true);
		pOut->PrintMessage("This city is now owned by player " + to_string(pOwner->GetPlayernum()) + "(Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		break;
	case 5:
		Hurghada->SetCityOwner(pOwner);
		Hurghada->SetBought(true);
		Hurghada->SetisOwned(true);
		pOut->PrintMessage("This city is now owned by player " + to_string(pOwner->GetPlayernum()) + "(Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		break;
	default:
		break;
	}
}

void Card12::Save(ofstream & SaveAction,int type)
{
	if(type==4)
	{
		SaveAction << cardNumber << " " << position.GetCellNum() << " " << z << endl;
	}
}

void Card12::Load(ifstream & openFile,int type)
{
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


Card12::~Card12()
{
}