#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Number:200110618\n");
    printf("subject No.2-program No.2\n\n");
    double a,b,c,p,s,i;
    printf("���������������߱߳�a,b,c\n");
    scanf("%lf,%lf,%lf",&a,&b,&c);
    if(a+b>c&&a+c>b&&b+c>a)
    {
        i=1e-6;
        p=(a+b+c)/2;
        s=pow(p*(p-a)*(p-b)*(p-c),0.5);
        if(fabs(a*a+b*b-c*c)<=i||fabs(c*c+a*a-b*b)<=i||fabs(c*c+b*b-a*a)<=i)
        {
            if(a==b||a==c||b==c)
                printf("����һ������ֱ��������\n");
            else
                printf("����һ��һ��ֱ��������\n");
        }
        else if((fabs(a*a+b*b-c*c)>i&&fabs(c*c+a*a-b*b)>i&&fabs(c*c+b*b-a*a)>i)&&(a==b||a==c||b==c))
        {
            if(a==b&&a==c&&b==c)
                printf("����һ���ȱ�������\n");
            else
                printf("����һ��һ�����������\n");
        }
        else
            printf("����һ��һ��������\n");
        printf("���������Ϊ%lf",s);
    }
    else
        printf("�������߲������������");
}
