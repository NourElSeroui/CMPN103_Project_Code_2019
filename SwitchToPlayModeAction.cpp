#include "SwitchToPlayModeAction.h"

SwitchToPlayModeAction::~SwitchToPlayModeAction(void)
{}
SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager *pApp):Action(pApp)
{}
void SwitchToPlayModeAction::ReadActionParameters()
{
	int x,y;
	Grid *pGrid = pManager->GetGrid();
	Output *pOut=pGrid->GetOutput();
	Input *pIn=pGrid->GetInput();
	pOut->PrintMessage("Switch to Play Mode. Click to Continue...");
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
}
void SwitchToPlayModeAction::Execute()
{
	ReadActionParameters();
	Grid *pGrid=pManager->GetGrid();
	UI.InterfaceMode= MODE_PLAY;
	pGrid->UpdateInterface(); //OR
	//Output *pOut=pGrid->GetOutput();
	//pOut->CreatePlayModeToolBar();
}