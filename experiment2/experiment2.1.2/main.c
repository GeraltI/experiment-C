#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110618\n");
    printf("subject No.2-program No.1-2\n\n");
    const double pi=3.14159;
    int R;
    double S,V;
    printf("Please input R\n");
    scanf("%d",&R);
    S=pi*R*R*4;
    V=pi*R*R*R*4/3;
    printf("S=%lf,V=%lf",S,V);
}
