#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_set>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>

//#define TEST
//#define DEBUG

struct Node;
struct NodeGroup;

enum class GroupDirection { Horizontal, Vertical, DiagonalLeft, DiagonalRight };
enum class State { None, X, O };

size_t n, m;
std::unordered_set<Node*> groups;
char* board;
NodeGroup** boardNodes;

struct Node
{
	State state;
	Node* first;
	Node* last;
	Node* next;
	Node* previous;
	int connections;
	int x, y;
	GroupDirection dir;

	Node()
	{
		this->state = State::None;
		this->first = nullptr;
		this->last = nullptr;
		this->next = nullptr;
		this->previous = nullptr;
		this->connections = 0;
		this->x = 0;
		this->y = 0;
		this->dir = GroupDirection::Vertical;
	}

	Node(const Node &other)
	{
		this->state = other.state;
		this->first = other.first;
		this->last = other.last;
		this->next = other.next;
		this->previous = other.previous;
		this->connections = other.connections;
		this->x = other.x;
		this->y = other.y;
		this->dir = other.dir;
	}

	inline bool isFirst() { return getFirst() == this; }
	inline bool isLast() { return getLast() == this; }
	inline bool hasNext() { return this->next != nullptr; }
	inline bool hasPrevious() { return this->previous != nullptr; }
	inline Node* getLast() { return this->first->last; }
	inline Node* getFirst() { return this->first; }
	inline int getConnections() { return getFirst()->connections; }

	void link(Node* node)
	{
		assert(getLast() != nullptr);
		Node* oldLast = getLast();
		oldLast->next = node;
		node->first = getFirst();
		node->previous = oldLast;
		this->first->last = node;
		this->first->connections++;
	}

	~Node()
	{
		if (isFirst())
		{
			Node* current = this->next;
			while (current != nullptr)
			{
				Node* next = current->next;
				delete current;
				current = next;
			}
		}
	}
};

struct NodeGroup
{
	Node* horizontal;
	Node* vertical;
	Node* diagonalLeft;
	Node* diagonalRight;

	NodeGroup()
	{
		this->horizontal = nullptr;
		this->vertical = nullptr;
		this->diagonalLeft = nullptr;
		this->diagonalRight = nullptr;
	}
};

State getState(char c)
{
	switch (c)
	{
	case 'X':
		return State::X;
	case 'O':
		return State::O;
	default:
		return State::None;
	}
}

std::string stateToChar(State state)
{
	switch (state)
	{
	case State::X:
		return "X";
	case State::O:
		return "O";
	default:
		return ".";
	}
}

std::string directionToString(GroupDirection dir)
{
	switch (dir)
	{
	case GroupDirection::Horizontal:
		return "horizontal";
	case GroupDirection::Vertical:
		return "vertical";
	case GroupDirection::DiagonalLeft:
		return "diagonal (left)";
	case GroupDirection::DiagonalRight:
		return "diagonal (right)";
	default:
		return "";
	}
}

char& get(size_t x, size_t y)
{
	return board[y*n + x];
}

Node* getNode(size_t x, size_t y, GroupDirection dir)
{
	NodeGroup* group = boardNodes[y*n + x];
	if (group == nullptr) return nullptr;
	switch (dir)
	{
	case GroupDirection::Horizontal:
		return group->horizontal;
	case GroupDirection::Vertical:
		return group->vertical;
	case GroupDirection::DiagonalLeft:
		return group->diagonalLeft;
	case GroupDirection::DiagonalRight:
		return group->diagonalRight;
	default:
		assert(false);
		return nullptr;
	}
}

NodeGroup* getGroup(size_t x, size_t y)
{
	return boardNodes[y*n + x];
}

NodeGroup* newNodeGroup(size_t x, size_t y)
{
	NodeGroup* group = new NodeGroup();
	boardNodes[y*n + x] = group;
	return group;
}

Node* addNode(size_t x, size_t y, GroupDirection dir)
{
	Node* node = new Node();
	node->first = node;
	node->last = node;
	node->x = x;
	node->y = y;
	node->dir = dir;
	NodeGroup* group = boardNodes[y*n + x];
	switch (dir)
	{
	case GroupDirection::Horizontal:
		group->horizontal = node;
		break;
	case GroupDirection::Vertical:
		group->vertical = node;
		break;
	case GroupDirection::DiagonalLeft:
		group->diagonalLeft = node;
		break;
	case GroupDirection::DiagonalRight:
		group->diagonalRight = node;
		break;
	default:
		assert(false);
	}
	return node;
}

struct Point
{
	int x;
	int y;
};
bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) && q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y)) return true;
	return false;
}
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4)
		return true;

	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false;
}

int main()
{
#ifdef TEST
	int tests;
	std::cin >> tests;

	for (int i = 0; i < tests; i++) {
		std::string testResult;
		std::cin >> testResult;
		if (testResult == "X" || testResult == "O")
		{
			testResult += " WINS";
			std::string tmp;
			std::cin >> tmp;
		}
		
#endif

		std::cin >> n;
		std::cin >> m;

		groups.clear();
		boardNodes = (NodeGroup**)calloc(n*n, sizeof(NodeGroup*));
		board = (char*)calloc(n*n, sizeof(char));

		int movesX = 0;
		int movesO = 0;
		int emptySlots = 0;

		for (size_t y = 0; y < n; y++)
		{
			for (size_t x = 0; x < n; x++)
			{
				char val;
				std::cin >> val;
				get(x, y) = val;
				State state = getState(val);

				if (state == State::None)
				{
					emptySlots++;
					continue;
				}
				if (state == State::X) movesX++;
				if (state == State::O) movesO++;

				newNodeGroup(x, y);
				Node* currentH = addNode(x, y, GroupDirection::Horizontal);
				Node* currentV = addNode(x, y, GroupDirection::Vertical);
				Node* currentDL = addNode(x, y, GroupDirection::DiagonalLeft);
				Node* currentDR = addNode(x, y, GroupDirection::DiagonalRight);
				currentH->state = state;
				currentV->state = state;
				currentDL->state = state;
				currentDR->state = state;

				if (x == 0 && y == 0)
				{
					continue;
				}

				//Check left
				if (x > 0)
				{
					Node* left = getNode(x - 1, y, GroupDirection::Horizontal);
					if (left != nullptr && state == left->state)
					{
						left->link(currentH);
						groups.emplace(left->getFirst());
					}
				}

				//Check up
				if (y > 0)
				{
					Node* up = getNode(x, y - 1, GroupDirection::Vertical);
					if (up != nullptr && state == up->state)
					{
						up->link(currentV);
						groups.emplace(up->getFirst());
					}
				}

				//Check diagonal left
				if (x > 0 && y > 0)
				{
					Node* diagonal = getNode(x - 1, y - 1, GroupDirection::DiagonalLeft);
					if (diagonal != nullptr && state == diagonal->state)
					{
						diagonal->link(currentDL);
						groups.emplace(diagonal->getFirst());
					}
				}

				//Check diagonal right
				if (x + 1 < n && y > 0)
				{
					Node* diagonal = getNode(x + 1, y - 1, GroupDirection::DiagonalRight);
					if (diagonal != nullptr && state == diagonal->state)
					{
						diagonal->link(currentDR);
						groups.emplace(diagonal->getFirst());
					}
				}
			}
		}

		//FOR DEBUGGING
#ifdef DEBUG
		std::cout << "\n======================\n";
		std::cout << "GROUPS (for debugging)\n";
		std::cout << "======================\n";
		for (Node* node : groups)
		{
			std::cout << stateToChar(node->state) << " (" << node->getConnections() + 1 << ") starting at (" << node->x << ", " << node->y << ") and going " << directionToString(node->dir) << "\n";
		}
		std::cout << "\n\n";
#endif

		//Determine game state
		int wins = 0;
		State winner = State::None;
		bool isImpossible = false;
		for (Node* node : groups)
		{
			if (node->getConnections() + 1 >= m)
			{
				if (winner != State::None && node->state != winner)
				{
					//We have 2 DIFFERENT winners???
					isImpossible = true;
					break;
				}
				//We have a winner
				winner = node->state;
				wins++;
			}
		}
		if (wins > 1)
		{
			//We have more than 1 win solution, check if they are valid using line segment intersections
			//If any lines don't intersect, it's not valid.

			std::vector<Node*> possibleSolutions;
			for (Node* node : groups)
			{
				if (node->getConnections() + 1 == m)
				{
					//Valid solution
					possibleSolutions.push_back(node);
				}
				else if (node->getConnections() + 1 > m)
				{
					//Solution needs to be split up into segments of m
					if (((double)node->getConnections()+1.0 / (double)m) >= 2.0)
					{
						//Row is impossible, c/m must be [1, 2)
						isImpossible = true;
						break;
					}
					Node* absoluteEnd = node->getLast();
					Node* current = node->getFirst();
					Node* end = current->next->next;
					for (;;)
					{
						Node* newNodeGroup = new Node();
						newNodeGroup->connections = 2;
						newNodeGroup->first = current;
						newNodeGroup->last = end;
						newNodeGroup->x = current->x;
						newNodeGroup->y = current->y;
						possibleSolutions.push_back(newNodeGroup);
						if (end == absoluteEnd)
						{
							break;
						}
						else
						{
							assert(current->next != nullptr);
							assert(end->next != nullptr);
							current = current->next;
							end = end->next;
						}
					}
				}
			}

			if (!isImpossible)
			{
				bool invalid = false;
				for (Node* node1 : possibleSolutions)
				{
					for (Node* node2 : possibleSolutions)
					{
						if (node1 != node2)
						{
							Node* node1First = node1->first;
							Node* node1Last = node1->last;
							Node* node2First = node2->first;
							Node* node2Last = node2->last;
							if (!doIntersect({ node1First->x, node1First->y }, { node1Last->x, node1Last->y }, { node2First->x, node2First->y }, { node2Last->x, node2Last->y }))
							{
#ifdef DEBUG
								std::cout << "(" << node1First->x << "," << node1First->y << "), " << "(" << node1Last->x << "," << node1Last->y << ")";
								std::cout << "does not connect with ";
								std::cout << "(" << node2First->x << "," << node2First->y << "), " << "(" << node2Last->x << "," << node2Last->y << ")\n";
#endif
								isImpossible = true;
								invalid = true;
								break;
							}
						}
					}
					if (invalid) break;
				}
			}
		}
		else if (wins == 1)
		{
			for (Node* node : groups)
			{
				if (node->getConnections() + 1 > m)
				{
					if (((double)node->getConnections()+1.0 / (double)m) >= 2.0)
					{
						//Row is impossible, c/m must be [1, 2)
						isImpossible = true;
						break;
					}
				}
			}
		}

		if (m == 1)
		{
			if (movesX == 1)
			{
				winner = State::X;
			}
			else
			{
				if (movesX != 0 && movesO != 0) isImpossible = true;
			}
			if (movesO > 0)
			{
				//X always goes first, so X has to win a game where you only need 1 in a row to win
				isImpossible = true;
			}
		}
		if (movesO > movesX)
		{
			//If X always goes first, O can't have more moves than X
			isImpossible = true;
		}
		if (movesX - 1 > movesO)
		{
			//O moves must be equal to or 1 less than X moves, if it isn't, they must have skipped a turn
			isImpossible = true;
		}
		if (winner == State::X && movesO >= movesX)
		{
			//If X wins, O has to have less moves than X because X went first
			isImpossible = true;
		}
		if (winner == State::O && movesO != movesX)
		{
			//If O wins, O has to have the same amount of moves than X
			isImpossible = true;
		}

		std::string winnerString;
		if (isImpossible)
		{
			winnerString = "ERROR";
		}
		else
		{
			if (winner == State::None)
			{
				if (emptySlots == 0)
				{
					winnerString = "DRAW";
				}
				else
				{
					winnerString = "IN PROGRESS";
				}
			}
			else
			{
				winnerString = stateToChar(winner) + " WINS";
			}
		}

#ifdef TEST
		if (testResult == winnerString)
		{
			std::cout << "TEST PASSED\n";
		}
		else
		{
			std::cout << "TEST FAILED ON " << i << "\n";
			for (size_t y = 0; y < n; y++)
			{
				for (size_t x = 0; x < n; x++)
				{
					std::cout << get(x, y);
				}
				std::cout << "\n";
			}
			std::cout << "EXPECTED: " << testResult << " | GOT: " << winnerString << "\n";
			return 1;
		}
	}
#else
		std::cout << winnerString << "\n";
#endif

#ifdef DEBUG
		getchar();
		getchar();
#endif
		//free(board);
		return 0;
}