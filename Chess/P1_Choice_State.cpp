#include "P1_Choice_State.hpp"
#include "ChessConstants.hpp"




P1_Choice_State::P1_Choice_State(Piece pieces[8][8]) : pieceArray{ pieces }
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
	std::string inputString;
	std::getline(std::cin, inputString);
	inputString.resize(2);
}

bool P1_Choice_State::validateOwner(int sFile, int sRow) const
{
		bool ownerMatch{ false };

		if (pieceArray[sRow][sFile].ownerID == 1) ownerMatch = true;


		if (ownerMatch) return true;
		else return false;
}

bool P1_Choice_State::validateSyntax(int sFile, int sRow) const
{
	return false;
}

void P1_Choice_State::parseInput(std::string input)
{
}
