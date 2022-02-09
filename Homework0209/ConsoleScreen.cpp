#include <iostream>
#include "TextScreen.h"
#include "Player.h"
#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    TextScreen NewScreen(10, 10, "ㅁ");

    Player NewPlayer(&NewScreen, "★");

    NewScreen.SettingScreen();


    //구현한 예외처리

    //DefaultValue로 2개 이상의 문자가 들어오면 assert
    //TextScreen NewScreen(10, 10, "ㅁㅎ");
    //Player NewPlayer(&NewScreen, "★♥");

    //Player가 TextScreen의 Size_ 범위 밖에 있으면 assert
    //NewPlayer.SetPos(ConsoleVector(-1, -1));
    //NewPlayer.SetPos(ConsoleVector(1000, 1000));
    //키보드로 조작하는도중 Screen 밖으로 이동하면 assert



    while (true)
    {
        NewScreen.SettingScreen();
        NewPlayer.Render();
        NewScreen.PrintScreen();
        NewPlayer.Update();
    }
}

