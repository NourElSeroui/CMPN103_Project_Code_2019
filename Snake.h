#pragma once
#include "GameObject.h"

class Snake :public GameObject
{
	CellPosition endCellPos;
	
public:
	Snake(const CellPosition & startCellPos, const CellPosition & endCellPos);

	virtual void Draw(Output* pOut) const; 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	CellPosition GetEndPosition() const; 

	virtual void Save(ofstream &,int type);
	virtual void Load(ifstream &,int type);
	virtual bool IsOverlapping(GameObject * GameObj);
	~Snake(void);
};