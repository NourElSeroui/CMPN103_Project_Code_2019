#include "Card8.h"

int Card8 ::City_Price=0;
int Card8::City_Fees=0;
Player* Card8::pOwner=NULL; 
bool Card8::IsSaved=false;
bool Card8:: isCreated=false;
bool Card8::IsLoaded=false;
bool Card8::IsMortgaged=false;
bool Card8::City_Exist=false;
bool Card8::CityIsOwned=false;
int Card8::Owned_Player=4;
bool Card8::Bought=false;
int Card8::PassedByCity_Counter=0;
int Card8::City_isCreatedCounter=0;
bool Card8::IsAccepted=false;

Card8::~Card8(void)
{}
Card8::Card8(const CellPosition & pos):Card(pos)
{
	cardNumber=8;
	pOwner=NULL;//
}
void Card8::SetCityOwner(Player *pPlayer)
{
	pOwner=pPlayer;
}
bool Card8::isBought()
{
	if (!pOwner) // if pOwner==NULL
		return false;
	else
		return true;
}
Player* Card8::BuyCity(Grid *pGrid)
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
void Card8::PayCityFees(Grid *pGrid)
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
void Card8::ReadCardParameters(Grid * pGrid)
{
	Input *pIn=pGrid->GetInput();
	Output *pOut=pGrid->GetOutput();
	
	if (isCreated==true)
		return;

	if (isCreated==false)
	{
		pOut->PrintMessage("New Card8(Alex): Enter City Price: ");
		City_Price=pIn->GetInteger(pOut);
		while (City_Price<=0)
		{
			pGrid->PrintErrorMessage("Invalid Price Amount. Please Re-Enter A Valid Amount:");
			City_Price=pIn->GetInteger(pOut);
		}	
		pOut->PrintMessage("New Card8(Alex): Enter City Fees: ");
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
// It applies the effect of the Card Type on the passed player
// It is a virtual function (implementation depends on Card Type)
///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
// 1- Call Apply() of the base class Card to print the message that you reached this card number
// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
void Card8::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	BuyCity(pGrid);
	PayCityFees(pGrid);
}

void Card8::SetPrice(int p)
{
	City_Price=(p>0)?p:0;
}
int Card8::GetPrice() const  
{
	return City_Price;
}
void Card8::SetFees(int f)
{
	City_Fees=(f>0)?f:0;
}
int Card8::GetFees() const  
{
	return City_Fees;
}

///////////////
void Card8::SetBought(bool a)
{
	Bought=a;
}
bool Card8::GetBought() const
{
	return Bought;
}
void Card8::SetisCityExist(bool a)
{
	City_Exist=a;
}
bool Card8::GetisCityExist() const
{
	return City_Exist;
}
void Card8::SetisOwned(bool a)
{
	CityIsOwned=a;
}
bool Card8::GetisOwned() const
{
	return CityIsOwned;
}
void Card8::SetOwnedPlayer(int p) 
{
	if (p>=0 && p<=3)
	{
		Owned_Player=p;
		CityIsOwned=true;
	}
}
int Card8::GetOwnedPlayer() const 
{
	return Owned_Player;
}
void Card8::SetPassedByCityCounter(int c)
{
	PassedByCity_Counter=c;
}
int Card8::GetPassedByCityCounter() const
{
	return PassedByCity_Counter;
}
void Card8::SetCityisCreatedCounter (int c)
{
	City_isCreatedCounter=c;
}
int Card8::GetCity_isCreatedCounter () const
{
	return City_isCreatedCounter;
}

Player * Card8::getPlayer() const
{
	return pOwner;
}

void Card8::setIsMortgaged(bool mortgage)
{
	IsMortgaged=mortgage;
}
bool Card8::getIsMortgaged() const
{
	return IsMortgaged;
}
void Card8::setIsAccepted(bool accept)
{
	IsAccepted=accept;
}
bool Card8::getIsAccepted() const
{
	return IsAccepted;
}
void Card8::Save(ofstream & SaveAction,int type)
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

void Card8::Load(ifstream & openFile,int type)
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

void Card8::ResetLoad()
{
	IsLoaded=false;
}
