#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 30
#define N 6
int Descending_score(int a,int b);//降序排序
int Ascending_score(int a,int b);//升序排序
int Ascending_number(long int a,long int b);//升序排序
void SelectionSort_score(long int number[],char name[][24],int sum[],float average[],int m,int(*compare)(int a,int b));//根据成绩排序
void SelectionSort_number(long int number[],char name[][24],int sum[],float average[],int m,int(*compare)(long int a,long int b));//根据学号排序
void SelectionSort_name(long int number[],char name[][24],int sum[],float average[],int m);//根据名字排序
void Swap_score(int *a,int *b);//运用指针交换两个成绩
void Swap_number(long int *a,long int *b);//运用指针交换两个学号
void Swap_average(float *a,float *b);//运用指针交换两个平均分
int main(void)
{
    int choice,m,n,i,j,sum_course[N],sum_student[M],ranking[M],k;
    int score[M][N];
    long int number[M],numberx;
    char name[M][24],temp[24];
    float average_course[N],average_student[M];
    printf("Number:200110618\n");
    printf("subject No.7-program No.1\n\n");
    printf("1.Input record\n2.Calculate total and average score of every course\n");
    printf("3.Calculate total and average score of every student\n4.Sort in descending order by total score of every student\n");
    printf("5.Sort in ascending order by total score of every student\n6.Sort in ascending order by student's ID\n");
    printf("7.Sort in dictionary order by name\n8. Search by student's ID\n");
    printf("9. Search by name\n10.Statistic analysis for every course\n");
    printf("11.List record\n12.Exit\nPlease enter your choice:\n");
    scanf("%d",&choice);
    do
    {
        if(choice==1)
        {
            printf("Please input the quantity of students:\n");
            scanf("%d",&m);//输入学生数量
            while(m<1||m>M)//检测学生数量，防止记忆容量溢出
            {
                printf("Error!Please input the quantity of students again:\n");
                scanf("%d",&m);
            }
            printf("Please input the quantity of courses:\n");
            scanf("%d",&n);//输入课程数量
            while(n<1||n>N)//检测课程数量，防止记忆容量溢出
            {
                printf("Error!Please input the quantity of courses again:\n");
                scanf("%d",&n);
            }
            printf("Please input the number,the name and the score of every course of every student\n");
            for(i=0;i<m;i++)
            {
                printf("Please input the number and the name of %d.student:\n",i+1);
                scanf("%ld %s",&number[i],name[i]);
                for(j=0;j<n;j++)
                {
                    printf("Please input the score of %d.course of %d.student:\n",j+1,i+1);
                    scanf("%d",&score[i][j]);
                    while(score[i][j]<0||score[i][j]>100)//检测每门课程的成绩
                    {
                        printf("Error!Please input the score of %d.course of %d.student:\n",j+1,i+1);
                        scanf("%d",&score[i][j]);
                    };
                }
            }
        }
        else if(choice==2)
        {
            memset(sum_course,0,sizeof(int)*N);//初始化课程总分的数组
            memset(average_course,0,sizeof(float)*N);//初始化课程平均分的数组
            for(j=0;j<n;j++)
            {
                for(i=0;i<m;i++)
                {
                    sum_course[j]=sum_course[j]+score[i][j];//将每门课程中的学生成绩相加
                }
                average_course[j]=(float)sum_course[j]/m;
                printf("the total score of %d.course is %d\n",1+j,sum_course[j]);
                printf("the average score of %d.course is %g\n",1+j,average_course[j]);
            }
        }
        else if(choice==3)
        {
            memset(sum_student,0,sizeof(int)*M);//初始化学生总分的数组
            memset(average_student,0,sizeof(float)*M);//初始化学生平均分的数组
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    sum_student[i]=sum_student[i]+score[i][j];//将每个学生的课程成绩相加
                }
                average_student[i]=(float)sum_student[i]/n;
                printf("the total score of %d.student is %d\n",1+i,sum_student[i]);
                printf("the average score of %d.student is %g\n",1+i,average_student[i]);
            }
            SelectionSort_score(number,name,sum_student,average_student,m,Descending_score);//将学生进行成绩逆排序
            for(i=0,k=1;i<m;i++)
            {
                ranking[i]=k;//利用逆排序将成绩进行排名
                if(sum_student[i]!=sum_student[i+1])
                {
                    k=i+2;
                }
            }
        }
        else if(choice==4)
        {
            SelectionSort_score(number,name,sum_student,average_student,m,Descending_score);//将学生进行成绩逆排序
            for(i=0;i<m;i++)
            {
                printf("ranking:%d number:%ld name:%s sum of score:%d\n",ranking[i],number[i],name[i],sum_student[i]);
            }
        }
        else if(choice==5)
        {
            SelectionSort_score(number,name,sum_student,average_student,m,Ascending_score);//将学生进行成绩顺排序
            for(i=0;i<m;i++)
            {
                printf("ranking:%d number:%ld name:%s sum of score:%d\n",ranking[m-i-1],number[i],name[i],sum_student[i]);
            }
        }
        else if(choice==6)
        {
            SelectionSort_number(number,name,sum_student,average_student,m,Ascending_number);//将学生进行学号顺排序
            for(i=0;i<m;i++)
            {
                printf("number:%ld name:%s sum of score:%d\n",number[i],name[i],sum_student[i]);
            }
        }
        else if(choice==7)
        {
            SelectionSort_name(number,name,sum_student,average_student,m);//将学生进行名字顺排序
            for(i=0;i<m;i++)
            {
                printf("name:%s number:%ld sum of score:%d\n",name[i],number[i],sum_student[i]);
            }
        }
        else if(choice==8)
        {
            SelectionSort_score(number,name,sum_student,average_student,m,Descending_score);//将学生进行成绩逆排序来查询排名
            printf("Please input the number of the student:\n");
            scanf("%ld",&numberx);
            for(i=0;i<m;i++)
            {
                if(numberx==number[i])//判断学生学号和输入的学号
                {
                    printf("ranking:%d sum of score:%d\n",ranking[i],sum_student[i]);
                }
            }
        }
        else if(choice==9)
        {
            SelectionSort_score(number,name,sum_student,average_student,m,Descending_score);//将学生进行成绩逆排序来查询排名
            printf("Please input the name of the student:\n");
            scanf("%s",temp);
            for(i=0;i<m;i++)
            {
                if(strcmp(temp,name[i])==0)//判断学生名字和输入的名字
                {
                    printf("ranking:%d sum of score:%d\n",ranking[i],sum_student[i]);
                }
            }
        }
        else if(choice==10)
        {
            int excellent,good,medium,passed,failed;
            float percentexcellent,percentgood,percentmedium,percentpassed,percentfailed;
            for(j=0;j<n;j++)
            {
                excellent=good=medium=passed=failed=0;
                percentexcellent=percentgood=percentmedium=percentpassed=percentfailed=0;
                for(i=0;i<m;i++)
                {
                if(score[i][j]>=90&&score[i][j]<=100)
                    excellent++;
                else if(score[i][j]>=80&&score[i][j]<=89)
                    good++;
                else if(score[i][j]>=70&&score[i][j]<=79)
                    medium++;
                else if(score[i][j]>=60&&score[i][j]<=69)
                    passed++;
                else if(score[i][j]>=0&&score[i][j]<=59)
                    failed++;
                }
                percentexcellent=(float)excellent/m;//类型强转
                percentgood=(float)good/m;
                percentmedium=(float)medium/m;
                percentpassed=(float)passed/m;
                percentfailed=(float)failed/m;
                printf("the quantity of excellent students of %d.course is%d\n",1+j,excellent);
                printf("the quantity of good students of %d.course is%d\n",1+j,good);
                printf("the quantity of medium students of %d.course is%d\n",1+j,medium);
                printf("the quantity of passed students of %d.course is%d\n",1+j,passed);
                printf("the quantity of failed students of %d.course is%d\n",1+j,failed);
                printf("the percent of excellent students of %d.course is%g\n",1+j,percentexcellent);
                printf("the percent of good students of %d.course is%g\n",1+j,percentgood);
                printf("the percent of medium students of %d.course is%g\n",1+j,percentmedium);
                printf("the percent of passed students of %d.course is%g\n",1+j,percentpassed);
                printf("the percent of failed students of %d.course is%g\n",1+j,percentfailed);
            }
        }
        else if(choice==11)
        {
            for(i=0;i<m;i++)
            {
                printf("number:%ld name:%s\n",number[i],name[i]);
                for(j=0;j<n;j++)
                {
                    printf("%d.course:%d ",1+j,score[i][j]);
                }
                printf("\nsum of score:%d the average of score:%g\n",sum_student[i],average_student[i]);
            }
        }
        else
            printf("Error!\n");//输入异常值则再次输入
        printf("Please enter your choice again:\n");
        scanf("%d",&choice);
    }while(choice!=12);
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
int Ascending_number(long int a,long int b)//升序排序
{
    return a<b;
}
void SelectionSort_score(long int number[],char name[][24],int sum[],float average[],int m,int(*compare)(int a,int b))
{
    int i,j,k;
    char temp[24];
    for(i=0;i<m-1;i++)
    {
        k=i;
        for(j=i+1;j<m;j++)
        {
            if((*compare)(sum[j],sum[k]))
                k=j;
        }
        if(k!=i)
        {
            Swap_score(&sum[k],&sum[i]);//交换总分
            Swap_number(&number[k],&number[i]);//交换学号
            Swap_average(&average[k],&average[i]);//交换平均分
            strcpy(temp,name[k]);//交换名字
            strcpy(name[k],name[i]);
            strcpy(name[i],temp);
        }
    }
}
void SelectionSort_number(long int number[],char name[][24],int sum[],float average[],int m,int(*compare)(long int a,long int b))//通过学号进行排序
{
    int i,j,k;
    char temp[24];
    for(i=0;i<m-1;i++)
    {
        k=i;
        for(j=i+1;j<m;j++)
        {
            if((*compare)(number[j],number[k]))
                k=j;
        }
        if(k!=i)
        {
            Swap_score(&sum[k],&sum[i]);//交换总分
            Swap_number(&number[k],&number[i]);//交换学号
            Swap_average(&average[k],&average[i]);//交换平均分
            strcpy(temp,name[k]);//交换名字
            strcpy(name[k],name[i]);
            strcpy(name[i],temp);
        }
    }
}
void SelectionSort_name(long int number[],char name[][24],int sum[],float average[],int m)//通过姓名顺序进行排序
{
    int i,j;
    char temp[24];
    for(i=0;i<m-1;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(strcmp(name[j],name[i])<0)
            {
                Swap_score(&sum[j],&sum[i]);//交换总分
                Swap_number(&number[j],&number[i]);//交换学号
                Swap_average(&average[j],&average[i]);//交换平均分
                strcpy(temp,name[i]);//交换名字
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
void Swap_average(float *a,float *b)//运用指针交换两个平均分
{
    float temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
