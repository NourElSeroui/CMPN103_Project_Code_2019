#include "Card13.h"

Card13::Card13(CellPosition & pos) :Card(pos)
{
	cardNumber=13;
	pOwner=NULL;
}

void Card13::ReadCardParameters(Grid *pGrid)
{
	count = 0;
	j=0;
	max=0;
	whichCard=0;
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	CellPosition poCard(8,0);
	Cairo = dynamic_cast<Card7 *>(pGrid->GetNextCard(poCard,7));
	Alex= dynamic_cast<Card8 *>(pGrid->GetNextCard(poCard,8));
	Aswan= dynamic_cast<Card9 *>(pGrid->GetNextCard(poCard,9));
	Luxor= dynamic_cast<Card10 *>(pGrid->GetNextCard(poCard,10));
	Hurghada= dynamic_cast<Card11 *>(pGrid->GetNextCard(poCard,11));
}

void Card13::Apply(Grid * pGrid,Player * pPlayer)
{
	int a,b;
	Card::Apply(pGrid,pPlayer);
	pOwner=pPlayer;
	ReadCardParameters(pGrid);
		if(!(Cairo->getIsAccepted()))
		{
			if(Cairo->getPlayer() == pOwner)
			{
				count++;
			}
		}
		if(!(Alex->getIsAccepted()))
		{
			if(Alex->getPlayer() == pOwner)
			{
				count++;
			}
		}
		if(!(Aswan->getIsAccepted()))
		{
			if(Aswan->getPlayer() == pOwner)
			{
				count++;
			}
		}
		if(!(Luxor->getIsAccepted()))
		{
			if(Luxor->getPlayer() == pOwner)
			{
				count++;
			}
		}
		if(!(Hurghada->getIsAccepted()))
		{
			if(Hurghada->getPlayer() == pOwner)
			{
				count++;
			}
		}
		for(int i=0;i<MaxMortgageCount;i++)
		{
			if(pGrid->getMortgageList(i))
			{
				if(Cairo->getIsAccepted())
				{
					if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum())
					{
						count ++;
					}
				}
				if(Alex->getIsAccepted())
				{
					if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum())
					{
						count ++;
					}
				}
				if(Aswan->getIsAccepted())
				{
					if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum())
					{
						count ++;
					}
				}
				if(Luxor->getIsAccepted())
				{
					if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum())
					{
						count ++;
					}
				}
				if(Hurghada->getIsAccepted())
				{
					if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum())
					{
						count ++;
					}
				}
			}
		}
		if(count>0)
		{
			PriceList = new int [count];
			if(!(Cairo->getIsAccepted()))
			{
				if(Cairo->getPlayer() == pOwner)
				{
					PriceList[j]=Cairo->GetPrice();
					j++;
				}
			}
			if(!(Alex->getIsAccepted()))
			{
				if(Alex->getPlayer() == pOwner)
				{
					PriceList[j]=Alex->GetPrice();
					j++;
				}
			}
			if(!(Aswan->getIsAccepted()))
			{
				if(Aswan->getPlayer() == pOwner)
				{
					PriceList[j]=Aswan->GetPrice();
					j++;
				}
			}
			if(!(Luxor->getIsAccepted()))
			{
				if(Luxor->getPlayer() == pOwner)
				{
					PriceList[j]=Luxor->GetPrice();
					j++;
				}
			}
			if(!(Hurghada->getIsAccepted()))
			{
				if(Hurghada->getPlayer() == pOwner)
				{
					PriceList[j]=Hurghada->GetPrice();
					j++;
				}
			}
			for(int i=0;i<MaxMortgageCount;i++)
			{
				if(pGrid->getMortgageList(i))
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
			}
		for(int i=0;i<j;i++)
		{
			if(max<PriceList[i])
			{
				max = PriceList[i];
			}
		}
		if(max=Cairo->GetPrice())
		{
			whichCard=1;
		}
		if(max=Alex->GetPrice())
		{
			whichCard=2;
		}
		if(max=Aswan->GetPrice())
		{
			whichCard=3;
		}
		if(max=Luxor->GetPrice())
		{
			whichCard=4;
		}
		if(max=Hurghada->GetPrice())
		{
			whichCard=5;
		}
		switch(whichCard)
		{
		case 1:
			if(Cairo->getIsAccepted())
			{
				if(pGrid->getMortgageNumber() > 0)
				{
					for(int i=0;i<MaxMortgageCount;i++)
					{
						if(pGrid->getMortgageList(i))
						{
							if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum() && pGrid->getMortgageList(i)->getWhichCard() == 1)
							{
								pOut->PrintMessage("Cairo Will Be Taken From You ! Mortgage Cancelled, Player : " +to_string(Cairo->getPlayer()->GetPlayernum())+ " Now Owns Cairo Permanently. (Click to continue....)");
								pIn->GetPointClicked(a,b);
								pOut->ClearStatusBar();
								pGrid->setMortgageList(-1,-1,i);
								int z = pGrid->getMortgageNumber();
								pGrid->setMortgageNumber(z-1);
								Cairo->setIsMortgaged(0);
								Cairo->setIsAccepted(0);
							}
						}
					}
				}
			}
			else
			{
				if(Cairo->getPlayer() == pOwner)
				{
					pOut->PrintMessage("Cairo Will Be Taken From You ! You No Longer Own Cairo. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					Cairo->SetCityOwner(NULL);
					Cairo->SetBought(0);
					Cairo->setIsMortgaged(0);
					pGrid->setMortgageList(-1,-1,0);
					Cairo->SetisOwned(0);
				}
			}
			break;
		case 2:
			if(Alex->getIsAccepted())
			{
				if(pGrid->getMortgageNumber() > 0)
				{
					for(int i=0;i<MaxMortgageCount;i++)
					{
						if(pGrid->getMortgageList(i))
						{
							if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum() && pGrid->getMortgageList(i)->getWhichCard() == 2)
							{
								pOut->PrintMessage("Alex Will Be Taken From You ! Mortgage Cancelled, Player : " +to_string(Alex->getPlayer()->GetPlayernum())+ " Now Owns Alex Permanently. (Click to continue....)");
								pIn->GetPointClicked(a,b);
								pOut->ClearStatusBar();
								pGrid->setMortgageList(-1,-1,i);
								int z = pGrid->getMortgageNumber();
								pGrid->setMortgageNumber(z-1);
								Alex->setIsMortgaged(0);
								Alex->setIsAccepted(0);
							}
						}
					}
				}
			}
			else
			{
				if(Alex->getPlayer() == pOwner)
				{
					pOut->PrintMessage("Alex Will Be Taken From You ! You No Longer Own Alex. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					Alex->SetCityOwner(NULL);
					Alex->SetBought(0);
					Alex->setIsMortgaged(0);
					pGrid->setMortgageList(-1,-1,1);
					Alex->SetisOwned(0);
				}
			}
			break;
		case 3:
			if(Aswan->getIsAccepted())
			{
				if(pGrid->getMortgageNumber() > 0)
				{
					for(int i=0;i<MaxMortgageCount;i++)
					{
						if(pGrid->getMortgageList(i))
						{
							if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum() && pGrid->getMortgageList(i)->getWhichCard() == 3)
							{
								pOut->PrintMessage("Aswan Will Be Taken From You ! Mortgage Cancelled, Player : " +to_string(Aswan->getPlayer()->GetPlayernum())+ " Now Owns Aswan Permanently. (Click to continue....)");
								pIn->GetPointClicked(a,b);
								pOut->ClearStatusBar();
								pGrid->setMortgageList(-1,-1,i);
								int z = pGrid->getMortgageNumber();
								pGrid->setMortgageNumber(z-1);
								Aswan->setIsMortgaged(0);
								Aswan->setIsAccepted(0);
							}
						}
					}
				}
			}
			else
			{
				if(Aswan->getPlayer() == pOwner)
				{
					pOut->PrintMessage("Aswan Will Be Taken From You ! You No Longer Own Aswan. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					Aswan->SetCityOwner(NULL);
					Aswan->SetBought(0);
					Aswan->setIsMortgaged(0);
					pGrid->setMortgageList(-1,-1,2);
					Aswan->SetisOwned(0);
				}
			}
			break;
		case 4:
			if(Luxor->getIsAccepted())
			{
				if(pGrid->getMortgageNumber() > 0)
				{
					for(int i=0;i<MaxMortgageCount;i++)
					{
						if(pGrid->getMortgageList(i))
						{
							if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum() && pGrid->getMortgageList(i)->getWhichCard() == 4)
							{
								pOut->PrintMessage("Luxor Will Be Taken From You ! Mortgage Cancelled, Player : " +to_string(Luxor->getPlayer()->GetPlayernum())+ " Now Owns Luxor Permanently. (Click to continue....)");
								pIn->GetPointClicked(a,b);
								pOut->ClearStatusBar();
								pGrid->setMortgageList(-1,-1,i);
								int z = pGrid->getMortgageNumber();
								pGrid->setMortgageNumber(z-1);
								Luxor->setIsMortgaged(0);
								Luxor->setIsAccepted(0);
							}
						}
					}
				}
			}
			else
			{
				if(Luxor->getPlayer() == pOwner)
				{
					pOut->PrintMessage("Luxor Will Be Taken From You ! You No Longer Own Luxor. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					Luxor->SetCityOwner(NULL);
					Luxor->SetBought(0);
					Luxor->setIsMortgaged(0);
					pGrid->setMortgageList(-1,-1,3);
					Luxor->SetisOwned(0);
				}
			}
			break;
		case 5:
			if(Hurghada->getIsAccepted())
			{
				if(pGrid->getMortgageNumber() > 0)
				{
					for(int i=0;i<MaxMortgageCount;i++)
					{
						if(pGrid->getMortgageList(i))
						{
							if(pOwner->GetPlayernum() == pGrid->getMortgageList(i)->getLastOwnerNum() && pGrid->getMortgageList(i)->getWhichCard() == 5)
							{
								pOut->PrintMessage("Hurghada Will Be Taken From You ! Mortgage Cancelled, Player : " +to_string(Hurghada->getPlayer()->GetPlayernum())+ " Now Owns Hurghada Permanently. (Click to continue....)");
								pIn->GetPointClicked(a,b);
								pOut->ClearStatusBar();
								pGrid->setMortgageList(-1,-1,i);
								int z = pGrid->getMortgageNumber();
								pGrid->setMortgageNumber(z-1);
								Hurghada->setIsMortgaged(0);
								Hurghada->setIsAccepted(0);
							}
						}
					}
				}
			}
			else
			{
				if(Hurghada->getPlayer() == pOwner)
				{
					pOut->PrintMessage("Hurghada Will Be Taken From You ! You No Longer Own Hurghada. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					Hurghada->SetCityOwner(NULL);
					Hurghada->SetBought(0);
					Hurghada->setIsMortgaged(0);
					pGrid->setMortgageList(-1,-1,4);
					Hurghada->SetisOwned(0);
				}
			}
			break;
		}
	}
	else
	{
		pOut->PrintMessage("You Do Not Own Any City. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		return;
	}
}

void Card13::Save(ofstream & SaveAction,int type)
{
	if(type==4)
	{
		SaveAction << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void Card13::Load(ifstream & openFile,int type)
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


Card13::~Card13()
{
}
