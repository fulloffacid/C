#include "pch.h"
#include <stdio.h>

int x[50][50];
void vvod(int x[50][50], int n1, int m1);
int vivod(int x[50][50], int n1, int m1);

int main()
{
	int n, m;
	printf("Vvedite n\n");
	scanf_s("%d",&n);
	printf("Vvedite m\n");
	scanf_s("%d", &m);
	vvod(x,n,m);
	vivod(x, n, m);
}
void vvod(int x[50][50], int n1, int m1)
{
	int z, j;
	for (z = 0;z < n1;z++)
		for (j = 0;j < m1;j++) {
			printf("Vvedite element [%d%d]\n", z + 1, j + 1);
			scanf_s("%d", &x[z][j]);
		}
}

int vivod(int x[50][50], int n1, int m1)
{
	int z, j;
	printf("\n");
	for (z = 0;z < n1;z++) {
		for (j = 0;j < m1;j++)
			printf("%d ", x[z][j]);
		printf("\n");
	}
	return 0;
}

