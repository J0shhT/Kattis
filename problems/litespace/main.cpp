#include <iostream>
#include <stack>
#include <string>
#include <vector>

enum class Lexeme
{
	Eof,
	Space,
	Newline,
	Tab
};

enum class Instruction
{
	Eof,
	Push,
	Copy,
	Swap,
	Remove,
	Addition,
	Subtraction,
	Multiplication,
	Division,
	Print
};

class Program
{
public:
	Program() = delete;
	explicit Program(const std::string& source)
		: m_source(source)
		, m_cursor(0)
		, m_stack()
	{
	}

	void Execute()
	{
		for (;;)
		{
			switch (_nextInstruction())
			{
			case Instruction::Push:
				_push();
				break;
			case Instruction::Copy:
				_copy();
				break;
			case Instruction::Swap:
				_swap();
				break;
			case Instruction::Remove:
				_remove();
				break;
			case Instruction::Addition:
				_add();
				break;
			case Instruction::Subtraction:
				_subtract();
				break;
			case Instruction::Multiplication:
				_multiply();
				break;
			case Instruction::Division:
				_divide();
				break;
			case Instruction::Print:
				_print();
				break;
			default:
				return;
			}
		}
	}

private:
	char _nextToken()
	{
		if (m_cursor >= m_source.size())
			return '\0';
		return m_source.at(m_cursor++);
	}

	Lexeme _nextLexeme()
	{
		for (;;)
		{
			switch (_nextToken())
			{
			case '\0':
				return Lexeme::Eof;
			case 'S':
				return Lexeme::Space;
			case 'N':
				return Lexeme::Newline;
			case 'T':
				return Lexeme::Tab;
			default:
				break;
			}
		}
	}

	Instruction _nextInstruction()
	{
		switch (_nextLexeme())
		{
		case Lexeme::Space:
			return _readSpaceInstruction();
		case Lexeme::Tab:
			return _readTabInstruction();
		default:
			return Instruction::Eof;
		}
	}

	Instruction _readSpaceInstruction()
	{
		switch (_nextLexeme())
		{
		case Lexeme::Space:
			return Instruction::Push;
		case Lexeme::Newline:
			return _readSpaceNewlineInstruction();
		default:
			return Instruction::Eof;
		}
	}

	Instruction _readSpaceNewlineInstruction()
	{
		switch (_nextLexeme())
		{
		case Lexeme::Space:
			return Instruction::Copy;
		case Lexeme::Newline:
			return Instruction::Remove;
		case Lexeme::Tab:
			return Instruction::Swap;
		default:
			return Instruction::Eof;
		}
	}

	Instruction _readTabInstruction()
	{
		switch (_nextLexeme())
		{
		case Lexeme::Space:
			return _readTabSpaceInstruction();
		case Lexeme::Newline:
			if (_nextLexeme() != Lexeme::Space)
				return Instruction::Eof;
			if (_nextLexeme() != Lexeme::Tab)
				return Instruction::Eof;
			return Instruction::Print;
		default:
			return Instruction::Eof;
		}
	}

	Instruction _readTabSpaceInstruction()
	{
		switch (_nextLexeme())
		{
		case Lexeme::Space:
			return _readTabSpaceSpaceInstruction();
		case Lexeme::Tab:
			if (_nextLexeme() != Lexeme::Space)
				return Instruction::Eof;
			return Instruction::Division;
		default:
			return Instruction::Eof;
		}
	}

	Instruction _readTabSpaceSpaceInstruction()
	{
		switch (_nextLexeme())
		{
		case Lexeme::Space:
			return Instruction::Addition;
		case Lexeme::Newline:
			return Instruction::Multiplication;
		case Lexeme::Tab:
			return Instruction::Subtraction;
		default:
			return Instruction::Eof;
		}
	}

	int _readInteger()
	{
		Lexeme lexeme = _nextLexeme();
		if (lexeme == Lexeme::Eof)
			return 0;

		bool isNegative = lexeme == Lexeme::Tab;

		std::vector<Lexeme> bitLexemes;
		bitLexemes.reserve(31);
		while (lexeme = _nextLexeme(), lexeme == Lexeme::Space || lexeme == Lexeme::Tab)
			bitLexemes.push_back(lexeme);

		int bit = 0;
		int value = 0;
		for (auto iter = bitLexemes.rbegin(); iter != bitLexemes.rend(); ++iter)
		{
			if (*iter == Lexeme::Tab)
				value |= (1 << bit);
			++bit;
		}

		if (isNegative)
			value = -value;
		return value;
	}

	void _push()
	{
		m_stack.push(_readInteger());
	}

	void _copy()
	{
		if (m_stack.empty())
		{
			std::cout << "Invalid copy operation\n";
			return;
		}
		m_stack.push(m_stack.top());
	}

	void _swap()
	{
		if (m_stack.size() < 2)
		{
			std::cout << "Invalid swap operation\n";
			return;
		}

		int a = m_stack.top();
		m_stack.pop();
		int b = m_stack.top();
		m_stack.pop();
		m_stack.push(a);
		m_stack.push(b);
	}

	void _remove()
	{
		if (m_stack.empty())
		{
			std::cout << "Invalid remove operation\n";
			return;
		}
		m_stack.pop();
	}

	void _add()
	{
		if (m_stack.size() < 2)
		{
			std::cout << "Invalid addition operation\n";
			return;
		}

		int a = m_stack.top();
		m_stack.pop();
		int b = m_stack.top();
		m_stack.pop();
		m_stack.push(a + b);
	}

	void _subtract()
	{
		if (m_stack.size() < 2)
		{
			std::cout << "Invalid subtraction operation\n";
			return;
		}

		int a = m_stack.top();
		m_stack.pop();
		int b = m_stack.top();
		m_stack.pop();
		m_stack.push(b - a);
	}

	void _multiply()
	{
		if (m_stack.size() < 2)
		{
			std::cout << "Invalid multiplication operation\n";
			return;
		}

		int a = m_stack.top();
		m_stack.pop();
		int b = m_stack.top();
		m_stack.pop();
		m_stack.push(a * b);
	}

	void _divide()
	{
		if (m_stack.size() < 2)
		{
			std::cout << "Invalid division operation\n";
			return;
		}

		int a = m_stack.top();
		if (a == 0)
		{
			std::cout << "Division by zero\n";
			return;
		}
		m_stack.pop();
		int b = m_stack.top();
		m_stack.pop();
		m_stack.push(b / a);
	}

	void _print()
	{
		if (m_stack.empty())
		{
			std::cout << "Invalid print operation\n";
			return;
		}

		std::cout << m_stack.top() << '\n';
		m_stack.pop();
	}

private:
	const std::string m_source;
	size_t m_cursor;
	std::stack<int> m_stack;
};

int main()
{
	std::string source;
	std::getline(std::cin, source);
	Program program(source);
	program.Execute();
}