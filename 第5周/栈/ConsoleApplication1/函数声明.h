#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "gloabledef.h"
typedef struct
{
	ElemType* data;
	int length;
	int size;
}SqStack;


int IfEmpty(SqStack*S);
int InitStack(SqStack *S);
int Stacklen(SqStack *S);
void ClearStack(SqStack *S);
int GetTop(SqStack *S, ElemType *e);
int Push(SqStack*S, ElemType item);
int DisSqStack(SqStack*S);
int Pop(SqStack*S, ElemType *e);
void SqStackTest();