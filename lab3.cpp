#include "pch.h"
#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;

  int main()
{
  setlocale(LC_ALL, "Russian");
  int kol, i;
 
  char str[1000];//string, ster[20][20];
  char **ptr;

  cout <<"Введите кол-во строк в массиве"<<endl;
  cin >> kol;
  ptr = new char*[kol];

  if (str == 0)
  {
	  cout << "Ошибка" << endl;
	  exit(1);
  }

 cout << "Введите массив символов" << endl;
 /* for (i = 0; i < kol; i++) {
	  fgets(str, 20, stdin);
	 // gets_s(str);
	 // cout << endl;
  }*/



  for (int i = 0; i < kol; i++) {
	  do {
		  cin >> str;
		//  strlen(ptr[i]) == strlen(ptr[i + 1]);
		  int len = strlen(str);
		  ptr[i] = new char[len + 1];
		  strcpy_s(ptr[i],50, str);
	  } while (sizeof(ptr[0])!=sizeof(str));
  }
  cout << endl;
  for (i = kol-1; i > -1; i--) {
	  cout << ptr[i] << endl;
  }
 // for (i = 0; i <kol; i++) {
	// delete[] ptr[i];
  //}
  delete[] ptr;
  return 0;
}
  


