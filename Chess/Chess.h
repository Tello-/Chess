#pragma once


class Chess
{
public:
	Chess();
	int Run();
	
private:
	void reset();
	void input();
	void update();
	void render();
	void drawBoard(char pieces[64]); // Putting this here, no need for a Board.h class yet

	enum State {PLAYER1, PLAYER2};
	State current;

	bool gameFinished;
};