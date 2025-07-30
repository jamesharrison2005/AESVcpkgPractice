#include <iostream>
#include "AESEncryption.h"

std::string EnterText();
void Menu();

int main()
{
	Menu();

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

void Menu()
{
	std::cout << "Welcome to the AES Encryption Test" << std::endl;
	std::cout << "This program will encrypt and decrypt a text using AES CBC mode." << std::endl;
	std::cout << "Please enter the text you want to encrypt below or type (done) to exit." << std::endl;
	while (true)
	{
		std::string plainText;
		AESEncryptionCBC AES;
		plainText = EnterText();
		std::system("cls"); // Clear the console
		if (plainText == "done")
		{
			break;
		}else 
		{
			plainText = AES.Encrypt(plainText);
			std::cout << "Encrypted text: " << plainText << std::endl;
			std::string decryptedText = AES.Decrypt(plainText);
			std::cout << "Decrypted text: " << decryptedText << std::endl;
		}
		
	}
	
}