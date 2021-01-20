#include "SellCityAction.h"


SellCityAction::SellCityAction(ApplicationManager * pApp) : Action(pApp)
{
	whichCity="N/A";
	whichCard=0;
}

void SellCityAction::ReadActionParameters()
{
	int a,b;
	Grid * pGrid=pManager->GetGrid();
	Output * pOut=pGrid->GetOutput();
	Input * pIn=pGrid->GetInput();
	pOut->PrintMessage("Enter The Name Of The City You Want To Sell....");
	whichCity=pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	if(whichCity=="cairo" || whichCity=="Cairo")
	{
		whichCity = "Cairo";
	}
	else if(whichCity=="alex" || whichCity=="Alex")
	{
		whichCity = "Alex";
	}
	else if(whichCity=="aswan" || whichCity=="Aswan")
	{
		whichCity = "Aswan";
	}
	else if(whichCity=="luxor" || whichCity=="Luxor")
	{
		whichCity = "Luxor";
	}
	else if(whichCity=="hurghada" || whichCity=="Hurghada")
	{
		whichCity = "Hurghada";
	}
	else
	{
		pOut->PrintMessage("ERROR ! You Entered Wrong Characters. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		return;
	}
}

void SellCityAction::Execute()
{
	int a,b;
	Grid * pGrid=pManager->GetGrid();
	Output * pOut=pGrid->GetOutput();
	Input * pIn=pGrid->GetInput();
	ReadActionParameters();
	CellPosition pos(1);
	StringToCase();
	Cairo= dynamic_cast<Card7 *>(pGrid->GetNextCard(pos,7));
	Alex= dynamic_cast<Card8 *>(pGrid->GetNextCard(pos,8));
	Aswan= dynamic_cast<Card9 *>(pGrid->GetNextCard(pos,9));
	Luxor= dynamic_cast<Card10 *>(pGrid->GetNextCard(pos,10));
	Hurghada= dynamic_cast<Card11 *>(pGrid->GetNextCard(pos,11));
	if(!Cairo && !Alex && !Aswan && !Luxor && !Hurghada)
	{
		pOut->PrintMessage("No Cities Exist In The Grid To Sell. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
	}
	else
	{
		switch(whichCard)
		{
		case 1:
			if(Cairo)
			{
				if(pGrid->GetCurrentPlayer() == Cairo->getPlayer())
				{
					if(!(Cairo->getIsAccepted()))
					{
						pOut->PrintMessage("Cairo Has Been Successfully Sold. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						pOut->PrintMessage(to_string(0.9 *Cairo->GetPrice()) + " Will Be Now Taken From Player : " + to_string(pGrid->GetCurrentPlayer()->GetPlayernum()) + "(Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						pGrid->GetCurrentPlayer()->SetWallet(pGrid->GetCurrentPlayer()->GetWallet() + 0.9*(Cairo->GetPrice()));
						pOut->PrintMessage("Player : " +to_string(pGrid->GetCurrentPlayer()->GetPlayernum()) + " Now Has " +to_string(pGrid->GetCurrentPlayer()->GetWallet()) + " In His Wallet. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						Cairo->SetCityOwner(NULL);
						Cairo->SetBought(false);
						Cairo->setIsAccepted(false);
						if(Cairo->getIsMortgaged())
						{
							pGrid->setMortgageList(-1,-1,0);
						}
						Cairo->setIsMortgaged(false);
						Cairo->SetisOwned(false);
					}
				}
				else if(Cairo->getIsAccepted() && pGrid->GetCurrentPlayer()->GetPlayernum() == pGrid->getMortgageList(0)->getLastOwnerNum())
				{
					pOut->PrintMessage("ERROR ! You Cannot Sell Cairo Until You Return It From Mortgage. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					return;
				}

				else
				{
					pOut->PrintMessage("ERROR ! You Don't Own Cairo. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
				}
			}
			else
			{
				pOut->PrintMessage("ERROR ! There Is No Any Cairo City Card In The Grid. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
			}
			break;
		case 2:
			if(Alex)
			{
				if(pGrid->GetCurrentPlayer() == Alex->getPlayer())
				{
					if(!(Alex->getIsAccepted()))
					{
						pOut->PrintMessage("Alex Has Been Successfully Sold. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						pOut->PrintMessage(to_string(0.9 *Alex->GetPrice()) + " Will Be Now Taken From Player : " + to_string(pGrid->GetCurrentPlayer()->GetPlayernum()) + "(Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						pGrid->GetCurrentPlayer()->SetWallet(pGrid->GetCurrentPlayer()->GetWallet() + 0.9*(Alex->GetPrice()));
						pOut->PrintMessage("Player : " +to_string(pGrid->GetCurrentPlayer()->GetPlayernum()) + " Now Has " +to_string(pGrid->GetCurrentPlayer()->GetWallet()) + " In His Wallet. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						Alex->SetCityOwner(NULL);
						Alex->SetBought(false);
						Alex->setIsAccepted(false);
						if(Alex->getIsMortgaged())
						{
							pGrid->setMortgageList(-1,-1,1);
						}
						Alex->setIsMortgaged(false);
						Alex->SetisOwned(false);
					}
				}
				else if(Alex->getIsAccepted() && pGrid->getMortgageList(1)->getLastOwnerNum() == pGrid->GetCurrentPlayer()->GetPlayernum())
				{
					pOut->PrintMessage("ERROR ! You Cannot Sell Alex Until You Return It From Mortgage. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					return;
				}
				else
				{
					pOut->PrintMessage("ERROR ! You Don't Own Alex. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
				}
			}
			else
			{
				pOut->PrintMessage("ERROR ! There Is No Any Alex City Card In The Grid. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
			}
			break;
		case 3:
			if(Aswan)
			{
				if(pGrid->GetCurrentPlayer() == Aswan->getPlayer())
				{
					if(!Aswan->getIsAccepted())
					{
						pOut->PrintMessage("Aswan Has Been Successfully Sold. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						pOut->PrintMessage(to_string(0.9 *Aswan->GetPrice()) + " Will Be Now Taken From Player : " + to_string(pGrid->GetCurrentPlayer()->GetPlayernum()) + "(Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						pGrid->GetCurrentPlayer()->SetWallet(pGrid->GetCurrentPlayer()->GetWallet() + 0.9*(Aswan->GetPrice()));
						pOut->PrintMessage("Player : " +to_string(pGrid->GetCurrentPlayer()->GetPlayernum()) + " Now Has " +to_string(pGrid->GetCurrentPlayer()->GetWallet()) + " In His Wallet. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						Aswan->SetCityOwner(NULL);
						Aswan->SetBought(false);
						Aswan->setIsAccepted(false);
						if(Aswan->getIsMortgaged())
						{
							pGrid->setMortgageList(-1,-1,2);
						}
						Aswan->setIsMortgaged(false);
						Aswan->SetisOwned(false);
					}
				}
				else if(Aswan->getIsAccepted() && pGrid->getMortgageList(2)->getLastOwnerNum() == pGrid->GetCurrentPlayer()->GetPlayernum())
				{
					
						pOut->PrintMessage("ERROR ! You Cannot Sell Aswan Until You Return It From Mortgage. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						return;
					
				}
				else
				{
					pOut->PrintMessage("ERROR ! You Don't Own Aswan. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
				}
			}
			else
			{
				pOut->PrintMessage("ERROR ! There Is No Any Aswan City Card In The Grid. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
			}
			break;
		case 4:
			if(Luxor)
			{
				if(pGrid->GetCurrentPlayer() == Luxor->getPlayer())
				{
					if(!(Luxor->getIsAccepted()))
					{
						pOut->PrintMessage("Luxor Has Been Successfully Sold. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						pOut->PrintMessage(to_string(0.9 *Luxor->GetPrice()) + " Will Be Now Taken From Player : " + to_string(pGrid->GetCurrentPlayer()->GetPlayernum()) + "(Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						pGrid->GetCurrentPlayer()->SetWallet(pGrid->GetCurrentPlayer()->GetWallet() + 0.9*(Luxor->GetPrice()));
						pOut->PrintMessage("Player : " +to_string(pGrid->GetCurrentPlayer()->GetPlayernum()) + " Now Has " +to_string(pGrid->GetCurrentPlayer()->GetWallet()) + " In His Wallet. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						Luxor->SetCityOwner(NULL);
						Luxor->SetBought(false);
						Luxor->setIsAccepted(false);
						if(Luxor->getIsMortgaged())
						{
							pGrid->setMortgageList(-1,-1,3);
						}
						Luxor->setIsMortgaged(false);
						Luxor->SetisOwned(false);
					}
				}
				else if(Luxor->getIsAccepted() && pGrid->getMortgageList(3)->getLastOwnerNum() == pGrid->GetCurrentPlayer()->GetPlayernum())
				{
					pOut->PrintMessage("ERROR ! You Cannot Sell Luxor Until You Return It From Mortgage. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					return;
				}
				else
				{
					pOut->PrintMessage("ERROR ! You Don't Own Luxor. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
				}
			}
			else
			{
				pOut->PrintMessage("ERROR ! There Is No Any Luxor City Card In The Grid. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
			}
			break;
		case 5:
			if(Hurghada)
			{
				if(pGrid->GetCurrentPlayer() == Hurghada->getPlayer())
				{
					
					if(!(Hurghada->getIsAccepted()))
					{
						pOut->PrintMessage("Hurghada Has Been Successfully Sold. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						pOut->PrintMessage(to_string(0.9 *Hurghada->GetPrice()) + " Will Be Now Taken From Player : " + to_string(pGrid->GetCurrentPlayer()->GetPlayernum()) + "(Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						pGrid->GetCurrentPlayer()->SetWallet(pGrid->GetCurrentPlayer()->GetWallet() + 0.9*(Hurghada->GetPrice()));
						pOut->PrintMessage("Player : " +to_string(pGrid->GetCurrentPlayer()->GetPlayernum()) + " Now Has " +to_string(pGrid->GetCurrentPlayer()->GetWallet()) + " In His Wallet. (Click to continue....)");
						pIn->GetPointClicked(a,b);
						pOut->ClearStatusBar();
						Hurghada->SetCityOwner(NULL);
						Hurghada->SetBought(false);
						Hurghada->setIsAccepted(false);
						if(Hurghada->getIsMortgaged())
						{
							pGrid->setMortgageList(-1,-1,4);
						}
						Hurghada->setIsMortgaged(false);
						Hurghada->SetisOwned(false);
					}
				}
				else if(Hurghada->getIsAccepted() && pGrid->getMortgageList(4)->getLastOwnerNum() == pGrid->GetCurrentPlayer()->GetPlayernum())
				{
					pOut->PrintMessage("ERROR ! You Cannot Sell Hurghada Until You Return It From Mortgage. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
					return;
				}
				else
				{
					pOut->PrintMessage("ERROR ! You Don't Own Hurghada. (Click to continue....)");
					pIn->GetPointClicked(a,b);
					pOut->ClearStatusBar();
				}
			}
			else
			{
				pOut->PrintMessage("ERROR ! There Is No Any Hurghada City Card In The Grid. (Click to continue....)");
				pIn->GetPointClicked(a,b);
				pOut->ClearStatusBar();
			}
			break;
		default:
			break;
		}
	}
	return;
}

void SellCityAction::StringToCase()
{
	if(whichCity=="Cairo")
	{
		whichCard=1;
	}
	if(whichCity=="Alex")
	{
		whichCard=2;
	}
	if(whichCity=="Aswan")
	{
		whichCard=3;
	}
	if(whichCity=="Luxor")
	{
		whichCard=4;
	}
	if(whichCity=="Hurghada")
	{
		whichCard=5;
	}
	else
	{
		return;
	}
}


SellCityAction::~SellCityAction()
{
}