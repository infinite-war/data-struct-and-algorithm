//#include "Linklist.h"
#include "question_two.h"

/*函数名：IfEmpty
  功能：判断L是不是空表
  输入：Node型指针L
  输出：判断L是不是空表   */
int IfEmpty(Node* L)
{
    if (L->data == 0)
    {
        printf("the linklist is empty!\n");
        return ERROR;
    }
    return TRUE;
}

//completed
/*函数名：Initlist
  功能：建立链表
  输入：Node型指针L
  输出：构造链表L   */
int InitList(Node *L)
{   
    L->data = 0;
    L->next = NULL;
    return TRUE;
}

//completed
/*函数名：GetLen
  功能：取链表的表长
  输入：Node型指针L
  输出：L的表长   */
int GetLen(Node* L) { return  L->data; }


//completed
/*函数名：GetElem
  功能：取链表某个位置的值
  输入：Node型指针L，指定位置i
  输出：取L的第i个位置的元素 */
int GetElem(Node *L, int i)
{   
    if (IfEmpty(L)== ERROR)  return ERROR;

    else if (i<0 || i>L->data)
    {
        printf("error input!\n");
        return ERROR;
    }
    Node* p = L->next;
    int j = 1;
    while (p ->next!= NULL && j < i)
    {
        p = p->next;
        j++;
    }
    printf("the number locates in %d is %d\n", i, p->data);
    return p->data;
}
/*函数名：Locate
  功能：寻找x在首次出现的位置
  输入：Node型指针L，待查找元素x
  输出：x在L中首次出现的位置   */
int Locate(Node *L, ElemType x)
{   
    if (IfEmpty(L) == ERROR)  return ERROR;

    int temp = 1;
    Node* p = L->next;
    while (p != NULL)
    {
        if (p->data == x)
        {
            printf("x's first location:%d\n", temp);
            return TRUE;
        }
        p = p->next;
        temp++;
    }
    printf("x is not exist!\n");
    return ERROR;
}


/*函数名：ClearLisr=t
  功能：清空链表
  输入：Node型指针L
  输出：清空链表L   */
void ClearList(Node *L)
{   
    Node* temp;
    while (L->next != NULL)
    {
        temp = L->next;
        L->next = L->next->next;
        free(temp);
    }
    free(L);
    L = NULL;
}

//completed
/*函数名：TailInsert
  功能：向链表添加元素（尾插法）
  输入：Node型指针L
  输出：链表L表尾插值   */
int TailInsert(Node *L)
{     
    int item,n,temp=0;
    Node* p=L;
    Node* s;
    printf("input the number of element:");
    scanf("%d", &n);
    printf("input the detail element:");
    while (temp < n)
    {
        scanf("%d", &item);
        s = (Node*)malloc(sizeof(Node));
        if (NULL == s)
        {
            printf("mission failed!\n");
            return ERROR;
        }
        s->data = item;
        p->next = s;
        p = p->next;
        temp++;
        L->data++;
    }
    p->next = NULL;
    printf("input completed.\n");
    return TRUE;
}

//completed
/*函数名：HeadInsert
  功能：向链表添加元素（头插法）
  输入：Node型指针L
  输出：链表L表头插值   */
int HeadInsert(Node* L,ElemType x)
{
    if (IfEmpty(L) == ERROR) return ERROR;
    Node* s = (Node*)malloc(sizeof(Node));
    if (NULL == s)
    {
        printf("mission failed!\n");
        return ERROR;
    }
    s->data = x;
    s->next = L->next;
    L->next = s;
    L->data++;
    return TRUE;
}

//completed
/*函数名：Insert
  功能：在链表的位置i处插入元素
  输入：Node型指针L，待插入位置i，待插入元素item
  输出：将item插入L的位置i   */
int Insert(Node* L, int i, ElemType item)
{
    if (IfEmpty(L) == ERROR)  return ERROR;

    if (i<1 || i>L->data + 1)
    {
        printf("input error!\n");
        return ERROR;
    }

    Node* p = L->next;
    Node* s = (Node*)malloc(sizeof(Node));
    if (NULL == s)
    {
        printf("mission failed.\n");
        return ERROR;
    }
    s->data = item;
    s->next = NULL;
    int temp=1;
    while (p != NULL && temp < i - 1)
    {
        p = p->next;
        temp++;
    }
    
    if (temp == L->data)
    {
        p->next = s;
        s->next = NULL;
        L->data++;
        return TRUE;
    }

    s->next = p->next;
    p->next = s;
    L->data++;
    return TRUE;
}


/*函数名：DeleteElem
  功能：删除链表在i处的元素
  输入：Node型指针L，待删除位置i
  输出：删除L在位置i处的元素   */
int DeleteElem(Node *L, int i)
{
    if (IfEmpty(L) == ERROR) return ERROR;
    if (i<1 || i>L->data)
    {
        printf("error input!\n");
        return ERROR;
    }
    int temp = 1;
    Node* p = L->next;
    Node* s = (Node*)malloc(sizeof(Node));
    
    while (p != NULL && temp < i - 1)
    {
        p = p->next;
        temp++;
    }
    if (i == 1)  //删除表首位的元素
    {
        if (L->data == 1)    //如果仅剩一个元素
        {
            L->next = NULL;
            free(p);
            L->data--;
            return TRUE;
        }
        s = L->next;
        L->next = L->next->next;
        free(s);
        L->data--;
        return TRUE;
    }
    else if (temp == L->data - 1) //删除表尾元素
    {
        s = p->next;
        p->next = NULL;
        free(s);
        L->data--;
        return TRUE;
    }
    s = p->next;
    p->next = p->next->next;
    free(s);
    L->data--;
    return TRUE;
}
 
 

/*函数名：OutputList
  功能：输出链表
  输入：Node型指针L
  输出：输出链表L   */
void OutputList(Node* L)
{
    Node* p = L->next;
    //printf("%d\n", L->data);
    if (L->data==0) printf("the linklist is empty!\n");
    else
    {
        printf("\n表中数据为：");
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}


//void CreateSqlist(sqlist* L)
//{
//	L->data = (int*)malloc(INITSIZE * sizeof(int));
//	L->length = 0;
//	L->listsize = INITSIZE;//自己尝试编写根据提示输入顺序表元素个数，数值，创建顺序表
//}
//




void   LinklistTest()
{
    Node L;

    int choice = -1;
    int InputNum;
    int i, result;

    while (choice != 0)
    {
        printf("单链表示例:\n");
        printf("1. 建立并输入\n");
        printf("2. 取值\n");
        printf("3. 查找\n");
        printf("4. 插入\n");
        printf("5. 删除\n");
        printf("6. 输出\n");
        printf("7. 第二题各小题实验结果\n");
        printf("0. 退出\n\n");
        printf("\n请选择:");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1://建立L并输入L
                if (!InitList(&L))
                {
                    printf("mission failed!\n");
                    break;
                }

                //printf("%d\n", L.data);
                printf("an empty linklist is created.\n");
                TailInsert(&L);
                break;

            case 2://取链表L某个位置的值
                printf("请输入要查找的位置i：");
                scanf("%d", &InputNum);
                GetElem(&L, InputNum);
                break;
            
            case 3://在链表L中查找x
                printf("请输入要查找的数x：");
                scanf("%d", &InputNum);
                Locate(&L, InputNum);
                break;

            case 4://在指定位置插入x
                printf("请输入要插入的值x：");
                scanf("%d", &InputNum);
                printf("请输入要插入的位置i：");
                scanf("%d", &i);
                Insert(&L, i, InputNum);
                break;

            case 5://删除指定位置的值
                printf("请输入要删除的位置i：");
                scanf("%d", &InputNum);
                DeleteElem(&L, InputNum);
                break;

            case 6:
                OutputList(&L);
                break;

            case 7:
                printf("开始前，请输入另一个链表M：");
                Node M;
                if (!InitList(&M))
                {
                    printf("mission failed!\n");
                    break;
                }
                printf("an empty linklist is created.\n");
                TailInsert(&M);
                int temp_choice=-1,tt;

                while (temp_choice != 0)
                {
                    printf("1. 删除L中的最大元素\n");
                    printf("2. 将L递增排序\n");
                    printf("3. 将L倒序\n");
                    printf("4. 分离L的奇偶位\n");
                    printf("5. 合并L与M（升序且去重）\n");
                    printf("6. 输出L或M\n");
                    printf("0. 退出该分支\n\n");
                    printf("请输入：");
                    scanf("%d", &temp_choice);
                    switch (temp_choice)
                    {
                        case 1://删除L中的最大元素
                            if (Del_max(&L))
                            {
                                printf("the maxnum had deleted.\n");
                                OutputList(&L);
                            }

                            break;

                        case 2://将L递增排序
                            printf("before sort:"); OutputList(&L);
                            Upsort(&L);
                            printf("after sort:"); OutputList(&L);
                            break;

                        case 3://将L倒序
                            reverse(&L);
                            break;

                        case 4://分离L的奇偶位
                            printf("before devide(L):");
                            OutputList(&L);
                            Node L1; InitList(&L1);
                            Devide_a_b(&L, &L1);
                            printf("after devide:\n");
                            printf("L:"); OutputList(&L);
                            printf("L1:"); OutputList(&L1);
                            break;

                        case 5://合并L与M（升序且去重）
                            printf("before union:\n");
                            printf("L:"); OutputList(&L);
                            printf("\nM:"); OutputList(&M);
                            DownUnion(&L, &M);
                            printf("after union:\n");
                            printf("L:"); OutputList(&L);
                            break;

                        case 6://输出L或M
                            printf("1.输出L\n2.输出M\n请输入：");
                            scanf("%d", &tt);
                            if (tt == 1) OutputList(&L);
                            else OutputList(&M);
                            break;
                    }
                }

            case 0:
                exit(0);
        }
    }




}