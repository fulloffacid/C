#include <stdio.h>

void main()
{
    int a,b,c;
    printf("Menu\n");
    printf("1-Slojenie +\n");
    printf("2-Vichitanie -\n");
    printf("3-Umnojenie *\n");
    printf("4-Delenie /\n");
    printf("5-Ostatok % \n");
    printf("6-Exit\n");
    scanf("%d",&c);
    printf("Vvedite 2 chisla\n");
    scanf("%d%d",&a,&b);
    switch(c)
    {
    case 1: printf("Summa ravna %d\n",a+b);
            break;
    case 2: printf("Raznost' ravna %d\n",a-b);
            break;
    case 3: printf("Proizvedenie ravno %d\n",a*b);
            break;
    case 4: printf("Chastnoe ravno %d\n",a/b);
            break;
    case 5: printf("Ostatok raven %d\n",a%b);
            break;
    case 6: return; break;

    default: printf("Nevernoe znachenie");
    }
}
