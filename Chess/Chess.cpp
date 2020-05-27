#include "Chess.h"
#include <iostream>
#include <string>


Chess::Chess() : current{ State::PLAYER1 }, gameFinished{ false }
{
}

int Chess::Run()
{	
	if (!gameFinished) reset();
	while (true)
	{
		input();
		update();
		render();
	}
	return 0;
}

void Chess::reset()
{
}

void Chess::input()
{
	switch (current)
	{
	case Chess::PLAYER1:
		p1_input();
		break;
	case Chess::PLAYER2:
		p2_input();
		break;
	}
}

void Chess::p1_input() // allow p1 pieces to be interacted with
{
}

void Chess::p2_input() // allow p2 pieces to be interacted with
{
}

void Chess::update()
{
}

void Chess::render()
{
	drawBoard(NULL); // TODO: replace NULL placeholder
}

void Chess::drawBoard(char pieces[64])
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

bool Chess::validateMove()
{
	return false;
}
