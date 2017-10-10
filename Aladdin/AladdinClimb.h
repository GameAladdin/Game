#pragma once
#ifndef _ALADDIN_CLIMB_H__
#define _ALADDIN_CLIMB_H__

#include"AladdinAction.h"
#include"AladdinCharacter.h"
#include"define.h"
#define COUNT_FRAME 10
//Thể hiện hành động leo của Aladdin
class AladdinClimb :public AladdinAction
{
public:
	AladdinClimb(D3DXVECTOR3 startLocation);
	~AladdinClimb();
	void				Activities(DIRECTION direction);
private:
	void	Update(DIRECTION direction);

	void				LoadResource();
};

#endif _ALADDIN_CLIMB_H__