#include <stdio.h>
#include <conio.h>

int main()
{
    float mas[100],max,min,sum=0,pr=1,c=0;
    int i,n,i1 = 0,i2 = 0;
    printf("Vvedite kolichestvo elementov massiva\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("mas[%d] ",i+1);
        scanf("%f",&mas[i]);
    sum+=mas[i];
    pr*=mas[i];

    }
    min=mas[0];
    for(i=1;i<n;i++) {
    if (min>mas[i]){
    min=mas[i];
    i1=i; }
    }
    printf("Min element %.2f\n",min);



    max=mas[0];
    for(i=1;i<n;i++) {
    if (max<mas[i]){
    max=mas[i];
    i2=i;}
    }
    printf("Max element %.2f\n",max);
     c = mas[i1];
        mas[i1]= mas[i2];
    mas[i2]=c ;
 for(i=0;i<n;i++){

printf("%.2f ",mas[i]);
   }




    //printf("Sum = %.2f\n",sum);
   // printf("Pr = %.2f\n",pr);

    return 0;
}
