#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct theatre
{
	char vremia_goda[20];
	int kol_vo;
	//char name[20];
	float stoimost;
	float itog_stoimost;
};
static theatre prodaja[20], temp[20];
struct theatre *pam;
int kol_biletov;

/*int main() {
	pam=new struct theatre;
	//delete[] pam;
	return 0;
}*/

extern void enter()
{
	register int a;
	cout << "Kol-vo sezonov vvodit: ";
	
	while (!scanf_s("%d", &kol_biletov) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		printf("Error!\n");
	}
	//cin >> kol_biletov;

	for (a = 0;a < kol_biletov;a++)
	{
		cout << "\nEnter vremia goda \n"; cin >> prodaja[a].vremia_goda;
		cout << "Enter kol-vo biletov: \n"; 
		
		//cin >> prodaja[a].kol_vo;
		while (!scanf_s("%d", &prodaja[a].kol_vo) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			printf("Error!\n");
		}
		
		//cout << "Enter nazvanie spectaclia: \n"; cin >> prodaja[a].name;
		cout << "Enter stoimost za odin: \n"; 
		//cin >> prodaja[a].stoimost;
		while (!scanf_s("%f", &prodaja[a].stoimost) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			printf("Error!\n");
		}
		prodaja[a].itog_stoimost = prodaja[a].kol_vo * prodaja[a].stoimost;
	}
	cout << '\n';
}

extern void print()
{
	register int a;
	cout << '\n';
	cout << "№  Vremia goda  Kol-vo	 Stoimost Itog.Stoimost\n";
	cout << "************************************************\n";
	for (a = 0; a < kol_biletov; a++)
	{
		printf("%d %10s    %5d      %.2f      %.2f", a+1, prodaja[a].vremia_goda, prodaja[a].kol_vo, prodaja[a].stoimost, prodaja[a].itog_stoimost);
		cout << '\n';
	}
	cout << '\n';
}

extern int read()
{
	register int a;
	cout << "Vvedite vremia goda chtob prochitat inform.\n";
	//auto 
	char choice[10]; cin >> choice;
	for (a = 0; a < kol_biletov; a++)
	{
		if (strcmp (choice,prodaja[a].vremia_goda)==0)
		{
			cout << "№	Vremia goda	  Kol-vo    Stoimost Itog.Stoimost\n";
			cout << "**********************************************\n";
			printf("%d    %10s     %5d       %.2f          %.2f", a+1, prodaja[a].vremia_goda, prodaja[a].kol_vo, prodaja[a].stoimost, prodaja[a].itog_stoimost);
			cout << "\n\n";
			return 0;
		}
	}
	cout << "Takoi pori net \n";
}

extern void sort_itog_stoimost()
{
	register int a, b;
	cout << "!OLD!";
	print();
	for (a = 1; a < kol_biletov; a++) for (b = kol_biletov - 1; b >= a; b--)
	{
		if (prodaja[b - 1].itog_stoimost > prodaja[b].itog_stoimost)
		{
			temp[b] = prodaja[b - 1];
			prodaja[b - 1] = prodaja[b];
			prodaja[b] = temp[b];
		}
	}
	cout << "!NEW!";
	print();
}

extern void sort_kol()
{
	register int a, b;
	cout << "!OLD!";
	print();
	for (a = 1; a < kol_biletov; a++) for (b = kol_biletov - 1; b >= a; b--)
	{
		if (prodaja[b - 1].kol_vo > prodaja[b].kol_vo)
		{
			temp[b] = prodaja[b - 1];
			prodaja[b - 1] = prodaja[b];
			prodaja[b] = temp[b];
		}
	}
	cout << "!NEW!";
	print();
}
extern void sort_stoimost()
{
	register int a, b;
	cout << "!OLD!";
	print();
	for (a = 1; a < kol_biletov; a++) for (b = kol_biletov - 1; b >= a; b--)
	{
		if (prodaja[b - 1].stoimost > prodaja[b].stoimost)
		{
			temp[b] = prodaja[b - 1];
			prodaja[b - 1] = prodaja[b];
			prodaja[b] = temp[b];
		}
	}
	cout << "!NEW!";
	print();
}



extern int sort()
{
	//auto 
	int choice;
	do {
		cout << "\t1. Sort po \"kol-vy\".\n";
		cout << "\t2. Sort po \"stoimosti\".\n";
		cout << "\t3. Sort po \"itogovoi stoimosti\".\n";
		cin >> choice;
		switch (choice)
		{
		case 1: sort_kol();
			break;
		case 2: sort_stoimost();
			break;
		case 3: sort_itog_stoimost();
			break;
		}
	} while (choice > 3);
	cout << "**COMPLETE**\n";
	cout << '\n';
	return 0;
}



