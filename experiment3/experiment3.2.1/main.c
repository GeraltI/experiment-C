#include <stdio.h>
#include <stdlib.h>
#define p 1.42e8
int main()
{
    printf("Number:200110618\n");
    printf("subject No.3-program No.2-1\n\n");
    double k;
    unsigned long long a,sum;
    int i;
    sum=0;
    a=1;
    for(i=0;i<64;i++)
    {
        sum=sum+a;
        a=a*2;
    }
    printf("����������%llu\n",sum);
    k=sum/p;
    printf("�������(������)%.5lf",k);
    return 0;
}
