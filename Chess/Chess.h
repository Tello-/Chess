#pragma once


struct Piece
{
	Piece() = default;
	Piece(int oID, char sym) : ownerID{ oID }, symbol{ sym } {}
	int			ownerID{ 0 };
	char			symbol{ ' ' };
	// TODO implement move pattern somehow
};


enum State { PLAYER1=1, PLAYER2, GAME_OVER };
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
	void			drawBoard(/*const Piece[8][8]*/); // Putting this here, no need for a Board.h class yet

	bool			validateMove(State state, File sFile, int sRow, File dFile, int dRow) const;

	
	State		current;
	bool			gameFinished;

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