#include "Card7.h"

int Card7::City_Price=0;
int Card7::City_Fees=0;
Player* Card7::pOwner=NULL; 
bool Card7:: IsSaved=false;
bool Card7:: isCreated=false;
bool Card7:: IsLoaded=false;
bool Card7::IsMortgaged=false;
bool Card7::City_Exist=false;
bool Card7::CityIsOwned=false;
int Card7::Owned_Player=4;
bool Card7::Bought=false;
int Card7::PassedByCity_Counter=0;
int Card7::City_isCreatedCounter=0;
bool Card7::IsAccepted=false;

Card7::~Card7(void)
{}
Card7::Card7(const CellPosition & pos):Card(pos)
{
	cardNumber=7;
	pOwner=NULL;//
}
void Card7::SetCityOwner(Player *pPlayer)
{
	pOwner=pPlayer;
}
bool Card7::isBought()
{
	if (!pOwner) // if pOwner==NULL
		return false;
	else
		return true;
}
Player* Card7::BuyCity(Grid *pGrid)
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
void Card7::PayCityFees(Grid *pGrid)
{
	int x,y;
	Output* pOut=pGrid->GetOutput();
	Input* pIn=pGrid->GetInput();
	bool B=isBought();
	Player* Currplayer=pGrid->GetCurrentPlayer();
	if (B) //if B==true
	{
		if (pOwner != Currplayer) // !(pOwner==Currplayer) && Currplayer->GetWallet() >= City_Fees
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
// if a player chooses to buy Alex, he will own all cells having a card Alex (A cell is considered as a station)
//Each city has a "price" to be bought with and "fees" for any players passes by the cell.
// The city price is deducted from the player�s wallet "in case he chooses to buy the cell".
// Whenever a player moves to a city owned by another player, he has to pay fees to owner.
// Input data during grid design time:
//i. City price
//ii. Fees to be paid by passing players
//Important Note: Input data is only taken if it is the first time to insert a city of this type in the grid. 
//For example, user will insert price and fees of Alex only "once" no matter how many Alex cells exist in the grid.

// It reads the parameters specific for each Card Type
// It is a virtual function (implementation depends on Card Type)
///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
// 1- Get a Pointer to the Input / Output Interfaces from the Grid
// 2- Read an Integer from the user using the Input class and set the parameter with it 
//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its  amount ..." 
// [ Note ]:
// In CardN, the only parameter of CardN is the "...." value to decrease from player
// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
// to be able to perform his Apply() action
// 3- Clear the status bar
void Card7::ReadCardParameters(Grid * pGrid)
{
	Input *pIn=pGrid->GetInput();
	Output *pOut=pGrid->GetOutput();
	
	if (isCreated==true)
		return;

	if (isCreated==false)
	{
		pOut->PrintMessage("New Card7(Cairo): Enter City Price: ");
		City_Price=pIn->GetInteger(pOut);
		while (City_Price<=0)
		{
			pGrid->PrintErrorMessage("Invalid Price Amount. Please Re-Enter A Valid Amount:");
			City_Price=pIn->GetInteger(pOut);
		}	
		pOut->PrintMessage("New Card7(Cairo): Enter City Fees: ");
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
void Card7::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	BuyCity(pGrid);
	PayCityFees(pGrid);
}

void Card7::SetPrice(int p)
{
	City_Price=(p>0)?p:0;
}
int Card7::GetPrice() const  
{
	return City_Price;
}
void Card7::SetFees(int f)
{
	City_Fees=(f>0)?f:0;
}
int Card7::GetFees() const  
{
	return City_Fees;
}

///////////////
void Card7::SetBought(bool a)
{
	Bought=a;
}
bool Card7::GetBought() const
{
	return Bought;
}
void Card7::SetisCityExist(bool a)
{
	City_Exist=a;
}
bool Card7::GetisCityExist() const
{
	return City_Exist;
}
void Card7::SetisOwned(bool a)
{
	CityIsOwned=a;
}
bool Card7::GetisOwned() const
{
	return CityIsOwned;
}
void Card7::SetOwnedPlayer(int p) 
{
	if (p>=0 && p<=3)
	{
		Owned_Player=p;
		CityIsOwned=true;
	}
}
int Card7::GetOwnedPlayer() const 
{
	return Owned_Player;
}
void Card7::SetPassedByCityCounter(int c)
{
	PassedByCity_Counter=c;
}
int Card7::GetPassedByCityCounter() const
{
	return PassedByCity_Counter;
}
void Card7::SetCityisCreatedCounter (int c)
{
	City_isCreatedCounter=c;
}
int Card7::GetCity_isCreatedCounter () const
{
	return City_isCreatedCounter;
}

Player * Card7::getPlayer() const
{
	return pOwner;
}

void Card7::setIsMortgaged(bool mortgage)
{
	IsMortgaged=mortgage;
}
bool Card7::getIsMortgaged() const
{
	return IsMortgaged;
}
void Card7::setIsAccepted(bool accept)
{
	IsAccepted=accept;
}
bool Card7::getIsAccepted() const
{
	return IsAccepted;
}

void Card7::Save(ofstream & SaveAction,int type)
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

void Card7::Load(ifstream & openFile,int type)
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

void Card7::ResetLoad()
{
	IsLoaded=false;
}