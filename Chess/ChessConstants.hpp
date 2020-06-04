#pragma once


namespace ChessConstants
{
	//:::::::::::::::::::DEFINES::::::::::::::::::::::::::::::::::::::::
#define CONSOLE_BUFFER_X 150
#define CONSOLE_BUFFER_Y 52
#define CONSOLE_WINDOW_X (CONSOLE_BUFFER_X - 1)
#define CONSOLE_WINDOW_Y (CONSOLE_BUFFER_Y - 1)
#define ASCII_LETTER_OFFSET 48
#define ASCII_NUMBER_OFFSET 64
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	const int		BOARD_COORD_X{ 0 };
	const int		BOARD_COORD_Y{ 0 };
	const int		PIECE_COORD_X{ 7 };
	const int		PIECE_COORD_Y{ 46 };
	const int		PROMPT_COORD_X{80};
	const int		PROMPT_COORD_Y{5};
	const int		INPUT_COORD_X{ 60 };
	const int		INPUT_COORD_Y{ 5 };

	const std::string P1_PROMPT_CHOOSE{ "Player 1, choose a piece: " };
	const std::string P2_PROMPT_CHOOSE{ "Player 2, choose a piece: " };

	const std::string PROMPT_MOVE{ "Where to place?:  " };

};