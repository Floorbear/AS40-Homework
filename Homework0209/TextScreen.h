#pragma once
#include "ConsoleMath.h"
#include <assert.h>

class TextScreen
{
public:

	TextScreen(int _Width, int _Height, const char* _DefaultValue);
	~TextScreen();


	TextScreen(const TextScreen& _Other) = delete;
	TextScreen(TextScreen&& _Other) noexcept = delete;
	TextScreen& operator=(const TextScreen& _Other) = delete;
	TextScreen& operator=(TextScreen&& _Other) noexcept = delete;


	ConsoleVector GetSize()
	{
		return Size_;
	}

	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);


	void SettingScreen();


	void PrintScreen();


	void SetPixel(ConsoleVector _Pos, const char* _DefaultValue);
	void SetPixel(int _X, int _Y, const char* _DefaultValue);



private:
	ConsoleVector Size_;
	char** PixelData_;
	char DefaultPixel_[3];

};
