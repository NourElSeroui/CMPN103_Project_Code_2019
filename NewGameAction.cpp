#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"

NewGameAction::NewGameAction(ApplicationManager *pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{

}

void NewGameAction::Execute()
{

	
	for(int i=0;i<2;i++)
	{
	
		Grid* pGrid = pManager->GetGrid();

		Output* pOut = pGrid->GetOutput();
	
		Input* pIn = pGrid->GetInput();
	
		int x,y;
	

	
		pOut->ClearGridArea();
	
		pOut->ClearStatusBar();
	
		CellPosition origin(8,0);
	
		CellPosition pCell;

		for(int i=0;i<4;i++)
	
		{
		
			pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(),origin);
	
			pGrid->GetCurrentPlayer()->SetWallet(100);
		
			pGrid->GetCurrentPlayer()->SetTurnCount(0);
		
			pGrid->GetCurrentPlayer()->SetStepCount(0);
		
			pGrid->AdvanceCurrentPlayer();
		
	
		}
	
	
		pGrid->RemoveAllObjects();

while(pGrid->GetCurrentPlayer()->GetPlayernum() !=0)

{
					
	pGrid->AdvanceCurrentPlayer();
		
}

pGrid->SetEndGame(false);

}
}

NewGameAction::~NewGameAction(void)
{
}
