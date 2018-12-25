#pragma once
#include "Translator.h"
#include <string>
#include <stdio.h>
#include <iostream>


class Plugboard : public Translator
{
public:
	Plugboard(std::string c);
	char trans(char a);
};

