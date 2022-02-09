#include "ConsoleMath.h"

ConsoleMath::ConsoleMath()
{
}

ConsoleMath::~ConsoleMath()
{
}

ConsoleVector ConsoleVector::GetHalfVector()
{
    return ConsoleVector(x_/2,y_/2);
}

ConsoleVector ConsoleVector::operator+(const ConsoleVector& _Other)
{
    ConsoleVector Result;
    Result.x_ = this->x_ + _Other.x_;
    Result.y_ = this->y_ + _Other.y_;
    return Result;
}

ConsoleVector& ConsoleVector::operator+=(const ConsoleVector& _Other)
{
    this->x_ += _Other.x_;
    this->y_ += _Other.y_;
    return *this;
}
