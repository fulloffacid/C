#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5][5],i,j,n=0,m=0,r=0;
    printf("Vvedite kol-vo strok i stolbcov n \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        printf("Vvedite element a[%d%d]\n",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    printf("\n");


    printf(" Matrica \n");
    for(i=0;i<n;i++){
     for(j=0;j<n;j++)
        printf(" %d " ,a[i][j]);
    printf("\n");
    }

   for(i=0;i<n-1;i++){
   for(j=i;j<n;j++){
        if (a[i][j]>a[i][j+1]){
            r=a[i][j];
            a[i][j]=a[i][j+1];
            a[i][j+1]=r;
        }
        }
   }





    printf(" Matrica \n");
    for(i=0;i<n;i++){
     for(j=0;j<n;j++)
        printf(" %d " ,a[i][j]);
    printf("\n");
    }
    return 0;
}
