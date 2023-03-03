#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    long number;
    char name[24];
    int score[6];
    int sum;
    int ranking;
    float average;
}STUDENT;
int Descending_score(int a,int b);//降序排序
int Ascending_score(int a,int b);//升序排序
int Ascending_number(long int a,long int b);//升序排序
void SelectionSort_score(STUDENT stu[],int m,int(*compare)(int a,int b));//根据成绩排序
void SelectionSort_number(STUDENT stu[],int m,int(*compare)(long int a,long int b));//根据学号排序
void SelectionSort_name(STUDENT stu[],int m);//根据名字排序
void WritetoFile(STUDENT stu[],int n,int m);//将结构体数据写入文件
void ReadfromFile(STUDENT stu[],int *m,int *n);//读出文件数据写入结构体
void PrintData(STUDENT stu[],int m,int n);//显示数据
int main(void)
{
    int choice,m,n,i,j,k;
    long int numberx;
    char temp[24];
    int sum_course[30];
    float average_course[6];
    printf("Number:200110618\n");
    printf("subject No.9-program No.1\n\n");
    printf("1.Input record\n2.Calculate total and average score of every course\n");
    printf("3.Calculate total and average score of every student\n4.Sort in descending order by total score of every student\n");
    printf("5.Sort in ascending order by total score of every student\n6.Sort in ascending order by student's ID\n");
    printf("7.Sort in dictionary order by name\n8. Search by student's ID\n");
    printf("9. Search by name\n10.Statistic analysis for every course\n");
    printf("11.List record\n12.Write to a file\n");
    printf("13.read from a file\n14.Exit\nPlease enter your choice:\n");
    STUDENT stu[31]={0};
    scanf("%d",&choice);
    do
    {
        if(choice==1)
        {
            printf("Please input the quantity of students:\n");
            scanf("%d",&m);//输入学生数量
            while(m<1||m>30)//检测学生数量，防止记忆容量溢出
            {
                printf("Error!Please input the quantity of students again:\n");
                scanf("%d",&m);
            }
            printf("Please input the quantity of courses:\n");
            scanf("%d",&n);//输入课程数量
            while(n<1||n>6)//检测课程数量，防止记忆容量溢出
            {
                printf("Error!Please input the quantity of courses again:\n");
                scanf("%d",&n);
            }
            printf("Please input the number,the name and the score of every course of every student\n");
            for(i=0;i<m;i++)
            {
                printf("Please input the number and the name of %d.student:\n",i+1);
                scanf("%ld %s",&stu[i].number,stu[i].name);
                for(j=0;j<n;j++)
                {
                    printf("Please input the score of %d.course of %d.student:\n",j+1,i+1);
                    scanf("%d",&stu[i].score[j]);
                    while(stu[i].score[j]<0||stu[i].score[j]>100)//检测每门课程的成绩
                    {
                        printf("Error!Please input the score of %d.course of %d.student:\n",j+1,i+1);
                        scanf("%d",&stu[i].score[j]);
                    };
                }
            }
        }
        else if(choice==2)
        {
            memset(sum_course,0,sizeof(int)*6);//初始化课程总分的数组
            memset(average_course,0,sizeof(float)*6);//初始化课程平均分的数组
            for(j=0;j<n;j++)
            {
                for(i=0;i<m;i++)
                {
                    sum_course[j]=sum_course[j]+stu[i].score[j];//将每门课程中的学生成绩相加
                }
                average_course[j]=(float)sum_course[j]/m;
                printf("the total score of %d.course is %d\n",1+j,sum_course[j]);
                printf("the average score of %d.course is %g\n",1+j,average_course[j]);
            }
        }
        else if(choice==3)
        {
            for(i=0;i<m;i++)
            {
                stu[i].sum=0;//初始化结构体的学生总分
                for(j=0;j<n;j++)
                {
                    stu[i].sum=stu[i].sum+stu[i].score[j];//将每个学生的课程成绩相加
                }
                stu[i].average=(float)stu[i].sum/n;
                printf("the total score of %d.student is %d\n",1+i,stu[i].sum);
                printf("the average score of %d.student is %g\n",1+i,stu[i].average);
            }
            SelectionSort_score(stu,m,Descending_score);//将学生进行成绩逆排序
            for(i=0,k=1;i<m;i++)
            {
                stu[i].ranking=k;//利用逆排序将成绩进行排名
                if(stu[i].sum!=stu[i+1].sum)
                {
                    k=i+2;
                }
            }
        }
        else if(choice==4)
        {
            SelectionSort_score(stu,m,Descending_score);//将学生进行成绩逆排序
            for(i=0;i<m;i++)
            {
                printf("ranking:%d number:%ld name:%s sum of score:%d\n",stu[i].ranking,stu[i].number,stu[i].name,stu[i].sum);
            }
        }
        else if(choice==5)
        {
            SelectionSort_score(stu,m,Ascending_score);//将学生进行成绩顺排序
            for(i=0;i<m;i++)
            {
                printf("ranking:%d number:%ld name:%s sum of score:%d\n",stu[i].ranking,stu[i].number,stu[i].name,stu[i].sum);
            }
        }
        else if(choice==6)
        {
            SelectionSort_number(stu,m,Ascending_number);//将学生进行学号顺排序
            for(i=0;i<m;i++)
            {
                printf("number:%ld name:%s sum of score:%d\n",stu[i].number,stu[i].name,stu[i].sum);
            }
        }
        else if(choice==7)
        {
            SelectionSort_name(stu,m);//将学生进行名字顺排序
            for(i=0;i<m;i++)
            {
                printf("name:%s number:%ld sum of score:%d\n",stu[i].name,stu[i].number,stu[i].sum);
            }
        }
        else if(choice==8)
        {
            printf("Please input the number of the student:\n");
            scanf("%ld",&numberx);
            for(i=0;i<m;i++)
            {
                if(numberx==stu[i].number)//判断学生学号和输入的学号
                {
                    printf("ranking:%d the sum of score:%d\nthe score of all course:\n",stu[i].ranking,stu[i].sum);
                    for(j=0;j<n;j++)
                    {
                        printf("course%d:%d ",1+j,stu[i].score[j]);
                    }
                }
            }
        }
        else if(choice==9)
        {
            printf("Please input the name of the student:\n");
            scanf("%s",temp);
            for(i=0;i<m;i++)
            {
                if(strcmp(temp,stu[i].name)==0)//判断学生名字和输入的名字
                {
                    printf("ranking:%d the sum of score:%d\nthe score of all course:\n",stu[i].ranking,stu[i].sum);
                    for(j=0;j<n;j++)
                    {
                        printf("course%d:%d ",1+j,stu[i].score[j]);
                    }
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
                if(stu[i].score[j]>=90&&stu[i].score[j]<=100)
                    excellent++;
                else if(stu[i].score[j]>=80&&stu[i].score[j]<=89)
                    good++;
                else if(stu[i].score[j]>=70&&stu[i].score[j]<=79)
                    medium++;
                else if(stu[i].score[j]>=60&&stu[i].score[j]<=69)
                    passed++;
                else if(stu[i].score[j]>=0&&stu[i].score[j]<=59)
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
                printf("number:%ld name:%s\n",stu[i].number,stu[i].name);
                printf("the score of every course:\n");
                for(j=0;j<n;j++)
                {
                    printf("%d.course:%d ",1+j,stu[i].score[j]);
                }
                printf("\nthe sum of score:%d the average of score:%g\n",stu[i].sum,stu[i].average);
            }
        }
        else if(choice==12)
        {
            WritetoFile(stu,m,n);
        }
        else if(choice==13)
        {
            ReadfromFile(stu,&m,&n);
            PrintData(stu,m,n);
        }
        else
            printf("Error!\n");//输入异常值则再次输入
        printf("Please enter your choice again:\n");
        scanf("%d",&choice);
    }while(choice!=14);
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
void SelectionSort_score(STUDENT stu[],int m,int(*compare)(int a,int b))
{
    int i,j,k;
    for(i=0;i<m-1;i++)
    {
        k=i;
        for(j=i+1;j<m;j++)
        {
            if((*compare)(stu[j].sum,stu[k].sum))
                k=j;
        }
        if(k!=i)
        {
            stu[30]=stu[i];//交换两个结构体的数据，运用stu[30]作为介质
            stu[i]=stu[k];
            stu[k]=stu[30];
        }
    }
}
void SelectionSort_number(STUDENT stu[],int m,int(*compare)(long int a,long int b))
{
    int i,j,k;
    for(i=0;i<m-1;i++)
    {
        k=i;
        for(j=i+1;j<m;j++)
        {
            if((*compare)(stu[j].number,stu[k].number))
                k=j;
        }
        if(k!=i)
        {
            stu[30]=stu[i];//交换两个结构体的数据，运用stu[30]作为介质
            stu[i]=stu[k];
            stu[k]=stu[30];
        }
    }
}
void SelectionSort_name(STUDENT stu[],int m)
{
    int i,j,k;
    for(i=0;i<m-1;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(strcmp(stu[j].name,stu[k].name)<0)
            {
                k=j;
            }
        }
        if(k!=i)
        {
            stu[30]=stu[i];//交换两个结构体的数据，运用stu[30]作为介质
            stu[i]=stu[k];
            stu[k]=stu[30];
        }
    }
}
void WritetoFile(STUDENT stu[],int m,int n)
{
    FILE *fp;
    int i,j;
    if((fp=fopen("score.txt","w"))==NULL)
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    fprintf(fp,"%d\t%d\n",m,n);
    for(i=0;i<m;i++)
    {
        fprintf(fp,"%10ld",stu[i].number);
        fprintf(fp,"%8s",stu[i].name);
        for(j=0;j<n;j++)
        {
            fprintf(fp,"%3d/",stu[i].score[j]);
        }
        fprintf(fp,"%4d/",stu[i].sum);
        fprintf(fp,"%3.3f\n",stu[i].average);
    }
    fclose(fp);
}
void ReadfromFile(STUDENT stu[],int *m,int *n)
{
    FILE *fp;
    int i,j;
    if((fp=fopen("score.txt","r"))==NULL)
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    fscanf(fp,"%d\t%d",m,n);
    for(i=0;i<*m;i++)
    {
        fscanf(fp,"%10ld",&stu[i].number);
        fscanf(fp,"%8s",stu[i].name);
        for(j=0;j<*n;j++)
        {
            fscanf(fp,"%3d/",&stu[i].score[j]);
        }
        fscanf(fp,"%4d/",&stu[i].sum);
        fscanf(fp,"%f",&stu[i].average);
    }
    fclose(fp);
}
void PrintData(STUDENT stu[],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        printf("学号:%-10ld 名字:%-8s\n成绩:",stu[i].number,stu[i].name);
        for(j=0;j<n;j++)
        {
            printf("%d.课程成绩:%-4d",j+1,stu[i].score[j]);
        }
        printf("总分:%-d 平均分:%-3.3f\n",stu[i].sum,stu[i].average);
    }
}
