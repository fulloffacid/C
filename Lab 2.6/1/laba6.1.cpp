#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <io.h>
using namespace std;

struct Stack {
	char info;
	Stack*next;
} *big, *t;

Stack* InStack(Stack*p, char inn) {
	Stack *t = new Stack;
		t->info = inn;
		t->next = p;
		return t;
	
}

void View(Stack*p) {
	Stack *t = p;
	int o = 0;
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
		o++;
	}
	cout << "Size of stack= " << o << endl;
}

Stack* OutStack(Stack* p, char *out) {
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

Stack* Del_1_3_5(Stack *b)
{
	b = InStack(b, 21);	   
	Stack *p = b;
	t = p->next;
	int k = 1;           
	while (t != NULL) {
		if (k == 1 || k == 3 || k == 5) {
			p->next = t->next;
			delete t;
			t = p->next;
		}
		else {
			p = t;
			t = t->next;
		}
		k++;
	}
	t = b;			
	b = b->next;
	delete t;
	return b;
}

int main()
{
	srand(time(NULL));
	int  i, n, kod;
	char in, etalon; int l = 0,q=0;
	while (true) {
		cout << "\n\tcreat stack - 1.\n\tadd to stack- 2.\n\tview stack - 3.\n\tdelete all stack - 4.\n\texit - 0. ";
		cout << "\nyour choice :";
		cin >> kod;
		switch (kod) {
		case 1: case 2:
			if (kod == 1 && big != NULL) {
				cout << "Clear Memory!" << endl;
				break;
			}
			cout <<"Enter etalonni symbol"<<endl;

			cin >> etalon;
			cout << "Razmer:";
			cin >> n;
			cout << "Enter elements of stack" << endl;
			for (i = 1; q!=-1,i<=n; i++) {
				cin >> in;
				if (in == etalon) {q = -1; break;}
				else
					big = InStack(big, in); l++;
				//cout << in;
			}
			if (kod == 1) cout << "create elements " << l << endl;
			else cout << "add elemets " << l << endl;
			break;
		case 3:         if (!big) {
			cout << "Stack is empty!" << endl;
			break;
		}
						cout << "------// Stack //------" << endl;
						View(big);
						break;
		case 4:
			Del_All(&big);
			cout << "Memory Free!" << endl;
			break;
		case 0:
			if (big != NULL)
				Del_All(&big);
			return  0;		

		//case 5:

			//big = Del_1_3_5(big);
		}
	}
	return 0;
}
