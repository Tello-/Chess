#include "Chess.h"



Chess::Chess() 
	: gameFinished{ false }, boardCoord{ COORD() }, currentState{ State::P1_SOURCE_CHOICE }, currentPlayer{1}
{
	promptCoord.X = 0;
	promptCoord.Y = 52;
	inputCoord.X = 48;
	inputCoord.Y = promptCoord.Y;
	initBoard();
}

int Chess::Run()
{	
	while (true)
	{
		
		while (true)
		{
			drawBoard(boardCoord);
			drawPrompt(promptCoord);
			getUserInputAndValidate();
			activePiece = pieceLayout[inputRow][inputFile];
			advanceState();

			drawPrompt(promptCoord);
			do
			{
				getUserInputAndValidate();
				targetPiece = pieceLayout[inputRow][inputFile];
				// TODO check for range validation
				// Check for target ownership validation...

			} while ();

			//TODO check if target piece is 1: Blank or 2: ActivePlayers own piece or 3: Occupied by other player
			
			
			
			advanceState();
		}


	}
	return 0;
}

void Chess::initBoard()
{
	char temp[8] = { 'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R' };
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			switch (i)
			{
			case 1:
				pieceLayout[i][j].symbol = 'P';
				pieceLayout[i][j].ownerID = 1;
				break;
			case 6:
				pieceLayout[i][j].symbol = 'P';
				pieceLayout[i][j].ownerID = 2;
				break;
			case 0:
				pieceLayout[i][j].symbol = temp[j];
				pieceLayout[i][j].ownerID = 1;
				break;
			case 7:
				pieceLayout[i][j].symbol = temp[j];
				pieceLayout[i][j].ownerID = 2;
				break;
			default:
				pieceLayout[i][j].symbol = ' ';
				pieceLayout[i][j].ownerID = 0;
				break;
			}
		}
	}
}

void Chess::reset()
{
	currentState = P1_SOURCE_CHOICE;
	initBoard();
}


void Chess::drawBoard(COORD coord)
{
	std::string file_bar	{ "     A         B        C        D        E        F        G        H     " };
	std::string full_bar	{ " ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" };
	std::string dotted_bar	{ " ::       ::       ::       ::       ::       ::       ::       ::       ::" };
	std::string open_bar	{ "::   " };
	std::string close_bar	{ "   ::" };
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	std::cout << file_bar << std::endl;
	std::cout << full_bar << std::endl;
	for (int iRow = 7; iRow >= 0; --iRow)
	{
		std::cout << dotted_bar << std::endl;
		std::cout << dotted_bar << std::endl;

		int iFile = 0;
		for (int iCol = 0; iCol < 8; ++iCol)
		{
			iCol == 0 ? std::cout << iRow+1 << open_bar : std::cout << "   ";
			std::cout << pieceLayout[iRow][iFile].symbol << close_bar;
			++iFile;
		}
		std::cout << iRow + 1;
		std::cout << std::endl;
		std::cout << dotted_bar << std::endl;
		std::cout << dotted_bar << std::endl;
		std::cout << full_bar << std::endl;
		
	}
	std::cout << file_bar << std::endl;
}

void Chess::drawPrompt(COORD coord) const
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	switch (currentState)
	{
	case P1_SOURCE_CHOICE:
	case P2_SOURCE_CHOICE:
		std::cout << "Player " << currentPlayer << ": Which piece would you like to move?: ";
		break;
	case P1_DEST_CHOICE:
	case P2_DEST_CHOICE:
		std::cout << "Player " << currentPlayer << ":    Where would you like to move to?: ";
	}
}

void Chess::getUserInputAndValidate()
{
	do
	{
		getUserInput();
	} while (!validateSyntax(userInput) ||
		!validateOwner(File(userInput[1] - ASCII_LETTER_OFFSET),
			userInput[0] - ASCII_NUMBER_OFFSET, currentPlayer));

	inputFile = File(userInput[1] - ASCII_LETTER_OFFSET);
	inputRow = userInput[0] - ASCII_NUMBER_OFFSET;
}

void Chess::getUserInput()
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hndl, inputCoord);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hndl, &bufferInfo);
	while (bufferInfo.dwCursorPosition.X != 0)
	{
		std::cout << " ";
		GetConsoleScreenBufferInfo(hndl, &bufferInfo);
	}
	
	SetConsoleCursorPosition(hndl, inputCoord);
	std::cin >> userInput;
	userInput.resize(2);
}

bool Chess::validateSyntax(std::string untestedInput)
{
	bool syntaxMatch{ false };
	if (untestedInput.size() != 2  ||
		untestedInput[0]	< 'A' ||
		untestedInput[0]	> 'H' ||
		untestedInput[1]-48 <  1  ||
		untestedInput[1]-48	>  8) return false;
	else return true;
}

bool Chess::validateOwner(File file, int row, int potentialOwner)
{
	if (pieceLayout[row-1][file-1].ownerID == potentialOwner) return true;
	else return false;
}

void Chess::movePiece()
{
}

void Chess::advanceState()
{
	switch (currentState)
	{
	case P1_SOURCE_CHOICE:
		currentState = P1_DEST_CHOICE;
		break;
	case P2_SOURCE_CHOICE:
		currentState = P2_DEST_CHOICE;
		break;
	case P1_DEST_CHOICE:
		currentState = P2_SOURCE_CHOICE;
		currentPlayer = 2;
		break;
	case P2_DEST_CHOICE:
		currentState = P1_SOURCE_CHOICE;
		currentPlayer = 1;
		break;
	default:
		break;
	}
}
