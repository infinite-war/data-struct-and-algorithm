#include "global.h"

int main()
{
	int mData[5]={2,3,5,4,1};
//     �ڴ˴��������

//����Ϊfun1ʾ�������ո�ʾ������д����fun2-5����������printf��������
	int rmax;
	rmax=fun1(mData, 5);
	printf("fun1:min=%d,max=%d.\n",MIN,rmax);
	
	int* c = fun2(mData, 5);
	printf("fun2:min=%d,max=%d.\n", c[1], c[0]);

	Data* q = fun3(mData, 5);
	printf("fun3:min=%d,max=%d.\n",q->min,q->max);

	Data r = fun4(mData, 5);
	printf("fun4:min=%d,max=%d.\n", r.min, r.max);

	int* max_5, * min_5;
	max_5 = (int*)malloc(sizeof(int));
	min_5 = (int*)malloc(sizeof(int));

	fun5(mData, 5, min_5, max_5);
	printf("fun5:min=%d,max=%d.\n", *max_5, *min_5);

	system("pause");
	exit(0);
}