#include "AddCoinSetAction.h"

#include "Input.h"
#include "Output.h"

AddCoinSetAction::AddCoinSetAction(ApplicationManager *pApp) : Action(pApp)
{// Initializes the pManager pointer of Action with the passed pointer
}
AddCoinSetAction::~AddCoinSetAction()
{}
void AddCoinSetAction::ReadActionParameters() 
{	
	Grid *pGrid=pManager->GetGrid();
	Output *pOut=pGrid->GetOutput();
	Input *pIn=pGrid->GetInput();
	
	// note: amount will be read from coinset.cpp
	/*pOut->PrintMessage("New CoinSet: Enter it's Amount ...");
	Amount=pIn->GetInteger(pOut);
	while (Amount<0)
	{
		pOut->PrintMessage("Invalid Amount! Please re-enter valid Amount!");
		Amount=pIn->GetInteger(pOut);
	}*/
	pOut->PrintMessage("New CoinSet: Select it's Position ...");
	CoinSetPosition=pIn->GetCellClicked();
	while (CoinSetPosition.IsValidCell()==false)
	{
		pOut->PrintMessage("Invalid Card Position! Please re-select a valid Card Position!");
		CoinSetPosition=pIn->GetCellClicked();
	}
	while (CoinSetPosition.GetCellNum()==1 || CoinSetPosition.GetCellNum()==99)
	{
		pOut->PrintMessage("Invalid CoinSet Position! You cannot place Coin Set game object in first or last cell! Please re-select a valid CoinSet Position!");
		CoinSetPosition=pIn->GetCellClicked();
	}
	pOut->ClearStatusBar();
}
void AddCoinSetAction::Execute() 
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	CoinSet * pCoinSet = new CoinSet(CoinSetPosition); // will point to the coinset object type
	
	// A- We get a pointer to the Grid from the ApplicationManager
	Grid *pGrid=pManager->GetGrid();
	// B- Make the "pCoinSet" reads its CoinSet parameters [AMOUNT]: ReadCoinSetParameters(), [It is virtual and depends on the type]

	pCoinSet->ReadCoinSetParameters(pGrid);

	// C- Add the card object to the GameObject of its Cell:
	bool added=pGrid->AddObjectToCell(pCoinSet);
	// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
	if (!added)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the coinset is created and added to the GameObject of its Cell, so we finished executing the AddCoinSetAction
}