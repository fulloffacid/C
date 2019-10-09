#include "pch.h"
#include "conio.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"


int main()
{
	int i = 0, j = 0, n, **a, pr = 1, k = 0, sum1 = 0, sum2 = 0, max = 0;
	printf_s("Vvedite kol-vo strok i stolbcov kvadratnoi matrici\n");
	scanf_s("%d", &n);
	a = new int*[n];
	for (i = 0;i < n;i++) {
		a[i] = new int[n];
	}
	if (a == NULL) {
		printf_s("Error");
		return 0;
	}

	for (i = 0;i < n;i++)
		for (j = 0;j < n;j++) {
			printf_s("Element [%d%d]\n", i + 1, j + 1);
			scanf_s("%d", (*(a + i) + j));
		}
	for (i = 0;i < n;i++) {
		pr = 1;k = 0;
		for (j = 0;j < n;j++) {
			pr *= *(*(a + i) + j);
			if (*(*(a + i) + j) < 0) k--;
		}
		if (k == 0) printf_s("Proizvedenie %d stroki %d\n", i + 1, pr);
	}


	for (i = 1;i < n;i++) {
		for (j = 0;j < n - i;j++) {
			sum1 = sum1 + *(*(a + i + j) + j);
			sum2 = sum2 + *(*(a + j) + i + j);
			printf_s("Elem1 %d \n", *(*(a + i + j) + j));
			printf_s("Elem2 %d \n", *(*(a + j) + i + j));
		}

		if (sum1 > max) max = sum1;
		if (sum2 > max) max = sum2;
		printf_s("Sum1 %d \n", sum1);
		printf_s("Sum2 %d \n", sum2);

		sum1 = 0;
		sum2 = 0;
	}
	printf_s("Maximum %d \n", max);


	printf_s("Matrica\n");

	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++)
			printf_s(" %i  ", *(*(a + i) + j));
		printf_s("\n");
	}


	for (i = 0;i < n;i++)
		delete[]a[i];
	delete[]a;
	return 0;
}
