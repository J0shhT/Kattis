#include <iostream>

#define tileIndex(x, y) (((y)*3)+(x))
#define getTile(arr, x, y) (arr)[tileIndex(x, y)]

enum class GameState { WinX, WinO, Draw, InProgress };

class BoardState
{
public:

	BoardState() = delete;

	explicit BoardState(int32_t packedState)
		: m_PackedState(packedState),
		m_Board(new char[9]), //m_PlayedStates(new bool[9]), m_TileStates(new bool[9]),
		m_IsXTurn(false), m_RemainingTiles(9)
	{
		int32_t playedStates = packedState & 0b111111111;
		int32_t tileStates = (packedState >> 9) & 0b111111111;
		m_IsXTurn = (packedState >> 18) & 1;
		for (int y = 0; y < 3; ++y)
		{
			for (int x = 0; x < 3; ++x)
			{
				bool hasPlayedOnTile = (playedStates >> tileIndex(x, y)) & 1;
				bool hasXPlayedOnTile = (tileStates >> tileIndex(x, y)) & 1;
				//getTile(m_PlayedStates, x, y) = hasPlayedOnTile;
				//getTile(m_TileStates, x, y) = hasXPlayedOnTile;
				getTile(m_Board, x, y) = (hasPlayedOnTile ? (hasXPlayedOnTile ? 'X' : 'O') : 0);
				if (hasPlayedOnTile) --m_RemainingTiles;
			}
		}
	}

	~BoardState()
	{
		//delete[] m_TileStates;
		//delete[] m_PlayedStates;
		delete[] m_Board;
	}

	GameState getState() const
	{
		//check horizontally
		for (int y = 0; y < 3; ++y)
		{
			char winner = checkForWinnerTiles(getTile(m_Board, 0, y), getTile(m_Board, 1, y), getTile(m_Board, 2, y));
			if (winner == 'X')
				return GameState::WinX;
			else if (winner == 'O')
				return GameState::WinO;
		}
		//check vertically
		for (int x = 0; x < 3; ++x)
		{
			char winner = checkForWinnerTiles(getTile(m_Board, x, 0), getTile(m_Board, x, 1), getTile(m_Board, x, 2));
			if (winner == 'X')
				return GameState::WinX;
			else if (winner == 'O')
				return GameState::WinO;
		}
		//check diagonally
		{
			char winner = checkForWinnerTiles(getTile(m_Board, 0, 0), getTile(m_Board, 1, 1), getTile(m_Board, 2, 2));
			if (winner == 'X')
				return GameState::WinX;
			else if (winner == 'O')
				return GameState::WinO;
		}
		{
			char winner = checkForWinnerTiles(getTile(m_Board, 2, 0), getTile(m_Board, 1, 1), getTile(m_Board, 0, 2));
			if (winner == 'X')
				return GameState::WinX;
			else if (winner == 'O')
				return GameState::WinO;
		}
		if (m_RemainingTiles > 0)
			return GameState::InProgress;
		else
			return GameState::Draw;
	}
	
	// void debugPrintBoard() const
	// {
	// 	for (int y = 0; y < 3; ++y)
	// 	{
	// 		for (int x = 0; x < 3; ++x)
	// 		{
	// 			char tile = getTile(m_Board, x, y);
	// 			if (tile)
	// 				std::cout << tile;
	// 			else
	// 				std::cout << '*';
	// 			std::cout << ' ';
	// 		}
	// 		std::cout << '\n';
	// 	}
	// 	std::cout << (m_IsXTurn ? "X next" : "O next") << '\n' << '\n';
	// }

private:

	inline char checkForWinnerTiles(char tile1, char tile2, char tile3) const
	{
		if (tile1 == 'X' && tile2 == 'X' && tile3 == 'X')
			return 'X';
		else if (tile1 == 'O' && tile2 == 'O' && tile3 == 'O')
			return 'O';
		else
			return 0;
	}

	int32_t m_PackedState;
	char *m_Board;
	//bool *m_PlayedStates;
	//bool *m_TileStates;
	bool m_IsXTurn;
	int m_RemainingTiles;
};

int main()
{
	int c;
	std::cin >> c;
	while (c--)
	{
		int32_t packedState;
		std::cin >> std::oct >> packedState;
		BoardState game(packedState);
		//game.debugPrintBoard();
		GameState state = game.getState();
		switch (state)
		{
			case GameState::WinX:
				std::cout << "X wins\n";
				break;
			case GameState::WinO:
				std::cout << "O wins\n";
				break;
			case GameState::Draw:
				std::cout << "Cat's\n";
				break;
			case GameState::InProgress:
				std::cout << "In progress\n";
				break;
			default:
				break;
		}
	}
	return 0;
}