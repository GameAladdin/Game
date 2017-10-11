#include "ObjectBase.h"
#include"define.h"
USEGAME_FRAMEWORK




ObjectBase::ObjectBase(eIDCharacter id)
{
	this->_id = id;
	this->setState(eStateAllOfCharacter::NORMAL);
}

ObjectBase::~ObjectBase()
{
}

eIDCharacter ObjectBase::getID()
{
	return _id;
}

eStateAllOfCharacter ObjectBase::getState()
{
	return _state;
}

void ObjectBase::setState(eStateAllOfCharacter state)
{
	this->_state=state;
}

IControlable::IControlable()
{
	_input = InputController::getInstance();
}
