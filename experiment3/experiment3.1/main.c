#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    printf("Number:200110618\n");
    printf("subject No.3-program No.1\n\n");
    int n,i,N,find,k,K;
    int a,b,c;
    K=100;
    k=0;
    int num[K];
    int zhuan[K];
    for(n=101;n<=200;n++)
    {
        find=0;
        N=sqrt(n);
        for(i=2;i<=N;i++)
        {
            if(n%i==0)
            {
                find=1;
            }
        }
        if(find==0)
        {
            num[k]=n;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        a=num[i]/100;
        c=num[i]%10;
        b=num[i]-a*100-c;
        zhuan[i]=c*100+b+a;
    }
    for(i=0;i<k;i++)
    {
        printf("%d·´×ª:%d ",num[i],zhuan[i]);
        if(i%5==0)
        {
            printf("\n");
        }
    }
    return 0;
}
