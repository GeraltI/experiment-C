#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110618\n");
    printf("subject No.1-program No.1\n\n");
    printf("Please input char a:");
    char q;
    scanf("%c",&q);
    printf("char a=%c,size of char is%d \n",q,sizeof(char));
    printf("Please input int b:");
    int w;
    scanf("%d",&w);
    printf("int b=%d,size of int is%d\n",w,sizeof(int));
    printf("Please input short c:");
    short e;
    scanf("%d",&e);
    printf("shrot c=%d,size of short is%d\n",e,sizeof(short));
    printf("Please input float d:");
    float r;
    scanf("%f",&r);
    printf("float d=%f,size of float is%d\n",r,sizeof(float));
    printf("Please input double e:");
    double t;
    scanf("%lf",&t);
    printf("double e=%lf,size of double is%d\n",t,sizeof(double));
}
