#ifndef __ALADDIN_H__
#define __ALADDIN_H__

#include "../../FrameWork/define.h"
#include "../../FrameWork/Animation.h"
#include "../../FrameWork/InputController.h"
#include"../../FrameWork/IComponent.h"
#include "BaseObject.h"

#define ALADDIN_MOVE_SPEED 100
#define ALADDIN_JUMP_VEL 100
#define ALADDIN_ACC_MOVE 300
#define TEST_LAND 200
#define GRAVITY 50

[event_receiver(native)]
class Aladdin : public BaseObject, public IControlable
{
public:
	Aladdin();
	~Aladdin();

	void InIt();
	void UpdateInput(float dt);
	void Update(float deltatime);
	void Draw(LPD3DXSPRITE spriteHandle, Viewport* viewport);
	void Release();

	void setPosition(float x, float y);

	void onKeyPressed(KeyEventArg* key_event);
	void onKeyReleased(KeyEventArg* key_event);

private:
	map<int, Animation*> _animations;
	map<string, IComponent*> _componentList;

	void standing();
	void moveLeft();
	void moveRight();
	void jump();
	void layDown();

	//void setState(int state);
	void addStatus(eStatus status);
	void removeStatus(eStatus status);
	bool isInStatus(eStatus status);

	Vector2 getVelocity();
	void updateStatus(float dt);

	eStatus _currentAnimateIndex;
	void updateCurrentAnimateIndex();
};


#endif // !__ALADDIN_H__
