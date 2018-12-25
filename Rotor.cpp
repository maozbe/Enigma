#include "Rotor.h"
#include "Reflector.h"
#include <iostream>
#include <unordered_map>



Rotor::Rotor(std::string permutation, char notch, char setting, char offset)
{
	this->notch = notch -65;
	this->setting = int(setting)-64;
	this->offset = int(offset)-64;
	

	for (int i = 65; i <= 90; i++)//Initiate the the forward permutation for the rotor
	{
		dictionary[char(i)] = permutation[i - 65];
	}

	for (int i = 65; i <= 90; i++)//Initiate the reverse permutation for the rotor
	{
		char value = dictionary[char(i)];
		reverseDict[value] = char(i);
	}

	std::cout << "print the initiation:\n";
	std::cout << "forward:\n";
	for (int i = 65; i <= 90; i++)
		std::cout << "{" << "key: " << char(i) << " value: " << dictionary[char(i)] << "}\n";
	std::cout << "reverse:\n";
	for (int i = 65; i <= 90; i++)
		std::cout << "{" << "key: " << char(i) << " value: " << reverseDict[char(i)] << "}\n";

}


char Rotor::transF(char c)
{
	//return dictionary[c];
	int tran = ((int(c) - 65) + (offset)-(setting)) % 26;
	if (tran < 0)
		tran = tran + 26;
	int forward = (int(dictionary[char((tran)+65)])) - 65;
	if (forward < 0)
		forward = forward + 26;
	int newc = (forward - offset + setting) % 26;
	if (newc < 0)
		newc = newc + 26;
	return newc + 65;
}

char Rotor::transR(char c)
{
	//return reverseDict[c];
	int tran = ((int(c) - 65) + offset - setting) % 26;
	if (tran < 0)
		tran = tran + 26;
	int reverse = (int(reverseDict[char((tran)+65)])) - 65;
	if (reverse < 0)
		reverse = reverse + 26;
	int newc = (reverse - offset + setting) % 26;
	if (newc < 0)
		newc = newc + 26;
	return newc + 65;
}


void Rotor::moveTrans()
{
	this->offset++;
	this->offset = this->offset % 26;
}

bool Rotor::isNotch()
{
	if (this->offset == this->notch)
		return true;
	else
		return false;
}

int Rotor::getOffset()
{
	return this->offset;
}

int Rotor::getSetting()
{
	return this->setting;
}

void Rotor::setOffset(char offset1)
{
	this->offset = toupper(offset1)-64;
}


