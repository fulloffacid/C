#include "pch.h"
#include <iostream>
#include <stdio.h>
using namespace std;

double factorial(double n);
double summa(double n);

double factorial(double n)
{
	if (n == 0) 
		return 1;
	else 
		return n * factorial(n - 1);
}

double summa(double n) {
	if (n == 0)
		return 1;
	else
		return 1 / factorial(n);
}

int main()
{
	int n, i;
	double sum = 0;
	cout << "Enter the number:";
	cin >> n;
	for (i = 0; i <= n; i++)
		sum += summa(i);

	cout <<"The amount of row"<<endl;
	cout << sum;
	return 0;
}
