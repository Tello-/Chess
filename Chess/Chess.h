#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

#define ASCII_LETTER_OFFSET 48
#define ASCII_NUMBER_OFFSET 64

struct Piece
{
	Piece() = default;
	Piece(int oID, char sym, int* ofs) : ownerID{ oID }, symbol{ sym } { offset = ofs; }
	int			ownerID{ 0 };
	char			symbol{ ' ' };
	int*			offset; // a test offset...
};


enum File { A = 1, B, C, D, E, F, G, H };

class Chess
{
public:
				Chess		     ();
	int			Run			     ();
	
private:
	void			initBoard			();
	void			reset			();
	void			drawBoard			(COORD); // Putting this here, no need for a Board.h class yet
	void			drawPrompt		(COORD) const;
	
	
	void			movePiece		     ();

	void			advanceState        ();

	
	
	int			currentPlayer;
	bool			gameFinished;
	COORD		boardCoord;
	COORD		promptCoord;
	COORD		inputCoord;
	
	Piece		pieceLayout[8][File::H];
	

};