#include "OfferMortgageAction.h"


OfferMortgageAction::OfferMortgageAction(ApplicationManager * pApp) :Action(pApp)
{
}

void OfferMortgageAction::ReadActionParameters()
{
	int a,b;
	int cellNum;
	CellPosition pos;
	pGrid=pManager->GetGrid();
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	CurrPlayer=pGrid->GetCurrentPlayer();
	pOut->PrintMessage("Enter the cell number containing the city to offer mortgage.....");
	cellNum=pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
	pos=pos.GetCellPositionFromNum(cellNum);
	Cairo= dynamic_cast<Card7 *>(pGrid->GetNextCard(pos,7));
	Alex= dynamic_cast<Card8 *>(pGrid->GetNextCard(pos,8));
	Aswan= dynamic_cast<Card9 *>(pGrid->GetNextCard(pos,9));
	Luxor= dynamic_cast<Card10 *>(pGrid->GetNextCard(pos,10));
	Hurghada= dynamic_cast<Card11 *>(pGrid->GetNextCard(pos,11));
	bool benefit=false;
	for(int i=0;i<MaxPlayerCount;i++)
	{
		if(pGrid->GetCurrentPlayer()->getHasBenefitAll())
		{
			benefit=true;
		}
		pGrid->AdvanceCurrentPlayer();
	}
	if(benefit)
	{
		pOut->PrintMessage("You Can Not Offer Mortgage Until Card 15 Loses Effect. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		return;
	}
	if(!Cairo && !Alex && !Aswan && !Luxor && !Hurghada)
	{
		pOut->PrintMessage("ERROR ! No Cities Exist In The Rest Of The Grid. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		LastOwnerNum= -1;
		CanMortgage=0;
		return;
	}
	else if(Cairo && Cairo->GetPosition().GetCellNum() == pos.GetCellNum())
	{
		if(!(Cairo->getIsAccepted()))
		{
			if(CurrPlayer==Cairo->getPlayer())
			{
				if(!(Cairo->getIsMortgaged()))
				{
					LastOwnerNum=CurrPlayer->GetPlayernum();
					CanMortgage=1;
					whichCard=1;
					int z= pGrid->getMortgageNumber();
					int n= z+1;
					pGrid->setMortgageNumber(n);
					if(!(pGrid->getMortgageList(0)))
					{
						pGrid->setMortgageList(whichCard,LastOwnerNum,(0));
						Cairo->setIsMortgaged(1);
						pOut->PrintMessage("Mortgage offer successful. Awaiting player's acceptance in the upcoming turns.(Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						return;
					}
				}
				else
				{
					pOut->PrintMessage("ERROR ! Cairo is already mortgaged. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					return;
				}
			}
			else
			{
				pOut->PrintMessage("ERROR ! You do not own Cairo. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				return;
			}
		}
		else
		{
			pOut->PrintMessage("ERROR ! Cairo is already mortgaged to another player. You cannot mortgage it again until you return it. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
		}
	}
	else if(Alex && Alex->GetPosition().GetCellNum() == pos.GetCellNum())
	{
		if(!(Alex->getIsAccepted()))
		{
			if(CurrPlayer==Alex->getPlayer())
			{
				if(!(Alex->getIsMortgaged()))
				{
					LastOwnerNum=CurrPlayer->GetPlayernum();
					CanMortgage=1;
					whichCard=2;
					int z= pGrid->getMortgageNumber();
					int n= z+1;
					pGrid->setMortgageNumber(n);
					if(!(pGrid->getMortgageList(1)))
					{
						pGrid->setMortgageList(whichCard,LastOwnerNum,(1));
						Alex->setIsMortgaged(1);
						pOut->PrintMessage("Mortgage offer successful. Awaiting player's acceptance in the upcoming turns.(Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						return;
					}
				}
				else
				{
					pOut->PrintMessage("ERROR ! Alex is already mortgaged. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					return;
				}
			}
			else
			{
				pOut->PrintMessage("ERROR ! You do not own Alex. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				return;
			}
		}
		else
		{
			pOut->PrintMessage("ERROR ! Alex is already mortgaged to another player. You cannot mortgage it again until you return it. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
		}

	}
	else if(Aswan && Aswan->GetPosition().GetCellNum() == pos.GetCellNum())
	{
		if(!(Aswan->getIsAccepted()))
		{
			if(CurrPlayer==Aswan->getPlayer())
			{
				if(!(Aswan->getIsMortgaged()))
				{
					LastOwnerNum=CurrPlayer->GetPlayernum();
					CanMortgage=1;
					whichCard=3;
					int z= pGrid->getMortgageNumber();
					int n= z+1;
					pGrid->setMortgageNumber(n);
					if(!(pGrid->getMortgageList(2)))
					{
						pGrid->setMortgageList(whichCard,LastOwnerNum,(2));
						Aswan->setIsMortgaged(1);
						pOut->PrintMessage("Mortgage offer successful. Awaiting player's acceptance in the upcoming turns.(Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						return;
					}
				}
				else
				{
					pOut->PrintMessage("ERROR ! Aswan is already mortgaged. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					return;
				}
			}
			else
			{
				pOut->PrintMessage("ERROR ! You do not own Aswan. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				return;
			}
		}
		else
		{
			pOut->PrintMessage("ERROR ! Aswan is already mortgaged to another player. You cannot mortgage it again until you return it. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
		}
	}
	else if(Luxor && Luxor->GetPosition().GetCellNum() == pos.GetCellNum())
	{
		if(!(Luxor->getIsAccepted()))
		{
			if(CurrPlayer==Luxor->getPlayer())
			{
				if(!(Luxor->getIsMortgaged()))
				{
					LastOwnerNum=CurrPlayer->GetPlayernum();
					CanMortgage=1;
					whichCard=4;
					int z= pGrid->getMortgageNumber();
					int n= z+1;
					pGrid->setMortgageNumber(n);
					if(!(pGrid->getMortgageList(3)))
					{
						pGrid->setMortgageList(whichCard,LastOwnerNum,(3));
						Luxor->setIsMortgaged(1);
						pOut->PrintMessage("Mortgage offer successful. Awaiting player's acceptance in the upcoming turns.(Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						return;
					}
				}
				else
				{
					pOut->PrintMessage("ERROR ! Luxor is already mortgaged. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					return;
				}
			}
			else
			{
				pOut->PrintMessage("ERROR ! You do not own Luxor. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				return;
			}
		}
		else
		{
			pOut->PrintMessage("ERROR ! Luxor is already mortgaged to another player. You cannot mortgage it again until you return it. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
		}
	}
	else if(Hurghada && Hurghada->GetPosition().GetCellNum() == pos.GetCellNum())
	{
		if(!(Hurghada->getIsAccepted()))
		{
			if(CurrPlayer==Hurghada->getPlayer())
			{
				if(!(Hurghada->getIsMortgaged()))
				{
					LastOwnerNum=CurrPlayer->GetPlayernum();
					CanMortgage=1;
					whichCard=5;
					int z= pGrid->getMortgageNumber();
					int n= z+1;
					pGrid->setMortgageNumber(n);
					if(!(pGrid->getMortgageList(4)))
					{
						pGrid->setMortgageList(whichCard,LastOwnerNum,(4));
						Hurghada->setIsMortgaged(1);
						pOut->PrintMessage("Mortgage offer successful. Awaiting player's acceptance in the upcoming turns.(Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						return;
					}
				}
				else
				{
					pOut->PrintMessage("ERROR ! Hurghada is already mortgaged. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					return;
				}
			}
			else
			{
				pOut->PrintMessage("ERROR ! You do not own Hurghada. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				return;
			}
		}
		else
		{
			pOut->PrintMessage("ERROR ! Hurghada is already mortgaged to another player. You cannot mortgage it again until you return it. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
			LastOwnerNum= -1;
			CanMortgage=0;
			return;
		}
	}
	else
	{
		pOut->PrintMessage("This cell doesn't contain a city. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
	}
}

void OfferMortgageAction::Execute()
{
	ReadActionParameters();
}

int OfferMortgageAction::getWhichCard() const
{
	return whichCard;
}

OfferMortgageAction::~OfferMortgageAction()
{
}