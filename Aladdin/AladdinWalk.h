#pragma once
#ifndef _ALADDIN_WALK_H__
#define _ALADDIN_WALK_H__
#include"AladdinAction.h"
#include"AladdinCharacter.h"
#include<vector>
#include"define.h"
using namespace std;
#define COUNT_FRAME 13

class AladdinWalk :public AladdinAction
{
public:
	AladdinWalk(D3DXVECTOR3 startLocation);
	~AladdinWalk();
	void				Activities(Engine::DIRECTION direction);
private:
	//Update sprite location
	void				Update(Engine::DIRECTION direction);
	//Load resource from file
	void				LoadResource();
};

#endif _ALADDIN_WALK_H__