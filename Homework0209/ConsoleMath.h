#pragma once

class ConsoleMath
{
	ConsoleMath();
	~ConsoleMath();

	
	ConsoleMath(const ConsoleMath& _Other) = delete;
	ConsoleMath(ConsoleMath&& _Other) noexcept = delete;
	ConsoleMath& operator=(const ConsoleMath& _Other) = delete;
	ConsoleMath& operator=(ConsoleMath&& _Other) noexcept = delete;

};

class ConsoleVector
{
public:
	int x_, y_;

public:
	ConsoleVector()
		: x_(0), y_(0)
	{

	}
	ConsoleVector(int _x, int _y)
		:x_(_x), y_(_y)
	{

	}

	ConsoleVector GetHalfVector();

	ConsoleVector operator+(const ConsoleVector& _Other);
	ConsoleVector& operator+=(const ConsoleVector& _Other);
};

