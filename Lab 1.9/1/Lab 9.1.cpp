
#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main() 
{
	int A, B, C, kol=0,i=0, max=0,v=0;
	FILE *a, *b, *c, *d;
	char f;
	fopen_s(&a,"nameA.txt","w+t");
	if (a == NULL) {
		printf("Error");
		_getch();
		exit(0);
	}
	fopen_s(&b, "nameB.txt", "w+t");
	if (a == NULL) {
		printf("Error");
		_getch();
		exit(0);
	}
	fopen_s(&c, "nameC.txt", "w+t");
	if (a == NULL) {
		printf("Error");
		_getch();
		exit(0);
	}
	fopen_s(&d, "nameD.txt", "w+t");

	printf_s("Vvedite kol-vo chisel \n");
	//scanf_s("%d", &kol);
	while (!scanf_s("%d", &kol) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		printf ("Error!\n");
	}
	for (i = 0;i < kol;i++)
	{
		printf("vvedite %d-element file A\n",i+1);
		//scanf_s("%d",&A);
		while (!scanf_s("%d", &A) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			printf("Error!\n");
		}
		printf("vvedite %d-element file B\n", i + 1);
		//scanf_s("%d", &B);
		while (!scanf_s("%d", &B) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			printf("Error!\n");
		}
		printf("vvedite %d-element file C\n", i + 1);
		//scanf_s("%d", &C);
		while (!scanf_s("%d", &C) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			printf("Error!\n");
		}
		fprintf(a,"%d ",A);
		fprintf(b, "%d ", B);
		fprintf(c, "%d ", C);

		if (A >= B && A >= C) max = A;
		else if (B >= A && B >= C) max = B;
		else if (C >= A && C>=B) max = C;
		printf("Max element %d\n", max);
		fprintf(d, "%d ", max);
	}
	fclose(a);
	fclose(b);
	fclose(c);
	fclose(d);

	fopen_s(&d, "nameD.txt", "r+t");
	printf("Soderjimoe file\n");
		while (!feof(d)) {
			f = fgetc(d);
			fprintf(stdout, "%c", f);
		}
	fclose(d);
	return 0;
}

