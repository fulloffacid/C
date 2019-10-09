#include "pch.h"
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

const double h = 0.0001;
FILE *file;

typedef double(*pointFunc) (double);
double f(double x) {
	return (2 * 1 / tan(x / 2));
}

double left_rectangle(pointFunc f, double a, double b) {
	double x;
	double sum = 0.0;
	double fx;
//	h = (b - a) / n; //шаг
//	for (int i = 0; i < n; i++) {
//		x = a + i * h;
	x = a - h;
	while (x < b) {
		x = x + h;
		fx = f(x)*h;
//	fx = f(x);
		sum += fx;
	}
	return(sum);//sum*h
}

double right_rectangle(pointFunc f, double a, double b) {
	double x;
	double sum = 0.0;
	double fx;
//    h = (b - a) / n; 
//    for (int i = 0; i < n; i++) {   
	for (x=a+h; x <=b; x=x+h) {
		fx = f(x)*h;
		sum += fx;
	}
	//	x = b + i * h;
	return(sum);
}

double middle_rectangle(pointFunc f, double a, double b) {
	double x;
	double sum = 0.0;
	double fx;
	//h = (b - a) / n; 
//    for (int i = 0; i < n; i++) {
//		x = a + h * i - h / 2;
	for (x = a; x < b; x = x + (0.5*h)) {
		x = (x + x + h) / 2;
		fx = f(x)*h;
		sum += fx;
	}
	return(sum);
}

double trapecium(pointFunc f, double a, double b) {
	double x1,x2;
	double sum = 0.0;
	double fx;
	//h = (b - a) / n;
	//for (int i = 0; i < n; i++) {
	//	x = a + i * h;
	//	sum = sum + f(x);
	//	sum = sum + 0.5*(f(a) + f(b))*h;
	for (x1 = a, x2 = a + h; x2 <= b; x1 = x1 + h, x2 = x2 + h) {
		fx = (f(x1) + f(x2)) / 2 * h;
		sum += fx;
	}
	return(sum);
}

int main() {
	fopen_s(&file, "vivod.txt", "w+");
	bool ok = true;
	double a, b;
	double s, s1, s2, s3, s4, srznach = 0.0;
	int k = 0;
	cout << "\nenter the left border a = ";
	cin >> a;
	cout << "\nenter the right border b = ";
	cin >> b;
	//cout << "\nenter required accuracy e = ";
	//cin >> e;
	while (ok) {
		//int n = 1;
		int kod;
		cout << "\t1 - method of the left rectangle\n"
			"\t2 - method of the right rectangle\n"
			"\t3 - method of the middle rectangle\n"
			"\t4 - method of trapezium\n"
			"\t5 - view average\n"
			"\t6 - relative error\n"
			"\t7 - table\n"
		   // "\t8 - read file\n"
			"\t0 - quit\n";
		cout << "\nyour choise ";
		cin >> kod;

		switch (kod) {
		case 1:
			s1 = left_rectangle(f, a, b); //первое приближение для интеграла
			cout << "\nintegral = " << s1 << endl;
			k++;
			break;
		case 2:
			s2 = right_rectangle(f, a, b); 
			cout << "\nintegral = " << s2 << endl;
			k++;
			break;
		case 3:
			s3 = middle_rectangle(f, a, b);
			cout << "\nintegral = " << s3 << endl;
			k++;
			break;
		case 4:
			s4 = trapecium(f, a, b);
			cout << "\nintegral = " << s4 << endl;
			k++;
			break;
		case 5:
			if (k == 4) {
				srznach = (s1 + s2 + s3 + s4) / 4;
				cout << "srednee znachenie: " << srznach << endl;
				k++;
			}
			else cout << "srednee znachenie ne naideno\n";
			break;
		case 6:
			if (k == 5) {
				cout << "Max average of the first method: " << (fabs(srznach - s1)) / s1 << endl;
				cout << "Max average of the second method: " << (fabs(srznach - s2)) / s2 << endl;
				cout << "Max average of the third method: " << (fabs(srznach - s3)) / s3 << endl;
				cout << "Max average of the fourth method: " << (fabs(srznach - s4)) / s4 << endl;
				k++;
			}
			else cout << "srednee znachenie ne naideno\n";
			break;
		case 7:
			if (k == 6) {
				printf("\t ----------------------------\n"
					"\t |   table  of     integral |\n"
					"\t |--------------------------|\n"
					"\t | integral   |    error    |\n"
					"\t |------------|-------------|\n"
					"\t1|  %.5f   | %.5f     |\n"
					"\t2|  %.5f   | %.5f     |\n"
					"\t3|  %.5f   | %.5f     |\n"
					"\t4|  %.5f   | %.5f     |\n"
					, s1, (fabs(srznach - s1)) / s1, s2, (fabs(srznach - s2)) / s2, s3, (fabs(srznach - s3)) / s3, s4, (fabs(srznach - s4)) / s4);
				
				fprintf(file, "\t ----------------------------\n"
					"\t |   table  of     integral |\n"
					"\t |--------------------------|\n"
					"\t | integral   |    error    |\n"
					"\t |------------|-------------|\n"
					"\t1|  %.5f   | %.5f     |\n"
					"\t2|  %.5f   | %.5f     |\n"
					"\t3|  %.5f   | %.5f     |\n"
					"\t4|  %.5f   | %.5f     |\n"
					, s1, (fabs(srznach - s1)) / s1, s2, (fabs(srznach - s2)) / s2, s3, (fabs(srznach - s3)) / s3, s4, (fabs(srznach - s4)) / s4);
			}
			else cout << "errors ne naideni\n";
				break;
		//case 8:
		//	fscanf(file, "%s", );
		//	break;
		case 0:
			ok = false;
			break;
		default:
			cout << "unknown command\n\n";
		}
	}
	return 0;
}

