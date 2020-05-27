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

