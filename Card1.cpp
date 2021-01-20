#include "Card1.h"

Card1::Card1(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}
Card1::~Card1(void)
{}
void Card1::SetWalletAmount(int w)
{
	walletAmount=(w>0)?w:walletAmount;
}
int Card1::GetWalletAmount() const
{
	return walletAmount;
}
void Card1::ReadCardParameters(Grid * pGrid)
{
	// Reads the parameters of DecWalletCard_1 which is: walletAmount
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input *pIn;
	Output *pOut;
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New DecWalletCard_1: Enter its wallet amount ..."
	pOut->PrintMessage("New Card1: Enter its wallet amount ...");
	walletAmount=pIn->GetInteger(pOut);
	while (walletAmount<0)
	{
		pGrid->PrintErrorMessage("Invalid Wallet Amount please Enter A Valid Amount!");
		walletAmount=pIn->GetInteger(pOut);
	}
	// [ Note ]:
	// In DecWalletCard_1, the only parameter of DecWalletCard_1 is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void Card1::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of DecWalletCard_1
	Output* pOut=pGrid->GetOutput();
	Input* pIn=pGrid->GetInput();
	int x,y;
	pOut->PrintMessage(std::to_string(walletAmount)+ " will be deducted from player"+std::to_string(pPlayer->GetPlayernum())+"'s wallet...(click to continue)");
	pIn->GetPointClicked(x,y);
	pPlayer->SetWallet(pPlayer->GetWallet()-walletAmount);
	pOut ->PrintMessage("Current player new wallet amount is: "+ to_string(pPlayer ->GetWallet()));
	pOut->ClearStatusBar();
}

void Card1::Save(ofstream & SaveAction,int type)
{
	if(type == 4)
	{
		SaveAction << cardNumber << " " << position.GetCellNum() << " " << walletAmount << endl;
	}
	else
	{
		return;
	}
}

void Card1::Load(ifstream & openFile,int type)
{
	if(type == 4)
	{
		int cellNum;
		openFile >> cellNum >> walletAmount;
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