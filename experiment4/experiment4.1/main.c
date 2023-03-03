#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int k(int m)
{
    int s;
    srand((unsigned)time(NULL)*m);
    s=rand();
    return s;
}
int main()
{
    printf("Number:200110618\n");
    printf("subject No.4-program No.1\n\n");
    long int i,j;
    int a,b,n,sum,find,score;
    float percent;
    score=0;
    for(j=0;j<10;j++)
    {
        a=k(1)%10+1;
        b=k(2)%10+1;
        sum=a*b;
        printf("%d*%d=?\n",a,b);
        find=0;
        for(i=0;i<3;i++)
        {
            scanf("%d",&n);
            if(n==sum)
            {
                printf("Right!\n");
                find=1;
                break;
            }
            else if(n!=sum&&i<2)
            {
                printf("Wrong! Please try again.\n");
            }
        }
        if(find==0)
            printf("Wrong！Test next subject!\n");
        else
            score=score+10;
    }
    printf("你的得分是:%d",score);
    percent=(float)score/100.0;
    printf("你的正确率是:%.1f",percent);
    return 0;
}
