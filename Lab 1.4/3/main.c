#include <stdio.h>
#include <conio.h>

int main()
{
    int A[100],B[100],m,n,max,i,j,a,b=0;
    printf("Vvedite kol-vo elementov massiva A\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("A[%i] ",i+1);
        scanf("%i",&A[i]);
    }
    max=A[0];
    for(i=1;i<n;i++)
    if(max<A[i]) max=A[i];
    printf("Max chislo = %i\n",max);

    printf("Vvedite kol-vo elementov massiva B\n");
    scanf("%d",&m);
    for(j=0;j<m;j++){
        printf("B[%i] ",j+1);
        scanf("%i",&B[j]);
    }
    for(j=0;j<m;j++){
    if(B[j]==max) b++;
}
   if(b!=0) printf("Element vstrechaetsa %d times\n",b);
     else printf("Elementa net\n");

return 0;
}
