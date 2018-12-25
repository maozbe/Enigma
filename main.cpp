#pragma once

#include "Reflector.h"
#include "Plugboard.h"
#include "Rotor.h"
using namespace std;


int main()
{
	std::string newWord;
	std::string newPlug;
	cout << "\nplease choose the Plugboard set: ect(AT CH RW)..press enter for no plugboard setting\n";
	getline(cin, newPlug);
	Plugboard OR(newPlug);
	Reflector Maoz;
	Rotor Alona1("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'R', 'C', 'S');
	Rotor Alona2("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'F', 'H', 'D');
	Rotor Alona3("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', 'A', 'V');
	Rotor Alona4("ESOVPZJAYQUIRHXLNFTGKDCMWB", 'K', 'F', 'I');
	Rotor Alona5("VZBRGITYUPSDNHLXAWMJQOFECK ", 'Z', 'F', 'I');
	Rotor rotor1 = Alona1;
	Rotor rotor2 = Alona2;
	Rotor rotor3 = Alona3;
	cout << "\nplease choose the rotor: ect(123)/(514)..\n";
	string choose;
	cin >> choose;
	if (choose.length() > 3) {
		cout << "wrong input!\n";
		exit(0);
	}
	cout << "\nplease choose the offset in order: ect(DOR)..\n";
	string chooseOF;
	cin >> chooseOF;
	if (chooseOF.length() > 3) {
		cout << "wrong input!\n";
		exit(0);
	}
	//input check for rotors and assemble
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			if (choose[i] > '5' || choose[i] < '1')
				return 0;
			if (choose[i] == '1') {
				rotor1 = Alona1;
				rotor1.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '2'){
				rotor1 = Alona2;
				rotor1.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '3'){
				rotor1 = Alona3;
				rotor1.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '4'){
				rotor1 = Alona4;
				rotor1.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '5'){
				rotor1 = Alona5;
				rotor1.setOffset(chooseOF[i]);
			}
		}
		if (i == 1)
		{
			if (choose[i] > '5' || choose[i] < '1')
				return 0;
			if (choose[i] == '1'){
				rotor2 = Alona1;
				rotor2.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '2'){
				rotor2 = Alona2;
				rotor2.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '3'){
				rotor2 = Alona3;
				rotor2.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '4'){
				rotor2 = Alona4;
				rotor2.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '5'){
				rotor2 = Alona5;
				rotor2.setOffset(chooseOF[i]);
			}
		}
		if (i == 2)
		{
			if (choose[i] > '5' || choose[i] < '1')
				return 0;
			if (choose[i] == '1'){
				rotor3 = Alona1;
				rotor3.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '2'){
				rotor3 = Alona2;
				rotor3.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '3'){
				rotor3 = Alona3;
				rotor3.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '4'){
				rotor3 = Alona4;
				rotor3.setOffset(chooseOF[i]);
			}
			else if (choose[i] == '5'){
				rotor3 = Alona5;
				rotor3.setOffset(chooseOF[i]);
			}
		}
	}
	std::cout << "Ring setting:\n";
	std::cout << rotor1.getSetting() << " - " << rotor2.getSetting() << " - " << rotor3.getSetting() << "\n";
	std::cout << "Initial ring offsets:\n";
	std::cout << rotor1.getOffset() << " - " << rotor2.getOffset() << " - " << rotor3.getOffset() << "\n";
	std::cout << "please enter the word for translate";
	getline(cin, newWord);
	getline(cin, newWord);
	std::string temp;
	for (int i = 0; i < newWord.length(); i++)
	{
		if (newWord[i] == ' ')
		{
			temp += ' ';
			continue;
		}
		if (rotor3.isNotch() || rotor2.isNotch())
		{
			if (rotor2.isNotch())
				rotor1.moveTrans();
			rotor2.moveTrans();
		}
		rotor3.moveTrans();
		temp += OR.trans(rotor3.transR(rotor2.transR(rotor1.transR(Maoz.symetricTrans(rotor1.transF(rotor2.transF(rotor3.transF(OR.trans(toupper(newWord[i]))))))))));
	}
	std::cout << "\n\n\ntemp:  " << temp << "\n\n\n";
	std::cout << "Final ring offsets:\n";
	std::cout << rotor1.getOffset() << " - " << rotor2.getOffset() << " - " << rotor3.getOffset() << "\n";

	return 0;

}

