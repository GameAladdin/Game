﻿#pragma once
#ifndef _ALADDIN_DROP_H__
#define _ALADDIN_DROP_H__

#include"AladdinAction.h"
#include"AladdinCharacter.h"
#include"define.h"
#define COUNT_FRAME 19
//Thể hiện hành động nhảy xuống của Aladdin
class AladdinDrop :public AladdinAction
{
public:
	AladdinDrop(D3DXVECTOR3 startLocation);

	~AladdinDrop();
	void					Activities(DIRECTION direction);

	void					SetEndLocation(D3DXVECTOR3 location);
private:
	void					Update(DIRECTION direction);

	void					LoadResource();

	void					SetUpCurrentFrame();

	D3DXVECTOR3				mEndLocation;
};

#endif _ALADDIN_DROP_H__