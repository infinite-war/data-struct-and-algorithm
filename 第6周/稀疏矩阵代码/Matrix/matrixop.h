#include "globaldef.h"
#define MAXSIZE 42
#pragma once
typedef   struct  node {/*��Ԫ�����Ͷ���*/
	int  i;
	int j;
	ElemType e;
} tupletype;
typedef struct table{
	 tupletype   data[MAXSIZE];/*��Ԫ�����Ա�*/
	 int RowNum;   /*����*/
	 int ColNum;    /*����*/
	 int NZNum;     /*����Ԫ�ظ���*/
}table;
table InitTable1();
table InitTable2();
int  assign(table* T, ElemType* x, int r, int c);
void OutputTable(table mTable);
int fast_trans_matrix(table* M, table* T);

