#ifndef   __OBJECTBASE_H__
#define   __OBJECTBASE_H__

#include"Sprite.h"
#include"define.h"
#include"InputController.h"
GAME_FRAMEWORK
GAME_FRAMEWORK_BEGIN

//Class quản lí UpdateInput
class IControlable
{
public:
	IControlable();
	virtual void UpdateInput(float deltatime) = 0;
protected:
	InputController* _input;
};

class ObjectBase
{
public:
	ObjectBase(eIDCharacter id);
	virtual ~ObjectBase();

	virtual void InIt() = 0;
	virtual void Update(float deltatime) = 0;
	virtual void Draw(LPD3DXSPRITE) = 0;
	virtual void Release() = 0;

	eIDCharacter getID();
	eStateAllOfCharacter getState();
	virtual void setState(eStateAllOfCharacter state);


	//Change position sprite of character

	virtual Vector2 getPosition();
	virtual float getPositionX();
	virtual float getPositionY();

	virtual void setPosition(Vector3 vector); 
	virtual void setPosition(Vector2 vector); 
	virtual void setPosition(float x, float y, float z);
	virtual void setPosition(float x, float y);
	virtual void setPositionX(float x);
	virtual void setPositionY(float y);

	//Scale -> Zoom in, out
	virtual Vector2 getScale();
	virtual void setScale(Vector2 scale);
	virtual void setScale(float scale);
	virtual void setScaleX(float sx);
	virtual void setScaleY(float sy);

	//Rotate -> Gốc quay
	virtual void getRotate();
	virtual void setRotate(float degree);
	
	//Góc đầu tiên được khởi tạo
	virtual Vector2 getOrigin();
	virtual void setOrigin(Vector2 origin);

	//


	//Độ mờ, lúc aladdin bị dín đạn
	virtual void setOpacity(float opacity);
	virtual float getOpacity();

	virtual D3DXCOLOR getColor();
	virtual void setColor(D3DXCOLOR color);

	virtual Vector2 getAnchorPoint();

	Sprite* getSprite();

	//Region sprite in texture
	virtual RECT getBounding();

	//Vaật nào cũng có vật tốc, nếu khác 0 thì override
	virtual Vector2 getVelocity();



private:
	Sprite* _sprite;
	eIDCharacter _id;
	eStateAllOfCharacter _state;
};
GAME_FRAMEWORK_END
#endif  __OBJECTBASE_H__
