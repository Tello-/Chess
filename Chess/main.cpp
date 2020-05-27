// This is an implementation of Chess done for practice

#include <iostream>
#include <string>




char defaultSetup[64] = { 'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R',
					 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
					 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
					 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
					 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
					 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
					 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
					 'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R' 
					};

void DrawBoard(char[64]);
 
int main()
{
	DrawBoard(defaultSetup);

	return 0;
}

void DrawBoard(char pieces[64])
{

	std::string full_bar{ "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" };
	std::string dotted_bar{ "::       ::       ::       ::       ::       ::       ::       ::       ::" };
	std::string open_bar{ "::   " };
	std::string close_bar{ "   ::" };


	std::cout << full_bar << std::endl;
	for (int iRow = 0, iPiece=0; iRow < 8; ++iRow)
	{
		std::cout << dotted_bar	<< std::endl;
		std::cout << dotted_bar	<< std::endl;
		
		for (int iCol = 0; iCol < 8; ++iCol)
		{
			iCol == 0 ? std::cout << open_bar : std::cout << "   ";
			std::cout  << pieces[iPiece] << close_bar;
			++iPiece;
		}
		std::cout << std::endl;
		std::cout << dotted_bar	<< std::endl;
		std::cout << dotted_bar	<< std::endl;
		std::cout << full_bar	<< std::endl;
	}
}