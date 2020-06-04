#include "P1_Choice_State.hpp"
#include "ChessConstants.hpp"


P1_Choice_State::P1_Choice_State()
{
}

void P1_Choice_State::ProcessInput(std::string input)
{
}

void P1_Choice_State::UpdateState()
{
}

void P1_Choice_State::RenderState()
{
	using namespace ChessConstants;
	COORD tempCoord;
	tempCoord.X = PROMPT_COORD_X;
	tempCoord.Y = PROMPT_COORD_Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tempCoord);

	std::cout << P1_PROMPT_CHOOSE;
}
