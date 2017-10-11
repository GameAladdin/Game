#pragma once
#ifndef  _GameALADDIN_H_
#define _GameALADDIN_H
#include"Engine.h"
#include"Game.h"
#include"AladdinCharacter.h"

using namespace std;
USEGAME_FRAMEWORK

/*NOTE
SpriteHandler->Draw(
_Image,              //Textture
&srect,              //Vùng ảnh sprite trên texture
NULL, 
&position,           //Vị trí sprite trên surface(màn hình)
D3DCOLOR_XRGB(255,255,255)
); */
class AladdinGame:public Game
{
public:
	AladdinGame(HINSTANCE hInstance,LPCSTR Name):Game(hInstance,Name){}
	~AladdinGame();

	void	InIt();   //Khởi tạo đối tượng
	void	Release();

	void	UpdateInput(float deltatime);  //override update input
	void	Update(float deltatime);       //override update your object
	void	Draw();                        //Draw your Object
	void	LoadResourse();

};
#endif _GAMEALADDIN_H_


