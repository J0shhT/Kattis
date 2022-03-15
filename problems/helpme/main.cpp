#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>

#define isUpper(c) ((c) >= 'A' && (c) <= 'Z')
#define toUpper(c) (!isUpper(c) ? (c)-('a'-'A') : (c))

enum ChessPiece { KING,	QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

struct Tile
{
	ChessPiece piece;
	size_t row;
	size_t col;
};

static ChessPiece determinePiece(char c)
{
	c = toUpper(c);
	switch (c)
	{
		case 'K': return KING;
		case 'Q': return QUEEN;
		case 'R': return ROOK;
		case 'B': return BISHOP;
		case 'N': return KNIGHT;
		case 'P': return PAWN;
		default : assert(false);
	}
}

static char pieceLetter(ChessPiece piece)
{
	switch (piece)
	{
		case KING: return 'K';
		case QUEEN: return 'Q';
		case ROOK: return 'R';
		case BISHOP: return 'B';
		case KNIGHT: return 'N';
		case PAWN: return 'P';
		default : assert(false);
	}
}

int main()
{
	std::string skip;
	std::getline(std::cin, skip);

	static const int SIZE = 8;
	std::vector<Tile> white;
	std::vector<Tile> black;

	for (size_t row = 0; row < SIZE; ++row)
	{
		std::string line;
		std::getline(std::cin, line);
		std::getline(std::cin, skip);
		bool printed = false;
		for (size_t col = 0; col < SIZE; ++col)
		{
			size_t i = 2 + (4*col);
			char c = line[i];
			if (c == '.' || c == ':')
				continue;
			
			Tile tile = {.piece = determinePiece(c), .row = row, .col=col};
			if (isUpper(c))
				white.push_back(tile);
			else
				black.push_back(tile);
		}
	}

	std::sort(white.begin(), white.end(), [](const Tile &a, const Tile &b){
		if (a.piece != b.piece)
			return a.piece < b.piece;
		if (a.row == b.row)
			return a.col < b.col;
		return a.row > b.row;
	});
	std::sort(black.begin(), black.end(), [](const Tile &a, const Tile &b){
		if (a.piece != b.piece)
			return a.piece < b.piece;
		if (a.row == b.row)
			return a.col < b.col;
		return a.row < b.row;
	});

	std::cout << "White: ";
	bool hasPrinted = false;
	for (Tile tile : white)
	{
		if (hasPrinted) std::cout << ',';
		hasPrinted = true;
		char c = pieceLetter(tile.piece);
		if (c != 'P')
			std::cout << c;
		std::cout << (char)('a'+tile.col) << SIZE - tile.row;
	}
	std::cout << std::endl << "Black: ";
	hasPrinted = false;
	for (Tile tile : black)
	{
		if (hasPrinted) std::cout << ',';
		hasPrinted = true;
		char c = pieceLetter(tile.piece);
		if (c != 'P')
			std::cout << c;
		std::cout << (char)('a'+tile.col) << SIZE - tile.row;
	}
	std::cout << std::endl;
	return 0;
}