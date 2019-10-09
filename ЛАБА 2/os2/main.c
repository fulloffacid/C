#include <stdio.h>
#include <math.h>

void main()
{
    float a,b,c;
    printf("Vvedite znachenia M(a,b)\n");
    scanf("%f%f",&a,&b);
    c=sqrt(a*a+b*b);
    if (b>0 && c<1) printf("Tochka nahoditsa vnutri\n");
     else printf("Tochka ne v nutri");
    return 0;
}
