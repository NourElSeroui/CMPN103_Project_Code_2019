#include "Card11.h"

int Card11 ::City_Price=0;
int Card11::City_Fees=0;
Player* Card11::pOwner=NULL; 
bool Card11::IsLoaded=false;
bool Card11:: isCreated=false;
bool Card11::IsSaved=false;
bool Card11::IsMortgaged=false;
bool Card11::City_Exist=false;
bool Card11::CityIsOwned=false;
int Card11::Owned_Player=4;
bool Card11::Bought=false;
int Card11::PassedByCity_Counter=0;
int Card11::City_isCreatedCounter=0;
bool Card11::IsAccepted=false;

Card11::~Card11(void)
{}
Card11::Card11(const CellPosition & pos):Card(pos)
{
	cardNumber=11;
	pOwner=NULL;//
}
void Card11::SetCityOwner(Player *pPlayer)
{
	pOwner=pPlayer;
}
bool Card11::isBought()
{
	if (!pOwner) // if pOwner==NULL
		return false;
	else
		return true;
}
Player* Card11::BuyCity(Grid *pGrid)
{
	Output *pOut=pGrid->GetOutput();
	Input *pIn=pGrid->GetInput();
	Player *Currplayer=pGrid->GetCurrentPlayer();
	bool B=isBought();
	int x,y;
	if (!B) //if B==false
	{
		pOut->PrintMessage("Do you want to Buy this Cell(City) for "+std::to_string(City_Price)+"? (Y/N): ");
		string option=pIn->GetSrting(pOut);
		if (option == "y" || option == "Y")
		{
			if (Currplayer->GetWallet() >= City_Price)
			{
				pOut->PrintMessage(std::to_string(City_Price)+ " will be taken from player"+std::to_string(Currplayer->GetPlayernum())+"'s wallet...(click to continue)");
				pIn->GetPointClicked(x,y);
				pOut->ClearStatusBar();
				int CurrWallet=Currplayer->GetWallet()-City_Price;
				Currplayer->SetWallet(CurrWallet); // buying player
				SetCityOwner(Currplayer);
				pOut ->PrintMessage("Your current wallet amount is " + to_string(Currplayer->GetWallet())+" ...(click to continue)");
				pIn->GetPointClicked(x,y);
				pOut->ClearStatusBar();
				pOut->PrintMessage("Player"+std::to_string(Currplayer->GetPlayernum())+" is now the owner of this City...(click to continue)");
				pIn->GetPointClicked(x,y);
				pOut->ClearStatusBar();
				Bought=true;
				CityIsOwned=true;
			}
			else //if Currplayer->GetWallet() < City_Price
			{
				pOut->PrintMessage("No Sufficient Amount of Money to Buy this City!...(click to continue)");
				pIn->GetPointClicked(x,y);
				pOut->ClearStatusBar();
			}	
		}
		else if (option == "n" || option == "N")
		{
			pOut->PrintMessage("You have chosen not to Buy this City!...(click to continue)");
			pIn->GetPointClicked(x,y);
			pOut->ClearStatusBar();
		}
		else //any other character
		{
			pOut->PrintMessage("Invalid Character!...(click to continue)");
			pIn->GetPointClicked(x,y);
			pOut->ClearStatusBar();
		}
	}
	return Currplayer;
}
void Card11::PayCityFees(Grid *pGrid)
{
	int x,y;
	Output* pOut=pGrid->GetOutput();
	Input* pIn=pGrid->GetInput();
	bool B=isBought();
	Player* Currplayer=pGrid->GetCurrentPlayer();
	if (B) //if B==true
	{
		if (pOwner != Currplayer) // !(pOwner==Currplayer)
		{
			pOut->PrintMessage("You Have Reached an Owned City! You Must Pay a Fee...(click to continue)");
			pIn->GetPointClicked(x,y);
			pOut->ClearStatusBar();
			pOut->PrintMessage(std::to_string(City_Fees)+ " will be taken from player"+std::to_string(Currplayer->GetPlayernum())+"'s wallet...(click to continue)");
			pIn->GetPointClicked(x,y);
			pOut->ClearStatusBar();
			int decfees=Currplayer->GetWallet();
			decfees=decfees-City_Fees;
			Currplayer->SetWallet(decfees);
			int incfees=pOwner->GetWallet();
			incfees=incfees+City_Fees;
			pOwner->SetWallet(incfees);
			//Currplayer->SetWallet(Currplayer->GetWallet()-City_Fees);
			//pOwner->SetWallet(pOwner->GetWallet() +City_Fees);
			pOut ->PrintMessage("Player"+std::to_string(Currplayer->GetPlayernum())+ " ,Your current wallet amount is " + to_string(Currplayer->GetWallet())+" ...(click to continue)");
			pIn->GetPointClicked(x,y);
			pOut->ClearStatusBar();
			pOut ->PrintMessage("Player"+std::to_string(pOwner->GetPlayernum())+ " ,Your current wallet amount is " + to_string(pOwner->GetWallet())+" ...(click to continue)");
			pIn->GetPointClicked(x,y);
			pOut->ClearStatusBar();
		}	
	}
}
void Card11::ReadCardParameters(Grid * pGrid)
{
	Input *pIn=pGrid->GetInput();
	Output *pOut=pGrid->GetOutput();
	
	if (isCreated==true)
		return;

	if (isCreated==false)
	{
		pOut->PrintMessage("New Card11(Hurghada): Enter City Price: ");
		City_Price=pIn->GetInteger(pOut);
		while (City_Price<=0)
		{
			pGrid->PrintErrorMessage("Invalid Price Amount. Please Re-Enter A Valid Amount:");
			City_Price=pIn->GetInteger(pOut);
		}	
		pOut->PrintMessage("New Card11(Hurghada): Enter City Fees: ");
		City_Fees=pIn->GetInteger(pOut);
		while (City_Fees<=0)
		{
			pGrid->PrintErrorMessage("Invalid Fees Amount. Please Re-Enter A Valid Amount:");
			City_Fees=pIn->GetInteger(pOut);
		}
		isCreated=true;
		pOut->ClearStatusBar();
	}
}
void Card11::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	BuyCity(pGrid);
	PayCityFees(pGrid);
}

void Card11::SetPrice(int p)
{
	City_Price=(p>0)?p:0;
}
int Card11::GetPrice() const  
{
	return City_Price;
}
void Card11::SetFees(int f)
{
	City_Fees=(f>0)?f:0;
}
int Card11::GetFees() const  
{
	return City_Fees;
}

///////////////
void Card11::SetBought(bool a)
{
	Bought=a;
}
bool Card11::GetBought() const
{
	return Bought;
}
void Card11::SetisCityExist(bool a)
{
	City_Exist=a;
}
bool Card11::GetisCityExist() const
{
	return City_Exist;
}
void Card11::SetisOwned(bool a)
{
	CityIsOwned=a;
}
bool Card11::GetisOwned() const
{
	return CityIsOwned;
}
void Card11::SetOwnedPlayer(int p) 
{
	if (p>=0 && p<=3)
	{
		Owned_Player=p;
		CityIsOwned=true;
	}
}
int Card11::GetOwnedPlayer() const 
{
	return Owned_Player;
}
void Card11::SetPassedByCityCounter(int c)
{
	PassedByCity_Counter=c;
}
int Card11::GetPassedByCityCounter() const
{
	return PassedByCity_Counter;
}
void Card11::SetCityisCreatedCounter (int c)
{
	City_isCreatedCounter=c;
}
int Card11::GetCity_isCreatedCounter () const
{
	return City_isCreatedCounter;
}

Player * Card11::getPlayer() const
{
	return pOwner;
}

void Card11::setIsMortgaged(bool mortgage)
{
	IsMortgaged=mortgage;
}
bool Card11::getIsMortgaged() const
{
	return IsMortgaged;
}
void Card11::setIsAccepted(bool accept)
{
	IsAccepted=accept;
}
bool Card11::getIsAccepted() const
{
	return IsAccepted;
}
void Card11::Save(ofstream & SaveAction,int type)
{
	if(type==4)
	{
		if(!IsSaved)
		{
			SaveAction << cardNumber << " " << position.GetCellNum() << " " << City_Price << " " << City_Fees << endl;
			IsSaved=true;
		}
		else
		{
			SaveAction << cardNumber << " " << position.GetCellNum() << endl;
		}
	}

}

void Card11::Load(ifstream & openFile,int type)
{
	int cellNum;
	if(type==4)
	{
		if(!IsLoaded)
		{
			openFile >> cellNum >> City_Price >> City_Fees;
			if(cellNum > 0 && cellNum < 99)
			{
				position=position.GetCellPositionFromNum(cellNum);
				IsLoaded=true;
			}
		}
		else
		{
			openFile >> cellNum ;
			position=position.GetCellPositionFromNum(cellNum);
		}
	}
}

void Card11::ResetLoad()
{
	IsLoaded=false;
}
