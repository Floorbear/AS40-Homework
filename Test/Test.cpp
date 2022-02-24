#include <iostream>

int Value = 0;

int fun()
{
	Value++;
	if (Value < 30)
	{
		fun();
	}
	Value++;
	return Value;
}

int main() {

	int a[30] = fun();

	std::cout << a << std::endl;
}

