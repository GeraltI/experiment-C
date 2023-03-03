#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void right(int i)
{
    switch(i)
    {
        case 0:printf("Very good!\n");break;
        case 1:printf("Excellent!\n");break;
        case 2:printf("Nice work!\n");break;
        case 3:printf("Keep up the good work!\n");break;
    }
}
void wrong(int i)
{
    switch(i)
    {
        case 0:printf("No.Please try next subject.\n");break;
        case 1:printf("Wrong.Be careful.\n");break;
        case 2:printf("Don't give up.\n");break;
        case 3:printf("Not correct.Keep trying.\n");break;
    }
}
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
    printf("subject No.4-program No.2\n\n");
    char q;
    float n,sum;
    int i,a,b,c,d,e,score;
    do
    {
        for(i=0,score=0;i<10;i++)
        {
            a=k(i*10+1)%10+1;
            b=k(i*10+2)%10+1;
            c=k(i*10+3)%4;
            d=k(i*10+4)%4;
            e=k(i*10+5)%4;
            switch(e)
            {
                case 0:q='+';sum=(float)(a+b);break;
                case 1:q='-';sum=(float)(a-b);break;
                case 2:q='*';sum=(float)(a*b);break;
                case 3:q='/';sum=(float)a/b;break;
            }
            printf("%d%c%d=?\n",a,q,b);
            scanf("%f",&n);
            if(fabs(sum-n)<=1e-2)
            {
                score=score+10;
                right(c);
            }
            else
            {
                wrong(d);
            }
        }
        if(score<75)
        {
            printf("your percentage of answering right is lower than 0.75.Try again!\n");
        }
    }
    while(score<75);
    printf("your percentage of answering right is higher than 0.75.you pass the test!\n");
    return 0;
}
