#include "Chess.h"
#include <vector>



Chess::Chess() 
	: gameFinished{ false }, boardCoord{ COORD() }, pieceCoord{ COORD{} }, currentPlayer{ 1 }, boardNeedsRedraw{ true }
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

		boardCoord.X = 0;
		boardCoord.Y = 0;
		pieceCoord.X = 7;
		pieceCoord.Y = 46;
		squareColor = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
		player1Foreground = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
		player2Foreground = NULL;
		p1BG = NULL;
		p2BG = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
}

int Chess::Run()
{	
	initConsole();
	initPieces();
	printPieces(pieceCoord);

	bool swapDebug = true;


	while (true)
	{
		if (boardNeedsRedraw)
		{
			drawBoard(boardCoord);
		}
		if (swapDebug)
		{
			swapPiece(H, 8, A, 4);
			swapDebug = false;
		}
		printPieces(pieceCoord);
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

void Chess::initPieces()
{
	char temp[8] = { 'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R' };
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			switch (i)
			{
			case 1:
				pieceLayout[i][j].symbol = 'P';
				pieceLayout[i][j].ownerID = 1;
				break;
			case 6:
				pieceLayout[i][j].symbol = 'P';
				pieceLayout[i][j].ownerID = 2;
				break;
			case 0:
				pieceLayout[i][j].symbol = temp[j];
				pieceLayout[i][j].ownerID = 1;
				break;
			case 7:
				pieceLayout[i][j].symbol = temp[j];
				pieceLayout[i][j].ownerID = 2;
				break;
			default:
				pieceLayout[i][j].symbol = ' ';
				pieceLayout[i][j].ownerID = 0;
				break;
			}
		}
	}
}

void Chess::reset()
{
	
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
			printSquare(tempCoord, 7, 5);
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
			printSquare(tempCoord, 7, 5);
			tempCoord.X = tempCoord.X + 18;
		}
		tempCoord.Y = tempCoord.Y + 12;
	}
}


Piece Chess::movePiece(File sF, int sR, File dF, int dR)
{
	Piece returnPiece;
	returnPiece = pieceLayout[dR][dF];
	pieceLayout[dR][dF] = pieceLayout[sR][sF];
	return returnPiece;
}

Piece Chess::removePiece(File sF, int sR)
{
	Piece returnPiece = pieceLayout[sR][sF];
	pieceLayout[sR][sF].symbol = ' ';
	pieceLayout[sR][sF].ownerID = 0;
	return returnPiece;
}

void Chess::swapPiece(File sF, int sR, File dF, int dR)
{
	pieceLayout[sR][sF] = movePiece(sF, sR, dF, dR);
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

void Chess::printSquare(COORD pos, int width, int height) // TODO adapt this to take any color
{
	short returnTemp;
	if (!GetColor(returnTemp))
	{
		// TODO handle failure
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), squareColor);
	std::vector<std::string> spaces;
	for (int i = 0; i < width; ++i)
	{
		spaces.push_back(" ");
	}

	for (int i = 0; i < 5; ++i)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		
		for (auto j : spaces)
		{
			std::cout << j;
		}
		pos.Y = pos.Y + 1;
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), returnTemp);  // restore print color back to what it was
}

void Chess::printPieces(COORD pos)
{
	short preserveColor;
	GetColor(preserveColor);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);


	
	COORD printCoord = pos;
	for (int i = 0; i < 8; ++i)
	{		
		for (int j = 0; j < 8; ++j)
		{
			if(pieceLayout[i][j].ownerID == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1BG | player1Foreground);
			if (pieceLayout[i][j].ownerID == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  p2BG | player2Foreground);
			if(pieceLayout[i][j].ownerID != 0) std::cout << pieceLayout[i][j].symbol;
			printCoord.X = printCoord.X + 9;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), printCoord);
			
		}
		printCoord.X = pos.X;
		printCoord.Y = printCoord.Y - 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), printCoord);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), preserveColor);
}

bool Chess::GetColor(short& ret)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info)) return false;
		
	ret = info.wAttributes;
	return true;
}
