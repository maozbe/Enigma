#include "Plugboard.h"

Plugboard::Plugboard(std::string c)///[AH CB DR]
{
	int count = 0;
	for (int i = 0; c[i]; i++)
	{
		if (isdigit(c[i]))
			exit(0);
		if (c[i] != ' ')
			c[count++] = toupper(c[i]);
	}
	c[count] = '\0';
	
	for (int i = 0; i<count-1; i++)
	{ 
		dictionary[c[i]] = c[i + 1];
		dictionary[c[i + 1]] = c[i];
		i++;
	}
	for (int i = 65; i<=90; i++)
		std::cout << "{" << "key: " << char(i) << " value: " << dictionary[char(i)] << "}\n";

}

char Plugboard::trans(char a)
{
	return dictionary[a];
}