#pragma once
#ifndef __SPRITE_H__
#define	__SPRITE_H__
#include<vector>
using namespace std;
#include"define.h"
GAME_FRAMEWORK
GAME_FRAMEWORK_BEGIN

class Sprite
{
public:
	/*
	filePath:	Đường dẫn file
	sourceRect: Hình chữ nhật chứa sprite cần vẽ
	transcolor: Màu chỉ định là màu trong suốt
	..*/
	Sprite(
		const char* filePath,
		D3DCOLOR transcolor = 0,
		vector<RECT> listSourceRect = vector<RECT>(),
		D3DXVECTOR2 scale = D3DXVECTOR2(1, 1));
	~Sprite();
	Sprite*             getInstance();


	/*
	position:		Vị trí của sprite cần vẽ
	sourceRect:		Hình chữ nhật chứa sprite cần vẽ
	scale:			Vector tuỳ chỉnh zoom sprite
	transform:		Vector tịnh tiến sprite
	rotation:		Góc quay sprite
	rotationCenter: Điểm quay sprite
	..*/
	void				Draw(
		int				spriteIndex = 0,
		D3DXVECTOR2		scale = D3DXVECTOR2(),
		D3DXVECTOR3		position = D3DXVECTOR3(),
		RECT			sourceRect = RECT(),
		D3DXVECTOR2		transform = D3DXVECTOR2(),
		float			rotation = 0,
		D3DXVECTOR2		rotationCenter = D3DXVECTOR2());

	LPDIRECT3DTEXTURE9	GetTexture();

	D3DXIMAGE_INFO		GetImageInfo();

	D3DXVECTOR3			GetPosition();
	void				SetPosition(D3DXVECTOR3 position);
	void				SetPosition(float x, float y);
	void				SetPosition(D3DXVECTOR2 position);

	D3DXVECTOR2			GetScale();
	void				SetScale(D3DXVECTOR2 scale);
	void				SetScale(float x, float y);

	D3DXVECTOR2			GetTranslation();
	void				SetTranslation(D3DXVECTOR2 translation);

	D3DXVECTOR2			GetRotationCenter();
	void				SetRotationCenter(D3DXVECTOR2 rotationCenter);

	float				GetRotation();
	void				SetRotation(float rotation);

	void				SetResourceRect(RECT rect);

	void				FlipHorizontal(bool flag);
	bool				IsFlipHorizontal();

	void				FlipVertical(bool flag);
	bool				IsFlipVertical();


private:
	bool							isRect(RECT rect);
	static Sprite*					_instance;
	//-----------------------------------------------------------------------
	D3DXVECTOR3						_Position;			//Sprite location
	LPDIRECT3DTEXTURE9				_Texture;
	D3DXIMAGE_INFO					_ImageInfo;
	static LPD3DXSPRITE				_SpriteHandler;
	RECT							_SourceRect;		//Rectangle chứa sprite cần vẽ
	bool							_IsFlipVertical;
	bool							_IsFlipHorizontal;
	float							_Rotation;			//Góc quay tính theo radian
	D3DXVECTOR2						_RotationCenter;	//Điểm quay
	D3DXVECTOR2						_Scale;				//Vector tuỳ chỉnh zoom hình
	D3DXVECTOR2						_Translation;		//Vector tịnh tiến
	D3DXMATRIX						_Matrix;			// Ma trận hỗ trợ phép dời hình
	vector<RECT>					_ListRect;			//Danh sách các hình chữ nhất chứa các sprite cần vẽ lên
};
GAME_FRAMEWORK_END
#endif __SPRITE_H__