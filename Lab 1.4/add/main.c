#include <stdio.h>
#include <conio.h>

int main()
{
    int A[100],B[100],m,n,k,i,j,a,b=0;
    printf("Vvedite kol-vo elementov massiva A\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("A[%i] ",i+1);
        scanf("%i",&A[i]);
    }
    printf("Vvedite kol-vo elementov massiva B\n");
    scanf("%d",&m);
    for(j=0;j<m;j++){
        printf("B[%i] ",j+1);
        scanf("%i",&B[j]);
    }
    for(j=0;j<m;j++){
         k=0;
        for(i=0;i<n;i++){
        if(B[j]==A[i]) {k=1;break;
        }
     }

     if(k==0) { printf("%d  ",B[j]);
     }
    }

    return 0;
}
