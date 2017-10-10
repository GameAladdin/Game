#include"AladdinCharacter.h"
#include"define.h"

AladdinCharacter::AladdinCharacter(D3DXVECTOR3 startLocation)
{
	this->mAction[STATE::WALK] = new AladdinCharacterWalk(startLocation);
	this->mAction[STATE::CLIMB] = new AladdinCharacterClimb(startLocation);
	this->mAction[STATE::SWING] = new AladdinCharacterSwing(startLocation);
	this->mAction[STATE::DROP] = new AladdinCharacterDrop(startLocation);
	this->mCurrentLocation = startLocation;
}


AladdinCharacter::~AladdinCharacter()
{
}

void AladdinCharacter::Activities(GLOBAL::STATE state, GLOBAL::DIRECTION direction)
{
	this->mAction[state]->Activities(direction);
}

AladdinCharacterAction ** AladdinCharacter::GetAction()
{
	return this->mAction;
}

D3DXVECTOR3 AladdinCharacter::GetCurrentLocation()
{
	return AladdinCharacterAction::GetCurrentLocation();
}

void AladdinCharacter::SetCurrentLocation(D3DXVECTOR3 location)
{
	AladdinCharacterAction::SetCurrentLocation(location);
}

void AladdinCharacter::SetEndLocation(D3DXVECTOR3 location)
{
	AladdinCharacterAction::SetEndLocation(location);
}

D3DXVECTOR3 AladdinCharacter::GetEndLocation()
{
	return AladdinCharacterAction::GetEndLocation();;
}

void AladdinCharacter::SetSpeed(float speed, GLOBAL::STATE state)
{
	this->mAction[state]->SetSpeed(speed);
}



