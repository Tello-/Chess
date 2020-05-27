#pragma once


class Chess
{
public:
	Chess();
	int Run();
	
private:
	void reset();
	void input();
	void p1_input();
	void p2_input();
	void update();
	void render();
	void drawBoard(char pieces[64]); // Putting this here, no need for a Board.h class yet

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