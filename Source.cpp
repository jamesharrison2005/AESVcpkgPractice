#include <iostream>
#include "AESEncryption.h"

std::string EnterText();

int main()
{

	std::string plainText;
	AESEncryptionCBC AES;
	plainText = EnterText();
	plainText = AES.Encrypt(plainText);
	std::cout << "Encrypted text: " << plainText << std::endl;
	std::string decryptedText = AES.Decrypt(plainText);
	std::cout << "Decrypted text: " << decryptedText << std::endl;

	return 0;
}

std::string EnterText()
{
	std::string text;
	std::cout << "Enter text to encrypt: " << std::endl;
	std::getline(std::cin, text);
	if (text.empty())
	{
		std::cerr << "Error: No text entered." << std::endl;
		exit(1);
	}

	return text;
}