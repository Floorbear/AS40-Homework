// Vector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "GameVector.h"

GameVectorSort<int> ReturnVector() 
{
    GameVectorSort<int> NewArr;

    NewArr.resize(20);

    return NewArr;
}

int main()
{
    GameVectorSort<int> NewVectorSort;
    NewVectorSort.reserve(20);

    NewVectorSort.push_back(9);
    NewVectorSort.push_back(10);
    NewVectorSort.push_back(9);
    NewVectorSort.push_back(8);
    NewVectorSort.push_back(3);
    NewVectorSort.push_back(7);
    NewVectorSort.push_back(6);
    NewVectorSort.push_back(5);
    NewVectorSort.push_back(8);
    NewVectorSort.push_back(4);
    NewVectorSort.push_back(3);
    NewVectorSort.push_back(2);
    NewVectorSort.push_back(1);
    NewVectorSort.push_back(9);

    for (size_t i = 0; i < NewVectorSort.size(); i++)
    {
        std::cout << NewVectorSort[i] << std::endl;
    }
}
