#include "Sqlist.h"


int InitList(sqlist *L)
{   
       /* 存储空间初始化 */
      L->data= (int*)malloc(INITSIZE * sizeof(int));//补全代码，申请INITSIZE大小空间代码
	if(!L->data) {
		printf("动态存储分配失败!\n");
		return FALSE; /*执行此函数则中止程序运行*/
	        }
        L-> length=0;   /* 长度为0 */
        L->listsize = INITSIZE; /* 当前存储容量初始化 */
        return TRUE;
}

int GetLen(sqlist *L)
{   
	return  L->length;  //补全代码，返回表长
}

int GetElem(sqlist *L, int i, ElemType *e)
{   
      if( i<1 || i>L->length )  //补全代码，写出所取元素序号超出范围的判断条件
            return FALSE;
       else 
            *e=L->data[i-1];   //补全代码，写出取值语句
        return TRUE;
}

int Locate(sqlist *L, ElemType x)
{   
      int  i=0;
      while( L->data[i]!=x && i<L->length)   //补全代码，循环条件
          i++;
      if (i<L->length)
            return i+1;
      else 
            return -1;
}
void ClearList(sqlist *L)
{   
        free(L->data);
        L->data = (ElemType*)malloc(sizeof(ElemType)*INITSIZE);
        L-> length=0;   /* 长度为0 */
        L->listsize = INITSIZE; /* 当前存储容量初始化 */
}

int Insert(sqlist *L,int i,ElemType item)
{     
     int j;
     if( i<1 || i>L->length+1 ) //补全代码，写出i越界插入判断条件
	     return FALSE;
     if(  L->length==L->listsize ) //补全代码，数组是否已满
		againMalloc(L);  /*重新分配更大的存储空间*/
     for(j=L->length-1;j>=i-1;j--)/*因为数组的下标从0开始*/
           L->data[j+1]=L->data[j]; //补全代码，写出后移语句
           L->data[i-1]=item; //补全代码写出插入语句
     L->length++; /*元素个数增1*/
     return TRUE;
}
void againMalloc(sqlist *L){
      /*空间扩展为原来的2倍，并由p指针所指向，原内容自动拷贝到p所指向的存储空间*/
       ElemType *p=(ElemType *)realloc((L->data), 2*L->listsize*(sizeof(ElemType)));
       if(!p){  /*分配失败则退出运行*/
               printf("存储空间分配失败！");
               exit(1);
	}
        L->data=p; /*使list指向新线性表空间*/
        L->listsize=2*L->listsize; /*线性表空间大小修改为新的长度*/
}
int DeleteElem(sqlist *L, int i){
	int j;
     	if( i<1 || i>L->length )  //补全代码，写出i越界判断条件
         		return FALSE;/*i越界，删除失败*/
     	for(j=i;j<L->length;j++)
        		L->data[j-1]=L->data[j];//补全代码写出前移语句
     	L->length--;
     	return TRUE;
}
void OutputList(sqlist L)
{
	int i;
	printf("\n表中数据为：");
	for (i=0;i<L.length;i++)
		printf("%d  ",L.data[i]);
	printf("\n");
}

void SqlistTest()
{
	sqlist L;
	int choice;
	int InputNum;
	int i;
	int e;
	int result;
	
	choice = -1;
	while (choice != 0) 
	{
		printf("线性表示例：\n");
		printf( "1. 建立\n");
		printf( "2. 输入\n");
		printf( "3. 取值\n");
		printf( "4. 查找\n");
		printf( "5. 插入\n");
		printf( "6. 删除\n");
		printf( "7. 输出\n");
		printf( "0. 退出\n\n");
		printf("\n请选择:");
		scanf("%d", &choice);
		switch (choice) 
		{
		case 1://创建顺序表
			if (InitList(&L))
				printf("成功建立顺序表\n\n");
			else
				printf( "顺序表建立失败\n\n");
			break;

		case 2: //顺序表信息输入
			ClearList(&L);
			printf("请输入顺序表元素个数：");
			scanf("%d",&InputNum);
			printf("\n请输入元素：");
			for (i=0;i<InputNum;i++)
			{
				scanf("%d",&L.data[i]);
			}
			L.length=InputNum;
			printf("输入数据成功！\n");
			break;

		case 3://顺序表的取值
			printf("请输入一个位置用来取值：\n");
			scanf("%d",&i);
			if (GetElem(&L, i, &e)) printf("%d\n",e);//补全代码，调用取值函数，注意根据返回值做不同操作
			else printf("ERROR!\n");
			break;

		case 4: //顺序表的查找
			printf("请输入所要查找的数值:");
			scanf("%d",&e);
			if (Locate(&L, e)>0) printf("%d在位置%d\n", e, Locate(&L, e));//补全代码，调用取值函数，注意根据返回值做不同操作
			else printf("can't find %d\n", e);
			break;

		case 5: //顺序表的插入
			printf("请输入插入的位置:");
			scanf("%d",&i);
			printf("\n请输入插入数值:");
			scanf("%d",&e);
			if (Insert(&L, i, e) == TRUE) OutputList(L);//补全代码，调用取值函数，注意根据返回值做不同操作
			else printf("ERROR Input!\n");
			break;

  	   case 6: //顺序表的删除
			printf( "\n请输入所要删除的数据位置:");
			scanf("%d",&i);
			if (DeleteElem(&L, i) == FALSE) printf("ERROR Input!\n");//补全代码，调用取值函数，注意根据返回值做不同操作
			else OutputList(L);
			break;

		case 7: //顺序表的输出
			OutputList(L);
			break;
		}
	}
	return ;
}

void CreateSqlist(sqlist *L)
{
	L->data = (int*)malloc(INITSIZE * sizeof(int));
	L->length = 0;
	L->listsize = INITSIZE;//自己尝试编写根据提示输入顺序表元素个数，数值，创建顺序表
}
