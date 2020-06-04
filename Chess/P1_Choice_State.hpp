#pragma once
#include "IState.hpp"
#include <iostream>
#include <string>
#include <Windows.h>
#include "Chess.h"


class P1_Choice_State :
	public IState
{
public:
	P1_Choice_State(Piece pieces[8][8]);
	virtual ~P1_Choice_State() {}
	virtual void ProcessInput(std::string input);
	virtual void UpdateState();
	virtual void RenderState();

private:
	bool validateOwner(int sFile, int sRow) const;
	bool validateSyntax(int sFile, int sRow) const;
	void parseInput(std::string input);

private:
	Piece		(*pieceArray)[8];
	int			mFile;
	int			mRow;
};

