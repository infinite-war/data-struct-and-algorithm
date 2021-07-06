#pragma once
#include "Sqlist.h"


int swap(int* x, int* y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
	return 0;
}


/*题(1) 
  函数名：DownUnion
  功能：合并两个非递减顺序表LA,LB形成新的非递减顺序表LC
  输入：sqlist型指针LA,LB，待合并的sqlist型指针LC
  输出：合并后的LC  */

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
/*题(2)
  函数名：Del_odd
  功能：删除线性表中所有奇数
  输入：sqlist型指针L
  输出：删除所有奇数的L
  要求：时间复杂度：O(n),空间复杂度：O(1)   */

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
		L->data = (ElemType*)realloc(L->data, k * sizeof(ElemType));//重新申请空间
		//L->data = (int*)realloc(L->data, (++L->listsize) * sizeof(int));
		L->length = k;
		L->listsize = k;
		for (int i = 0; i < L->length; i++) printf("%d ", L->data[i]);
	}
	

	printf("\n");
	return 0;
}



/*****completed******/
/*题(3)
  函数名：Devide_odd_even
  功能：以第一个元素为基准，将顺序表中的奇数排前，偶数排后
  输入：sqlist型指针L
  输出：排序后的L   */

int Devide_odd_even(sqlist* L)
{
	int first = L->data[0];
	int i = 0, j = L->length - 1;
	int k = 1;

	while (i <= j)
	{
		//k=1,首元素在i处；k=0，首元素在j处
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
/*题(4)
  函数名：Del_x
  功能：删除线性表中所有的元素x
  输入：sqlist型指针LA，待删除元素x
  输出：删除x后的LA
  要求：时间复杂度：O(n)，空间复杂度：O(1)   */


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
/*题(5)
  函数名：Del_x_y
  功能：删除线性表中所有值在[x,y]中的元素
  输入：sqlist型指针L
  输出：删除相应元素后的L   */

//时间复杂度O(n),空间复杂度O(1);

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
		L->data = (ElemType*)realloc(L->data, k * sizeof(ElemType));//重新申请空间
		L->length = k;
		L->listsize = k;
	}
	for (int i = 0; i < L->length; i++) printf("%d ", L->data[i]);
	printf("\n");
	return 0;
}

//题(2)-题(5)大体算法是一样的