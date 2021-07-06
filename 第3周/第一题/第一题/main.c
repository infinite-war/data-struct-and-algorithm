#include <stdio.h>
#include <stdlib.h>
typedef struct Data
{
	int min;
	int max;
}Data;
int MIN;      /* ȫ�ֱ��� */
int fun1(int a[], int n)
/*ͨ������return�������ֵ��ͨ��ȫ�ֱ���MIN������Сֵ*/
{  int i,max;
    max=MIN=a[0]; //�����ֵ��Сֵ����ֵ
    for (i=0;i<n;i++)
        {
             if(a[i]>max) max=a[i];
             if (a[i]<MIN) MIN=a[i];
        }
    return(max);
}
int *fun2(int a[],int n)
/*�������Сֵ�ŵ�����b�У�ͨ��return����*/
{  static int b[2];

    int i;
	 b[0]=b[1]=a[0];  //�����ֵ��Сֵ����ֵ
    for (i=1;i<n;i++)
        {
	if (a[i]>b[0])	b[0]=a[i];
	if (a[i]<b[1]) 	b[1]=a[i];
        }
    return(b);
}
Data *fun3(int a[],int n)
/*�������Сֵ�ŵ��ṹ��ָ��p�У�ͨ��return����*/
{ Data *p;
   int i;
   p=(Data *)malloc(sizeof(Data *));
   p->max=p->min=a[0];
   for(i=1;i<n;i++)
    {  if (a[i]>p->max) 	p->max=a[i];
        if (a[i]<p->min)	p->min=a[i];
    }
   return(p);
}
Data fun4(int a[],int n)
/*�������Сֵ�ŵ��ṹ��p�У�ͨ���ṹ��p���ط���ֵ*/
{	Data p;
	int i;
	p.max=p.min=a[0];      //�����ֵ��Сֵ����ֵ
	for(i=1;i<n;i++)
	{
		if (a[i]>p.max) 		p.max=a[i];
		if (a[i]<p.min)		p.min=a[i];
	}
	return(p);
}
void fun5(int a[], int n, int *p, int *q)
/*��ָ����ط���ֵ��ָ��pָ�����ֵ��ָ��qָ����Сֵ*/
{   int i;
     *p=*q=a[0];
     for(i=1;i<n;i++)
        {  if (*p<a[i]) 	*p=a[i];
            if (*q>a[i])	*q=a[i];
        }
      }

int main()
{
	int mData[5]={2,3,5,4,1};
//     �ڴ˴��������

//����Ϊfun1ʾ�������ո�ʾ������д����fun2-5����������printf��������
	int rmax;
	rmax=fun1(mData, 5);
	printf("fun1:min=%d,max=%d.\n",MIN,rmax);


	//fun 2
	int *r;
	r=fun2(mData,5);
	printf("fun2:min=%d,max=%d.\n",r[1],r[0]);
	//fun 3
	Data *r1;
	r1=fun3(mData,5);
	printf("fun3:min=%d,max=%d.\n",r1->min,r1->max);
	//fun 4
	Data r2;
	r2=fun4(mData,5);
	printf("fun4:min=%d,max=%d.\n",r2.min,r2.max);
	//fun 5
	int *p,*q;
	fun5(mData, 5,  &p,  &q);
	printf("fun5:min=%d,max=%d.\n",p,q);


	system("pause");
	exit(0);
}
