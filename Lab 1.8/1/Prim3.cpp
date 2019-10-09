
#include "pch.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
using namespace std;

struct pokupka
{
	char fam[20];
	char name[20];
	char otch[20];
	char adres[20];
	int phone;
	int card;
};
struct pokupka mas[30];
struct pokupka tmp;
int s=0;
int ent;



void vvod();
int menu();
void sort();
void vivod();
void delet();
void change();
void find();

int main()
{
	setlocale(LC_ALL, "Rus");
	while (1)
	{
		switch (menu())
		{
		case 1:vvod();break;
		case 2:sort();break;
		case 3:find();break;
		case 4:change();break;
		case 5:delet();break;
		case 6:vivod();break;
		case 7:return 0;
		default: cout << "Попробуйте другое\n";
		}
	}
}
void vvod()
{
	int i = 0,lens=0,f=0,a=0;
	if (s < 20)
	{
		    cout << "Клиент номер №" << s + 1;
			//cout << "\nВведите фамилию клиента\n";
			//cin >> mas[s].fam;
			do {
				cout <<"\nВведите фамилию клиента\n";
				cin >> mas[s].fam;
				lens = strlen(mas[s].fam);
				for (i = 0;i < lens;i++) {
					if ((mas[s].fam[i] > 'a') && (mas[s].fam[i] < 'z')) f++;
				}
				if (f == lens)
					a = 0;
				else a = 1;
			} while (a); f = 0;
			cout << "Введите имя клиента\n";
			cin >> mas[s].name;
			cout << "Введите отчество клиента\n";
			cin >> mas[s].otch;
			cout << "Введите дом.адрес клиента\n";
			cin >> mas[s].adres;
			cout << "Введите номер телефона клиента\n";
			cout << "Введите номер карты клиента\n";
			while (true) {
				scanf_s("%d %d", &mas[s].phone, &mas[s].card);
				if (cin.get() == '\n') {
					break;
				}
				else {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					printf("Некорректный ввод\n");
				}
			}
			s++;
	} else cout << "Введено много записей\n";

}

int menu()
{
	int ent=0;
	cout << "  Введите \n";
	cout << "1 Ввод \n";
	cout << "2 Сортировка\n";
	cout << "3 Поиск\n";
	cout << "4 Изменение\n";
	cout << "5 Удаление \n";
	cout << "6 Вывод\n";
	cout << "7 Выход\n";
	while (true) {
		scanf_s("%d", &ent);
		if (cin.get() == '\n') {
			break;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("Некорректный ввод\n");
		}
	}
	//cin >> ent;
	return ent;
}
void vivod()
{
	int sw=0;
	int n=0,i=0;
	if (s == 0) cout << "Нет клиентов: \n";
	else 
	{
		cout << "Ввод \n";
		cout << "1 вывести любого клиента\n";
		cout << "2 вывести всех клиентов\n";
		cin >> sw;
		if (sw == 1)
		{
			 cout << "Введите номер клиента, которого нужно вывести\n";
			 cin >> n;
			 cout << endl;
			 cout << "Фамилия " << mas[n-1].fam << endl;
			 cout << "Имя " << mas[n - 1].name << endl;
			 cout << "Отчество " << mas[n - 1].otch << endl;
			 cout << "Адрес " << mas[n - 1].adres << endl;
			 cout << "Номер телефона " << mas[n - 1].phone << endl;
			 cout << "Номер карты " << mas[n - 1].card << endl;
			 cout << "____________" << endl;
		}
		if (sw == 2)
		{
			for (i = 0; i < s;i++)
			{
				cout << "Фамилия " << mas[i].fam << endl;
				cout << "Имя " << mas[i].name << endl;
				cout << "Отчество " << mas[i].otch << endl;
				cout << "Адрес " << mas[i].adres << endl;
				cout << "Номер телефона " << mas[i].phone << endl;
				cout << "Номер карты " << mas[i].card << endl;
				cout << "____________" << endl;
			}
		}
	}
}
void delet()
{
	int d=0;
	cout << "Введите номер клиента, которого нужно удалить\n";
	cout << "Если нужно удалить всех клиентов,нажмите '99'\n";
	cin >> d;
	if (d != 99)
	{
		for (int i = (d - 1);i < s;i++)
			mas[i] = mas[i + 1]; 
		s = s - 1; 
	}
	if (d == 99)
	{
		for (int i = 0;i < 20;i++)
			mas[i] = tmp; 
		    s = 0; 
	}
}
void change()
{
	int c=0;
	int key;
	cout << "Введите номер клиента\n";
	cin >> c;
	do
	{
		cout << "Ввод \n";
		cout << "1 изменение фамилии клиента\n";
		cout << "2 изменение имени клиента\n";
		cout << "3 изменение отчества клиента\n";
		cout << "4 изменение адреса клиента\n";
		cout << "5 изменение номера телефона клиента\n";
		cout << "6 изменение номера карты клиента\n";
		cout << "7 выход\n";
		cin >> key;
		switch (key)
		{
		case 1: cout << "Введите новую фамилию клиента\n";
			cin >> mas[c - 1].fam;
			break;
		case 2:
			cout << "Введите новое имя клиента\n";
			cin >> mas[c - 1].name;
			break;
		case 3:
			cout << "Введите новое отчество клиента \n";
			cin >> mas[c - 1].otch;
			break;
		case 4:
			cout << "Введите новый адрес клиента\n";
			cin >> mas[c - 1].adres;
			break;
		case 5:
			cout << "Введите новый номер телефона  клиента\n";
			cin >> mas[c - 1].phone;
			break;
		case 6:
			cout << "Введите новый номер карты клиента\n";
			cin >> mas[c - 1].card;
			break;
		case 7: return ;
		}
	} while (1);
}

void find()   
{
	int sw,i=0;
	int num = 0;
	char f[20];
	if (s == 0)
		cout << "Нет клиентов\n";
	else
	{
		cout << "Ввод \n";
		cout << "1 Поиск по фамилии\n";
		cout << "2 Поиск по имени\n";
		cout << "3 Поиск по отчеству\n";
		cout << "4 поиск по адрес\n";
		cout << "5 поиск по номеру телефона\n";
		cout << "6 поиск по номеру карты\n";
		cin >> sw;
		switch (sw)
		{
		case 1: cout << "Введите фамилию клиента\n";
			cin >> f;
			for (i = 0; i < s;i++) 
				if (strcmp(f, mas[i].fam) == 0)
			{
				cout << "Фамилия " << mas[i].fam << endl;
				cout << "Имя " << mas[i].name << endl;
				cout << "Отчество " << mas[i].otch << endl;
				cout << "Адрес " << mas[i].adres << endl;
				cout << "Номер телефона " << mas[i].phone << endl;
				cout << "Номер карты " << mas[i].card << endl;
			}
				break;
		case 2:
			cout << "Введите имя клиента\n";
			cin >> f;
			for (i = 0; i < s;i++) 
				if (strcmp(f, mas[i].name) == 0)
			{
				cout << "Фамилия " << mas[i].fam << endl;
				cout << "Имя " << mas[i].name << endl;
				cout << "Отчество " << mas[i].otch << endl;
				cout << "Адрес " << mas[i].adres << endl;
				cout << "Номер телефона " << mas[i].phone << endl;
				cout << "Номер карты " << mas[i].card << endl;
			}
				break;
		case 3:
			cout << "Введите отчество клиента \n";
			cin >> f;
			for (i = 0; i < s;i++) 
				if (strcmp(f, mas[i].otch) == 0)
				{
				cout << "Фамилия " << mas[i].fam << endl;
				cout << "Имя " << mas[i].name << endl;
				cout << "Отчество " << mas[i].otch << endl;
				cout << "Адрес " << mas[i].adres << endl;
				cout << "Номер телефона " << mas[i].phone << endl;
				cout << "Номер карты " << mas[i].card << endl;
			}
				break;
		case 4:
			cout << "Введите адрес клиента\n";
			cin >> f;
			for (i = 0; i < s;i++) 
				if (strcmp(f, mas[i].adres) == 0)
				{ 
				cout << "Фамилия " << mas[i].fam << endl;
				cout << "Имя " << mas[i].name << endl;
				cout << "Отчество " << mas[i].otch << endl;
				cout << "Адрес " << mas[i].adres << endl;
				cout << "Номер телефона " << mas[i].phone << endl;
				cout << "Номер карты " << mas[i].card << endl;
			}
				break;
		case 5:
			cout << "Введите номер телефона  клиента\n";
			cin >> num;
			for (i = 0; i < s;i++) 
				if (num == mas[i].phone)
				{
				cout << "Фамилия " << mas[i].fam << endl;
				cout << "Имя " << mas[i].name << endl;
				cout << "Отчество " << mas[i].otch << endl;
				cout << "Адрес " << mas[i].adres << endl;
				cout << "Номер телефона " << mas[i].phone << endl;
				cout << "Номер карты " << mas[i].card << endl;
			}
				break;
		case 6:
			cout << "Введите номер карты клиента\n";
			cin >> num;
			for (i = 0; i < s;i++) 
				if (num == mas[i].phone)
				{
				cout << "Фамилия " << mas[i].fam << endl;
				cout << "Имя " << mas[i].name << endl;
				cout << "Отчество " << mas[i].otch << endl;
				cout << "Адрес " << mas[i].adres << endl;
				cout << "Номер телефона " << mas[i].phone << endl;
				cout << "Номер карты " << mas[i].card << endl;
			}
				break;
		case 7: return;
		}
	}
}
void sort()
{ 
	int i = 0, j=0;
	for (i = 0; i < s-1; i++)
		for (j = i + 1; j < s; j++)
			if (strcmp(mas[i].fam, mas[j].fam) > 0)
			{
				tmp= mas[i]; mas[i] = mas[j]; mas[j] = tmp;
			}
}
