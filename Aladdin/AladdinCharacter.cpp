#include "AladdinCharacter.h"

ALADDIN::ALADDIN(D3DXVECTOR3 startLocation)
{
	this->mAction[Engine::WALK] = new AladdinWalk(startLocation);
	this->mAction[Engine::CLIMB] = new AladdinClimb(startLocation);
	this->mAction[Engine::SWING] = new AladdinSwing(startLocation);
	this->mAction[Engine::DROP] = new AladdinDrop(startLocation);
	this->mCurrentLocation = startLocation;
}


ALADDIN::~ALADDIN()
{
}

void ALADDIN::Activities(Engine::STATE state, Engine::DIRECTION direction)
{
	this->mAction[state]->Activities(direction);
}

AladdinAction ** ALADDIN::GetAction()
{
	return this->mAction;
}

D3DXVECTOR3 ALADDIN::GetCurrentLocation()
{
	return AladdinAction::GetCurrentLocation();
}

void ALADDIN::SetCurrentLocation(D3DXVECTOR3 location)
{
	AladdinAction::SetCurrentLocation(location);
}

void ALADDIN::SetEndLocation(D3DXVECTOR3 location)
{
	AladdinAction::SetEndLocation(location);
}

D3DXVECTOR3 ALADDIN::GetEndLocation()
{
	return AladdinAction::GetEndLocation();;
}

void ALADDIN::SetSpeed(float speed, Engine::STATE state)
{
	this->mAction[state]->SetSpeed(speed);
}





