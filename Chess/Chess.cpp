#include "Chess.h"
#include <iostream>
#include <string>


Chess::Chess() : gameFinished{ false }, boardCoord{ COORD() }, current{ State::PLAYER1 }
{
	promptCoord.X = 0;
	promptCoord.Y = 52;
	reset();
}

int Chess::Run()
{	
	while (true)
	{
		input();
		update();
		render();
	}
	return 0;
}

void Chess::initState()
{
	current = State::PLAYER1;
}

void Chess::initBoard()
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
	initState();
	initBoard();
}

void Chess::input()
{
	
}

void Chess::update()
{
}

void Chess::render()
{
	drawBoard(boardCoord);
	drawPrompt(promptCoord);
}

void Chess::drawBoard(COORD coord)
{
	std::string file_bar	{ "     A         B        C        D        E        F        G        H     " };
	std::string full_bar	{ " ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" };
	std::string dotted_bar	{ " ::       ::       ::       ::       ::       ::       ::       ::       ::" };
	std::string open_bar	{ "::   " };
	std::string close_bar	{ "   ::" };
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	std::cout << file_bar << std::endl;
	std::cout << full_bar << std::endl;
	for (int iRow = 7; iRow >= 0; --iRow)
	{
		std::cout << dotted_bar << std::endl;
		std::cout << dotted_bar << std::endl;

		int iFile = 0;
		for (int iCol = 0; iCol < 8; ++iCol)
		{
			iCol == 0 ? std::cout << iRow+1 << open_bar : std::cout << "   ";
			std::cout << pieceLayout[iRow][iFile].symbol << close_bar;
			++iFile;
		}
		std::cout << iRow + 1;
		std::cout << std::endl;
		std::cout << dotted_bar << std::endl;
		std::cout << dotted_bar << std::endl;
		std::cout << full_bar << std::endl;
		
	}
	std::cout << file_bar << std::endl;
}

void Chess::drawPrompt(COORD coord) const
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "Player " << current << ", which piece would you like to move? (ex a1): ";
}

bool Chess::validateMove(State state, File sFile, int sRow, File dFile, int dRow) const
{
	bool ownerMatch{ false };
	bool rangeMatch{ true }; //TODO add range check logic, make sure to change true to false in final build

	if (pieceLayout[sRow][sFile].ownerID == state) ownerMatch = true;
	

	if (ownerMatch && rangeMatch) return true;
	else return false;
}

void Chess::movePiece()
{
}
