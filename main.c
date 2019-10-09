#include <stdio.h>
#include <conio.h>

int main()
{
   int n,m,i,j,i1=0,i2=0,j1=0,j2=0;
   float A[100][100],s=0,max,min,c=0;
  printf("Vvedite kol-vo strok i slolbcov matrici\n");
  scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      {
        printf("Vvedite elementi A[%d%d]\n",i+1,j+1);
        scanf("%f",&A[i][j]);
      }

   for(i=0;i<n;i++)
   for(j=0;j<m;j++)
    {
        if (i==j && n==m) s+=A[i][j];
    }
   if(s!=0) printf("Sum elementov na glavnoi diagonali = %.1f\n",s);
    else printf("Matrica nekvadratnaia\n");

    printf("MATRICA\n");
    for (i=0;i<n;i++){
        for (j=0;j<m;j++)
        printf("%.2f ", A[i][j]);
    printf("\n");
}


  for(i=0;i<n;i++){
   max=A[i][0];
   min=A[i][0];
   for(j=0;j<m;j++){
        if(max<=A[i][j]){
        max=A[i][j];
        i1=i;
        j1=j;}
   // printf("Max element %d stroki = %.2f\n",i+1,max);

        if(A[i][j]<=min){
        min=A[i][j];
        i2=i;
        j2=j;}
    //printf("Min element %d stroki = %.2f\n",i+1,min);
}
     printf("Max->Min\n");
     c=A[i1][j1];
     A[i1][j1]=A[i2][j2];
     A[i2][j2]=c;
  }
 for(i=0;i<n;i++) {
     //c=0;i1=0;i2=0;j1=0;j2=0;
     for(j=0;j<m;j++)
     printf("%.2f ",A[i][j]);
      printf("\n");
}
}
