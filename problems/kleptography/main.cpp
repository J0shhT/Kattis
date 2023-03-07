#include <iostream>
#include <limits>
#include <string>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string keyword;
	keyword.reserve(n);
	while (n--)
	{
		char c;
		std::cin >> c;
		keyword += c;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string cipher;
	cipher.reserve(m);
	while (m--)
	{
		char c;
		std::cin >> c;
		cipher += c;
	}

	std::string message;
	message.resize(cipher.size());
	message.insert(cipher.size() - keyword.size(), keyword);
	for (int i = cipher.size() - keyword.size() - 1; i >= 0; --i)
	{
		int b = cipher[i + keyword.size()] - 'a';
		int a = message[i + keyword.size()] - 'a';
		int k = (26 + b - a) % 26;
		message[i] = 'a' + k;
	}

	std::cout << message << std::endl;
}