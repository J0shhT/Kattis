#include <iostream>
#include <limits>
#include <sstream>
#include <string>

enum class BitState
{
	Zero,
	One,
	Unknown
};

class Register
{
public:
	void ClearInstruction()
	{
		int i;
		std::cin >> i;
		setBitState(i, BitState::Zero);
	}

	void SetInstruction()
	{
		int i;
		std::cin >> i;
		setBitState(i, BitState::One);
	}

	void OrInstruction()
	{
		int i, j;
		std::cin >> i >> j;
		setBitState(i, logicalOr(getBitState(i), getBitState(j)));
	}

	void AndInstruction()
	{
		int i, j;
		std::cin >> i >> j;
		setBitState(i, logicalAnd(getBitState(i), getBitState(j)));
	}

	std::string GetStateAsString() const
	{
		std::stringstream ss;
		for (int i = 31; i >= 0; --i)
		{
			auto state = getBitState(i);
			if (state == BitState::Zero)
				ss << '0';
			else if (state == BitState::One)
				ss << '1';
			else
				ss << '?';
		}
		return ss.str();
	}

private:
	BitState getBitState(size_t bit) const
	{
		if ((m_knownBits & (1 << bit)) == 0)
			return BitState::Unknown;
		return (m_bitStates & (1 << bit)) == 0 ? BitState::Zero : BitState::One;
	}

	void setBitState(size_t bit, BitState state)
	{
		int mask = 1 << bit;
		if (state != BitState::Unknown)
		{
			m_knownBits |= mask;
			if (state == BitState::Zero)
				m_bitStates &= ~mask;
			else
				m_bitStates |= mask;
		}
		else
		{
			m_knownBits &= ~mask;
		}
	}

	BitState logicalOr(BitState a, BitState b) const
	{
		if (a == BitState::One || b == BitState::One)
			return BitState::One;
		if (a == BitState::Zero)
			return b;
		if (b == BitState::Zero)
			return a;
		return BitState::Unknown;
	}

	BitState logicalAnd(BitState a, BitState b) const
	{
		if (a == BitState::Zero || b == BitState::Zero)
			return BitState::Zero;
		if (a == BitState::Unknown || b == BitState::Unknown)
			return BitState::Unknown;
		if (a == BitState::One && b == BitState::One)
			return BitState::One;
		return BitState::Zero;
	}

private:
	int m_knownBits = 0;
	int m_bitStates = 0;
};

int main()
{
	int n;
	for (std::cin >> n; n != 0; std::cin >> n)
	{
		Register reg;
		for (int i = 0; i < n; ++i)
		{
			std::string instruction;
			std::cin >> instruction;

			if (instruction == "CLEAR")
				reg.ClearInstruction();
			else if (instruction == "SET")
				reg.SetInstruction();
			else if (instruction == "OR")
				reg.OrInstruction();
			else if (instruction == "AND")
				reg.AndInstruction();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << reg.GetStateAsString() << std::endl;
	}
}