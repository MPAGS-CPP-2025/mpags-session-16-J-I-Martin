#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "CipherType.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include <memory>

std::unique_ptr<Cipher> CipherFactory ::makeCipher(const CipherType type,
                                                   const std::string& key)
{
    switch (type) {
        case CipherType::Caesar:
            return std::make_unique<CaesarCipher>(key);
        case CipherType::Vigenere:
            return std::make_unique<VigenereCipher>(key);
        case CipherType::Playfair:
            return std::make_unique<PlayfairCipher>(key);
    }
    // If we get here then the type was invalid, so set null pointer
    return nullptr;
}