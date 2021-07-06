#include <stdio.h>
#include <stdlib.h>
#include "gloabledef.h"


typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

int IfEmpty(Node* L);
int InitList(Node *L);
int GetLen(Node *L);
int GetElem(Node *L, int i, ElemType *e);
int Locate(Node *L,ElemType x);
void ClearList(Node *L);
int Insert(Node *L,int i,ElemType item);
//void againMalloc(Node*L);
int DeleteElem(Node*L, int i);
void SqlistTest();
void OutputList(Node L);
void CreateSqlist(Node *L);
int TailInsert(Node* L);
int HeadInsert(Node* L, ElemType x);
