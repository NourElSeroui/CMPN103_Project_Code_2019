#pragma once
#include "Action.h"


#include "Grid.h"
#include "Player.h"

//#include "cellposition.h"

//delete the game object in the cell that the user chooses

class DeleteGameObjectAction : public Action
{
private:
	CellPosition GameObjectCellPos;
public:
	DeleteGameObjectAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~DeleteGameObjectAction(void);

	//setter & getter for cellpos
};