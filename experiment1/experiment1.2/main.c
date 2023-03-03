#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110618\n");
    printf("subject No.1-program No.2\n\n");
    char a,b;
    scanf("%c",&a);
    b=a-32;
    int i,n;
    for(i=1;i<=8;i++)
    {
        if(i%2!=0)
            for(n=1;n<=8;n++)
            printf("%c ",b);
        else
            for(n=1;n<=8;n++)
            printf(" %c",b);
        printf("\n");
    }
}
