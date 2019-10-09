#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int *x, int *y);
void bubble_sort(int *a1, int count); //функция пузырьковой сортировки
void min_sort(int *a1, int count); //функция сортировки методом выбора
void insert_sort(int *a1, int count); // функция сортировки методом вставки
void shell_sort(int *x, int count); //функция сортировки методом Шелла
void hoare_sort(int *x, int, int); //функция сортировки методом хоора

void vvod(int *a1, int count); //функция ввода значений массива
void out(int *a1, int count); //функция вывода значений массива
void file_write(int *a1, int count, int choice);
void Poisk(int *a1, int count, int poisk); //функция поиска
void Poisk__2(int *a1, int count, int poisk); //функция бинарного поиска

FILE *file;
int i, j;
//int step = 0;

int main()
{
	int *a = 0, *b = 0, *c = 0, *d = 0, *e = 0, n1, n2, n3, n4, n5, choice = 1, poisk = 0;
	int podchoice = 0;

	fopen_s(&file, "result.txt", "w");
	while (true) {
		cout << "\nenter arrays -1\t\nresult of bubble sort-2\t\nresult of min sort-3\t\nresult of insert sort-4\t\nresult of Shell sort-5\t\nresult of Hoor sort-6\t\npoisk-7\t\nbinpoisk-8\nEXIT-0\n";

		cout << "your choice "; cin >> choice;
		switch (choice) {
		case 1:
			cout << "enter arrays\n";
			//if (choice == 1) {
			cout << "enter the length of array A: ";
			cin >> n1;
			static int *a = new int[n1];
			cout << "enter elements of array: \n";
			vvod(a, n1);
			for (i = 0; i < n1; i++)
				fprintf(file, "%d ", *(a + i));
			cout << "enter the length of array B: ";
			cin >> n2;
			static int *b = new int[n2];
			cout << "enter elements of array: \n";
			vvod(b, n2);
			for (i = 0; i < n2; i++)
				fprintf(file, "%d ", *(b + i));
			cout << "enter the length of array C: ";
			cin >> n3;
			static int *c = new int[n3];
			cout << "enter elements of array: \n";
			vvod(c, n3);
			for (i = 0; i < n3; i++)
				fprintf(file, "%d ", *(c + i));
			cout << "enter the length of array D: ";
			cin >> n4;
			static int *d = new int[n4];
			cout << "enter elements of array: \n";
			vvod(d, n4);
			for (i = 0; i < n4; i++)
				fprintf(file, "%d ", *(d + i));
			cout << "enter the length of array E: ";
			cin >> n5;
			static int *e = new int[n5];
			cout << "enter elements of array: \n";
			vvod(e, n5);
			for (i = 0; i < n5; i++)
				fprintf(file, "%d ", *(e + i));
			break;
		case 2:
			cout << "sorted array by method \\bubble sort\n";
			bubble_sort(a, n1);
			//cout << "CHOICE";cin >> choice;
			file_write(a, n1, choice);
			out(a, n1);
			break;
		case 3:
			cout << "sorted array by method \\min sort\n";
			min_sort(b, n2);
			//cout << "CHOICE";cin >> choice;
			file_write(b, n2, choice);
			out(b, n2);
			break;
		case 4:
			puts("sorted array by method \\insert sort\n");
			insert_sort(c, n3);
			//cout << "CHOICE";cin >> choice;
			file_write(c, n3, choice);
			out(c, n3);
			break;
		case 5:
			cout << "sorted array by method \\shell sort\n";
			shell_sort(d, n4);
			//cout << "CHOICE";cin >> choice;
			file_write(d, n4, choice);
			out(d, n4);
			break;
		case 6:
			cout << "sorted array by method \\hoor sort\n";
			hoare_sort(e, 0, n5 - 1);
			//cout << "CHOICE";cin >> choice;
			file_write(e, n5, choice);
			out(e, n5);
			break;
		case 7:	cout << "Vvedite iskomii elemeent\n";
			cin >> poisk;
			//cout << "Put 1 if u want use /// or put any key if u want use ////\n";
			fprintf(file, "\n\t\tPosledovatel’nyi poisk\n");
			fprintf(file, "\n\t\tPosledovatel’nyi poisk for the 1 flow\n");
			Poisk(a, n1, poisk);
			fprintf(file, "\n\t\tPosledovatel’nyi poisk for the 2 flow\n");
			Poisk(b, n2, poisk);
			fprintf(file, "\n\t\tPosledovatel’nyi poisk for the 3 flow\n");
			Poisk(c, n3, poisk);
			fprintf(file, "\n\t\tPosledovatel’nyi poisk for the 4 flow\n");
			Poisk(d, n4, poisk);
			fprintf(file, "\n\t\tPosledovatel’nyi poisk for the 5 flow\n");
			Poisk(e, n5, poisk);
			break;
		case 8:
			cout << "Vvedite iskomii elemeent\n";
			cin >> poisk;
			fprintf(file, "\n\t\t	Binarnyi  poisk\n");
			fprintf(file, "\n\t\t	Binarnyi  poisk for the 1 flow\n");
			Poisk__2(a, n1, poisk);
			fprintf(file, "\n\t\t	Binarnyi  poisk for the 2 flow\n");
			Poisk__2(b, n2, poisk);
			fprintf(file, "\n\t\t	Binarnyi  poisk for the 3 flow\n");
			Poisk__2(c, n3, poisk);
			fprintf(file, "\n\t\t	Binarnyi  poisk for the 4 flow\n");
			Poisk__2(d, n4, poisk);
			fprintf(file, "\n\t\t	Binarnyi  poisk for the 5 flow\n");
			Poisk__2(e, n5, poisk);
			break;
		case 9:
			delete[]a;
			delete[]b;
			delete[]c;
			delete[]d;
			delete[]e;
		case 0: cout << "FUCKK"; return 0;
		}
		//default: return 0;
	}
	fclose(file);
}
void swap(int *x, int *y)
{
	int t;   	t = *x;    	*x = *y;     *y = t;
}
void vvod(int *a1, int count)
{
	for (i = 0; i < count; i++)
		cin >> *(a1 + i);
}
void out(int *a1, int count)
{
	for (i = 0; i < count; i++)
		cout << *(a1 + i) << " ";
	cout << endl;
}
void bubble_sort(int *a1, int count)
{
	for (i = 0; i < count; i++)
		for (j = (count - 1); j > i; j--)
			if (*(a1 + j - 1) > (*(a1 + j)))
				swap((a1 + j - 1), (a1 + j)); /*поменять их местами */
}
void min_sort(int *a1, int count)
{
	int k;
	for (i = 0; i < count - 1; i++)
	{
		for (k = i, j = i + 1; j < count; j++) { // находим в цикле  
			if (*(a1 + j) < *(a1 + k))
			{               // минимальный элемент   
				k = j; 		// запоминаем его номер в k  
				swap((a1 + k), (a1 + i));

			}
		}
	}                   // меняем местами минимальный и
				  // элем, с которого начинался цикл
}
void insert_sort(int *a1, int count)
{
	for (i = 1; i <= count - 1; i++)
	{
		j = i;
		while (*(a1 + j) < *(a1 + j - 1) && j >= 1)
		{
			swap((a1 + j), (a1 + j - 1));
			j--;
		}
	}
}
void shell_sort(int *x, int count)
{
	int i, j;     //две переменные цикла         
	int gap;     //шаг сортировки     
	int sorted;  //флаг окончания этапа сортировки
	for (gap = count / 2; gap > 0; gap /= 2)//начало сортировки
		do {
			sorted = 0;
			for (i = 0, j = gap; j < count; i++, j++)
				if (*(x + i) > *(x + j))
				{
					swap((x + i), (x + j));
					sorted = 1;
				}
		} while (sorted);
}
void hoare_sort(int *x, int l, int r)
{
	int sr = *(x + (l + r) / 2);
	i = l;
	j = r;
	do
	{
		while (*(x + i) < sr) i++;
		while (*(x + j) > sr) j--;
		if (i <= j)
		{
			swap((x + i), (x + j));
			i++;     j--;
		}
	} while (i <= j);
	if (i < r)
		hoare_sort(x, i, r);
	if (j > l)
		hoare_sort(x, l, j);
}
void file_write(int *a1, int count, int choice)
{
	//if (choice == 0)
	//	fprintf(file, "\t\tRESULTS OF SORTS\n");
	if (choice == 2)
		fprintf(file, "\t\tRESULTS OF SORTS--Bubble Sort\n");
	if (choice == 3)
		fprintf(file, "\n\t\tRESULTS OF SORTS--Min Sort\n");
	if (choice == 4)
		fprintf(file, "\n\t\tRESULTS OF SORTS--Insert Sort\n");
	if (choice == 5)
		fprintf(file, "\n\t\tRESULTS OF SORTS--Shell Sort\n");
	if (choice == 6)
		fprintf(file, "\n\t\tRESULTS OF SORTS--Hoare Sort\n");
	if (choice != 0) {
		for (i = 0; i < count; i++)
			fprintf(file, "%d ", *(a1 + i));
	}
}
void Poisk(int *a1, int count, int poisk)
{
	int kolvo = 0;
	for (i = 0; i < count; i++)
		if (*(a1 + i) == poisk) kolvo++;
	if (kolvo == 0) {
		cout << "required element ne naiden\n";
		fprintf(file, "required element ne naiden\n");
	}
	else {
		cout << "kol-vo sovpadenii required element = " << kolvo << endl;
		fprintf(file, "kol-vo sovpadenii required element = %d ", kolvo);
	}
}

void Poisk__2(int *a1, int count, int poisk)
{
	int flag = 0;
	for (i = 0; i < count; i++)
		if (a1[i] == poisk) flag++;
	if (flag == 0) {
		cout << "required element ne naiden\n";
		fprintf(file, "required element ne naiden\n");
	}
	else {
		int m = (count - 1) / 2;
		while (*(a1 + m) != poisk)
		{
			if (*(a1 + m) < poisk)
				i += m;
			else j = m - i;
			m = (i + j) / 2;
		}
		if (*(a1 + m) == poisk) {
			printf("required element find in pozition %d\n", m + 1);
			fprintf(file, "required element  naiden\n");
		}

	}
}


