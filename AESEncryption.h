#pragma once
#include <iostream>
#include "cryptopp/cryptlib.h"
#include "cryptopp/rijndael.h"
#include "cryptopp/modes.h"
#include "cryptopp/files.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"

using namespace CryptoPP;

class AESEncryptionCBC
{
private:
	SecByteBlock key;
	SecByteBlock iv;
	AutoSeededRandomPool prng;
	HexEncoder encoder;
	std::string cipherText, recovered;

public:
	AESEncryptionCBC();
	~AESEncryptionCBC();
	std::string Encrypt(const std::string& plainText);
	std::string Decrypt(const std::string& cipherText);
	static SecByteBlock GenerateKey(AutoSeededRandomPool& prng, SecByteBlock& key);
	static SecByteBlock GenerateIV(AutoSeededRandomPool& prng, SecByteBlock& iv);
	void DisplayKey(SecByteBlock& key, HexEncoder& encoder);
};