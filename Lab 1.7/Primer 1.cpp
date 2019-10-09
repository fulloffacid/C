// Primer 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <stdio.h>

int square(int y); //прототип функции
int _tmain(int argc, char* argv[])
{
	int x = 0;
	for (x = 1;x <= 10;x++) 
	printf_s("%d \n",square(x));
return 0;
}
//описание функции
int square(int y)
{
	return y * y;
}

