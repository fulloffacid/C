#include "pch.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

int main()
{
	int *mas, i = 0, k=0, kol = 0, sum = 0, i_i = 0;
	do {
		printf_s("Vvedite kol-vo elementov massiva\n");
		scanf_s("%d", &k);
	} while (k >= 10);
	mas = new int[k];
	if (mas == NULL) {
		printf_s("Error");
		return 0;
	}

	for (i = 0;i < k;i++) {
		printf_s("Vvedite element [%d]\n", i + 1);
		scanf_s("%i", mas + i);
	}
	for (i = 0;i < k;i++) {
		if (*(mas + i) > 0) kol++;
	}
	printf_s("Kol-vo polojitel'nih chisel %d\n", kol);

	for (i = 0;i < k;i++)
		if (*(mas + i) == 0) i_i = i;

	for (i = i_i;i < k;i++) {
		sum += *(mas + i);
	}
	printf_s("Sum =  %d\n", sum);
	delete[]mas;

	return 0;
}
