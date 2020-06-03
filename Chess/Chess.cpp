#include "Chess.h"
#include <vector>



Chess::Chess() 
	: Context( new InitState ), gameFinished {false}, currentPlayer{ 1 }, boardNeedsRedraw{ true }
{}

int Chess::Run()  // TODO: Implement states in a way that can flag for redraw, this should get rid ot the flickering.. or look at a double buffer...
{	
	initState();
	//Sleep(1000);
	initConsole();
	initBoard();
	initPieces();	

	while (true)
	{

		Input();
		Update();

		if (boardNeedsRedraw)
		{
			drawBoard(boardCoord);
		}
		Render(); // delegates rendering to current state
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
	boardCoord.X = 0;
	boardCoord.Y = 0;
	boardColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	squareColor = BACKGROUND_RED;
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

void Chess::initPieces()
{
	pieceCoord.X = 7;
	pieceCoord.Y = 46;
	player1Foreground = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
	player2Foreground = NULL;
	p1BG = NULL;
	p2BG = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;

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

void Chess::initState()
{
}

void Chess::reset()
{
	
}

void Chess::drawBoard(COORD coord)
{
	if (boardNeedsRedraw)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), boardColor);
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

bool Chess::popState()
{
	if (!stateStack.empty())
	{
		stateStack.pop();
		return true;
	}
	return false;
}

void Chess::pushState(State newState)
{
	stateStack.push(newState);
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

//TODO: change all color DWORDs to WORDs
void Chess::printSquare(COORD pos, int width, int height, DWORD color)
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufInfo);
	auto preservedCursorPos = bufInfo.dwCursorPosition;

	short preservedColor;
	if (!GetColor(preservedColor))
	{
		// TODO handle failure
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::vector<std::string> spaces;
	for (int i = 0; i < width; ++i)
	{
		spaces.push_back(" ");
	}

	for (int i = 0; i < height; ++i)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		for (auto j : spaces)
		{
			std::cout << j;
		}
		pos.Y = pos.Y + 1;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), preservedColor);  // restore print color back to what it was
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), preservedCursorPos);
}

void Chess::printPieces(COORD pos, int offset_x, int offset_y)
{
	short preserveColor;
	GetColor(preserveColor);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	COORD printCoord = pos;
	COORD markerCoord;
	markerCoord.X = printCoord.X - 1;
	markerCoord.Y = printCoord.Y;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (pieceLayout[i][j].ownerID == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p1BG | player1Foreground);
			if (pieceLayout[i][j].ownerID == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p2BG | player2Foreground);

			if (pieceLayout[i][j].ownerID != 0) std::cout << pieceLayout[i][j].symbol;
			printCoord.X = printCoord.X + offset_x;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), printCoord);

		}
		printCoord.X = pos.X;
		printCoord.Y = printCoord.Y + offset_y;
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
