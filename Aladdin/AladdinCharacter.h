#pragma once
#ifndef __ALADDIN_H__
#define	__ALADDIN_H__
#include<vector>
#include"define.h"
#include"AladdinAction.h"
#include"AladdinWalk.h"
#include"AladdinClimb.h"
#include"AladdinSwing.h"
#include"AladdinDrop.h"
#include"Engine.h"
USEGAME_FRAMEWORK

class ALADDIN
{
public:
	/*
	startLocation: Điểm xuất phát của aladdin
	..*/
	ALADDIN(D3DXVECTOR3 startLocation);
	~ALADDIN();
	void		Render();
	/*state: Trạng thái của aladdin (Walk, Down, Up...)
	direction: Hướng đi của aladdin
	..*/
	void				Activities(Engine::STATE state, Engine::DIRECTION direction);
	AladdinAction**  	GetAction();
	D3DXVECTOR3			GetCurrentLocation();
	void				SetCurrentLocation(D3DXVECTOR3 location);
	void				SetEndLocation(D3DXVECTOR3 location);
	D3DXVECTOR3			GetEndLocation();
	void				SetSpeed(float speed, Engine::STATE state = Engine::DROP);
protected:
	AladdinAction*		mAction[4];
	D3DXVECTOR3			mCurrentLocation;
};

#endif _ALADDIN_H__