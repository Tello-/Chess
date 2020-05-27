// This is an implementation of Chess done for practice

#include <iostream>
#include <string>


std::string full_bar{   "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" };
std::string dotted_bar{ "::       ::       ::       ::       ::       ::       ::       ::       ::" };
std::string letter_bar{ "::   X   ::   X   ::   X   ::   X   ::   X   ::   X   ::   X   ::   X   ::" };
std::string open_bar{ "::   " };
std::string close_bar{ "   ::" };
void DrawBoard();
 
int main()
{
	DrawBoard();

	return 0;
}

void DrawBoard()
{
	std::cout << full_bar << std::endl;
	for (int i = 0; i < 8; ++i)
	{
		std::cout << dotted_bar	<< std::endl;
		std::cout << dotted_bar	<< std::endl;
		
		std::cout << dotted_bar	<< std::endl;
		std::cout << dotted_bar	<< std::endl;
		std::cout << full_bar	<< std::endl;
	}
}