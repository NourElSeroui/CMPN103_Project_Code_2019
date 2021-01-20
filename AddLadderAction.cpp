#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	int a,b;
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

    

	///TODO: Make the needed validations on the read parameters
	while (startPos.GetCellNum()==1 || endPos.GetCellNum()==99)
	{
		pGrid->PrintErrorMessage("Invalid! Ladder game object cannot be placed in first or last cell! (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
		pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
		startPos = pIn->GetCellClicked();
		pOut->PrintMessage("New Ladder: Click on its End Cell ...");
		endPos = pIn->GetCellClicked();
	}
	while (startPos.IsValidCell()==false)
	{
		pOut->PrintMessage("Invalid Start Cell! Please Re-select a valid start cell");
		pOut->ClearStatusBar();
		startPos = pIn->GetCellClicked();
	}
	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	while (startPos.GetCellNum()==endPos.GetCellNum())
	{
		pOut->PrintMessage("Invalid The end cell of a ladder cannot be the start cell of another ladder or snake!");
		pOut->ClearStatusBar();
		endPos = pIn->GetCellClicked();
		pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
		startPos = pIn->GetCellClicked();
		pOut->PrintMessage("New Ladder: Click on its End Cell ...");
		endPos = pIn->GetCellClicked();
	}
	while (endPos.GetCellNum()<startPos.GetCellNum())
	{
		pOut->PrintMessage("Invalid The end cell of a ladder cannot be under the start cell of the ladder!");
		pOut->ClearStatusBar();
		pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
		startPos = pIn->GetCellClicked();
		pOut->PrintMessage("New Ladder: Click on its End Cell ...");
		endPos = pIn->GetCellClicked();
	}
	while (startPos.HCell() != endPos.HCell())
	{
		pOut->PrintMessage("Invalid The ladder must be in the same column!");
		pOut->ClearStatusBar();
		pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
		startPos = pIn->GetCellClicked();
		pOut->PrintMessage("New Ladder: Click on its End Cell ...");
		endPos = pIn->GetCellClicked();
	}
	while (endPos.IsValidCell()==false)
	{
		pOut->PrintMessage("Invalid End Cell! Please Re-select a valid end cell");
		pOut->ClearStatusBar();
		endPos = pIn->GetCellClicked();
	}
	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	 Snake * snake=pGrid->GetNextSnake(endPos);
	 Ladder * ladder=pGrid->GetNextLadder(endPos);
	 
	 
	  
	 if(snake)
	 {	
		 if(snake->GetPosition().GetCellNum()==endPos.GetCellNum())
	 {
		 pGrid->PrintErrorMessage("End cell can't be the start of another Snake or Ladder");
		 return;
	 
	 }
	 }
	 
	 if(ladder)
	 { 
		 if(ladder->GetPosition().GetCellNum()==endPos.GetCellNum())
	 {
		 pGrid->PrintErrorMessage("End cell can't be the start of another Snake or Ladder");
		 return;
	 }
	 }

	 Ladder * l = new Ladder(startPos, endPos);
	 GameObject* g =l;

	 if(pGrid->IsOverlapping(g))
	 {
		 pGrid->PrintErrorMessage("Two Ladders can't overlap...(click to continue)");
		 return;
	 }
}