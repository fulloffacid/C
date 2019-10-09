#include <stdio.h>
#include <math.h>

void main()
{
    float x1,x2,x3,y1,y2,y3,x,y,x0,y0,co;
    printf("Vvedite koordinati A(x1,y1) i B(x2,y2) i C(x3,y3):\n");
    scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
    x=x2-x1;
    y=y2-y1;
    x0=x2-x3;
    y0=y2-y3;
    co=(x*x0+y*y0)/(sqrt(x*x+y*y)*sqrt(x0*x0+y0*y0));
    printf("%1.2f\n",co);
    if (co==0) printf("Priamougolnii");
     else if(co>=1||co<=-1)printf("Ne sushestvuet");
      else if (co<0)printf("Tupougolnii");
       else if (co>0)printf("Ostrougolnii");
    return 0;
}
