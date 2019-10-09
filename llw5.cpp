#include "pch.h"
#include <iostream> 
#include <cstdlib> 
#include <ctime>
using namespace std;

struct List
{
	int info; 
	List *next = NULL, *prev = NULL;
}; 

void clearMemory(List **first, List **last)
{
	List *prev = *first, *cur = *first;
	while (cur) {
		cur = cur->next;
		delete prev;
		prev = cur;
	}
	*first = *last = NULL;
}

void addToBack(List** first, List **last, int value)
{
	List *temp = new List;
	temp->info = value;
	if (*first == NULL) {
		*first = *last = temp;
	}
	else {
		(*last)->next = temp;
		temp->prev = *last;
		*last = temp;
	}
}

void addToFront(List **first, List **last, int value)
{
	List *temp = new List;
	temp->info = value;
	if (*first == NULL) {
		*first = *last = temp;
	}
	else {
		(*first)->prev = temp;
		temp->next = *first;
		*first = temp;
	}
}

void print(List *startPoint, int dir = 0) 
{
	List *cur = startPoint;
	while (cur) {
		cout << cur->info << " ";
		cur = (dir ? cur->prev : cur->next); 
	}                                        
	cout << "\n";
}

void delFromBack(List **first, List **last)
{
	if (*first == *last)
	{
		delete *first;
		*last = NULL;
		return;
	}

	List *tmp = (*last)->prev;
	delete *last;
	*last = tmp;
	(*last)->next = NULL;
}

void delFromFront(List **first, List **last)
{
	if (*first == *last)
	{
		delete *first;
		*last = NULL;
		return;
	}

	List *tmp = (*first)->next;
	delete *first;
	*first = tmp;
	(*first)->prev = NULL;
}
/*void sortValues(List *first, List *last, int dir = 0)
{
	List *edge = NULL, *cur;
	int tmp;
	do {
		for (cur = first; cur->next != edge; cur = cur->next)
			if ((cur->info > cur->next->info) == !(bool)dir) {
				tmp = cur->info;
				cur->info = cur->next->info;
				cur->next->info = tmp;
			}
		edge = cur;
	} while (first->next != edge);
}
*/
void  individual(List **first, List **last)
{
	//addToBack((first), (last), 0); 
	//addToFront((first), (last), 0);
	int i = 0;
	int k = 0;
	List *p = *first;
	List *t;
	t = p;
	while (t <= *last)
		if (t->info < 0)
			k++;
	if (k == 0) cout << "otricatel'nogo net" << endl;
	else
	{
		while (t != *last) {
			if (t->info > 0) {
				cout << t->info << " ";
				t = t->next;
			}
			else {
				//k = 0;
				cout << t->info;
				break;
			}

		}
	} //while (k != 0);
	//if (k == 0) cout << "otricatel'nogo net" << endl;
}

void raz(List **first, List **last,int re)
{
List *p = *first;
List *t;
t = p->next;
while (t != *last) {
re++;
p = t;
t = t->next;
}
cout << re;

}

int main()
{
	List *_begin = NULL, *_end = NULL;
	srand((unsigned int)time(NULL));

	bool ok = true;
	while (ok) {
		int cmd;
		cout << "\t1 - add\n"
			"\t2 - print\n"
			"\t3 - clear memory\n"
			"\t4 - task\n"
			"\t5 - del\n"
			"\t6 - razmer\n"
			"\t0 - quit\n";
		cout << "\nyour choise ";
		cin >> cmd;
		int re = 2, kol = 0;
		int value;
		switch (cmd) {
		case 1:
			cout << "vvedite kol-vo elem ";
			cin >> kol;
			for (int i = 0; i < kol; i++) {
				cout << "\t\t1 - add to right\n"
					"\t\t2 - add to left\n";
				cout << "your choise ";
				cin >> cmd;
				cout << "value ";
				cin >> value;
				if (cmd == 1) addToFront(&_begin, &_end, value);
				else          addToBack(&_begin, &_end, value);
			}
			break;
		case 2:
			cout << "\t\t1 - print from right\n"
				"\t\t2 - print from left\n";
			cout << "your choise ";
			cin >> cmd;
			if (cmd == 1) print(_begin);
			else          print(_end, 1);
			break;
		/*case 3:
			cout << "\t\t1 - sort from beginning\n"
				"\t\t2 - sort from end\n";
			cout << "your choise ";
			cin >> cmd;
			if (cmd == 1) {
				sortValues(_begin, _end);
			}
			else sortValues(_begin, _end, 1);
			break;*/
		case 3: clearMemory(&_begin,&_end);
		case 4:
			individual(&_begin,(&_end));
			cout << endl;
			continue;
			break;
		case 0:
			ok = false;
			break;
		case 5:
			cout << "\t\t1 - del from right\n"
				"\t\t2 - del from left\n";
			cout << "your choise ";
			cin >> cmd;
			if (cmd == 1) delFromBack(&_begin, &_end);
			else          delFromFront(&_begin, &_end);
			break;
		case 6:cout << "razmer \n";
			raz(&_begin, &_end, re);
			//cout << re;
			break;
		default:
			cout << "unknown command\n\n";
			}
	}
	return 0;
}


