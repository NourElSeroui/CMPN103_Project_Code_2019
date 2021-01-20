#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"
#include "Ladder.h"


AddSnakeAction::AddSnakeAction(ApplicationManager *pApp) : Action(pApp)
{
	
}

void AddSnakeAction::ReadActionParameters() 
{	
	
	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();
	
	Input* pIn = pGrid->GetInput();



	pOut->PrintMessage("New snake, Click on its start cell ....");

		startPos = pIn->GetCellClicked();

	
	
	pOut->PrintMessage("New snake, Click on its end cell ....");
	
	endPos = pIn->GetCellClicked();


	

	pOut->ClearStatusBar();


}

void AddSnakeAction::Execute() 
{
	
	
	ReadActionParameters();


	Grid * pGrid = pManager->GetGrid(); 
	
	if (startPos.HCell()!=endPos.HCell()) ///TODO: Make the needed validations on the read parameters
	
	{
	
		pGrid->PrintErrorMessage("Error! Start and End cell must be in the same coulumn....");
		
		return;
	}

	
	else if(startPos.VCell()>=endPos.VCell())
	
	{
	
		pGrid->PrintErrorMessage("start cell can't be lower than end cell");
	
		return;
	
	}	 
	
	  
	
	Snake* s=pGrid->GetNextSnake(endPos);
	
	Ladder* l=pGrid->GetNextLadder(endPos);
	

	 if(s)
	
	 {	
	
		 if(s->GetPosition().GetCellNum()==endPos.GetCellNum())
	
		 {
		
			 pGrid->PrintErrorMessage("End cell can not be the start of another snake or ladder....");
		
			 return;
	
		
		 }
	 
	 }
	 
	
	 if(l)
	
	 { 
		
		 if(l->GetPosition().GetCellNum()==endPos.GetCellNum())
	
		 {
		
			 pGrid->PrintErrorMessage("End cell can not be the start of another snake or ladder");
		
			 return;
	 
		 }
	
	 }

	
	 Snake * pSnake = new Snake (startPos,endPos);

	
	 GameObject* g =pSnake;

	
	 if(pGrid->IsOverlapping(g))
	
	 {
		
		 pGrid->PrintErrorMessage("Two snakes can not be overlaped");
		
		 return;
	 
	 }


	
	 bool added = pGrid->AddObjectToCell(pSnake);

	
	 if (! added)
	
	 {
	
		 pGrid->PrintErrorMessage("Error! Cell already has an object ,Click to continue ....");
	

	
	 }
	

}



AddSnakeAction::~AddSnakeAction(void)
{
}