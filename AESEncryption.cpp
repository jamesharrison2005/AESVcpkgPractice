#include"AESEncryption.h"

#include<iostream>


AESEncryptionCBC::AESEncryptionCBC()
    : key(AES::DEFAULT_KEYLENGTH), iv(AES::BLOCKSIZE), encoder(new FileSink(std::cout))
{
    GenerateKey(prng, key);
    GenerateIV(prng, iv);
}

AESEncryptionCBC::~AESEncryptionCBC()
{
}

std::string AESEncryptionCBC::Encrypt(const std::string& plainText)
{
    try
    {
        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource s(plainText, true,
            new StreamTransformationFilter(e,
                new StringSink(cipherText)
            ) // StreamTransformationFilter
        ); // StringSource
    }
    catch (const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    return cipherText;
}

std::string AESEncryptionCBC::Decrypt(const std::string& cipherText)
{
    try
    {
        CBC_Mode< AES >::Decryption d;
        d.SetKeyWithIV(key, key.size(), iv);

        StringSource s(cipherText, true,
            new StreamTransformationFilter(d,
                new StringSink(recovered)
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

SecByteBlock AESEncryptionCBC::GenerateKey(AutoSeededRandomPool& prng, SecByteBlock& key)
{
    prng.GenerateBlock(key, key.size());
    return key;
}

SecByteBlock AESEncryptionCBC::GenerateIV(AutoSeededRandomPool& prng, SecByteBlock& iv)
{
    prng.GenerateBlock(iv, iv.size());
    return iv;
}
