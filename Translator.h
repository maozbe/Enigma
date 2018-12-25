
#ifndef Translator_HEADER
#define Translator_HEADER
#include "Substitutor.h"
#include <map>


class Translator : public Substitutor
{
protected:
	std::map<char, char> dictionary;
public:
	Translator();

};
#endif