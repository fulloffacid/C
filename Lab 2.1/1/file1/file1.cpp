#include "file2.cpp"
#include "pch.h"
#include <iostream>
using namespace std;

extern int kol_prodbiletov;
int main()
{
	//auto
	char choice;
	do {
		cout << "(E)enter information.\n";
		cout << "(R)ead information.\n";
		cout << "Re(A)d opredelennuy inform.\n";
		cout << "(S)ort information.\n";
		cout << "E(X)it.\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 'e':
		case 'E':enter();
			break;
		case 'r':
		case 'R':print();
			break;
		case 'a':
		case 'A':read();
			break;
		case 's':
		case 'S':sort();
			break;
		case 'x':
		case 'X':return 0;
		}
	} while (choice != 'X');
	return 0;
}

