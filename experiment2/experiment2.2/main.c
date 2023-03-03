#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Number:200110618\n");
    printf("subject No.2-program No.2\n\n");
    double a,b,c,p,s,i;
    printf("请输入三角形三边边长a,b,c\n");
    scanf("%lf,%lf,%lf",&a,&b,&c);
    if(a+b>c&&a+c>b&&b+c>a)
    {
        i=1e-6;
        p=(a+b+c)/2;
        s=pow(p*(p-a)*(p-b)*(p-c),0.5);
        if(fabs(a*a+b*b-c*c)<=i||fabs(c*c+a*a-b*b)<=i||fabs(c*c+b*b-a*a)<=i)
        {
            if(a==b||a==c||b==c)
                printf("这是一个等腰直角三角形\n");
            else
                printf("这是一个一般直角三角形\n");
        }
        else if((fabs(a*a+b*b-c*c)>i&&fabs(c*c+a*a-b*b)>i&&fabs(c*c+b*b-a*a)>i)&&(a==b||a==c||b==c))
        {
            if(a==b&&a==c&&b==c)
                printf("这是一个等边三角形\n");
            else
                printf("这是一个一般等腰三角形\n");
        }
        else
            printf("这是一个一般三角形\n");
        printf("三角形面积为%lf",s);
    }
    else
        printf("这三条边不能组成三角形");
}
