#include <stdio.h>
#include <math.h>

void main()
{
    int x1,x2,x3,y1,y2,y3,x,y,x0,y0;
    float co;
    printf("Vvedite koordinati A(x1;y1) i B(x2;y2) i C(x3,y3)\n");
    scanf("%i%i%i%i%i%i",&x1,&y1,&x2,&y2,&x3,&y3);
    x=x2-x1; /*BA*/
    y=y2-y1; /*BA*/
    x0=x2-x3;/*BC*/
    y0=y2-y3;/*BC*/
    co=(x*x0+y*y0)/sqrt(x*x+y*y)*sqrt(x0*x0+y0*y0);
    printf("%.2f",co);
    if (co==0) printf("Priamoygolnii");
     else if(co<0)printf("Tupougolnii");
         else printf("Ostrougolnii");
return 0;
}
