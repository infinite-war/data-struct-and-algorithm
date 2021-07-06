#pragma once
#include "Sqlist.h"


int swap(int* x, int* y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
	return 0;
}


/*��(1) 
  ��������DownUnion
  ���ܣ��ϲ������ǵݼ�˳���LA,LB�γ��µķǵݼ�˳���LC
  ���룺sqlist��ָ��LA,LB�����ϲ���sqlist��ָ��LC
  ������ϲ����LC  */

int DownUnion(sqlist* LA, sqlist* LB,sqlist* LC)
{

	int lena = LA->length, lenb = LB->length;
	int i = 0, j = 0, k = 0;
	LC->data = (ElemType*)realloc(LC->data,(lena + lenb) * sizeof(ElemType));
	LC->length = lena + lenb;
	LC->listsize = lena + lenb;

	while (i < lena && j < lenb)
	{
		if (LA->data[i] > LB->data[j]) LC->data[k++] = LA->data[i++];
		else if (LA->data[i] < LB->data[j]) LC->data[k++] = LB->data[j++];
		else //  dataa==datab
		{
			LC->data[k++] = LA->data[i++];
			j++;
		}
	}
	while (i < lena) LC->data[k++] = LA->data[i++];
	while (j < lenb) LC->data[k++] = LB->data[j++];
	for (int i = 0; i < lena + lenb; i++) printf("%d ", LC->data[i]);
	printf("\n");
	return 0;
}




/*****completed******/
/*��(2)
  ��������Del_odd
  ���ܣ�ɾ�����Ա�����������
  ���룺sqlist��ָ��L
  �����ɾ������������L
  Ҫ��ʱ�临�Ӷȣ�O(n),�ռ临�Ӷȣ�O(1)   */

int Del_odd(sqlist* L)
{
	int i = 0, j = L->length - 1;
	int k=-1;
	while (i <= j)
	{
		int oddi = L->data[i] & 1, oddj = L->data[j] & 1;
		if (oddi && !oddj)
		{
			swap(&L->data[i], &L->data[j]);
			k = j;
			i++; j--;
		}
		else if (oddi && oddj) { k = j; j--; }
		else if (!oddi && oddj) { k = j; i++; j--; }
		else i++;
	}

	if (k == -1) printf("No odd exists.\n");
	else
	{
		L->data = (ElemType*)realloc(L->data, k * sizeof(ElemType));//��������ռ�
		//L->data = (int*)realloc(L->data, (++L->listsize) * sizeof(int));
		L->length = k;
		L->listsize = k;
		for (int i = 0; i < L->length; i++) printf("%d ", L->data[i]);
	}
	

	printf("\n");
	return 0;
}



/*****completed******/
/*��(3)
  ��������Devide_odd_even
  ���ܣ��Ե�һ��Ԫ��Ϊ��׼����˳����е�������ǰ��ż���ź�
  ���룺sqlist��ָ��L
  �����������L   */

int Devide_odd_even(sqlist* L)
{
	int first = L->data[0];
	int i = 0, j = L->length - 1;
	int k = 1;

	while (i <= j)
	{
		//k=1,��Ԫ����i����k=0����Ԫ����j��
		int oddi = L->data[i] & 1, oddj = L->data[j] & 1;

		if (k && oddj) 
		{ 
			swap(&L->data[i], &L->data[j]); 
			k = 1 - k;
			i++;
		}
		if (!k && !oddi)
		{
			swap(&L->data[i], &L->data[j]);
			k = 1 - k;
			j--;
		}

		else if (k && !oddj) j--;
		else if (!k && oddi) i++;
	}

	for (int i = 0; i < L->length; i++) printf("%d ", L->data[i]);
	printf("\n");
	return 0;
}

/*****completed******/
/*��(4)
  ��������Del_x
  ���ܣ�ɾ�����Ա������е�Ԫ��x
  ���룺sqlist��ָ��LA����ɾ��Ԫ��x
  �����ɾ��x���LA
  Ҫ��ʱ�临�Ӷȣ�O(n)���ռ临�Ӷȣ�O(1)   */


int Del_x(sqlist* L, int x)
{
	int i = 0, j = L->length - 1;
	int k = -1;
	while (i <= j)
	{
		int judgei = (L->data[i] == x), judgej = (L->data[j] == x);
		if (judgei && !judgej)
		{
			swap(&L->data[i], &L->data[j]);
			k = j;
			i++; j--;
		}
		else if (judgei && judgej) { k = j; j--; }
		else if (!judgei && judgej) { k = j; i++; j--; }
		else i++;
	}

	if (k == -1)
	{
		printf("ERROR Input!  No x exists\n");
		return 0;
	}
	else
	{
		L->data = (ElemType*)realloc(L->data, k * sizeof(ElemType));
		L->length = k;
		L->listsize = k;
	}

	for (int i = 0; i < L->length; i++) printf("%d ", L->data[i]);
	printf("\n");
	return 0;
}

/*****completed******/
/*��(5)
  ��������Del_x_y
  ���ܣ�ɾ�����Ա�������ֵ��[x,y]�е�Ԫ��
  ���룺sqlist��ָ��L
  �����ɾ����ӦԪ�غ��L   */

//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1);

int Del_x_y(sqlist* L, int x, int y)
{
	if (x > y)
	{
		printf("ERROR Input!\n");
		return 0;
	}
	
	int i = 0, j = L->length - 1;
	int k = 0;
	while (i <= j)
	{
		int judgei = (L->data[i] >= x && L->data[i] <= y);
		int judgej = (L->data[j] >= x && L->data[j] <= y);

		if (judgei && !judgej)
		{
			swap(&L->data[i], &L->data[j]);
			k = j;
			i++; j--;
		}
		else if (judgei && judgej) { k = j; j--; }
		else if (!judgei && judgej) { k = j; i++; j--; }
		else i++;
	}

	if (k == -1) printf("No number belongs to [x,y].\n");
	else
	{
		L->data = (ElemType*)realloc(L->data, k * sizeof(ElemType));//��������ռ�
		L->length = k;
		L->listsize = k;
	}
	for (int i = 0; i < L->length; i++) printf("%d ", L->data[i]);
	printf("\n");
	return 0;
}

//��(2)-��(5)�����㷨��һ����