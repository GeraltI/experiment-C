#include <stdio.h>
#include <stdlib.h>
#define p 1.42e8
int main()
{
    printf("Number:200110618\n");
    printf("subject No.3-program No.2-2\n\n");
    int i;
    int k=65;
    double g;
    unsigned long long sum[k];
    sum[0]=0;
    for(i=0;i<k;i++)
    {
        sum[i+1]=2*sum[i]+1;
    }
    printf("麦子数量：%llu\n",sum[64]);
    g=sum[64]/p;
    printf("麦子体积(平方米)%.5lf",g);
    return 0;
}
