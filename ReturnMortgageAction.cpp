#include "ReturnMortgageAction.h"


ReturnMortgageAction::ReturnMortgageAction(ApplicationManager * pApp) :Action(pApp)
{
	count = -1;
	times = 0;
	cellNum = -1;
	pGrid=pManager->GetGrid();
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	CurrPlayer=pGrid->GetCurrentPlayer();
}

void ReturnMortgageAction::ReadActionParameters()
{
	int a,b;
	times=0;
	CellPosition pos;
	pOut->PrintMessage("Enter the cell number to return mortgage of a city....");
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
		pOut->PrintMessage("You Can Not Return Mortgage Until Card 15 Loses Effect. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		return;
	}
	for(int i=0;i<pGrid->getMortgageNumber();i++)
	{
		if(pGrid->getMortgageList(i))
		{
			if(CurrPlayer->GetPlayernum() != pGrid->getMortgageList(i)->getLastOwnerNum())
			{
				times++;
			}
		}
	}
	if(times == pGrid->getMortgageNumber())
	{
		pOut->PrintMessage("ERROR ! None of the mortgage offers were made by you. You cannot return what you don't own. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		return;
	}

	if(!Cairo && !Alex && !Aswan && !Luxor && !Hurghada)
	{
		pOut->PrintMessage("ERROR ! No Cities Exist In The Rest Of The Grid. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		return;
	}
	if(Cairo && Cairo->GetPosition().GetCellNum() == pos.GetCellNum())
	{
		if(CurrPlayer->GetPlayernum() == pGrid->getMortgageList(0)->getLastOwnerNum())
		{
			if(pGrid->getMortgageList(0) != NULL)
			{
				if(Cairo->getIsAccepted() && pGrid->getMortgageList(0)->getWhichCard()==1)
				{
					NumberToString(pGrid->getMortgageList(0)->getWhichCard());
					pOut->PrintMessage("OPTION : " + whichCity + "Mortgaged To Player " +to_string(Cairo->getPlayer()->GetPlayernum()) + "(Y/N).....");
					decision="x";
					while(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
					{
						decision=pIn->GetSrting(pOut);
						pOut->ClearStatusBar();
						if(decision == "Y" || decision == "y")
						{
							count=0;
							return;
						}
						if(decision == "N" || decision == "n")
						{
							pOut->ClearStatusBar();
						}
						else
						{
							pOut->PrintMessage("ERROR ! The entered letter doesn't match the requirement. Re-enter : ");
						}
					}
				}
			}
		}
		else
		{
				pOut->PrintMessage("You Do Not Own Cairo To Return Mortgage. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
		}

	}
	if(Alex && Alex->GetPosition().GetCellNum() == pos.GetCellNum())
	{
	if(CurrPlayer->GetPlayernum() == pGrid->getMortgageList(1)->getLastOwnerNum())
		{
			if(pGrid->getMortgageList(1) != NULL)
			{
				if(Alex->getIsAccepted() && pGrid->getMortgageList(1)->getWhichCard()==2)
				{
					NumberToString(pGrid->getMortgageList(1)->getWhichCard());
					pOut->PrintMessage("OPTION : " + whichCity + "Mortgaged To Player " +to_string(Alex->getPlayer()->GetPlayernum()) + "(Y/N).....");
					decision="x";
					while(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
					{
						decision=pIn->GetSrting(pOut);
						pOut->ClearStatusBar();
						if(decision == "Y" || decision == "y")
						{
							count=1;
							return;
						}
						if(decision == "N" || decision == "n")
						{
							pOut->ClearStatusBar();
						}
						else
						{
							pOut->PrintMessage("ERROR ! The entered letter doesn't match the requirement. Re-enter : ");
						}
					}
				}
			}
		}
		else
		{
					pOut->PrintMessage("You Do Not Own Alex To Return Mortgage. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
		}
	}
	if(Aswan && Aswan->GetPosition().GetCellNum() == pos.GetCellNum())
	{
	if(CurrPlayer->GetPlayernum() == pGrid->getMortgageList(2)->getLastOwnerNum())
		{
			if(pGrid->getMortgageList(2) != NULL)
			{
				if(Aswan->getIsAccepted() && pGrid->getMortgageList(2)->getWhichCard()==3)
				{
					NumberToString(pGrid->getMortgageList(2)->getWhichCard());
					pOut->PrintMessage("OPTION : " + whichCity + "Mortgaged To Player " +to_string(Aswan->getPlayer()->GetPlayernum()) + "(Y/N).....");
					decision="x";
					while(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
					{
						decision=pIn->GetSrting(pOut);
						pOut->ClearStatusBar();
						if(decision == "Y" || decision == "y")
						{
							count=2;
							return;
						}
						if(decision == "N" || decision == "n")
						{
							pOut->ClearStatusBar();
						}
						else
						{
							pOut->PrintMessage("ERROR ! The entered letter doesn't match the requirement. Re-enter : ");
						}
					}
				}
			}
		}
		else
		{
					pOut->PrintMessage("You Do Not Own Aswan To Return Mortgage. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
		}
	}
	if(Luxor && Luxor->GetPosition().GetCellNum() == pos.GetCellNum())
	{
	if(CurrPlayer->GetPlayernum() == pGrid->getMortgageList(3)->getLastOwnerNum())
		{
			if(pGrid->getMortgageList(3) != NULL)
			{
				if(Luxor->getIsAccepted() && pGrid->getMortgageList(3)->getWhichCard()==4)
				{
					NumberToString(pGrid->getMortgageList(3)->getWhichCard());
					pOut->PrintMessage("OPTION : " + whichCity + "Mortgaged To Player " +to_string(Luxor->getPlayer()->GetPlayernum()) + "(Y/N).....");
					decision="x";
					while(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
					{
						decision=pIn->GetSrting(pOut);
						pOut->ClearStatusBar();
						if(decision == "Y" || decision == "y")
						{
							count=3;
							return;
						}
						if(decision == "N" || decision == "n")
						{
							pOut->ClearStatusBar();
						}
						else
						{
							pOut->PrintMessage("ERROR ! The entered letter doesn't match the requirement. Re-enter : ");
						}
					}
				}
			}
		}
		else
		{
					pOut->PrintMessage("You Do Not Own Luxor To Return Mortgage. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
		}
	}
	if(Hurghada && Hurghada->GetPosition().GetCellNum() == pos.GetCellNum())
	{
		if(CurrPlayer->GetPlayernum() == pGrid->getMortgageList(4)->getLastOwnerNum())
		{
			if(pGrid->getMortgageList(4) != NULL)
			{
				if(Hurghada->getIsAccepted() && pGrid->getMortgageList(4)->getWhichCard()==5)
				{
					NumberToString(pGrid->getMortgageList(4)->getWhichCard());
					pOut->PrintMessage("OPTION : " + whichCity + "Mortgaged To Player " +to_string(Hurghada->getPlayer()->GetPlayernum()) + "(Y/N).....");
					decision="x";
					while(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
					{
						decision=pIn->GetSrting(pOut);
						pOut->ClearStatusBar();
						if(decision == "Y" || decision == "y")
						{
							count=4;
							return;
						}
						if(decision == "N" || decision == "n")
						{
							pOut->ClearStatusBar();
						}
						else
						{
							pOut->PrintMessage("ERROR ! The entered letter doesn't match the requirement. Re-enter : ");
						}
					}
				}
				else
				{
					pOut->PrintMessage("You Do Not Own Hurghada To Return Mortgage. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
				}
			}
		}
		else
		{
			pOut->PrintMessage("You Do Not Own Luxor To Return Mortgage. (Click to continue....)");
			pIn->GetPointClicked(a,b);
			pOut->ClearStatusBar();
		}
	}
}

void ReturnMortgageAction::Execute()
{
	int a,b;
	ReadActionParameters();
	if(times==pGrid->getMortgageNumber())
	{
		return;
	}
	if(count != -1)
	{
		if(pGrid->getMortgageList(count) != NULL)
		{
			whichCard=pGrid->getMortgageList(count)->getWhichCard();
		}
	}
	switch(whichCard)
	{
	case 1:
		if(pGrid->getMortgageList(count) != NULL)
		{
			if(CurrPlayer->GetWallet() >= 0.7 * (Cairo->GetPrice()))
			{
				Cairo->getPlayer()->SetWallet((Cairo->getPlayer()->GetWallet()) + (0.7 * Cairo->GetPrice()));
				pOut->PrintMessage("Mortgage from Player " +to_string(CurrPlayer->GetPlayernum()) + "Returned. Player "+to_string(CurrPlayer->GetPlayernum()) + "Now has " +to_string(CurrPlayer->GetWallet()) + "(Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				CurrPlayer->SetWallet((CurrPlayer->GetWallet()) - (0.7 * Cairo->GetPrice()));
				pOut->PrintMessage("Player " +to_string(Cairo->getPlayer()->GetPlayernum()) + "Now has " + to_string(Cairo->getPlayer()->GetWallet()) + "(Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				Cairo->SetCityOwner(CurrPlayer);
				int z=pGrid->getMortgageNumber();
				int n = z-1;
				pGrid->setMortgageNumber(n);
				pGrid->setMortgageList(-1,-1,count);
				Cairo->setIsAccepted(0);
				Cairo->setIsMortgaged(0);
				return;
			}
			else
			{
				pOut->PrintMessage("ERROR ! Insufficient Funds To Return Mortgage. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				return;
			}
		}
		break;
	case 2:
		if(pGrid->getMortgageList(count) != NULL)
		{
			if(CurrPlayer->GetWallet() >= 0.7 * (Alex->GetPrice()))
			{
				Alex->getPlayer()->SetWallet((Alex->getPlayer()->GetWallet()) + (0.7 * Alex->GetPrice()));
				pOut->PrintMessage("Mortgage from Player " +to_string(CurrPlayer->GetPlayernum()) + "Returned. Player "+to_string(CurrPlayer->GetPlayernum()) + "Now has " +to_string(CurrPlayer->GetWallet()) + "(Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				CurrPlayer->SetWallet((CurrPlayer->GetWallet()) - (0.7 * Alex->GetPrice()));
				pOut->PrintMessage("Player " +to_string(Alex->getPlayer()->GetPlayernum()) + "Now has " + to_string(Alex->getPlayer()->GetWallet()) + "(Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				Alex->SetCityOwner(CurrPlayer);
				int z=pGrid->getMortgageNumber();
				int n = z-1;
				pGrid->setMortgageNumber(n);
				pGrid->setMortgageList(-1,-1,count);
				Alex->setIsAccepted(0);
				Alex->setIsMortgaged(0);
				return;
			}
			else
			{
				pOut->PrintMessage("ERROR ! Insufficient Funds To Return Mortgage. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				return;
			}
		}
		break;
	case 3:
		if(pGrid->getMortgageList(count) != NULL)
		{
			if(CurrPlayer->GetWallet() >= 0.7 * (Aswan->GetPrice()))
			{
				Aswan->getPlayer()->SetWallet((Aswan->getPlayer()->GetWallet()) + (0.7 * Aswan->GetPrice()));
				pOut->PrintMessage("Mortgage from Player " +to_string(CurrPlayer->GetPlayernum()) + "Returned. Player "+to_string(CurrPlayer->GetPlayernum()) + "Now has " +to_string(CurrPlayer->GetWallet()) + "(Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				CurrPlayer->SetWallet((CurrPlayer->GetWallet()) - (0.7 * Aswan->GetPrice()));
				pOut->PrintMessage("Player " +to_string(Aswan->getPlayer()->GetPlayernum()) + "Now has " + to_string(Aswan->getPlayer()->GetWallet()) + "(Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				Aswan->SetCityOwner(CurrPlayer);
				int z=pGrid->getMortgageNumber();
				int n = z-1;
				pGrid->setMortgageNumber(n);
				pGrid->setMortgageList(-1,-1,count);
				Aswan->setIsAccepted(0);
				Aswan->setIsMortgaged(0);
				return;
			}
			else
			{
				pOut->PrintMessage("ERROR ! Insufficient Funds To Return Mortgage. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				return;
			}
		}
		break;
	case 4:
		if(pGrid->getMortgageList(count) != NULL)
		{
			if(CurrPlayer->GetWallet() >= 0.7 * (Luxor->GetPrice()))
			{
				Luxor->getPlayer()->SetWallet((Luxor->getPlayer()->GetWallet()) + (0.7 * Luxor->GetPrice()));
				pOut->PrintMessage("Mortgage from Player " +to_string(CurrPlayer->GetPlayernum()) + "Returned. Player "+to_string(CurrPlayer->GetPlayernum()) + "Now has " +to_string(CurrPlayer->GetWallet()) + "(Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				CurrPlayer->SetWallet((CurrPlayer->GetWallet()) - (0.7 * Luxor->GetPrice()));
				pOut->PrintMessage("Player " +to_string(Luxor->getPlayer()->GetPlayernum()) + "Now has " + to_string(Luxor->getPlayer()->GetWallet()) + "(Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				Luxor->SetCityOwner(CurrPlayer);
				int z=pGrid->getMortgageNumber();
				int n = z-1;
				pGrid->setMortgageNumber(n);
				pGrid->setMortgageList(-1,-1,count);
				Luxor->setIsAccepted(0);
				Luxor->setIsMortgaged(0);
				return;
			}
			else
			{
				pOut->PrintMessage("ERROR ! Insufficient Funds To Return Mortgage. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				return;
			}
		}
		break;
	case 5:
		if(pGrid->getMortgageList(count) != NULL)
		{
			if(CurrPlayer->GetWallet() >= 0.7 * (Hurghada->GetPrice()))
			{
				Hurghada->getPlayer()->SetWallet((Hurghada->getPlayer()->GetWallet()) + (0.7 * Hurghada->GetPrice()));
				pOut->PrintMessage("Mortgage from Player " +to_string(CurrPlayer->GetPlayernum()) + "Returned. Player "+to_string(CurrPlayer->GetPlayernum()) + "Now has " +to_string(CurrPlayer->GetWallet()) + "(Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				CurrPlayer->SetWallet((CurrPlayer->GetWallet()) - (0.7 * Hurghada->GetPrice()));
				pOut->PrintMessage("Player " +to_string(Hurghada->getPlayer()->GetPlayernum()) + "Now has " + to_string(Hurghada->getPlayer()->GetWallet()) + "(Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				Hurghada->SetCityOwner(CurrPlayer);
				int z=pGrid->getMortgageNumber();
				int n = z-1;
				pGrid->setMortgageNumber(n);
				pGrid->setMortgageList(-1,-1,count);
				Hurghada->setIsAccepted(0);
				Hurghada->setIsMortgaged(0);
				return;
			}
			else
			{
				pOut->PrintMessage("ERROR ! Insufficient Funds To Return Mortgage. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				return;
			}
		}
		break;
	default:
		return;
	}
}


void ReturnMortgageAction::NumberToString(int m)
{
	switch(m)
	{
		case 1: whichCity = "Cairo" ;
		break;
		case 2: whichCity = "Alex" ;
		break;
		case 3: whichCity = "Aswan" ;
		break;
		case 4: whichCity = "Luxor" ;
		break;
		case 5: whichCity = "Hurghada" ;
		break;
		default: whichCity = "N/A" ;
		break;
	}
}

ReturnMortgageAction::~ReturnMortgageAction(void)
{
}
