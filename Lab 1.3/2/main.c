#include <stdio.h>
#include <stdlib.h>

void main()
{
    int nom,a,b,c,d;
    for(nom=1000;nom<9999;nom++){
    a=nom/1000;
    b=(nom-a*1000)/100;
    c=(nom-a*1000-b*100)/10;
    d=nom%10;
  if ( nom%154==0 && a+b+c+d==30)
    printf("Result %d\n",nom);
    }
return 0;
}
