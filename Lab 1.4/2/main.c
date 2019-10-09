#include <stdio.h>
#include <conio.h>

int main()
{
    int mas[100],i,k,kol=0,sum=0,i_i=0;
    printf("Vvedite kol-vo elementov massiva \n");
    scanf("%d",&k);
    for(i=0;i<k;i++){
        printf("mas[%i] ",i+1);
        scanf("%i",&mas[i]);
    }
    for(i=0;i<k;i++){
    if(mas[i]>0) kol++;
    }
printf("Kol-vo polojitwl'nih chisel %d\n",kol);

    for(i=0;i<k;i++){
    if(mas[i]==0) i_i=i;
    }
    for(i=0;i<i_i;i++){
    sum+=mas[i];
    }
printf("Sum = %d",sum);
    return 0;
}
