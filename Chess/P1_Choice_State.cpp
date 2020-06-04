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
	COORD tempCoord;
	tempCoord.X = ChessConstants::PROMPT_COORD_X;
	tempCoord.Y = ChessConstants::PROMPT_COORD_Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tempCoord);


}
