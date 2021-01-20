#include "DeleteGameObjectAction.h"

DeleteGameObjectAction::~DeleteGameObjectAction(void)
{}
DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager *pApp):Action(pApp) // Initializes the pManager pointer of Action with the passed pointer
{}
void DeleteGameObjectAction::ReadActionParameters()
{
	int x,y;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Delete Game Object: Click to continue...");
	pIn ->GetPointClicked(x,y);
	pOut->PrintMessage("Click on the Cell to Delete the Game Object in it ...");
	GameObjectCellPos=pIn->GetCellClicked(); // Read the  parameter
	while (GameObjectCellPos.IsValidCell()==false) //GameObjectCellPos.GetCellNum() <0 && GameObjectCellPos.GetCellNum() >99
	{
		pGrid->PrintErrorMessage("Invalid Cell Number. Please Re-Select a Valid Cell Number");
		pOut->ClearStatusBar();
		GameObjectCellPos=pIn->GetCellClicked();
	}
	/*
	while (! pGrid->GetGameObject(GameObjectCellPos)) //check if this cell contains a game object!
	{
		pGrid->PrintErrorMessage("There is no Game Object in this cell. Please Re-select a Game Object");
		pOut->ClearStatusBar();
		GameObjectCellPos=pIn->GetCellClicked();
	}
	*/
	// Clear messages
	pOut->ClearStatusBar();
}
void DeleteGameObjectAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveObjectFromCell(GameObjectCellPos);
}