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
    printf("麦子数量：%llu\n",sum);
    k=sum/p;
    printf("麦子体积(立方米)%.5lf",k);
    return 0;
}
