#include "ConsoleGlobalInst.h"

TextScreen MainScreen(10, 10, "��");
Monster* AllMonsters = new Monster[10];
Player MainPlayer(&MainScreen, "��");
bool IsGameEnd = false;

//ConsoleGlobalInst::ConsoleGlobalInst() 
//{
//}
//
//ConsoleGlobalInst::~ConsoleGlobalInst() 
//{
//}
//
