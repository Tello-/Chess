#include "Board.h"
#include <string>
#include <iostream>

bool Board::isOccupied(Column col, int row) const
{

	return false;
}

void Board::drawBoard(char pieces[64])
{

	std::string full_bar{ "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" };
	std::string dotted_bar{ "::       ::       ::       ::       ::       ::       ::       ::       ::" };
	std::string open_bar{ "::   " };
	std::string close_bar{ "   ::" };


	std::cout << full_bar << std::endl;
	for (int iRow = 0, iPiece = 0; iRow < 8; ++iRow)
	{
		std::cout << dotted_bar << std::endl;
		std::cout << dotted_bar << std::endl;

		for (int iCol = 0; iCol < 8; ++iCol)
		{
			iCol == 0 ? std::cout << open_bar : std::cout << "   ";
			std::cout << pieces[iPiece] << close_bar;
			++iPiece;
		}
		std::cout << std::endl;
		std::cout << dotted_bar << std::endl;
		std::cout << dotted_bar << std::endl;
		std::cout << full_bar << std::endl;
	}
}
