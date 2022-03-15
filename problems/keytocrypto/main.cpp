#include <iostream>
#include <string>

using namespace std;

inline int getOffset(char letter)
{
	return letter-'A';
}

inline char getLetterWithOffset(char letter, int offset)
{
	int current = getOffset(letter);
	int fullOffset = ((current+offset)%26);
	if (fullOffset < 0)
		fullOffset = 26+fullOffset; 
	//std::cout << letter << ' ' << fullOffset << std::endl;
	return 'A'+fullOffset;
}

int main()
{
	string cipher;
	string secret;
	getline(cin, cipher);
	getline(cin, secret);

	string key = ""+secret;
	string message = "";
	for (int i = 0; i < cipher.length(); ++i)
	{
		char letter = cipher[i];
		char decrypted = getLetterWithOffset(letter, -getOffset(key[i]));
		//std::cout << decrypted << " ('" << letter << "'-" << getOffset(key[i]) << ")" << std::endl;
		message += decrypted;
		if (key.length() < cipher.length())
			key += decrypted;
	}
	std::cout << message << std::endl;
}