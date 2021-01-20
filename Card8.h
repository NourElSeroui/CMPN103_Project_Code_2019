#pragma once
#include "card.h"

//Alex
class Card8 : public Card
{
private:
	static int City_Price;
	static int City_Fees;
	static Player* pOwner;//
	static bool IsSaved;
	static bool isCreated;
	static bool IsLoaded;
	static bool IsMortgaged;
	static bool City_Exist;	 //same city may exist in many cells in the grid
	static bool CityIsOwned;
	static int Owned_Player;
	static bool Bought;
	static int PassedByCity_Counter;
	static int City_isCreatedCounter;
	static bool IsAccepted;
public:
	
	Card8(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of Card8 which is: City price,fees

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card8 on the passed Player
	                                                  // by decrementing the player's wallet by the cityprice data member
														// & by decrementing the player's wallet everytime they reach a owned city

	virtual void Save(ofstream &,int type);

	virtual void Load(ifstream &,int type);

	virtual ~Card8(void);
	
	void SetCityOwner(Player *pPlayer);
	Player* BuyCity(Grid *pGrid);
	void PayCityFees(Grid *pGrid);
	bool isBought();

	void SetPrice(int p);
	int GetPrice() const;
	void SetFees(int f);
	int GetFees() const;
	void SetisCityExist(bool a);
	bool GetisCityExist() const;
	void SetisOwned(bool a);
	bool GetisOwned() const;
	void SetOwnedPlayer(int p);
	int GetOwnedPlayer() const;
	void SetBought(bool a);
	bool GetBought() const;
	void SetPassedByCityCounter(int c);
	int GetPassedByCityCounter() const;
	void SetCityisCreatedCounter (int c);
	int GetCity_isCreatedCounter () const;
	Player * getPlayer() const;
	void setIsMortgaged(bool mortgage);
	bool getIsMortgaged() const;
	void setIsAccepted(bool accept);
	bool getIsAccepted() const;
	void ResetLoad();
};