#include "file2.cpp"
#include "pch.h"
#include <iostream>

using namespace std;
extern void sort_stoimost();
extern void sort_kol();
extern void sort_itog_stoimost();

//extern int kol_prodbiletov;
struct theatre 
{
	char vremia_goda[20];
	int kol_vo;
	//char name[20];
	float stoimost;
	float itog_stoimost;
};
static theatre prodaja[20], temp[20];
static theatre pam;
extern int kol_biletov;

extern void print();
extern int read();
extern int sort();
extern void enter();

int main()
{
	//auto
	theatre* pam = new struct theatre;
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
	delete[] pam;
	return 0;
}
