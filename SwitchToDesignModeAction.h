#pragma once
#include "Action.h"
#include"Grid.h"
#include"Player.h"
class SwitchToDesignModeAction : public Action
{
public:

	SwitchToDesignModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~SwitchToDesignModeAction(void);
};