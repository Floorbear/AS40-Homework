#include "ReplicaInt.h"


ReplicaInt::ReplicaInt(int _x)
	: value(_x)
{

}

ReplicaInt ReplicaInt::operator+(const ReplicaInt& _Other)
{
	return ReplicaInt(value+_Other.value);
}

ReplicaInt ReplicaInt::operator-(const ReplicaInt& _Other)
{
	return ReplicaInt(value - _Other.value);
}

ReplicaInt& ReplicaInt::operator=(const ReplicaInt& _Other)
{
	value = _Other.value;
	return *this;
}

ReplicaInt& ReplicaInt::operator++()
{
	this->value += 1;
	return *this;
}

ReplicaInt ReplicaInt::operator++(int)
{
	ReplicaInt temp = *this;
	this->value += 1;
	return temp;
}
