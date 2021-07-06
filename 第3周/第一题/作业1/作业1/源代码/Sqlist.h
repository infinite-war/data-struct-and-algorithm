#include <stdio.h>
#include <stdlib.h>
#include "gloabledef.h"

typedef struct 
{
   ElemType *data;/*存储空间的基地址*/
   int length;   /*表的长度（已存入的元素个数）*/
   int listsize;  /*当前存储空间的容量（能够存入的元素个数）*/
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

