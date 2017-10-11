#pragma once
#ifndef _ALADDIN_CLIMB_H__
#define _ALADDIN_CLIMB_H__

#include"AladdinAction.h"
#include"AladdinCharacter.h"
#include"Engine.h"
#include"define.h"
USEGAME_FRAMEWORK
#define COUNT_FRAME 10
//Thể hiện hành động leo của Aladdin
class AladdinClimb :public AladdinAction
{
public:
	AladdinClimb(D3DXVECTOR3 startLocation);
	~AladdinClimb();
	void				Activities(Engine::DIRECTION direction);
private:
	void			
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		Update(Engine::DIRECTION direction);

	void				LoadResource();
};

#endif _ALADDIN_CLIMB_H__