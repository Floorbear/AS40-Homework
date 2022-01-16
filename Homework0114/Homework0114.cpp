#include <iostream>


int Toint(const char* _left)
{
    int digit=0;
    int numbers[1024] = { 0, };
    int want_number = 0;

    //숫자 분해
    for (int i = 0; _left[i] != 0; i++)
    {
        switch (_left[i])
        {
        case 48:
            numbers[i] = 0;
            digit++;
            break;
        case 49:
            numbers[i] = 1;
            digit++;
            break;
        case 50:
            numbers[i] = 2;
            digit++;
            break;
        case 51:
            numbers[i] = 3;
            digit++;
            break;
        case 52:
            numbers[i] = 4;
            digit++;
            break;
        case 53:
            numbers[i] = 5;
            digit++;
            break;
        case 54:
            numbers[i] = 6;
            digit++;
            break;
        case 55:
            numbers[i] = 7;
            digit++;
            break;
        case 56:
            numbers[i] = 8;
            digit++;
            break;
        case 57:
            numbers[i] = 9;
            digit++;
            break;
        default:
            break;
        }
    }

    //10진수로 숫자 재조립
    for (int i = 0; i < digit; i++)
    {
        int now_digit = digit - i;
        int temp = 1;
        
        //10^(now_digit-1)
        for (int j = 1; j < now_digit; j++)
        {
            temp *= 10;
        }

        want_number += temp * numbers[i];

    }

    return want_number;
}

int main()
{
    int number_1 = Toint("25");
    int number_2 = Toint("46");
    int number_3 = number_1 + number_2;
    std::cout << number_3 << std::endl;

}

