#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
using namespace std;

 struct pokupka
{
	char fam[20];
	char name[20];
	char otch[20];
	char adres[20];
	char phone[20];
	char card[20];
 };
struct pokupka mas[30];
FILE *f;
int enter,s;
char ff;

void vvod();
int vibor();
void print();
void add();
void find();

int main()
{
	fopen_s(&f, "name.txt", "w+b");
	if (f == NULL) {
		printf("Error");
		_getch();
		exit(0);
	}
	setlocale(LC_ALL, "Rus");
	while (1)
	{
		switch (vibor())
		{
		case 1:vvod();break;
		case 2:print();break;
		case 3:add();break;
		case 4:find();break;
		case 5:return 0;
		default: cout << "Попробуйте другое\n";
		}
	}
	fclose(f);
}
void vvod()
{
	int i = 0;
	if (s < 20)
	{
		cout << "Клиент номер №" << s + 1;
		cout << "\nВведите фамилию клиента\n";
		cin >> mas[s].fam;
		cout << "Введите имя клиента\n";
		cin >> mas[s].name;
		cout << "Введите отчество клиента\n";
		cin >> mas[s].otch;
		cout << "Введите дом.адрес клиента\n";
		cin >> mas[s].adres;
		cout << "Введите номер телефона клиента\n";
		cin >> mas[s].phone;
		cout << "Введите номер карты клиента\n";
		cin >> mas[s].card;
		s++;
		fwrite(&mas, 1, sizeof(mas), f);
	}
	else cout << "Введено много записей\n";
	fclose(f);
}

int vibor()
{
	int enter = 0;
	cout << "  Введите \n";
	cout << "1 Формирование\n";
	cout << "2 Печать\n";
	cout << "3 Добавить\n";
	cout << "4 Поиск \n";
	cout << "5 Выход\n";
	cin >> enter;
	return enter;
}

void find()
{
	int n=0;
	fopen_s(&f, "name.txt", "r+b");
	if (f == NULL) {
		printf("Error");
		_getch();
		exit(0);
	}
	while (1)
	{
		printf("Поиск по фамилии (1-вывод ,0 - выход) ");
		scanf_s("%d", &n);
		if (n==0) break;
		fseek(f, sizeof(struct pokupka)*(n - 1), SEEK_SET);
		if (sizeof(mas) != fread(&mas, 1, sizeof(mas), f))
			printf("Конец списка\n");
		else
			printf("%s %s %s %s %s %s\n", mas->fam, mas->name, mas->otch, mas->adres, mas->phone,mas->card);
	}
	fclose(f);

}

void print() 
{
	printf("\nСписок покупателей\n");
	fopen_s(&f, "name.txt", "r+b");
	if (f == NULL) {
		printf("Error");
		_getch();
		exit(0);
	}
	printf("Содержимое файла\n");
	while (!feof(f)) {
		ff = fgetc(f);
		fprintf(stdout, "%c", ff);
	}
	fclose(f);
}

void add()
{
	fopen_s(&f, "name.txt", "ab");
	int c = 0;
	int key;
	cout << "Введите номер клиента\n";
	cin >> c;
	do
	{
		cout << "1 добавление фамилии клиента\n";
		cout << "2 добавление имени клиента\n";
		cout << "3 добавление отчества клиента\n";
		cout << "4 добавление адреса клиента\n";
		cout << "5 добавление номера телефона клиента\n";
		cout << "6 добавление номера карты клиента\n";
		cout << "7 выход\n";
		cin >> key;
		switch (key)
		{
		case 1: cout << "Введите фамилию\n";
			cin >> mas[c - 1].fam;
			break;
		case 2:
			cout << "Введите имя\n";
			cin >> mas[c - 1].name;
			break;
		case 3:
			cout << "Введите отчество\n";
			cin >> mas[c - 1].otch;
			break;
		case 4:
			cout << "Введите адрес\n";
			cin >> mas[c - 1].adres;
			break;
		case 5:
			cout << "Введите номер телефона\n";
			cin >> mas[c - 1].phone;
			break;
		case 6:
			cout << "Введите номер карты\n";
			cin >> mas[c - 1].card;
			break;
		case 7: return;
		}
	} while (1);
	fwrite(mas,1, sizeof(mas), f);
	fclose(f);
}
