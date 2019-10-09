#include <stdio.h>
#include <conio.h>

int main()
{
    int a[20][20],i,j,n,pr,k=0;
    printf("Vvedite kol-vo strok i stolbcov kvadratnoi matrici\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        printf("Element [%d,%d] ",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++){
     pr=1;k=0;
     for(j=0;j<n;j++){
        pr*=a[i][j];
        if (a[i][j]<0) k--;}
        if(k==0) printf("Proizvedenie %d stroki %d\n",i+1,pr);
     //else if(pr=1)  printf("Stroka soderjit vse otricatel'nie znachenia");
    }


    int sum1=0,sum2=0,r,max=0;
    int size=n;
    for (r=0;r<n;r++){
        for(i=0;i<size;i++){
                if (i!=i+r){
            sum1=sum1+a[i][i+r];
            sum2=sum2+a[i+r][i];
            printf("Elem1 %d \n",a[i][i+r]);
            printf("Elem2 %d \n",a[i+r][i]);
        }
        }
        if (sum1>max) max=sum1;
        if (sum2>max) max=sum2;
        printf("Sum1 %d \n",sum1);
        printf("Sum2 %d \n",sum2);
        size=size-1;
        sum1=0;
        sum2=0;
    }
 printf("Maximum %d \n",max);


    printf("Matrica\n");
    for(i=0;i<n;i++){
      for(j=0;j<n;j++)
        printf(" %d  ",a[i][j]);
        printf("\n");
    }


    return 0;
}
