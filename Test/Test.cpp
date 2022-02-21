
#include <iostream>

class hi
{
public:
	hi()
	{}
	~hi()
	{
		printf("으악");
	}
};



void main() {
	hi* good = new hi();
	delete good;
	printf("dd");

}