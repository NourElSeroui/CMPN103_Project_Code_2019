#include "CutCardOrCoinsAction.h"

CutCardOrCoinsAction::CutCardOrCoinsAction(ApplicationManager* pApp) : Action(pApp)
{
	f=true;
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardOrCoinsAction::~CutCardOrCoinsAction()
{
}

void CutCardOrCoinsAction::ReadActionParameters()
{
	cardorcoinsno=0;
	int x, y;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pCard = NULL;


	pOut->PrintMessage("Copy Game Object: Click to continue...");
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("Click on the Cell to Copy the Game Object in it ...");
	cardorcoinsposition = pIn->GetCellClicked(); // Read the  parameter

	while (cardorcoinsposition.IsValidCell() == false) //GameObjectCellPos.GetCellNum() <0 && GameObjectCellPos.GetCellNum() >99
	{
		pGrid->PrintErrorMessage("Invalid Cell. Please Re-Select a Valid Cell");
		pOut->ClearStatusBar();
		cardorcoinsposition = pIn->GetCellClicked();
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
	Card * c = pGrid->GetNextCard(cardorcoinsposition,0);
	if(!(c && c->GetPosition().GetCellNum() == cardorcoinsposition.GetCellNum()))
	{
		pOut->PrintMessage("No Cards In This Cell.(Click to continue....)");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		f=false;
	}
	else
	{
		pCard=c;
	}

}

void CutCardOrCoinsAction::Execute()
{
	ReadActionParameters();
	if(f)
	{
		pGrid->SetClipboard1(pCard);
		pGrid->RemoveObjectFromCell(cardorcoinsposition);
	}
}