#include "Sqlist.h"


int InitList(sqlist *L)
{   
       /* �洢�ռ��ʼ�� */
      L->data= (int*)malloc(INITSIZE * sizeof(int));//��ȫ���룬����INITSIZE��С�ռ����
	if(!L->data) {
		printf("��̬�洢����ʧ��!\n");
		return FALSE; /*ִ�д˺�������ֹ��������*/
	        }
        L-> length=0;   /* ����Ϊ0 */
        L->listsize = INITSIZE; /* ��ǰ�洢������ʼ�� */
        return TRUE;
}

int GetLen(sqlist *L)
{   
	return  L->length;  //��ȫ���룬���ر�
}

int GetElem(sqlist *L, int i, ElemType *e)
{   
      if( i<1 || i>L->length )  //��ȫ���룬д����ȡԪ����ų�����Χ���ж�����
            return FALSE;
       else 
            *e=L->data[i-1];   //��ȫ���룬д��ȡֵ���
        return TRUE;
}

int Locate(sqlist *L, ElemType x)
{   
      int  i=0;
      while( L->data[i]!=x && i<L->length)   //��ȫ���룬ѭ������
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
        L-> length=0;   /* ����Ϊ0 */
        L->listsize = INITSIZE; /* ��ǰ�洢������ʼ�� */
}

int Insert(sqlist *L,int i,ElemType item)
{     
     int j;
     if( i<1 || i>L->length+1 ) //��ȫ���룬д��iԽ������ж�����
	     return FALSE;
     if(  L->length==L->listsize ) //��ȫ���룬�����Ƿ�����
		againMalloc(L);  /*���·������Ĵ洢�ռ�*/
     for(j=L->length-1;j>=i-1;j--)/*��Ϊ������±��0��ʼ*/
           L->data[j+1]=L->data[j]; //��ȫ���룬д���������
           L->data[i-1]=item; //��ȫ����д���������
     L->length++; /*Ԫ�ظ�����1*/
     return TRUE;
}
void againMalloc(sqlist *L){
      /*�ռ���չΪԭ����2��������pָ����ָ��ԭ�����Զ�������p��ָ��Ĵ洢�ռ�*/
       ElemType *p=(ElemType *)realloc((L->data), 2*L->listsize*(sizeof(ElemType)));
       if(!p){  /*����ʧ�����˳�����*/
               printf("�洢�ռ����ʧ�ܣ�");
               exit(1);
	}
        L->data=p; /*ʹlistָ�������Ա�ռ�*/
        L->listsize=2*L->listsize; /*���Ա�ռ��С�޸�Ϊ�µĳ���*/
}
int DeleteElem(sqlist *L, int i){
	int j;
     	if( i<1 || i>L->length )  //��ȫ���룬д��iԽ���ж�����
         		return FALSE;/*iԽ�磬ɾ��ʧ��*/
     	for(j=i;j<L->length;j++)
        		L->data[j-1]=L->data[j];//��ȫ����д��ǰ�����
     	L->length--;
     	return TRUE;
}
void OutputList(sqlist L)
{
	int i;
	printf("\n��������Ϊ��");
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
		printf("���Ա�ʾ����\n");
		printf( "1. ����\n");
		printf( "2. ����\n");
		printf( "3. ȡֵ\n");
		printf( "4. ����\n");
		printf( "5. ����\n");
		printf( "6. ɾ��\n");
		printf( "7. ���\n");
		printf( "0. �˳�\n\n");
		printf("\n��ѡ��:");
		scanf("%d", &choice);
		switch (choice) 
		{
		case 1://����˳���
			if (InitList(&L))
				printf("�ɹ�����˳���\n\n");
			else
				printf( "˳�����ʧ��\n\n");
			break;

		case 2: //˳�����Ϣ����
			ClearList(&L);
			printf("������˳���Ԫ�ظ�����");
			scanf("%d",&InputNum);
			printf("\n������Ԫ�أ�");
			for (i=0;i<InputNum;i++)
			{
				scanf("%d",&L.data[i]);
			}
			L.length=InputNum;
			printf("�������ݳɹ���\n");
			break;

		case 3://˳����ȡֵ
			printf("������һ��λ������ȡֵ��\n");
			scanf("%d",&i);
			if (GetElem(&L, i, &e)) printf("%d\n",e);//��ȫ���룬����ȡֵ������ע����ݷ���ֵ����ͬ����
			else printf("ERROR!\n");
			break;

		case 4: //˳���Ĳ���
			printf("��������Ҫ���ҵ���ֵ:");
			scanf("%d",&e);
			if (Locate(&L, e)>0) printf("%d��λ��%d\n", e, Locate(&L, e));//��ȫ���룬����ȡֵ������ע����ݷ���ֵ����ͬ����
			else printf("can't find %d\n", e);
			break;

		case 5: //˳���Ĳ���
			printf("����������λ��:");
			scanf("%d",&i);
			printf("\n�����������ֵ:");
			scanf("%d",&e);
			if (Insert(&L, i, e) == TRUE) OutputList(L);//��ȫ���룬����ȡֵ������ע����ݷ���ֵ����ͬ����
			else printf("ERROR Input!\n");
			break;

  	   case 6: //˳����ɾ��
			printf( "\n��������Ҫɾ��������λ��:");
			scanf("%d",&i);
			if (DeleteElem(&L, i) == FALSE) printf("ERROR Input!\n");//��ȫ���룬����ȡֵ������ע����ݷ���ֵ����ͬ����
			else OutputList(L);
			break;

		case 7: //˳�������
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
	L->listsize = INITSIZE;//�Լ����Ա�д������ʾ����˳���Ԫ�ظ�������ֵ������˳���
}
