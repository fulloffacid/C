#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a,b,c,obr,i;
    for (i=400;i<=500;i++){

        a=i/100;
        b=(i-a*100)/10;
        c=i-a*100-b*10;

        obr=c*100+b*10+a;

    if((a+b+c)==9 && i==(obr*47/36))
        printf("RESULT %d\n",i);
    }
    return 0;
}
