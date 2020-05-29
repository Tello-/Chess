#pragma once
#include <iostream>
#include <string>
#include <Windows.h>


struct Piece
{
	Piece() = default;
	Piece(int oID, char sym, int* ofs) : ownerID{ oID }, symbol{ sym } { offset = ofs; }
	int			ownerID{ 0 };
	char			symbol{ ' ' };
	int*			offset; // a test offset...
};


enum State { P1_SOURCE_CHOICE = 1, P2_SOURCE_CHOICE = 2, P1_DEST_CHOICE, P2_DEST_CHOICE};
enum File { A = 1, B, C, D, E, F, G, H };

class Chess
{
public:
				Chess();
	int			Run();
	
private:
	void			initState();
	void			initBoard();
	void			reset();
	void			input();
	void			update(); // update internal state based on input
	void			render();
	void			drawBoard(COORD); // Putting this here, no need for a Board.h class yet
	void			drawPrompt(COORD) const;
	void			getUserInput();

	bool			validateMove(File sFile, int sRow, 
						   File dFile, int dRow) const;
	void			movePiece();

	
	State		current;
	bool			gameFinished;
	COORD		boardCoord;
	COORD		promptCoord;
	std::string	source;
	std::string	destination;
	Piece		pieceLayout[8][File::H];
};





//char defaultSetup[64] = { 'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R',
//					 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
//					 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//					 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//					 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//					 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
//					 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
//					 'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R' 
//					};