#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,kol=0,n;
    float b[30],s=0,max,min;
    do{
       printf("Vvedite kol-vo elementov massiva (<30)\n");
       scanf("%d",&n);
    }while(n>=30);
    for(i=0;i<n;i++)
    {
        printf("Vvedite element [%d]\n",i+1);
        scanf("%f",b+i);
    }
    for(i=0;i<n;i++)
    s+=*(b+i);
    printf("Summa elementov matcici %.2f\n",s);

    max=*b;
    for(i=0;i<n;i++)
    if (*(b+i)>max)
    max=*(b+i);
    printf("Max element matcici %.2f\n",max);

    min=*b;
    for(i=0;i<n;i++)
    if (*(b+i)<min)
    min=*(b+i);
    printf("Min element matcici %.2f\n",min);

    return 0;
}
