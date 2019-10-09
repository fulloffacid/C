// Определение максимального из трех целых чисел
#include "pch.h"
#include <stdio.h>
int maximum(int x, int y, int z); //prototip funkcii

int main()
{
	int a, b, c;
	printf_s("Vvedite 3 chisla: ");
	scanf_s("%d%d%d", &a, &b, &c);
	printf_s("Maxsimum =  %d", maximum(a, b, c));
	return 0;
}
//opredelenie funkcii maximum
int maximum(int x, int y, int z)
{
	int max = x;
	if (y > max) max = y;
	if (z > max) max = z;
	return max;

}
