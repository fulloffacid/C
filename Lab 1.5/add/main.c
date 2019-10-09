#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int a[5][5],i,j,n,m,sum=0;
    int b,r=0;
    printf("Vvedite kol-vo strok i stolbcov n i m \n");
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    for(j=0;j<m;j++){
        printf("Vvedite element a[%d%d]\n",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    printf("\n");



        for(i=0;i<n;i++){
        for(j=m-1;j>0;j--){
         if (j>i ) sum+=a[i][j];
         }
        }
     printf(" Summa %d\n",sum);
    // if (n!=m) printf(" Glavnoi diagonali net \n");

    for (j=0;j<m;j++){
        r=0;
     for (i=0;i<n;i++){

     // for (a=j;a<m;a++)
        for(b=i+1;b<n;b++){
        if(a[i][j]<=a[b][j]) r++;
     }
     }
        if(r==n) printf("Stolbec %d uporiadochen\n",j+1);
        else printf("Stolbec %d ne uporiadochen\n",j+1);

    }


     printf(" Matrica \n");
     for(i=0;i<n;i++){
    for(j=0;j<m;j++)
        printf(" %d " ,a[i][j]);
    printf("\n");

    }
    return 0;
}
