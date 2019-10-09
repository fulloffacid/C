#include "pch.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int chislo(int n) {
	//int max = 0;
	if (n < 10)
	{
		//if (max < n) max = n;
		return n;
	}
	else //{
		//if (max < chislo(n / 10)){ max = chislo(n / 10);
		return chislo(n / 10);
	//}
		//else return chislo(n / 10);
}


int main()
{
	int number = 0;
	do {
		cout << "Enter the number: " << endl;
		cin >> number;
		if (number <= 0) cout <<"Enter positive value"<< endl;
		else
		{
			cout << "The senior level: " << endl;
			cout << chislo(number);
		}
	} while (number < 0);
	return 0;
}
