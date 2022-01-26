#include <iostream>




int main()
{
    const char* charArray[3] = { "My name is Dongwon" ,"Hellow" ,"32323" };


    int pA = 1;
    int pB = 2;
    int pC = 3;

    int* intArray[3];
    intArray[0] = &pA;
    intArray[1] = &pB;
    intArray[2] = &pC;
    
    
    int a =sizeof(charArray[0]);
    int b = sizeof(charArray[1]);

    return 0;
}
