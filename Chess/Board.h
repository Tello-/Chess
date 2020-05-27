#pragma once



class Board
{
public:
	enum Column {A=1, B, C, D, E, F, G, H};

	bool isOccupied(Column, int) const;
	void drawBoard(char pieces[64])
private:


};