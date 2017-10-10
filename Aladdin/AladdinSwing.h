#pragma once
#ifndef _ALADDIN_SWING_H__
#define _ALADDIN_SWING_H__

#include"AladdinAction.h"
#include"AladdinCharacter.h"
#include"define.h"
#define COUNT_FRAME 10
//Thể hiện hành động đu dây của Aladdin
class AladdinSwing:public AladdinAction
{
public:
	AladdinSwing(D3DXVECTOR3 startLocation);
	~AladdinSwing();
	void				Activities(DIRECTION direction);
private:
	void				Update(DIRECTION direction);
	
	void				LoadResource();
};

#endif _ALADDIN_SWING_H__