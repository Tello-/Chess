#include "Chess.h"
#include <vector>



Chess::Chess() 
	: gameFinished{ false }, boardCoord{ COORD() }, currentPlayer{ 1 }, boardNeedsRedraw{ true }
{
		boardAscii = "       A        B        C        D        E        F        G        H\n"
"  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"8 ::       ::       ::       ::       ::       ::       ::       ::       :: 8\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"7 ::       ::       ::       ::       ::       ::       ::       ::       :: 7\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"6 ::       ::       ::       ::       ::       ::       ::       ::       :: 6\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"5 ::       ::       ::       ::       ::       ::       ::       ::       :: 5\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"4 ::       ::       ::       ::       ::       ::       ::       ::       :: 4\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"3 ::       ::       ::       ::       ::       ::       ::       ::       :: 3\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"2 ::       ::       ::       ::       ::       ::       ::       ::       :: 2\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"1 ::       ::       ::       ::       ::       ::       ::       ::       :: 1\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::       ::       ::       ::       ::       ::       ::       ::       ::\n"
"  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
"       A        B        C        D        E        F        G        H\n";
}

int Chess::Run()
{	
	initConsole();
	initBoard();
	while (true)
	{
		drawBoard(COORD{});
	}
	return 0;
}

void Chess::initConsole()
{	
	COORD initCoord;
	initCoord.X = CONSOLE_BUFFER_X;
	initCoord.Y = CONSOLE_BUFFER_Y;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), initCoord);
	SMALL_RECT initRect;
	initRect.Top = 0;
	initRect.Left = 0;
	initRect.Right = CONSOLE_WINDOW_X;
	initRect.Bottom = CONSOLE_WINDOW_Y;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &initRect);	
	hidecursor();
}

void Chess::initBoard()
{
	
}

void Chess::reset()
{
	
	initBoard();
}

void Chess::drawBoard(COORD coord)
{
	if (boardNeedsRedraw)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << boardAscii;
		boardNeedsRedraw = false;
	}

	COORD tempCoord;
	
	tempCoord.Y = 2;
	for (int i = 0; i < 4; ++i)
	{
		tempCoord.X = 4;
		for (int i = 0; i < 4; ++i)
		{
			printWhiteSquare(tempCoord, 7, 5);
			tempCoord.X = tempCoord.X + 18;
		}		
		tempCoord.Y = tempCoord.Y + 12;
	}
	tempCoord.Y = 8;
	for (int i = 0; i < 4; ++i)
	{
		tempCoord.X = 13;
		for (int i = 0; i < 4; ++i)
		{
			printWhiteSquare(tempCoord, 7, 5);
			tempCoord.X = tempCoord.X + 18;
		}
		tempCoord.Y = tempCoord.Y + 12;
	}
}

void Chess::drawPrompt(COORD coord) const
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
}
void Chess::movePiece()
{
}

void Chess::advanceState()
{
	
}

void Chess::hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void Chess::printWhiteSquare(COORD pos, int width, int height) // TODO adapt this to take any color
{
	short returnTemp;
	if (!GetColor(returnTemp))
	{
		// TODO handle failure
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	std::vector<std::string> spaces;
	for (int i = 0; i < width; ++i)
	{
		spaces.push_back(" ");
	}

	for (int i = 0; i < 5; ++i)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		
		for (auto i : spaces)
		{
			std::cout << i;
		}
		pos.Y = pos.Y + 1;
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), returnTemp);  // restore print color back to what it was
}

bool Chess::GetColor(short& ret)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info)) return false;
		
	ret = info.wAttributes;
	return true;
}
