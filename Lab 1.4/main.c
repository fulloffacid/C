#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[100],i02=-2,n,k,i,j,i01=-2,sum=0;
    printf("Vvedite kol-vo elementov massiva A\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("A[%d]= ",i+1);
        scanf("%i",&A[i]);
    }

    for (i = 0; i < n; i++) //поиск первого 0
        if (A[i] ==0){
            i01 = i;
            break;
    }
    if ( i01 < 0 ) {
            printf("Not 0");
    return;
    }
    if ( i01 == 0 ) {
         printf("First 0");
     return;
    }
    for(sum=i=0; i<i01;i++)
        sum += A[i];
    printf("Sum= %d",sum);

    for (i = n-1; i >= 0; i--) //поиск последнего нуля с конца
         if (A[i] ==0){
            i02 = i;
            break;
    }
    if ( i02== n-1 ) {
             printf("Last 0");
     return;
    }
    for(sum = 0,i=i02+1;i<n;i++)
         sum += A[i];
    printf("Sum= %d",sum);

    for(sum = 0, i=i01+1; i<i02;i++)
        sum += A[i];
    printf("Sum= %d",sum);

    return 0;
}
