
#include "pch.h"
#include <stdio.h>

int sum(int x[])
{
	int  res = 0;
	for (int i = 0; i < 5; i++)
		res += x[i];
	return res;
}

int main()
{
	int mas[3][5], i, j;
	for (i = 0;i < 3;i++)
		for (j = 0;j < 5;j++)
			mas[i][j] = i * j;
	for (i = 0;i < 3;i++)
		printf("\n res=%d\n", sum(mas[i]));
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 5;j++)
			printf("%d ", mas[i][j]);
		printf("\n");
	}
}
