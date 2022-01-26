#pragma once

class ReplicaInt
{
private:
	int value;

public: 
	ReplicaInt(int _x);

public:
	ReplicaInt operator+(const ReplicaInt& _Other);


	ReplicaInt operator-(const ReplicaInt& _Other);


	ReplicaInt& operator=(const ReplicaInt& _Other);

	ReplicaInt& operator++();

	ReplicaInt operator++(int);

};

