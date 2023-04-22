#include <iostream>
#include <vector>

struct Node
{
	Node* above;
	Node* adjacent;
	const int element;

	Node() = delete;
	explicit Node(int element)
		: above(nullptr)
		, adjacent(nullptr)
		, element(element)
	{
	}

	~Node()
	{
		if (adjacent != nullptr && adjacent->adjacent == this)
			adjacent->adjacent = nullptr;
	}

	void Link(Node* other)
	{
		other->adjacent = this;
		adjacent = other;
	}
};

class LinkedNodes
{
public:
	LinkedNodes() = delete;
	explicit LinkedNodes(int element)
		: m_element(element)
		, m_bottom(new Node(m_element))
	{
	}

	~LinkedNodes()
	{
		Node* current = m_bottom;
		while (current != nullptr)
		{
			auto aboveNode = current->above;
			delete current;
			current = aboveNode;
		}
	}

	void Link(LinkedNodes& other)
	{
		createNode()->Link(other.createNode());
	}

	int TracePermutation() const
	{
		Node* current = m_bottom;
		while (current->above != nullptr)
		{
			if (current->adjacent != nullptr)
			{
				current = current->adjacent;
				if (current->above == nullptr)
					break;
			}
			current = current->above;
		}
		return current->element;
	}

private:
	Node* createNode()
	{
		Node* node = new Node(m_element);
		node->above = m_bottom;
		m_bottom = node;
		return m_bottom;
	}

private:
	const int m_element;
	Node* m_bottom;
};

int main()
{
	std::vector<LinkedNodes> elements;

	int n, m;
	std::cin >> n >> m;

	// create initial nodes
	elements.reserve(n);
	for (int i = 0; i < n; ++i)
		elements.emplace_back(i + 1);

	// create the connections
	while (m--)
	{
		int element;
		std::cin >> element;
		auto& nodes = elements.at(element - 1);
		auto& nodesToLink = elements.at(element);
		nodes.Link(nodesToLink);
	}

	for (const auto& nodes : elements)
		std::cout << nodes.TracePermutation() << std::endl;
}