#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

/*State Related Includes*/
#include "Context.hpp"
#include "InitState.hpp"
#include "P1_Choice_State.hpp"
#include "P1_Move_State.hpp"
#include "P2_Choice_State.hpp"
#include "P2_Move_State.hpp"

/*;;;;;;;;;;;;;;;;;;;;;;;*/




const std::string BOARD_ASCII = "       A        B        C        D        E        F        G        H\n"
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


struct Piece
{
	Piece() = default;
	Piece(int oID, char sym, int* ofs) : ownerID{ oID }, symbol{ sym } {}
	int			ownerID{ 0 };
	char			symbol{ ' ' };
};



class Chess : public Context // inherits from context in order to use state system
{
public:
	Chess();
	int			Run			     ();
	

private: 
	enum           File                { A = 1, B, C, D, E, F, G, H }; // columns of chess board
private:
	void           initConsole         (); // code to size and posistion the console for the purposes of the game
	void			initBoard           (); 
	void 		initPieces          ();
	
	void			hidecursor          ();
	bool			GetColor            (short& ret);

	void			drawBoard			(COORD); // Putting this here, no need for a Board.h class yet

	void			printSquare		(COORD, int, int); // not sure why I overloaded this without the color, probably can remove with some editing
	void			printSquare		(COORD, int, int, DWORD);
	void			printPieces		(COORD pos, int offset_x, int offset_y); // prints piece symbols on their square
	
	Piece		movePiece			(File sF, int sR, File dF, int dR);
	Piece		removePiece         (File sF, int sR);
	void			swapPiece			(File sF, int sR, File dF, int dR);

		
	int			currentPlayer;
	bool			gameFinished;

	COORD          boardCoord;

	DWORD		boardColor;
	DWORD		squareColor;
	DWORD		player1Foreground;
	DWORD		player2Foreground;
	DWORD		p1BG;
	DWORD		p2BG;
	
	Piece		pieceLayout[8][File::H];
};


