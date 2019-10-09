#include "pch.h"
#include<iostream>
#include<cstring>
#include<string.h>
#include<iomanip>
#include<stdio.h.>
#include<fstream>
#include <Windows.h>
#include<conio.h>
using namespace std;
const int MWORD = 30;           //макс длина слова

struct Link
{
	char word[MWORD];  //слово
	Link* next;        //указатель на следующее звено
	Link* prev;        //указатель на предыдущее звено
};
///////////////////////////////////////////////////////////////
class LinkList
{
private:
	Link* first;
	Link* last;
public:
	LinkList()             //конструктор
	{
		first = NULL;
		last = NULL;
	}
	//---------------------------------------------------
	~LinkList()            //деструктор
	{
		while (first != last)
		{
			Link*temp = first;
			first = first->prev;
			delete temp;
		}
		delete last;
	}
	//---------------------------------------------------
	void pushback(char* str)        //добавление данных в список
	{
		Link* newlink = new Link;
		strcpy_s(newlink->word, str);

		if (first)
		{
			newlink->prev = first;
			first->next = newlink;
		}

		else
			last = newlink;

		newlink->next = last;
		last->prev = newlink;
		first = newlink;
	}
	//---------------------------------------------------
	void pushfront(char* str)        //добавление данных в список
	{
		Link* newlink = new Link;
		strcpy_s(newlink->word, str);

		if (last)
		{
			newlink->next = last;
			last->prev = newlink;
		}

		else
			first = newlink;

		newlink->prev = first;
		first->next = newlink;
		last = newlink;
	}
	//----------------------------------------------------
	void showList_front()             //показать список с начала
	{
		Link* temp = last;
		if (first)
			do
			{
				cout << temp->word << endl;
				temp = temp->next;
			} while (temp != last);

	}
	//---------------------------------------------
	void showList_back()             //показать список с конца
	{
		Link* temp = first;
		if (first)
			do
			{
				cout << temp->word << endl;
				temp = temp->prev;
			} while (temp != first);
	}
	//--------------------------------------------------
	char* popfront()   //вытолкнуть первое звено из списка
	{
		Link* temp = first;
		deleteLink(first);
		return temp->word;

	}
	//------------------------------------------------------
	char* popback()                //вытолкнуть последнее звено из списка
	{
		Link* temp = last;
		deleteLink(last);
		return temp->word;
	}
	//--------------------------------------------
	void deleteLink(Link* temp)   //удаление звена из списка
	{
		if (first)                   //если в списке есть данные
		{
			if (temp->next == temp)    //если в списке единственный элемент
			{
				first = NULL;
				last = NULL;
			}
			else
			{
				if (temp == last)     //если эдемент на удаление последний
					last = last->next;

				if (temp == first)     //если элемент на удаление первый
					first = first->prev;

				(temp->next)->prev = temp->prev;
				(temp->prev)->next = temp->next;

				delete temp;
			}
		}
	}
	//--------------------------------------------------------
	Link* find_data(char* dt)           //найти данные в списке
	{
		Link* temp = first;
		if (first)
			do
			{
				if (strcmp(dt, temp->word) == 0)
					return temp;

				temp = temp->prev;
			} while (temp != first);

			temp = NULL;
			return temp;
	}
	//-----------------------------------------------
	void sortlist()                        //сортитровка списка
	{
		char tempdata[100];
		Link* temp1 = first;

		int n = howmany_links();

		for (int x = 0; x < n - 1; x++)
		{
			Link* temp2 = temp1->prev;

			for (int i = x; i < n - 1; i++)
			{
				if (strcmp(temp1->word, temp2->word) > 0)
				{
					strcpy_s(tempdata, temp2->word);
					strcpy_s(temp2->word, temp1->word);
					strcpy_s(temp1->word, tempdata);
				}

				temp2 = temp2->prev;
			}
			temp1 = temp1->prev;
		}
	}
	//------------------------------------------------
	LinkList operator=(LinkList& l)       //перегрузка оператора =
	{
		if (l.first)
		{
			Link* temp = l.first;
			do
			{
				pushfront(temp->word);
				temp = temp->prev;
			} while (temp != l.first);
		}

		return *this;
	}
	//--------------------------------------------------
	int howmany_links()             //посчитать звенья в списке
	{
		if (first)
		{
			Link* temp = first;
			int i = 0;
			do
			{
				temp = temp->prev;
				i++;
			} while (temp != first);

			return i;
		}
		else
			return 0;

	}
	//-------------------------------------------------
	void clear()            //очистить список
	{
		while (first->prev != last)
		{
			Link*temp = first->prev;
			first = first->prev;
			delete temp;
		}
		last = NULL;
		first = NULL;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LinkList li;
	char** mass = NULL;
	int mass_size = 0;
	char menu;

	while (true)
	{
		cin.sync();
		cout << "\nВыберите действие:"
			<< "\n1 - дополнить список"
			<< "\n2 - показать список(начиная с последнего звена)"
			<< "\n3 - удалить элемент из списка"
			<< "\n4 - копировать элементы списка в массив"
			<< "\n5 - сортировать список"
			<< "\n6 - найти элемент в списке"
			<< "\n7 - считывания данных из файла в список"
			<< "\n8 - сохранение списка в файл"
			<< "\n9 - очистить список"
			<< "\nВаш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case '1':
		{
			char data[MWORD];
			cout << "\nВведите данные:\n";
			cin >> data;
			li.pushfront(data);
			break;
		}
		case '2':
		{
			if (li.howmany_links() != 0)    //если список создан
			{
				cout << "\nCписок начиная с последнего звена: " << endl;
				li.showList_back();      //показать список
			}
			else
				cout << "\nСписок пуст" << endl;
			break;
		}
		case '3':
		{
			char data[MWORD];
			if (li.howmany_links() != 0)
			{
				cout << "\nВведите данные которые хотите удалить" << endl;
				cin >> data;
				Link* d = li.find_data(data);
				if (d)
					li.deleteLink(d);
				else
					cout << "\nДанных нет в списке" << endl;
			}
			else
				cout << "\nСписок пуст" << endl;
			break;
		}
		case '4':
		{
			LinkList li2;
			li2 = li;
			if (mass)                   //удаление предыдущего массива
				for (int i = 0; i < mass_size; i++)
					delete[]mass;

			mass_size = li.howmany_links();
			if (mass_size)
			{
				LinkList li2;
				li2 = li;
				mass = new char*[mass_size];
				for (int i = 0; i < mass_size; i++)
					mass[i] = new char[MWORD];

				//for (int i = 0; i < mass_size; i++)
					//strcpy_s(mass[i], li2.popfront());

				for (int i = 0; i < mass_size; i++)
					cout << mass[i] << "  ";
			}
			else
				cout << "\nСписок не создан" << endl;
			break;
		}
		case '5':
		{
			li.sortlist();
			cout << "\n";
			li.showList_back();
			break;
		}
		case '6':
		{
			char data[MWORD];
			cout << "\nВведите данные которые необходимо найти" << endl;
			cin >> data;
			if (li.find_data(data))
				cout << "\nДанные есть в списке" << endl;
			else
				cout << "\nДанных нет в списке" << endl;
			break;
		}
		case '7':
		{
			cin.sync();
			char adres[MWORD];
			char ch;
			char data[MWORD];

			cout << "\nВведите адрес файла: ";
			cin >> adres;
			ifstream fail(adres);
			if (fail)
				while (fail)
				{
					fail.get(ch);
					int y = 0;
					for (; isalpha((unsigned char)ch) && fail; fail.get(ch))
						data[y++] = ch;
					data[y] = ' ';

					if (y)
						li.pushfront(data);
				}
			else
				cout << "\nНевозможно открыть файл!\n";
			break;
		}
		case '8':
		{
			cin.sync();
			char adres[MWORD];
			LinkList li2;
			li2 = li;

			cout << "\nВведите адрес файла: ";
			cin >> adres;
			ofstream fail(adres);
			for (int i = 0; i < li.howmany_links(); i++)
				fail << li2.popback() << " ";
			break;
		}
		case '9':
		{
			li.clear();
			break;
		}

		case '0':
		{
			for (int i = 0; i < mass_size; i++)
				delete[]mass;
			return 0;
		}
		default:
			cout << "\nНеизвестное действие\n";
		}
	}

	return 0;
}
