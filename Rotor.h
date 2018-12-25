#pragma once
#include "Translator.h"
class Rotor : public Translator
{
	char notch;
	int setting;
	int offset;
	std::map<char, char> reverseDict;

public:
	Rotor(std::string permutation, char notch, char setting, char offset);
	char transF(char c);
	char transR(char c);
	void moveTrans();
	bool isNotch();
	int getOffset();
	int getSetting();
	void setOffset(char offset1);
};

