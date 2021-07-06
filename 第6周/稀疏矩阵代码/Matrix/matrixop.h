#include "globaldef.h"
#define MAXSIZE 42
#pragma once
typedef   struct  node {/*三元组类型定义*/
	int  i;
	int j;
	ElemType e;
} tupletype;
typedef struct table{
	 tupletype   data[MAXSIZE];/*三元组线性表*/
	 int RowNum;   /*行数*/
	 int ColNum;    /*列数*/
	 int NZNum;     /*非零元素个数*/
}table;
table InitTable1();
table InitTable2();
int  assign(table* T, ElemType* x, int r, int c);
void OutputTable(table mTable);
int fast_trans_matrix(table* M, table* T);

