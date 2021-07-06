#include "gloabledef.h"

//============================�ڽӾ���===============================
typedef struct
{
    int number;
    string sight_name;
    string sight_info;
}Vertex;

typedef struct
{
    int matrix[MAXSIZE][MAXSIZE];
    int n, e;
    Vertex vt[MAXSIZE];          //��ʱ����
}MatrixVertex;

//=============================�ڽӱ�================================
//�߽������
typedef struct ANode
{
    int archead;                 //��ͷ�ı��
    int weight;                  //Ȩ��
    struct ANode* nextarc;
}ArcNode;

//�ڽӱ�ͷ�ڵ�����
typedef struct Vnode
{
    ElemType data;               //���������
    ArcNode* firstarc;           //�ö���ĵ�һ����
}VNode;

//�ڽӱ�
typedef struct
{
    VNode head[MAXSIZE];
    int n, e;                //������=n ������=e
}Adjgraph;


typedef struct
{  
    int w;     //Ȩֵ
    int start; //��β
    int end;   //��ͷ

}edge;


//====================================��������==============================
//����
void graphTest();
void CreateGraph(Adjgraph* G,MatrixVertex* M);
void PrintGraph(Adjgraph* G);
void PrintMatrix(MatrixVertex* M);
void DestoryGraph(Adjgraph* G);
void dfs(Adjgraph* G, int v);
void bfs(Adjgraph* G, int v);

//��������
void Friends(MatrixVertex* M);
/*��������*/
int find(int a);
void combine(int x, int y);
//void evengraph(MatrixVertex* M);

//�������
void topological_sort();
void villege_connect(MatrixVertex* M);