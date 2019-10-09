#include "pch.h"
#include "add.cpp"
#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int b=5 ,i,l;
	//char b = 5;
	/*cout << "год високосный?";
	cin >> a;
	if (a == 1)
		Feb = 29;
	else
		Feb = 28;*/
	//cout << "с какого дня недели начинается январь?";
	//cin >> b;
	cout << endl;
	 month(b, 31, "Январь");
	 month(b, 28, "Февраль");
	 month(b, 31, "Март");
	 month(b, 30, "Апрель");
	 month(b, 31, "Май");
	 month(b, 30, "Июнь");
	 month(b, 31, "Июль");
	 month(b, 31, "Август");
	 month(b, 30, "Сентябрь");
	 month(b, 31, "Октябрь");
	 month(b, 30, "Ноябрь");
	 month(b, 31, "Декабрь");
	system("pause");
}