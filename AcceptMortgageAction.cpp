#include "AcceptMortgageAction.h"


AcceptMortgageAction::AcceptMortgageAction(ApplicationManager *pApp) : Action(pApp)
{
	CanAccept=0;
}

void AcceptMortgageAction::ReadActionParameters()
{
	int a,b;
	pGrid=pManager->GetGrid();
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	MortgageNumber=pGrid->getMortgageNumber();
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
		pOut->PrintMessage("You Can Not Accept Mortgage Until Card 15 Loses Effect. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		return;
	}
	if(MortgageNumber == 0)
	{
		pOut->PrintMessage("ERROR ! No offering requests are pending. (Click to continue...) ");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		pOwner = NULL;
		CanAccept=0;  //Used for a condition in "Execute" function.
	}
	if(MortgageNumber > 0)
	{
		for(int i=0;i<MaxMortgageCount;i++)
		{
			if(pGrid->getMortgageList(i))
			{
				if(pGrid->getMortgageList(i)->getLastOwnerNum() != pGrid->GetCurrentPlayer()->GetPlayernum())
				{
					if(pGrid->getMortgageList(i)->getWhichCard() == 1)
					{
						if(!(Cairo->getIsAccepted()) && Cairo->getIsMortgaged())
						{
							NumberToString(pGrid->getMortgageList(i)->getWhichCard());
							pOut->PrintMessage("OPTION : " +whichCity + "  Owned By Player : " +to_string(pGrid->getMortgageList(i)->getLastOwnerNum()) + " " "(Y/N).....");
							decision="x";
							while(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
							{
								decision=pIn->GetSrting(pOut);
								pOut->ClearStatusBar();
								if(decision == "Y" || decision == "y")
								{
									count=i;
									pOwner=pGrid->GetCurrentPlayer();
									CanAccept=1;
									Cairo->setIsAccepted(1);
									return;
								}
								if(decision == "N" || decision == "n")
								{
									pOut->PrintMessage("You Chose Not To Accept Mortgage Of City :  " +whichCity+ " " "(Click to continue....)");
									pIn->GetPointClicked(a,b);
									pOut->ClearStatusBar();
									CanAccept=0;
									Cairo->setIsAccepted(0);
								}
								else
								{
									pOut->PrintMessage("ERROR ! The entered letter doesn't match the requirement. Re-enter : ");
								}
							}
						}
					}
					if(pGrid->getMortgageList(i)->getWhichCard() == 2)
					{
						if(!(Alex->getIsAccepted()) && Alex->getIsMortgaged())
						{
							NumberToString(pGrid->getMortgageList(i)->getWhichCard());
							pOut->PrintMessage("OPTION : " +whichCity + "  Owned By Player : " +to_string(pGrid->getMortgageList(i)->getLastOwnerNum()) + " " "(Y/N).....");
							decision="x";
							while(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
							{
								decision=pIn->GetSrting(pOut);
								pOut->ClearStatusBar();
								if(decision == "Y" || decision == "y")
								{
									count=i;
									pOwner=pGrid->GetCurrentPlayer();
									CanAccept=1;
									Alex->setIsAccepted(1);
									return;
								}
								if(decision == "N" || decision == "n")
								{
									pOut->PrintMessage("You Chose Not To Accept Mortgage Of City :  " +whichCity+ " " "(Click to continue....)");
									pIn->GetPointClicked(a,b);
									pOut->ClearStatusBar();
									CanAccept=0;
									Alex->setIsAccepted(0);
								}
								else
								{
									pOut->PrintMessage("ERROR ! The entered letter doesn't match the requirement. Re-enter : ");
								}
							}
						}
					}
					if(pGrid->getMortgageList(i)->getWhichCard() == 3)
					{
						if(!(Aswan->getIsAccepted()) && Aswan->getIsMortgaged())
						{
							NumberToString(pGrid->getMortgageList(i)->getWhichCard());
							pOut->PrintMessage("OPTION : " +whichCity + "  Owned By Player : " +to_string(pGrid->getMortgageList(i)->getLastOwnerNum()) + " " "(Y/N).....");
							decision="x";
							while(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
							{
								decision=pIn->GetSrting(pOut);
								pOut->ClearStatusBar();
								if(decision == "Y" || decision == "y")
								{
									count=i;
									pOwner=pGrid->GetCurrentPlayer();
									CanAccept=1;
									Aswan->setIsAccepted(1);
									return;
								}
								if(decision == "N" || decision == "n")
								{
									pOut->PrintMessage("You Chose Not To Accept Mortgage Of City :  " +whichCity+ " " "(Click to continue....)");
									pIn->GetPointClicked(a,b);
									pOut->ClearStatusBar();
									CanAccept=0;
									Aswan->setIsAccepted(0);
								}
								else
								{
									pOut->PrintMessage("ERROR ! The entered letter doesn't match the requirement. Re-enter : ");
								}
							}
						}
					}
					if(pGrid->getMortgageList(i)->getWhichCard() == 4)
					{
						if(!(Luxor->getIsAccepted()) && Luxor->getIsMortgaged())
						{
							NumberToString(pGrid->getMortgageList(i)->getWhichCard());
							pOut->PrintMessage("OPTION : " +whichCity + "  Owned By Player : " +to_string(pGrid->getMortgageList(i)->getLastOwnerNum()) + " " "(Y/N).....");
							decision="x";
							while(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
							{
								decision=pIn->GetSrting(pOut);
								pOut->ClearStatusBar();
								if(decision == "Y" || decision == "y")
								{
									count=i;
									pOwner=pGrid->GetCurrentPlayer();
									CanAccept=1;
									Luxor->setIsAccepted(1);
									return;
								}
								if(decision == "N" || decision == "n")
								{
									pOut->PrintMessage("You Chose Not To Accept Mortgage Of City :  " +whichCity+ " " "(Click to continue....)");
									pIn->GetPointClicked(a,b);
									pOut->ClearStatusBar();
									CanAccept=0;
									Luxor->setIsAccepted(0);
								}
								else
								{
									pOut->PrintMessage("ERROR ! The entered letter doesn't match the requirement. Re-enter : ");
								}
							}
						}
					}
					if(pGrid->getMortgageList(i)->getWhichCard() == 5)
					{
						if(!(Hurghada->getIsAccepted()) && Hurghada->getIsMortgaged())
						{
							NumberToString(pGrid->getMortgageList(i)->getWhichCard());
							pOut->PrintMessage("OPTION : " +whichCity + "  Owned By Player : " +to_string(pGrid->getMortgageList(i)->getLastOwnerNum()) + " " "(Y/N).....");
							decision="x";
							while(decision != "Y" && decision != "y" && decision != "N" && decision != "n")
							{
								decision=pIn->GetSrting(pOut);
								pOut->ClearStatusBar();
								if(decision == "Y" || decision == "y")
								{
									count=i;
									pOwner=pGrid->GetCurrentPlayer();
									CanAccept=1;
									Hurghada->setIsAccepted(1);
									return;
								}
								if(decision == "N" || decision == "n")
								{
									pOut->PrintMessage("You Chose Not To Accept Mortgage Of City :  " +whichCity+ " " "(Click to continue....)");
									pIn->GetPointClicked(a,b);
									pOut->ClearStatusBar();
									CanAccept=0;
									Hurghada->setIsAccepted(0);
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
					CanAccept=0;
				}

			}
		}
	}
}

void AcceptMortgageAction::Execute()
{
	int a,b;
	ReadActionParameters();
	CellPosition poCard(8,0);
	Cairo= dynamic_cast<Card7 *>(pGrid->GetNextCard(poCard,7));
	Alex= dynamic_cast<Card8 *>(pGrid->GetNextCard(poCard,8));
	Aswan= dynamic_cast<Card9 *>(pGrid->GetNextCard(poCard,9));
	Luxor= dynamic_cast<Card10 *>(pGrid->GetNextCard(poCard,10));
	Hurghada= dynamic_cast<Card11 *>(pGrid->GetNextCard(poCard,11));
	if(CanAccept)
	{
		switch(pGrid->getMortgageList(count)->getWhichCard())
		{
		case 1:
			if((pOwner->GetWallet()) >= 0.7 * (Cairo->GetPrice()) )
			{
				Cairo->getPlayer()->SetWallet((Cairo->getPlayer()->GetWallet()) + (0.7 * Cairo->GetPrice()));
				pOut->PrintMessage("Mortgage from Player " +to_string(pGrid->getMortgageList(count)->getLastOwnerNum()) + "Accepted. Player "+to_string(pGrid->getMortgageList(count)->getLastOwnerNum()) + "Now has " +to_string(Cairo->getPlayer()->GetWallet()) + "(Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				pOwner->SetWallet((pOwner->GetWallet()) - (0.7 * Cairo->GetPrice()));
				pOut->PrintMessage("Player " +to_string(pOwner->GetPlayernum()) + "Now has " + to_string(pOwner->GetWallet()) + "(Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				Cairo->SetCityOwner(pOwner);
				Cairo->setIsAccepted(1);
			}
			else
			{
				pOut->PrintMessage("ERROR ! You have insufficient money to accept mortgage. (Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
			}
			break;
		case 2:
			if((pOwner->GetWallet()) >= 0.7 * (Alex->GetPrice()) )
			{
				Alex->getPlayer()->SetWallet((Alex->getPlayer()->GetWallet()) + (0.7 * Alex->GetPrice()));
				pOut->PrintMessage("Mortgage from Player " +to_string(pGrid->getMortgageList(count)->getLastOwnerNum()) + "Accepted. Player "+to_string(pGrid->getMortgageList(count)->getLastOwnerNum()) + "Now has " +to_string(Alex->getPlayer()->GetWallet()) + "(Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				pOwner->SetWallet((pOwner->GetWallet()) - (0.7 * Alex->GetPrice()));
				pOut->PrintMessage("Player " +to_string(pOwner->GetPlayernum()) + "Now has " + to_string(pOwner->GetWallet()) + "(Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				Alex->SetCityOwner(pOwner);
				Alex->setIsAccepted(1);
			}
			else
			{
				pOut->PrintMessage("ERROR ! You have insufficient money to accept mortgage. (Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
			}
			break;
		case 3:
			if((pOwner->GetWallet()) >= 0.7 * (Aswan->GetPrice()) )
			{
				Aswan->getPlayer()->SetWallet((Aswan->getPlayer()->GetWallet()) + (0.7 * Aswan->GetPrice()));
				pOut->PrintMessage("Mortgage from Player " +to_string(pGrid->getMortgageList(count)->getLastOwnerNum()) + "Accepted. Player "+to_string(pGrid->getMortgageList(count)->getLastOwnerNum()) + "Now has " +to_string(Aswan->getPlayer()->GetWallet()) + "(Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				pOwner->SetWallet((pOwner->GetWallet()) - (0.7 * Aswan->GetPrice()));
				pOut->PrintMessage("Player " +to_string(pOwner->GetPlayernum()) + "Now has " + to_string(pOwner->GetWallet()) + "(Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				Aswan->SetCityOwner(pOwner);
				Aswan->setIsAccepted(1);
			}
			else
			{
				pOut->PrintMessage("ERROR ! You have insufficient money to accept mortgage. (Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
			}
			break;
		case 4:
			if((pOwner->GetWallet()) >= 0.7 * (Luxor->GetPrice()) )
			{
				Luxor->getPlayer()->SetWallet((Luxor->getPlayer()->GetWallet()) + (0.7 * Luxor->GetPrice()));
				pOut->PrintMessage("Mortgage from Player " +to_string(pGrid->getMortgageList(count)->getLastOwnerNum()) + "Accepted. Player "+to_string(pGrid->getMortgageList(count)->getLastOwnerNum()) + "Now has " +to_string(Luxor->getPlayer()->GetWallet()) + "(Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				pOwner->SetWallet((pOwner->GetWallet()) - (0.7 * Luxor->GetPrice()));
				pOut->PrintMessage("Player " +to_string(pOwner->GetPlayernum()) + "Now has " + to_string(pOwner->GetWallet()) + "(Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				Luxor->SetCityOwner(pOwner);
				Luxor->setIsAccepted(1);
			}
			else
			{
				pOut->PrintMessage("ERROR ! You have insufficient money to accept mortgage. (Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
			}
			break;
		case 5:
			if((pOwner->GetWallet()) >= 0.7 * (Hurghada->GetPrice()) )
			{
				Hurghada->getPlayer()->SetWallet((Hurghada->getPlayer()->GetWallet()) + (0.7 * Hurghada->GetPrice()));
				pOut->PrintMessage("Mortgage from Player " +to_string(pGrid->getMortgageList(count)->getLastOwnerNum()) + "Accepted. Player "+to_string(pGrid->getMortgageList(count)->getLastOwnerNum()) + "Now has " +to_string(Hurghada->getPlayer()->GetWallet()) + "(Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				pOwner->SetWallet((pOwner->GetWallet()) - (0.7 * Hurghada->GetPrice()));
				pOut->PrintMessage("Player " +to_string(pOwner->GetPlayernum()) + "Now has " + to_string(pOwner->GetWallet()) + "(Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
				Hurghada->SetCityOwner(pOwner);
				Hurghada->setIsAccepted(1);
			}
			else
			{
				pOut->PrintMessage("ERROR ! You have insufficient money to accept mortgage. (Click to continue...)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
			}
			break;
		default: 
			return;
			break;
		}
	}
	else
	{
		return;
	}
}


void AcceptMortgageAction::NumberToString(int m)
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


AcceptMortgageAction::~AcceptMortgageAction()
{
}
