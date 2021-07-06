#include "gloabledef.h"

//============================邻接矩阵===============================
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
    Vertex vt[MAXSIZE];          //暂时无用
}MatrixVertex;

//=============================邻接表================================
//边界点类型
typedef struct ANode
{
    int archead;                 //弧头的编号
    int weight;                  //权重
    struct ANode* nextarc;
}ArcNode;

//邻接表头节点类型
typedef struct Vnode
{
    ElemType data;               //顶点的内容
    ArcNode* firstarc;           //该顶点的第一条边
}VNode;

//邻接表
typedef struct
{
    VNode head[MAXSIZE];
    int n, e;                //顶点数=n ，边数=e
}Adjgraph;


typedef struct
{  
    int w;     //权值
    int start; //弧尾
    int end;   //弧头

}edge;


//====================================函数声明==============================
//操作
void graphTest();
void CreateGraph(Adjgraph* G,MatrixVertex* M);
void PrintGraph(Adjgraph* G);
void PrintMatrix(MatrixVertex* M);
void DestoryGraph(Adjgraph* G);
void dfs(Adjgraph* G, int v);
void bfs(Adjgraph* G, int v);

//基础任务
void Friends(MatrixVertex* M);
/*辅助函数*/
int find(int a);
void combine(int x, int y);
//void evengraph(MatrixVertex* M);

//提高任务
void topological_sort();
void villege_connect(MatrixVertex* M);