#include "globaldef.h"
#include "matrixop.h"

table InitTable1()
{
	int k;
	table mTable;
	printf("请输入矩阵行数，列数，非零元素个数:");
	scanf("%d %d %d", &mTable.ColNum, & (mTable.RowNum), &(mTable.NZNum));
	
	printf("\n请按行依次输入非零元素行号、列号、值：");
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
	printf("初始化长度%d\n", mTable.NZNum);
	return mTable;

}
int  assign(table* T, ElemType* x, int r, int c)
{/*从三元组T中找到行标r列标c的元素，然后
将值送到x所指向的单元*/
	int k = 0;
	/*位置非法返回0*/
	if (r < 0 || r >= T->RowNum || c < 0 || c >= T->ColNum)
		return 0;
	/*找到行标是r列标是c的位置k*/
	for (; k < T->NZNum; k++)
		if (r == T->data[k].i && c == T->data[k].j)
			break;

	   /*若有该位置元素，读取元素的值*/

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
	/*找到插入位置k*/
	while (k<T->NZNum && r>T->data[k].i) k++;
	while (k<T->NZNum && r == T->data[k].i
		&& c>T->data[k].j)
		k++;
	/*已有该位置元素，修改值为x*/
	if (T->data[k].i == r && T->data[k].j == c)
		T->data[k].e = x;
	else
		/*没有,在第k个元素前面插入新元素*/
	{  /*其后元素后移*/
		for (i = T->NZNum - 1; i >= k; i--)
			T->data[i + 1] = T->data[i];
		/*完成插入*/
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
	printf("表中有%d个数据", mTable.NZNum);
	printf("表中内容为：\n");
	for (k = 0; k < mTable.NZNum; k++)
		printf("%d %d %d\n", mTable.data[k].i, mTable.data[k].j, mTable.data[k].e);
	printf("\n");
	return;
}

int fast_trans_matrix(table* M, table* T)
/*矩阵的快速转置*/
{
	int i, col, p, k,q;
	int num[MAXSIZE], cpot[MAXSIZE];
	T->RowNum = M->ColNum;
	T->ColNum = M->RowNum;
	T->NZNum = M->NZNum;
	if (M->NZNum <= 0)      return(0);
	/*计算num的值，注意计算前先清零*/
	for (i = 0; i < M->ColNum; i++)
		num[i] = 0;
	for (i = 0; i < M->NZNum; i++)
	{
		k = M->data[i].j;
		num[k]++;
	}
	/*计算cpot值*/
	cpot[0] = 0;
	for (i = 1; i < M->ColNum; i++)
		cpot[i] = cpot[i - 1] + num[i - 1];
	/*扫描M的三元组表完成转置运算，对M中每一个三元
	   组转置后放入T的合适位置*/
	for (p = 0; p < M->NZNum; p++)
	{ /*得到M当前位置p三元组在T的位置k*/
		col = M->data[p].j;
		q = cpot[col];
		T->data[q].i = M->data[p].j;
		T->data[q].j = M->data[p].i;
		T->data[q].e = M->data[p].e;
		cpot[col]++; /*注意*/
	}
	return(1);
}
