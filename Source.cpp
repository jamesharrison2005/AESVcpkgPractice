#include <iostream>
#include "AESEncryption.h"

/*
How to Run:
1. In powershell run the following command(if you dont have vcpkg installed already): vcpkg integrate install 
2.go to Project Properties -> vcpkg -> Use Vcpkg Manifest -> Yes
3.Build the solution which should download the Crypto++ library and link it to your project
4.fi the build fails you may need to install vcpkg.exe manually (also check vcpkg.json has the dependency cryptopp)
5.Run the Program
6.If that doesnt work im sorry i dont know how to use vcpkg properly
*/

std::string EnterText();
void Menu();

int main()
{
	Menu();

	return 0;
}
// Function to enter text from the user
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
// Function to display the menu and handle user input
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