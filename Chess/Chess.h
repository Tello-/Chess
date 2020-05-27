#pragma once


struct Piece
{
	int ownerID{ 0 };
	char logo{ ' ' };
	// TODO implement move pattern somehow
};

class Chess
{
public:
	Chess();
	int Run();
	
private:
	void reset();
	void input();
	void p1_input(); // called during State::PLAYER1
	void p2_input(); // called during State::PLAYER2
	void update();
	void render();
	void drawBoard(char pieces[64]); // Putting this here, no need for a Board.h class yet

	bool validateMove(/*TODO: Fill in some paramters to validate*/);

	enum State {PLAYER1, PLAYER2};
	State current;

	bool gameFinished;
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