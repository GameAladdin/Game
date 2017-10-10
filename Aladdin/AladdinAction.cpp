#include "AladdinAction.h"


D3DXVECTOR3		AladdinAction::mCurrentLocation = D3DXVECTOR3(0, 0, 0);
D3DXVECTOR3		AladdinAction::mEndLocation = D3DXVECTOR3(0, 0, 0);

AladdinAction::AladdinAction()
{
}

AladdinAction::~AladdinAction()
{
	if (this->mSprite)
		delete(this->mSprite);
}

void AladdinAction::Activities(DIRECTION direction)
{
	int i = this->GetCurrentFrame();
	this->mSprite->SetPosition(mCurrentLocation.x, mCurrentLocation.y);
	this->mSprite->Draw(i - 1, D3DXVECTOR2(this->mSprite->GetScale().x*2, this->mSprite->GetScale().y*2));
	this->SetUpCurrentFrame();
	this->Update(direction);
}

void AladdinAction::SetCurrentLocation(D3DXVECTOR3 location)
{
	mCurrentLocation = location;
}

D3DXVECTOR3 AladdinAction::GetCurrentLocation()
{
	return mCurrentLocation;
}

void AladdinAction::SetSpeed(float speed)
{
	this->mSpeed = speed;
}

void AladdinAction::SetEndLocation(D3DXVECTOR3 location)
{
	mEndLocation = location;
}

D3DXVECTOR3 AladdinAction::GetEndLocation()
{
	return mEndLocation;
}

int AladdinAction::GetCurrentFrame()
{
	return this->mCurrentFrame;
}

void AladdinAction::SetUpCurrentFrame()
{
	mCurrentFrame = (mCurrentFrame >= this->mEndFrame) ? this->mStartFrame : ++mCurrentFrame;
}
