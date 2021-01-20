#pragma once
#include "Gameobject.h"
#include "Player.h"

//please implement the coinset as card 16

class CoinSet : public GameObject
{
private:
	int Amount;
	CellPosition Pos;
public:
	
	virtual void Draw(Output* pOut) const; // Draws a coinset

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the coinset to the player

	virtual void Save(ofstream &,int type);

	virtual void Load(ifstream &,int type);

	virtual ~CoinSet(); // Virtual destructor

	CoinSet(const CellPosition & pos); // A constructor for initialization

	void ReadCoinSetParameters(Grid * pGrid);

	int GetCoinsetNumber();
	
};