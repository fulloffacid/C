#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int *b,i,j,n,buf;
    printf("Vvedite kol-vo elementov massiva\n");
    scanf("%d",&n);
    b=new int[n];
     for (i=0;i<n;i++)
    {
     printf("Vvedite element[%d]\n",i+1);
     scanf("%d",b+i);
    }
     printf("\nIshodnii massiv: \n",i+1);
     for (i=0;i<n;i++)
      printf("%d ",*(b+i));
     for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
        if(*(b+j)>*(b+j+1))
     {
         buf=*(b+j);
         *(b+j)=*(b+j+1);
         *(b+j+1)=buf;

     }
     printf("\n Otsortirovani massiv \n",i+1);
     for(i=0;i<n;i++)
        printf("%d ",*(b+i));

}
