#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if(startCellPos.GetCellNumFromPosition(startCellPos) < endCellPos.GetCellNumFromPosition(endCellPos))
	{
		this->endCellPos = endCellPos;
	}
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	int a,b;

	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->GetOutput()->PrintMessage("You Have Reached A Ladder.. (Click to continue....)");
	pGrid->GetInput()->GetPointClicked(a,b);
	pGrid->GetOutput()->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer,endCellPos);
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

void Ladder::Save(ofstream & SaveAction,int type)
{
	if(type==1)
	{
		SaveAction << GetPosition().GetCellNum() << " " << GetEndPosition().GetCellNum() << endl ;
	}
	else
	{
		return;
	}

}

void Ladder::Load(ifstream & openFile,int type)
{
}

bool Ladder::IsOverlapping(GameObject * GameObj)
{
	Ladder* pLadder=dynamic_cast<Ladder*>(GameObj);
	if(pLadder && pLadder->GetPosition().HCell()==this->GetPosition().HCell())
			{
				for (int k=this->GetPosition().VCell();k>=this->GetEndPosition().VCell();k--)
				{
					if(pLadder->GetPosition().VCell()==k || pLadder->GetEndPosition().VCell()==k)
					{
						return true;
					}				
				}
				for (int i=pLadder->GetPosition().VCell();i>=pLadder->GetEndPosition().VCell();i--)
				{
					if(this->GetPosition().VCell()==i || this->GetEndPosition().VCell()==i)
					{
						return true;
					}				
				}
			}
	return false;
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
