#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 30
#define N 6
int Descending_score(int a,int b);//��������
int Ascending_score(int a,int b);//��������
int Ascending_number(long int a,long int b);//��������
void SelectionSort_score(long int number[],char name[][24],int sum[],float average[],int m,int(*compare)(int a,int b));//���ݳɼ�����
void SelectionSort_number(long int number[],char name[][24],int sum[],float average[],int m,int(*compare)(long int a,long int b));//����ѧ������
void SelectionSort_name(long int number[],char name[][24],int sum[],float average[],int m);//������������
void Swap_score(int *a,int *b);//����ָ�뽻�������ɼ�
void Swap_number(long int *a,long int *b);//����ָ�뽻������ѧ��
void Swap_average(float *a,float *b);//����ָ�뽻������ƽ����
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
            scanf("%d",&m);//����ѧ������
            while(m<1||m>M)//���ѧ����������ֹ�����������
            {
                printf("Error!Please input the quantity of students again:\n");
                scanf("%d",&m);
            }
            printf("Please input the quantity of courses:\n");
            scanf("%d",&n);//����γ�����
            while(n<1||n>N)//���γ���������ֹ�����������
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
                    while(score[i][j]<0||score[i][j]>100)//���ÿ�ſγ̵ĳɼ�
                    {
                        printf("Error!Please input the score of %d.course of %d.student:\n",j+1,i+1);
                        scanf("%d",&score[i][j]);
                    };
                }
            }
        }
        else if(choice==2)
        {
            memset(sum_course,0,sizeof(int)*N);//��ʼ���γ��ֵܷ�����
            memset(average_course,0,sizeof(float)*N);//��ʼ���γ�ƽ���ֵ�����
            for(j=0;j<n;j++)
            {
                for(i=0;i<m;i++)
                {
                    sum_course[j]=sum_course[j]+score[i][j];//��ÿ�ſγ��е�ѧ���ɼ����
                }
                average_course[j]=(float)sum_course[j]/m;
                printf("the total score of %d.course is %d\n",1+j,sum_course[j]);
                printf("the average score of %d.course is %g\n",1+j,average_course[j]);
            }
        }
        else if(choice==3)
        {
            memset(sum_student,0,sizeof(int)*M);//��ʼ��ѧ���ֵܷ�����
            memset(average_student,0,sizeof(float)*M);//��ʼ��ѧ��ƽ���ֵ�����
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    sum_student[i]=sum_student[i]+score[i][j];//��ÿ��ѧ���Ŀγ̳ɼ����
                }
                average_student[i]=(float)sum_student[i]/n;
                printf("the total score of %d.student is %d\n",1+i,sum_student[i]);
                printf("the average score of %d.student is %g\n",1+i,average_student[i]);
            }
            SelectionSort_score(number,name,sum_student,average_student,m,Descending_score);//��ѧ�����гɼ�������
            for(i=0,k=1;i<m;i++)
            {
                ranking[i]=k;//���������򽫳ɼ���������
                if(sum_student[i]!=sum_student[i+1])
                {
                    k=i+2;
                }
            }
        }
        else if(choice==4)
        {
            SelectionSort_score(number,name,sum_student,average_student,m,Descending_score);//��ѧ�����гɼ�������
            for(i=0;i<m;i++)
            {
                printf("ranking:%d number:%ld name:%s sum of score:%d\n",ranking[i],number[i],name[i],sum_student[i]);
            }
        }
        else if(choice==5)
        {
            SelectionSort_score(number,name,sum_student,average_student,m,Ascending_score);//��ѧ�����гɼ�˳����
            for(i=0;i<m;i++)
            {
                printf("ranking:%d number:%ld name:%s sum of score:%d\n",ranking[m-i-1],number[i],name[i],sum_student[i]);
            }
        }
        else if(choice==6)
        {
            SelectionSort_number(number,name,sum_student,average_student,m,Ascending_number);//��ѧ������ѧ��˳����
            for(i=0;i<m;i++)
            {
                printf("number:%ld name:%s sum of score:%d\n",number[i],name[i],sum_student[i]);
            }
        }
        else if(choice==7)
        {
            SelectionSort_name(number,name,sum_student,average_student,m);//��ѧ����������˳����
            for(i=0;i<m;i++)
            {
                printf("name:%s number:%ld sum of score:%d\n",name[i],number[i],sum_student[i]);
            }
        }
        else if(choice==8)
        {
            SelectionSort_score(number,name,sum_student,average_student,m,Descending_score);//��ѧ�����гɼ�����������ѯ����
            printf("Please input the number of the student:\n");
            scanf("%ld",&numberx);
            for(i=0;i<m;i++)
            {
                if(numberx==number[i])//�ж�ѧ��ѧ�ź������ѧ��
                {
                    printf("ranking:%d sum of score:%d\n",ranking[i],sum_student[i]);
                }
            }
        }
        else if(choice==9)
        {
            SelectionSort_score(number,name,sum_student,average_student,m,Descending_score);//��ѧ�����гɼ�����������ѯ����
            printf("Please input the name of the student:\n");
            scanf("%s",temp);
            for(i=0;i<m;i++)
            {
                if(strcmp(temp,name[i])==0)//�ж�ѧ�����ֺ����������
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
                percentexcellent=(float)excellent/m;//����ǿת
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
            printf("Error!\n");//�����쳣ֵ���ٴ�����
        printf("Please enter your choice again:\n");
        scanf("%d",&choice);
    }while(choice!=12);
    return 0;
}
int Descending_score(int a,int b)//��������
{
    return a>b;
}
int Ascending_score(int a,int b)//��������
{
    return a<b;
}
int Ascending_number(long int a,long int b)//��������
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
            Swap_score(&sum[k],&sum[i]);//�����ܷ�
            Swap_number(&number[k],&number[i]);//����ѧ��
            Swap_average(&average[k],&average[i]);//����ƽ����
            strcpy(temp,name[k]);//��������
            strcpy(name[k],name[i]);
            strcpy(name[i],temp);
        }
    }
}
void SelectionSort_number(long int number[],char name[][24],int sum[],float average[],int m,int(*compare)(long int a,long int b))//ͨ��ѧ�Ž�������
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
            Swap_score(&sum[k],&sum[i]);//�����ܷ�
            Swap_number(&number[k],&number[i]);//����ѧ��
            Swap_average(&average[k],&average[i]);//����ƽ����
            strcpy(temp,name[k]);//��������
            strcpy(name[k],name[i]);
            strcpy(name[i],temp);
        }
    }
}
void SelectionSort_name(long int number[],char name[][24],int sum[],float average[],int m)//ͨ������˳���������
{
    int i,j;
    char temp[24];
    for(i=0;i<m-1;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(strcmp(name[j],name[i])<0)
            {
                Swap_score(&sum[j],&sum[i]);//�����ܷ�
                Swap_number(&number[j],&number[i]);//����ѧ��
                Swap_average(&average[j],&average[i]);//����ƽ����
                strcpy(temp,name[i]);//��������
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
        }
    }
}
void Swap_score(int*a,int *b)//����ָ�뽻�������ɼ�
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void Swap_number(long int *a,long int *b)//����ָ�뽻������ѧ��
{
    long int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void Swap_average(float *a,float *b)//����ָ�뽻������ƽ����
{
    float temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
