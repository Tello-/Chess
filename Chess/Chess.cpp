#include "Chess.h"



Chess::Chess() 
	: gameFinished{ false }, boardCoord{ COORD() }, currentPlayer{1}
{
	inputCoord.X = 48;
	inputCoord.Y = promptCoord.Y;	
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
	std::string file_bar	{ "     A         B        C        D        E        F        G        H     " };
	std::string full_bar	{ "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" };
	std::string dotted_bar	{ "::       ::       ::       ::       ::       ::       ::       ::       ::" };
	std::string color_dash   { "       " };
	
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << " " << file_bar << std::endl;
	std::cout << " " << full_bar << std::endl;
	for (int iRow = 7; iRow >= 0; --iRow)
	{
		std::cout << " " << dotted_bar << std::endl;
		std::cout << " " << dotted_bar << std::endl;		
		std::cout << iRow + 1 << dotted_bar << iRow + 1 << std::endl;
		std::cout << " " << dotted_bar << std::endl;
		std::cout << " " << dotted_bar << std::endl;
		std::cout << " " << full_bar << std::endl;		
	}
	std::cout << " " << file_bar << std::endl;
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
