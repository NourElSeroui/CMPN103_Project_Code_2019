#include "Card14.h"


Card14::Card14(CellPosition & pos) :Card(pos)
{
	cardNumber=14;
	pOwner=NULL;
}

void Card14::ReadCardParameters(Grid * pGrid)
{
	count=0;
	whichCard=0;
	j=0;
	times=0;
	min = 1000000;
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	CellPosition poCard(8,0);
	Cairo = dynamic_cast<Card7 *>(pGrid->GetNextCard(poCard,7));
	Alex= dynamic_cast<Card8 *>(pGrid->GetNextCard(poCard,8));
	Aswan= dynamic_cast<Card9 *>(pGrid->GetNextCard(poCard,9));
	Luxor= dynamic_cast<Card10 *>(pGrid->GetNextCard(poCard,10));
	Hurghada= dynamic_cast<Card11 *>(pGrid->GetNextCard(poCard,11));
}

void Card14::Apply(Grid * pGrid,Player * pPlayer)
{
	int a,b;
	Card::Apply(pGrid,pPlayer);
	pOwner=pPlayer;
	ReadCardParameters(pGrid);
	if(pGrid->getMortgageNumber() == 0)
	{
		if(pOwner == Cairo->getPlayer())
		{
			times++;
		}
		if(pOwner == Alex->getPlayer())
		{
			times++;
		}
		if(pOwner == Aswan->getPlayer())
		{
			times++;
		}
		if(pOwner == Luxor->getPlayer())
		{
			times++;
		}
		if(pOwner == Hurghada->getPlayer())
		{
			times++;
		}
	}
	if(pGrid->getMortgageNumber() > 0)
	{
		for (int i = 0;i<MaxMortgageCount;i++)
		{
			if(pGrid->getMortgageList(i))
			{
				if(pGrid->getMortgageList(i)->getLastOwnerNum() == pOwner->GetPlayernum())
				{
					times++;
				}
			}
		}
	}
	if(times==0)
	{
		pOut->PrintMessage("You Do Not Own Any City. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		return;
	}
	for(int i=0;i<MaxMortgageCount;i++)
	{
		if(pGrid->getMortgageList(i))
		{
			if(Cairo->getIsAccepted())
			{
				if(pGrid->getMortgageList(i)->getWhichCard() == 1 && pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum())
				{
					count ++;
				}
			}
			if(Alex->getIsAccepted())
			{
				if(pGrid->getMortgageList(i)->getWhichCard() == 2 && pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum())
				{
					count ++;
				}
			}
			if(pGrid->getMortgageList(i)->getWhichCard() == 3 && Aswan->getIsAccepted())
			{
				if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum())
				{
					count ++;
				}
			}
			if(pGrid->getMortgageList(i)->getWhichCard() == 4 && Luxor->getIsAccepted())
			{
				if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum())
				{
					count ++;
				}
			}
			if(Hurghada->getIsAccepted())
			{
				if(pGrid->getMortgageList(i)->getWhichCard() == 5 && pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum())
				{
					count ++;
				}
			}
		}
	}
	if(count>0)
	{
		PriceList = new int [count];
		for(int i=0;i<count;i++)
		{
			if(Cairo->getIsAccepted())
			{
				if(pGrid->getMortgageList(i)->getWhichCard() == 1 && pGrid->getMortgageList(i)->getLastOwnerNum() == pOwner->GetPlayernum())
				{
					PriceList[j]=Cairo->GetPrice();
					j++;
				}
			}
			if(Alex->getIsAccepted())
			{
				if(pGrid->getMortgageList(i)->getWhichCard() == 2 && pGrid->getMortgageList(i)->getLastOwnerNum() == pOwner->GetPlayernum())
				{
					PriceList[j]=Alex->GetPrice();
					j++;
				}
			}
			if(Aswan->getIsAccepted())
			{
				if(pGrid->getMortgageList(i)->getWhichCard() == 3 && pGrid->getMortgageList(i)->getLastOwnerNum() == pOwner->GetPlayernum())
				{
					PriceList[j]=Aswan->GetPrice();
					j++;
				}
			}
			if(Luxor->getIsAccepted())
			{
				if(pGrid->getMortgageList(i)->getWhichCard() == 4 && pGrid->getMortgageList(i)->getLastOwnerNum() == pOwner->GetPlayernum())
				{
					PriceList[j]=Luxor->GetPrice();
					j++;
				}
			}
			if(Hurghada->getIsAccepted())
			{
				if(pGrid->getMortgageList(i)->getWhichCard() == 5 && pGrid->getMortgageList(i)->getLastOwnerNum() == pOwner->GetPlayernum())
				{
					PriceList[j]=Hurghada->GetPrice();
					j++;
				}
			}
		}
		for(int i=0;i<count;i++)
		{
			if(PriceList[i] < min)
			{
				min = PriceList[i];
			}
		}
		if(min=Cairo->GetPrice())
		{
			whichCard=1;
		}
		if(min=Alex->GetPrice())
		{
			whichCard=2;
		}
		if(min=Aswan->GetPrice())
		{
			whichCard=3;
		}
		if(min=Luxor->GetPrice())
		{
			whichCard=4;
		}
		if(min=Hurghada->GetPrice())
		{
			whichCard=5;
		}
		switch(whichCard)
		{
		case 1:
			pOut->PrintMessage("Cairo Is Your Least Priced Mortgaged City. You Will Now Return It For Free ! (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			Cairo->setIsAccepted(0);
			Cairo->setIsMortgaged(0);
			Cairo->SetCityOwner(pOwner);
			pGrid->setMortgageList(-1,-1,0);
			break;
		case 2:
			pOut->PrintMessage("Alex Is Your Least Priced Mortgaged City. You Will Now Return It For Free ! (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			Alex->setIsAccepted(0);
			Alex->setIsMortgaged(0);
			Alex->SetCityOwner(pOwner);
			pGrid->setMortgageList(-1,-1,1);
			break;
		case 3:
			pOut->PrintMessage("Aswan Is Your Least Priced Mortgaged City. You Will Now Return It For Free ! (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			Aswan->setIsAccepted(0);
			Aswan->setIsMortgaged(0);
			Aswan->SetCityOwner(pOwner);
			pGrid->setMortgageList(-1,-1,2);
			break;
		case 4:
			pOut->PrintMessage("Luxor Is Your Least Priced Mortgaged City. You Will Now Return It For Free ! (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			Luxor->setIsAccepted(0);
			Luxor->setIsMortgaged(0);
			Luxor->SetCityOwner(pOwner);
			pGrid->setMortgageList(-1,-1,3);
			break;
		case 5:
			pOut->PrintMessage("Hurghada Is Your Least Priced Mortgaged City. You Will Now Return It For Free ! (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			Hurghada->setIsAccepted(0);
			Hurghada->setIsMortgaged(0);
			Hurghada->SetCityOwner(pOwner);
			pGrid->setMortgageList(-1,-1,4);
		default:
			break;
		}
	}
	else
	{
		pOut->PrintMessage("None Of The Cities You Own Are Mortgaged. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
	}
}

void Card14::Save(ofstream & SaveAction,int type)
{
	if(type==4)
	{
		SaveAction << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void Card14::Load(ifstream & openFile,int type)
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


Card14::~Card14()
{
}
