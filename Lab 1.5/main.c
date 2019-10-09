#include <stdio.h>
#include <conio.h>

int main()
{
     int a[20][20],i,j,n,k,p=0;
    printf("Vvedite kol-vo strok i stolbcov kvadratnoi matrici\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        printf("Element [%d,%d] ",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
     printf("Matrica\n");
    for(i=0;i<n;i++){
      for(j=0;j<n;j++)
        printf(" %d  ",a[i][j]);
        printf("\n");
    }
    for(i=0;i<n;i++){
        k=0;
      for(j=0;j<n;j++){
        if (a[i][j]==0) k++;
      }
      if (k==3) p=i;break;
    }

      for(j=0;j<n;j++){
        a[j][p]/=2;
      }
      printf("Matrica 2\n");
    for(i=0;i<n;i++){
      for(j=0;j<n;j++)
        printf(" %d  ",a[i][j]);
        printf("\n");
    }


    return 0;
}
