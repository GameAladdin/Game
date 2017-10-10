#pragma once
#ifndef __ALADDINCHARACTER_H__
#define	__ALADDINCHARACTER_H__
#include"Sprite.h"
#include"AladdinAction.h"
#include"AladdinWalk.h"
#include"AladdinClimb.h"
#include"AladdinSwing.h"
#include"AladdinDrop.h"
#include<vector>
USEGAME_FRAMEWORK
using namespace std;
#include<vector>
#include"ObjectBase.h"

class AladdinCharacter:public ObjectBase
{
public:
	
	/*
	startLocation: Điểm xuất phát của aladdin
	..*/
	AladdinCharacter(D3DXVECTOR3 startLocation);
	AladdinCharacter();
	~AladdinCharacter();
	void		Render();
	/*state: Trạng thái của aladdin (Walk, Down, Up...)
	direction: Hướng đi của aladdin
	..*/

	void InIt();
	void Update(float deltatime);
	void Draw(LPD3DXSPRITE);
	void Release();

	//Change position sprite of character

	Vector2 getPosition();
	float getPositionX();
	float getPositionY();

	void setPosition(Vector3 vector);
	void setPosition(Vector2 vector);
	void setPosition(float x, float y, float z);
	void setPosition(float x, float y);
	void setPositionX(float x);
	void setPositionY(float y);

	//Scale -> Zoom in, out
	Vector2 getScale();
	void setScale(Vector2 scale);
	void setScale(float scale);
	void setScaleX(float sx);
	void setScaleY(float sy);

	//Rotate -> Gốc quay
	void getRotate();
	void setRotate(float degree);

	//Góc đầu tiên được khởi tạo
	Vector2 getOrigin();
	void setOrigin(Vector2 origin);

	//


	//Độ mờ, lúc aladdin bị dín đạn
	void setOpacity(float opacity);
	float getOpacity();

	D3DXCOLOR getColor();
	void setColor(D3DXCOLOR color);

	Vector2 getAnchorPoint();

	Sprite* getSprite();

	//Region sprite in texture
	RECT getBounding();

	//Vaật nào cũng có vật tốc, nếu khác 0 thì override
	Vector2 getVelocity();


	void				Activities(STATE state, DIRECTION direction);
	AladdinAction**  	GetAction();
	D3DXVECTOR3			GetCurrentLocation();
	void				SetCurrentLocation(D3DXVECTOR3 location);
	void				SetEndLocation(D3DXVECTOR3 location);
	D3DXVECTOR3			GetEndLocation();
	void				SetSpeed(float speed,STATE state = DROP);
protected:
	AladdinAction*		mAction[4];
	D3DXVECTOR3			mCurrentLocation;

};
#endif __ALADDINCHARACTER_H__

