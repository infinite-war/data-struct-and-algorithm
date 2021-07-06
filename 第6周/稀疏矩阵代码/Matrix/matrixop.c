#include "globaldef.h"
#include "matrixop.h"

table InitTable1()
{
	int k;
	table mTable;
	printf("�������������������������Ԫ�ظ���:");
	scanf("%d %d %d", &mTable.ColNum, & (mTable.RowNum), &(mTable.NZNum));
	
	printf("\n�밴�������������Ԫ���кš��кš�ֵ��");
	for (k= 0;k < mTable.NZNum; k++)
		scanf("%d %d %d", &(mTable.data[k].i), &(mTable.data[k].j), &(mTable.data[k].e));
	
	return mTable;
}
/*
7 7 8
0 3 22
0 6 15
1 1 11
1 5 17
2 3 -6
3 5 39
4 0 91
5 2 28
*/

table InitTable2()
{
	table mTable;
	ElemType matrix[6][7] = { {0,0,0,22,0,0,15},{0,11,0,0,0,17,0},{0,0,0,-6,0,0,0},{0,0,0,0,0,39,0},{91,0,0,0,0,0,0},{0,0,28,0,0,0,0} };
	int i, j;
	
	mTable.ColNum = 7;
	mTable.RowNum = 6;
	mTable.NZNum = 0;
	for (i = 0; i < mTable.RowNum; i++)
		for (j = 0; j < mTable.ColNum; j++)
			if (matrix[i][j] != 0)
			{
				mTable.data[mTable.NZNum].i = i;
				mTable.data[mTable.NZNum].j = j;
				mTable.data[mTable.NZNum].e = matrix[i][j];
				mTable.NZNum++;
			}
	printf("��ʼ������%d\n", mTable.NZNum);
	return mTable;

}
int  assign(table* T, ElemType* x, int r, int c)
{/*����Ԫ��T���ҵ��б�r�б�c��Ԫ�أ�Ȼ��
��ֵ�͵�x��ָ��ĵ�Ԫ*/
	int k = 0;
	/*λ�÷Ƿ�����0*/
	if (r < 0 || r >= T->RowNum || c < 0 || c >= T->ColNum)
		return 0;
	/*�ҵ��б���r�б���c��λ��k*/
	for (; k < T->NZNum; k++)
		if (r == T->data[k].i && c == T->data[k].j)
			break;

	   /*���и�λ��Ԫ�أ���ȡԪ�ص�ֵ*/

	if (T->data[k].i == r && T->data[k].j == c)
	{
		*x = T->data[k].e; 
		return 1;
	}
	else
	{
		*x = 0;
		return 0;
	}
}

int value(table* T, ElemType x, int r, int c)
{
	int i, k = 0;
	if (r > T->RowNum || c > T->ColNum)     return 0;
	/*�ҵ�����λ��k*/
	while (k<T->NZNum && r>T->data[k].i) k++;
	while (k<T->NZNum && r == T->data[k].i
		&& c>T->data[k].j)
		k++;
	/*���и�λ��Ԫ�أ��޸�ֵΪx*/
	if (T->data[k].i == r && T->data[k].j == c)
		T->data[k].e = x;
	else
		/*û��,�ڵ�k��Ԫ��ǰ�������Ԫ��*/
	{  /*���Ԫ�غ���*/
		for (i = T->NZNum - 1; i >= k; i--)
			T->data[i + 1] = T->data[i];
		/*��ɲ���*/
		T->data[k].i = r;
		T->data[k].j = c;
		T->data[k].e = x;
		T->NZNum++;
	}
	return 1;
}

void OutputTable(table mTable)
{
	int k;
	printf("������%d������", mTable.NZNum);
	printf("��������Ϊ��\n");
	for (k = 0; k < mTable.NZNum; k++)
		printf("%d %d %d\n", mTable.data[k].i, mTable.data[k].j, mTable.data[k].e);
	printf("\n");
	return;
}

int fast_trans_matrix(table* M, table* T)
/*����Ŀ���ת��*/
{
	int i, col, p, k,q;
	int num[MAXSIZE], cpot[MAXSIZE];
	T->RowNum = M->ColNum;
	T->ColNum = M->RowNum;
	T->NZNum = M->NZNum;
	if (M->NZNum <= 0)      return(0);
	/*����num��ֵ��ע�����ǰ������*/
	for (i = 0; i < M->ColNum; i++)
		num[i] = 0;
	for (i = 0; i < M->NZNum; i++)
	{
		k = M->data[i].j;
		num[k]++;
	}
	/*����cpotֵ*/
	cpot[0] = 0;
	for (i = 1; i < M->ColNum; i++)
		cpot[i] = cpot[i - 1] + num[i - 1];
	/*ɨ��M����Ԫ������ת�����㣬��M��ÿһ����Ԫ
	   ��ת�ú����T�ĺ���λ��*/
	for (p = 0; p < M->NZNum; p++)
	{ /*�õ�M��ǰλ��p��Ԫ����T��λ��k*/
		col = M->data[p].j;
		q = cpot[col];
		T->data[q].i = M->data[p].j;
		T->data[q].j = M->data[p].i;
		T->data[q].e = M->data[p].e;
		cpot[col]++; /*ע��*/
	}
	return(1);
}
