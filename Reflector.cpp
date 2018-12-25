#include "Reflector.h"


char Reflector::symetricTrans(char c)
{
	dictionary['A'] = 'Y';
	dictionary['B'] = 'R';
	dictionary['C'] = 'U';
	dictionary['D'] = 'H';
	dictionary['E'] = 'Q';
	dictionary['F'] = 'S';
	dictionary['G'] = 'L';
	dictionary['H'] = 'D';
	dictionary['I'] = 'P';
	dictionary['J'] = 'X';
	dictionary['K'] = 'N';
	dictionary['L'] = 'G';
	dictionary['M'] = 'O';
	dictionary['N'] = 'K';
	dictionary['O'] = 'M';
	dictionary['P'] = 'I';
	dictionary['Q'] = 'E';
	dictionary['R'] = 'B';
	dictionary['S'] = 'F';
	dictionary['T'] = 'Z';
	dictionary['U'] = 'C';
	dictionary['V'] = 'W';
	dictionary['W'] = 'V';
	dictionary['X'] = 'J';
	dictionary['Y'] = 'A';
	dictionary['Z'] = 'T';
	//---------------------------------Assemble the dictionary
	return dictionary[c];
}
