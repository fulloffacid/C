
#include "pch.h"
#include <stdio.h>
#include <conio.h>

struct student
{
	char name[20];
	char fam[30];
	int year;
	int mark[5];
	int average;
};
struct student students[100];
struct student buffer;
int records;
int i, j;

int main()
{
	records = 0;
	do {
		printf("Student №%d\n",records+1);
		puts("Vvedite familiu: ");
		fflush(stdin);
		gets_s(students[records].fam);
		puts("Vvedite imya: ");
		fflush(stdin);
		gets_s(students[records].name);
		puts("Vvedite vozrast: ");
		scanf_s("%d",&students[records].year);
		for (i = 0;i < 5;i++)
		{
			printf("Vvedite ocenku po ekzamenu №%d\n", i + 1);
			scanf_s("%d",&students[records].mark[i]);
		}
		records++;
		puts("Precratit' rabotu (1/0)");
		scanf_s("%d", &i);
	} while (i);
	for (i = 0;i < records;i++)
	{
		students[i].average = 0;
		for (j = 0;j < 5;j++)
			students[i].average += students[i].mark[j];
	}
	for(i=0;i<records-1;i++)
		for (j = i;j < records;j++)
			if (students[i].average < students[j].average)
			{
				buffer = students[j];
				students[j] = students[i];
				students[i] = buffer;
			}
	for (i = 0;i < records;i++)
	{
		printf("Student %s %s \n", students[i].name, students[i].fam);
		printf("Vosrast %d \n", students[i].year);
		printf("Sr. ball %d \n", (students[i].average)/5);
	}
	_getch();
	return 0;

     
}

