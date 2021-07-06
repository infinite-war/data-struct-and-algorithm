#include "Linklist.h"
//#include "question_two.h"

/*��������IfEmpty
  ���ܣ��ж�L�ǲ��ǿձ�
  ���룺Node��ָ��L
  ������ж�L�ǲ��ǿձ�   */
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
/*��������Initlist
  ���ܣ���������
  ���룺Node��ָ��L
  �������������L   */
int InitList(Node *L)
{   
    L->data = 0;
    L->next = NULL;
    return TRUE;
}

//completed
/*��������GetLen
  ���ܣ�ȡ����ı�
  ���룺Node��ָ��L
  �����L�ı�   */
int GetLen(Node* L) { return  L->data; }


//completed
/*��������GetElem
  ���ܣ�ȡ����ĳ��λ�õ�ֵ
  ���룺Node��ָ��L��ָ��λ��i
  �����ȡL�ĵ�i��λ�õ�Ԫ�� */
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
/*��������Locate
  ���ܣ�Ѱ��x���״γ��ֵ�λ��
  ���룺Node��ָ��L��������Ԫ��x
  �����x��L���״γ��ֵ�λ��   */
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


/*��������ClearLisr=t
  ���ܣ��������
  ���룺Node��ָ��L
  ������������L   */
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
/*��������TailInsert
  ���ܣ����������Ԫ�أ�β�巨��
  ���룺Node��ָ��L
  ���������L��β��ֵ   */
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
/*��������Insert
  ���ܣ��������λ��i������Ԫ��
  ���룺Node��ָ��L��������λ��i��������Ԫ��item
  �������item����L��λ��i   */
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
        s->next = NULL;
        p->next = s;
        L->data++;
        return TRUE;
    }

    s->next = p->next;
    p->next = s;
    L->data++;
    return TRUE;
}


/*��������DeleteElem
  ���ܣ�ɾ��������i����Ԫ��
  ���룺Node��ָ��L����ɾ��λ��i
  �����ɾ��L��λ��i����Ԫ��   */
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
    if (i == 1)  //ɾ������λ��Ԫ��
    {
        if (L->data == 1)    //�����ʣһ��Ԫ��
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
    else if (temp == L->data - 1) //ɾ����βԪ��
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
 
 

/*��������OutputList
  ���ܣ��������
  ���룺Node��ָ��L
  ������������L   */
void OutputList(Node* L)
{
    Node* p = L->next;
    //printf("%d\n", L->data);
    if (L->data==0) printf("the linklist is empty!\n");
    else
    {
        printf("\n��������Ϊ��");
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
//	L->listsize = INITSIZE;//�Լ����Ա�д������ʾ����˳���Ԫ�ظ�������ֵ������˳���
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
        printf("������ʾ��:\n");
        printf("1. ����������\n");
        printf("2. ȡֵ\n");
        printf("3. ����\n");
        printf("4. ����\n");
        printf("5. ɾ��\n");
        printf("6. ���\n");
        printf("0. �˳�\n\n");
        printf("\n��ѡ��:");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1://����L������L
                //ClearList(&L);
                if (!InitList(&L))
                {
                    printf("mission failed!\n");
                    break;
                }

                //printf("%d\n", L.data);
                printf("an empty linklist is created.\n");
                TailInsert(&L);
                break;

            case 2://ȡ����Lĳ��λ�õ�ֵ
                printf("������Ҫ���ҵ�λ��i��");
                scanf("%d", &InputNum);
                GetElem(&L, InputNum);
                break;
            
            case 3://������L�в���x
                printf("������Ҫ���ҵ���x��");
                scanf("%d", &InputNum);
                Locate(&L, InputNum);
                break;

            case 4://��ָ��λ�ò���x
                printf("������Ҫ�����ֵx��");
                scanf("%d", &InputNum);
                printf("������Ҫ�����λ��i��");
                scanf("%d", &i);
                Insert(&L, i, InputNum);
                break;

            case 5://ɾ��ָ��λ�õ�ֵ
                printf("������Ҫɾ����λ��i��");
                scanf("%d", &InputNum);
                DeleteElem(&L, InputNum);
                break;

            case 6:
                OutputList(&L);
                break;

            case 0:
                exit(0);
        }
    }




}