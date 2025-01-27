#include "CellPosition.h"
#include "UI_Info.h"
CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}
CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	
	
		(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
													// from the passed (cellNum)
													// (*this) = ... --> this will copy the returned (vCell and hCell)
													//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	

	if (v <= (NumVerticalCells - 1) && v >= 0)
	{
		vCell = v;
		return true;
	}
	else
	
	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h < NumHorizontalCells && h >= 0)
	{
		hCell = h;
		return true;
	}
	else
	{


		return false; // this line sould be changed with your implementation
	}
}
int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if ((hCell >= 0 && hCell < NumHorizontalCells) && (vCell >= 0 && vCell <= (NumVerticalCells - 1)))
		return true;
	else
	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int cellNum;
	int x =cellPosition.HCell();
	int y= cellPosition.VCell();
	if((y<0 || y>=9) || (x<0 || x>=11))
	{
		cellNum=0;
		return cellNum;
	}

	cellNum=((8-y)*11)+(1+x);

	return cellNum;
	

 // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .
	if(cellNum<0 || cellNum>99)
	{
		position.SetHCell(-1);
		position.SetVCell(-1);
		return position;
	}
	int count=0;
	position.SetHCell((cellNum -1)%11);
	for(int i=1;i<10;i++)
	{
		if(cellNum == 11*i)
		{
			position.SetVCell(8-((cellNum-1)/11));
		}
		else
		{
			count++;
		}
	}
	if(count==9)
	{
		position.SetVCell(8-(cellNum/11));
	}

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	
	/// TODO: Implement this function as described in the .h file

	 int cellNum = this->GetCellNum() + addedNum;
	this->SetHCell(GetCellPositionFromNum(cellNum).HCell());
	this->SetVCell(GetCellPositionFromNum(cellNum).VCell());
	// Note: this function updates the data members (vCell and hCell) of the calling object

}