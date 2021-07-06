#include <stdio.h>
#include <stdlib.h>
#include "gloabledef.h"

typedef struct 
{
   ElemType *data;/*�洢�ռ�Ļ���ַ*/
   int length;   /*��ĳ��ȣ��Ѵ����Ԫ�ظ�����*/
   int listsize;  /*��ǰ�洢�ռ���������ܹ������Ԫ�ظ�����*/
}sqlist;

int InitList(sqlist *L);
int GetLen(sqlist *L);
int GetElem(sqlist *L, int i, ElemType *e);
int Locate(sqlist *L,ElemType x);
void ClearList(sqlist *L);
int Insert(sqlist *L,int i,ElemType item);
void againMalloc(sqlist *L);
int DeleteElem(sqlist *L, int i);
void SqlistTest();
void OutputList(sqlist L);
void CreateSqlist(sqlist *L);

