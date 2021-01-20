#include "SaveGridAction.h"

SaveGridAction::SaveGridAction(ApplicationManager *pApp) : Action(pApp)
{
}

void SaveGridAction::ReadActionParameters()
{
	pGrid=pManager->GetGrid();
	pIn=pGrid->GetInput();
	pOut=pGrid->GetOutput();
	int a,b;
	pOut->PrintMessage("Enter the file name to save....");
	file = pIn->GetSrting(pOut);
	save.open(file+".txt");
	pOut->PrintMessage("File created successfully. (Click to continue....)");
	pIn->GetPointClicked(a,b);
	pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	pGrid->SaveAll(save,1);  //saves Ladders , type=1
	pGrid->SaveAll(save,2);  //saves Snakes  , type=2
	pGrid->SaveAll(save,3);  //saves CoinSets , type=3
	pGrid->SaveAll(save,4);  //saves Cards , type=4
	save.close();

}


SaveGridAction::~SaveGridAction()
{
}
