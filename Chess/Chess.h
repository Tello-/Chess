#pragma once


class Chess
{
public:
	int Run();
private:
	void render();
	void drawBoard(char pieces[64]); // Putting this here, no need for a Board.h class yet
};