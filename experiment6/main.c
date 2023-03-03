#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 24
int Descending_score(int a,int b);
int Ascending_score(int a,int b);
int Ascending_number(long int a,long int b);
void SelectionSort_score(long int number[],char name[][N],int score[],int num,int(*compare)(int a,int b));
void SelectionSort_number(long int number[],char name[][N],int score[],int num,int(*compare)(long int a,long int b));
void SelectionSort_name(long int number[],char name[][N],int score[],int num);
void Swap_score(int *a,int *b);
void Swap_number(long int *a,long int *b);
int main(void)
{
    printf("Number:200110618\n");
    printf("subject No.6-program No.1\n\n");
    printf("Please input the number of students:\n");
    int num;
    scanf("%d",&num);
    printf("1.Input record\n2.Calculate total and average score of course\n");
    printf("3.Sort in descending order by score\n4.Sort in ascending order by score\n");
    printf("5.Sort in ascending order by number\n6.Sort in dictionary order by name\n");
    printf("7.Search by number\n8.Search by name\n");
    printf("9.Statistic analysis!\n10.List record\n");
    printf("0.Exit\nPlease enter your choice:\n");
    int choice,i;
    scanf("%d",&choice);
    long int number[num],numberx;
    int score[num],k,ranking[num];
    char name[num][N];
    char temp[N];
    int sum;
    float average;
    do
    {
        if(choice==1)
        {
            printf("Please input the number,the name and the score of each student:\n");
            for(i=0;i<num;i++)
            {
                printf("Please input the number,the name and the score of %d.student:\n",i+1);
                scanf("%ld %s %d",&number[i],name[i],&score[i]);
                while(score[i]<0||score[i]>100)
                {
                    printf("Wrong!Please input the data of %d.student again:\n",i+1);
                    scanf("%ld %s %d",&number[i],name[i],&score[i]);
                };
            }
            SelectionSort_score(number,name,score,num,Descending_score);
            for(i=0,k=1;i<num;i++)
            {
                ranking[i]=k;
                if(score[i]!=score[i+1])
                {
                    k=i+2;
                }
            }
        }
        else if(choice==2)
        {
            sum=0;
            for(i=0;i<num;i++)
            {
                sum=sum+score[i];
            }
            average=(float)(sum)/num;
        }
        else if(choice==3)
        {
            SelectionSort_score(number,name,score,num,Descending_score);
            for(i=0,k=1;i<num;i++)
            {
                    printf("ranking:%d number:%ld name:%s score:%d\n",ranking[i],number[i],name[i],score[i]);
            }
        }
        else if(choice==4)
        {
            SelectionSort_score(number,name,score,num,Ascending_score);
            for(i=0;i<num;i++)
            {
                printf("ranking:%d number:%ld name:%s score:%d\n",ranking[num-i-1],number[i],name[i],score[i]);
            }
        }
        else if(choice==5)
        {
            SelectionSort_number(number,name,score,num,Ascending_number);
            for(i=0;i<num;i++)
            {
                printf("number:%ld name:%s score:%d\n",number[i],name[i],score[i]);
            }
        }
        else if(choice==6)
        {
            SelectionSort_name(number,name,score,num);
            for(i=0;i<num;i++)
            {
                printf("name:%s number:%ld score:%d\n",name[i],number[i],score[i]);
            }
        }
        else if(choice==7)
        {
            SelectionSort_score(number,name,score,num,Descending_score);
            printf("Please input the number of the student:\n");
            scanf("%ld",&numberx);
            for(i=0;i<num;i++)
            {
                if(numberx==number[i])
                {
                    printf("ranking:%d score:%d\n",ranking[i],score[i]);
                }
            }
        }
        else if(choice==8)
        {
            SelectionSort_score(number,name,score,num,Descending_score);
            printf("Please input the name of the student:\n");
            scanf("%s",temp);
            for(i=0;i<num;i++)
            {
                if(strcmp(temp,name[i])==0)
                {
                    printf("ranking:%d score:%d\n",ranking[i],score[i]);
                }
            }
        }
        else if(choice==9)
        {
            int excellent,good,medium,passed,failed;
            excellent=good=medium=passed=failed=0;
            float percentexcellent,percentgood,percentmedium,percentpassed,percentfailed;
            for(i=0;i<num;i++)
            {
                if(score[i]>=90&&score[i]<=100)
                    excellent++;
                else if(score[i]>=80&&score[i]<=89)
                    good++;
                else if(score[i]>=70&&score[i]<=79)
                    medium++;
                else if(score[i]>=60&&score[i]<=69)
                    passed++;
                else if(score[i]>=0&&score[i]<=59)
                    failed++;
            }
            percentexcellent=(float)excellent/num;
            percentgood=(float)good/num;
            percentmedium=(float)medium/num;
            percentpassed=(float)passed/num;
            percentfailed=(float)failed/num;
            printf("the number of excellent students is%d\n",excellent);
            printf("the number of good students is%d\n",good);
            printf("the number of medium students is%d\n",medium);
            printf("the number of passed students is%d\n",passed);
            printf("the number of failed students is%d\n",failed);
            printf("the percent of excellent students is%g\n",percentexcellent);
            printf("the percent of good students is%g\n",percentgood);
            printf("the percent of medium students is%g\n",percentmedium);
            printf("the percent of passed students is%g\n",percentpassed);
            printf("the percent of failed students is%g\n",percentfailed);
        }
        else if(choice==10)
        {
            SelectionSort_score(number,name,score,num,Descending_score);
            for(i=0;i<num;i++)
            {
                printf("%d.number:%ld name:%s score:%d\n",i+1,number[i],name[i],score[i]);
            }
            printf("the sum of scores is%d\n",sum);
            printf("the average of scores is%g\n",average);
        }
        else
        {
            printf("Error!\n");
        }
        printf("Please enter your choice again:\n");
        scanf("%d",&choice);
    }while(choice!=0);
    return 0;
}
int Descending_score(int a,int b)//降序排序
{
    return a>b;
}
int Ascending_score(int a,int b)//升序排序
{
    return a<b;
}
int Ascending_number(long int a,long int b)
{
    return a<b;
}
void SelectionSort_score(long int number[],char name[][N],int score[],int num,int(*compare)(int a,int b))//通过排名进行排序
{
    int i,j,k;
    char temp[N];
    for(i=0;i<num-1;i++)
    {
        k=i;
        for(j=i+1;j<num;j++)
        {
            if((*compare)(score[j],score[k]))
                k=j;
        }
        if(k!=i)
        {
            Swap_score(&score[k],&score[i]);
            Swap_number(&number[k],&number[i]);
            strcpy(temp,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp);
        }
    }
}
void SelectionSort_number(long int number[],char name[][N],int score[],int num,int(*compare)(long int a,long int b))//通过学号进行排序
{
    int i,j,k;
    char temp[N];
    for(i=0;i<num-1;i++)
    {
        k=i;
        for(j=i+1;j<num;j++)
        {
            if((*compare)(number[j],number[k]))
                k=j;
        }
        if(k!=i)
        {
            Swap_score(&score[k],&score[i]);
            Swap_number(&number[k],&number[i]);
            strcpy(temp,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp);
        }
    }
}
void SelectionSort_name(long int number[],char name[][N],int score[],int num)//通过姓名顺序进行排序
{
    int i,j;
    char temp[N];
    for(i=0;i<num-1;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if(strcmp(name[j],name[i])<0)
            {
                Swap_score(&score[j],&score[i]);
                Swap_number(&number[j],&number[i]);
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
        }
    }
}
void Swap_score(int*a,int *b)//运用指针交换两个成绩
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void Swap_number(long int *a,long int *b)//运用指针交换两个学号
{
    long int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
