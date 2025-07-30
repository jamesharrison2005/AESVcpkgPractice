#include"AESEncryption.h"

#include<iostream>


AESEncryptionCBC::AESEncryptionCBC()
    : key(AES::DEFAULT_KEYLENGTH), iv(AES::BLOCKSIZE), encoder(new FileSink(std::cout))
{
    // Set key size to AES default (16 bytes for AES-128)
    // Set IV size to AES block size (16 bytes)
    // Output encoder (currently not used but was used to display key)
	GenerateKey(prng, key); // generates a random jey and initialisation vector
    GenerateIV(prng, iv);
}

AESEncryptionCBC::~AESEncryptionCBC()
{
}

//encrypts plaintext using AES in CBC mode
std::string AESEncryptionCBC::Encrypt(const std::string& plainText)
{
    try
    {
        CBC_Mode< AES >::Encryption e; // creates encryption object
		e.SetKeyWithIV(key, key.size(), iv); // sets the key and IV for encryption

        StringSource s(plainText, true, 
            new StreamTransformationFilter(e,// crypto++ wrapper that handles things like padding , feeding thorugh inputs and output formats
				new StringSink(cipherText) // writes the encrypted output to cipherText
            ) // StreamTransformationFilter
        ); // StringSource
    }
    catch (const Exception& e)
    {
		std::cerr << e.what() << std::endl; // catches any exceptions thrown by Crypto++ and prints the error message
        exit(1);
    }
    return cipherText;
}

//Decrypts ciphertext using AES in CBC mode
std::string AESEncryptionCBC::Decrypt(const std::string& cipherText)
{
    try
    {
		CBC_Mode< AES >::Decryption d; // creates decryption object
		d.SetKeyWithIV(key, key.size(), iv); // sets the key and IV for decryption

        StringSource s(cipherText, true,
            new StreamTransformationFilter(d,
				new StringSink(recovered) // writes the decrypted output to recovered
            ) // StreamTransformationFilter
        ); // StringSource

    }
    catch (const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    return recovered;
}
// Generates a random key and IV using AutoSeededRandomPool
SecByteBlock AESEncryptionCBC::GenerateKey(AutoSeededRandomPool& prng, SecByteBlock& key)
{
	//AutoSeededRandomPool is a cryptographically secure random number generator
    prng.GenerateBlock(key, key.size());
    return key;
}

SecByteBlock AESEncryptionCBC::GenerateIV(AutoSeededRandomPool& prng, SecByteBlock& iv)
{
    prng.GenerateBlock(iv, iv.size());
    return iv;
}
