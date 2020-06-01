#pragma once
#include <iostream>
#include <string>
#include <Windows.h>


#define CONSOLE_BUFFER_X 150
#define CONSOLE_BUFFER_Y 52
#define CONSOLE_WINDOW_X (CONSOLE_BUFFER_X - 1)
#define CONSOLE_WINDOW_Y (CONSOLE_BUFFER_Y - 1)
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
	void           initConsole         ();
	void			initBoard           ();
	void 		initPieces          ();
	void			hidecursor          ();
	bool			GetColor            (short& ret);


	void			reset			();

	void			drawBoard			(COORD); // Putting this here, no need for a Board.h class yet

	void			printSquare		(COORD, int, int);
	void			printSquare		(COORD, int, int, DWORD);
	void			printPieces		(COORD pos, int offset_x, int offset_y);
	
	Piece		movePiece			(File sF, int sR, File dF, int dR);
	Piece		removePiece         (File sF, int sR);
	void			swapPiece			(File sF, int sR, File dF, int dR);

	enum           State               {INIT=0, P1_CHOICE, P1_MOVE, P2_CHOICE, P2_MOVE, VALIDATE_CHOICE, VALIDATE_MOVE, GAME_OVER };
	State		current;
	void			advanceState        ();

	
	bool			boardNeedsRedraw;
	int			currentPlayer;
	bool			gameFinished;

	COORD		boardCoord;
	COORD		pieceCoord;
	COORD		promptCoord;
	COORD		inputCoord;
	DWORD		squareColor;
	DWORD		player1Foreground;
	DWORD		player2Foreground;

	DWORD		p1BG;
	DWORD		p2BG;
	DWORD		boardColor;

	
	Piece		pieceLayout[8][File::H];
	
	std::string    boardAscii;
};


