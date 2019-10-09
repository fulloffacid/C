#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
//#include <ctime>
using namespace std;
struct Stack {
	char info;
	Stack*next;
} *big, *t;
Stack* InStack(Stack*p, char in) {
	Stack *t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}
/*
Stack* Inf(Stack*p,int in,int out)
{Stack *t = p;
while (t != NULL) {
	out = t->info;
	t = t->next;
}
}
*/
void View(Stack*p) {
	Stack *t = p;
	while (t != NULL) {
		printf("%s  ",t->info);;
		t = t->next;
	}
}
/*int View222(Stack*p, int v, int i) {
	Stack *t = p;
	v = t->info;
	t = t->next;
	return v;
	if (--i > 0)
		View222(p, v, i);
}*/
char  OutStack(Stack **p) {
	char  out;
	Stack *t = *p;
	out = (*p)->info;
	*p = (*p)->next;
	delete t;


	return out;
}

int main(int argc, char* argv[])
{
	//srand(static_cast<unsigned int>(time(NULL)));
	FILE *fp;
	char name1[30], name2[30], ns = '\n';
	int N, i = 0, k = 0;
	
	char in,x,in;


	printf("\n Vvedite imya file: ");
	cin >> name1;
	fopen_s(&fp, name1, "w+");
	if (fp == NULL)
	{
		printf("\n File ne sozdan\n");
		return 0;
	}
	printf("\n Vvedite N>1, N= ");
	cin >> N; // g = new int[N];
	//c = new int[7];
	int r = N / 3;
	for (i = 1; i <= N; i++) {
		//x = -10 + rand() % 20;
		
		scanf("%s,", &x);
		//if (TryStrToInt(String(ch), num))
		//static_cast<int>(x);
			fprintf(fp, "%s,", x);

	}
	fclose(fp);
	fopen_s(&fp, name1, "r+");
	//rewind(fp);
	//fseek(fp, 0, SEEK_SET);
	//while ((fscanf(fp, "%d", &g) != EOF))
	//{if (!fp) break;    //чтобы не делал лишнего
		// k++;}
	//int *c;
	char* c = new char[15];

	//string *c = (string*)malloc(N * sizeof(string));  //должен быть динамическим

	//rewind(fp);    //перематываем файл для повторного чтения
	for (i = 1; i <= N; i++)
	{
		//static_cast<int>(c[i]);

		fscanf(fp, "%s", &c);
		in = *c;
		big = InStack(big, in);
		printf("c[]=%s  ", c);
	}

	/*for (i =0;i < N;i++) {
		fscanf_s(fp,"%d",&p);
		// strncpy(g,in,1);
		//in = g;
		//fread(&p,sizeof(int), N, fp);
		//int in = *y;

	}cout << p;	*/

	/*if (!big)
		cout << "Stack Pyst!" << endl;
	else {
		cout << "--- Stack ---" << endl;
		View(big);
	}
	*/
	for (i = 1; i <= N ; i++) {
		in = c[i];
		big = InStack(big, in);
	}
	if (!big)
		cout << "Stack Pyst!" << endl;
	else {
		cout << "--- Stack ---" << endl;
		View(big);
	}
	//free(c);
	fclose(fp);

	printf("\n Vvedite imya file: ");
	cin >> name2;
	fopen_s(&fp, name2, "w+");
	if (fp == NULL)
	{
		printf("\n File ne sozdan\n");
		return 0;
	}
	string out;
	//int v = 0;
	//int l = N;
	for (i = 1; i <= N; i++) {
		out = OutStack(&big);//z = View222(big,v,l);
		
		
				fprintf(fp, "%s", out);
				//	fprintf(fp, "%c", ',');
				//	fprintf(fp, "%c", '\n');
	}
	fclose(fp);
	return 0;
}