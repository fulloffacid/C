﻿#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <io.h>
#include <iostream>
using namespace std;

struct Stack {
	int info;
	Stack*next;
}*t, *big;

Stack* InStack(Stack*p, int in) {
	Stack *t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}

void View(Stack*p) {
	Stack *t = p;
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
	}
}

Stack* OutList(Stack* p, int *out) {
	Stack *t = p;
	*out = p->info;
	p = p->next;
	delete t;
	return p;
}
void Del_All(Stack **p) {
	Stack *t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

Stack* Del_0(Stack *b)
{
	b = InStack(b, 21);
	Stack *p = b;
	t = p->next;
	while (t != NULL) {
		int k = 1;
		if (t->info == 0) {
			p->next = t->next;
			delete t;
			t = p->next;
		}
		else {
			p = t;
			t = t->next;
		}
	}
	t = b;
	b = b->next;
	delete t;
	return b;
}

void main()
{
	//srand(time(NULL));
	int in, i, n, kod;
	while (true) {
		cout << "\n\tCreat - 1.\n\tAdd - 2.\n\tView - 3.\n\tDel - 4.\n\tEXIT - 0.\n\tPoisk and del-5.\n  ";
		cin >> kod;
		switch (kod) {
		case 1: case 2:

			if (kod == 1 && big != NULL) {
				cout << "Clear Memory!" << endl;
				break;
			}
			cout << "Input kol =  ";         cin >> n;
			for (i = 1; i <= n; i++) {
				//in =-1 + rand() % 5;
				cin >> in;
				big = InStack(big, in);
				//cout <<"  "<< in;
			}
			//if (kod == 1) cout << "Create " << n << endl;
			//else cout << "Add " << n << endl;
			break;
		case 3:         if (!big) {
			cout << "List Empty!" << endl;
			break;
		}
						cout << "--- List ---" << endl;
						View(big);
						break;
		case 4:
			Del_All(&big);
			cout << "Memory Free!" << endl;
			break;

		case 0:
			if (big != NULL)
				Del_All(&big);
			return;

		case 5:

			big = Del_0(big);
		}
	}
}
