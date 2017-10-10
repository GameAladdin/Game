#include "Sprite.h"
#include"DeviceManager.h"
USEGAME_FRAMEWORK


Sprite::Sprite(const char * filePath, D3DCOLOR transcolor, vector<RECT> listSourceRect, D3DXVECTOR2 scale)
{
	HRESULT result;
	this->_SpriteHandler = _SpriteHandler;
	this->_Position = D3DXVECTOR3(0, 0, 0);
	this->_Rotation = 0;
	this->_RotationCenter = D3DXVECTOR2(_Position.x, _Position.y);
	this->_Translation = D3DXVECTOR2(0, 0);
	this->_Scale = scale;
	this->_ListRect = listSourceRect;
	this->_IsFlipHorizontal = false;
	this->_IsFlipVertical = false;

	D3DXGetImageInfoFromFile(filePath, &_ImageInfo);

	//Update lại hình chữ nhật chưa sprite cần vẽ
	if (listSourceRect.size() > 0)
	{
		this->_SourceRect.left = 0;
		this->_SourceRect.top = 0;
		this->_SourceRect.right = this->_ImageInfo.Width;
		this->_SourceRect.bottom = this->_ImageInfo.Height;
		this->_ListRect.push_back(_SourceRect);
	}
	DeviceManager* deviceManager = DeviceManager::getInstance();
	D3DXCreateTextureFromFileEx(
		deviceManager->getDevice(),
		filePath,
		_ImageInfo.Width,
		_ImageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transcolor,
		&_ImageInfo,
		NULL,
		&_Texture);

	if (!this->_Texture)
	{
		MessageBox(NULL, "Can't Create Texture", "Error", MB_OK);
	}
}

Sprite::~Sprite()
{
	if (_Texture)
		_Texture->Release();
}

Sprite * Sprite::getInstance()

{
	if (_instance == nullptr)
		_instance = new Sprite();
	return _instance;
}


void Sprite::Draw(int spriteIndex, D3DXVECTOR2 scale, D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 transform, float rotation, D3DXVECTOR2 rotationCenter)
{
	D3DXVECTOR3	inPosition = (position != D3DXVECTOR3()) ? position : this->_Position;
	RECT		inSourceRect = (isRect(sourceRect)) ? sourceRect : this->_ListRect[spriteIndex];
	float		inRotation = (rotation != 0.0f) ? rotation : this->_Rotation;
	D3DXVECTOR2 inScale = (scale != D3DXVECTOR2()) ? scale : this->_Scale;
	D3DXVECTOR2	inTranslation = (transform != D3DXVECTOR2()) ? transform : this->_Translation;
	D3DXVECTOR2	inRotationCenter = (rotationCenter != D3DXVECTOR2()) ? rotationCenter : D3DXVECTOR2(inPosition.x, inPosition.y);
	D3DXVECTOR2	scalingCenter = D3DXVECTOR2(inPosition.x, inPosition.y);

	D3DXMatrixTransformation2D(
		&_Matrix,
		&scalingCenter,
		0,
		&inScale,
		&inRotationCenter,
		inRotation,
		&inTranslation);

	D3DXMATRIX oldMatrix;
	this->_SpriteHandler->GetTransform(&oldMatrix);
	this->_SpriteHandler->SetTransform(&_Matrix);

	D3DXVECTOR3 center = D3DXVECTOR3((inSourceRect.right - inSourceRect.left) / 2, (inSourceRect.bottom - inSourceRect.top) / 2, 0);//Tâm của sprite cần vẽ

	this->_SpriteHandler->Draw(
		this->_Texture,
		&inSourceRect,
		&center,
		&inPosition,
		D3DCOLOR_ARGB(255, 255, 255, 255));
	this->_SpriteHandler->SetTransform(&oldMatrix);
}

LPDIRECT3DTEXTURE9 Sprite::GetTexture()
{
	return this->_Texture;
}

D3DXIMAGE_INFO Sprite::GetImageInfo()
{
	return this->_ImageInfo;
}

D3DXVECTOR3 Sprite::GetPosition()
{
	return this->_Position;
}

void Sprite::SetPosition(D3DXVECTOR3 position)
{
	this->_Position = position;
}

void Sprite::SetPosition(float x, float y)
{
	this->_Position = D3DXVECTOR3(x, y, 0);
}

void Sprite::SetPosition(D3DXVECTOR2 position)
{
	this->SetPosition(position.x, position.y);
}

D3DXVECTOR2 Sprite::GetScale()
{
	return this->_Scale;
}

void Sprite::SetScale(D3DXVECTOR2 scale)
{
	this->_Scale = scale;
}

void Sprite::SetScale(float x, float y)
{
	this->_Scale = D3DXVECTOR2(x, y);
}

D3DXVECTOR2 Sprite::GetTranslation()
{
	return this->_Translation;
}

void Sprite::SetTranslation(D3DXVECTOR2 translation)
{
	this->_Translation = translation;
}

D3DXVECTOR2 Sprite::GetRotationCenter()
{
	return this->_RotationCenter;
}

void Sprite::SetRotationCenter(D3DXVECTOR2 rotationCenter)
{
	this->_RotationCenter = rotationCenter;
}

float Sprite::GetRotation()
{
	return this->_Rotation;
}

void Sprite::SetRotation(float rotation)
{
	this->_Rotation = rotation;
}

void Sprite::SetResourceRect(RECT rect)
{
	this->_SourceRect = rect;
}

void Sprite::FlipHorizontal(bool flag)
{
	if (_IsFlipHorizontal != flag)
	{
		this->_IsFlipHorizontal = flag;
		this->_Scale = D3DXVECTOR2(this->_Scale.x, -this->_Scale.y);
	}
}

bool Sprite::IsFlipHorizontal()
{
	return this->_IsFlipHorizontal;
}

void Sprite::FlipVertical(bool flag)
{
	if (this->_IsFlipVertical != flag)
	{
		this->_IsFlipVertical = flag;
		this->_Scale = D3DXVECTOR2(-this->_Scale.x, this->_Scale.y);
	}
}

bool Sprite::IsFlipVertical()
{
	return this->_IsFlipVertical;
}

bool Sprite::isRect(RECT rect)
{
	return ((rect.top != rect.bottom) && (rect.left != rect.right));
}
