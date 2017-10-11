#pragma once
#ifndef __ENGINE_H__
#define __ENGINE_H__

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include"define.h"

using namespace std;

#define NUMBEROFSPRITE 10

GAME_FRAMEWORK
GAME_FRAMEWORK_BEGIN

class Engine
{
public:	
	static int GetCurrentFrame() { return Engine::_currentFrame; }
	static void SetCurrentFrame(int currentFrame) 
	{ Engine::_currentFrame = (_currentFrame >= NUMBEROFSPRITE) ? 1 : ++_currentFrame; }
	static enum								DIRECTION { UP, DOWN, LEFT, RIGHT, NONE };
	static enum								STATE { WALK, CLIMB, SWING, DROP };
	static	LPD3DXSPRITE					GetSpriteHandler() { return Engine::_spriteHandler; }
	static	void							SetSpriteHandler(LPD3DXSPRITE spriteHandler) { Engine::_spriteHandler = spriteHandler; }

	Engine();
	~Engine();
private:	
	static	LPD3DXSPRITE					_spriteHandler;
    static	int								_currentFrame;
	};
GAME_FRAMEWORK_END
#endif _ENGINE_H_


