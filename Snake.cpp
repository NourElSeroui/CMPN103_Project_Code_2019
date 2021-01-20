#include "Snake.h"

Snake::Snake(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if(startCellPos.HCell()==endCellPos.HCell() && startCellPos.VCell()<endCellPos.VCell())
	{
		this->endCellPos = endCellPos;
	}

	/// validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	
	int x,y;
	Output* pOut=pGrid->GetOutput();
	Input* pIn=pGrid->GetInput();
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pIn->GetPointClicked(x,y);
	pGrid->UpdatePlayerCell(pPlayer,endCellPos);
	pOut->ClearStatusBar();

	
	
}

void Snake::Save(ofstream & SaveAction,int type)
{
	if(type==2)
	{
		SaveAction << GetPosition().GetCellNum()<<" "<<GetEndPosition().GetCellNum()<<endl;
	}
	else
	{
		return;
	}
}

void Snake::Load(ifstream & openFile,int type)
{
}

bool Snake::IsOverlapping(GameObject * GameObj)
{
	 Snake* pSnake=dynamic_cast<Snake*>(GameObj);
	 if(pSnake && this && pSnake->GetPosition().HCell()==this->GetPosition().HCell())
		{
			for (int k=this->GetPosition().VCell();k<=this->GetEndPosition().VCell();k++)
			{
				if(pSnake->GetPosition().VCell()==k ||pSnake->GetEndPosition().VCell()==k)
				{
					return true;
				}				
			}
			for (int i=pSnake->GetPosition().VCell();i<=pSnake->GetEndPosition().VCell();i++)
			{
				if(this->GetPosition().VCell()==i || this->GetEndPosition().VCell()==i)
				{
					return true;
				}				
			}
		}
	return false;
}


CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}


Snake::~Snake()
{
}
