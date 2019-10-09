#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>

struct st
{
	char name[80];
	int age;
};

int main()
{
	int i, j, k;
	struct st m[100], t;
	printf("Vvedite kol-vo studentov: ");
	scanf_s("%d",&k);
	for (i = 0;i < k;i++)
	{
		printf("Vvedite imya studenta \n ");
		fflush(stdin);
		gets_s(m[i].name);
		puts("Vvedite vosrast ");
		m[i].age = 0;
		scanf_s("%d", &m[i].age);
	}
	for (i=0;i<k-1;i++)
		for(j=i+1;j<k;j++)
			if (strcmp(m[i].name,m[j].name)>0)
			{
				t = m[i]; m[i] = m[j]; m[j] = t;
			}
	printf("\n\n Resultat ");
	for (i = 0;i < k;i++)
	{
		printf("\n\n");
		puts(m[i].name);
		printf("%d years",m[i].age);
	}
	_getch();
	return 0;
}

