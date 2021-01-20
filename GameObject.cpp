#include "GameObject.h"

GameObject::GameObject(const CellPosition & pos)
{
		position = pos; // Sets Position
}
CellPosition GameObject::GetPosition() const
{
	return position;
}
GameObject::~GameObject()
{}

void GameObject::SetPosition(const CellPosition &pos)
{
	if (pos.IsValidCell()==true)
		position = pos;
}
bool GameObject::IsOverlapping(GameObject * GameObj)
{
	return 0;
}