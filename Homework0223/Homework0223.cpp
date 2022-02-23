#include <iostream>

int Value = 0;

void Func()
{
    if (Value == 30)
    {
        std::cout << "End!" << std::endl;
        return;
    }
    std::cout << ++Value << std::endl;
    Func();
}

int main()
{
    Func();
}
