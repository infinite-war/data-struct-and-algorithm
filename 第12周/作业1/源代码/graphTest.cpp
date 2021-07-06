#include "graph.h"

//===============全局变量=============
int visited[MAXSIZE] = { 0 };
int fset[MAXSIZE + 1];  //索引数组。同一个集合中，每个元素的fset值为集合中的最小元素值
//====================================

//图测试
void graphTest()
{
    Adjgraph G;
    MatrixVertex M;
    queue<int>q;
    int choice = -1;
    int tchoice = -1;
    int tempa=0, tempb=0, tempc=0;

    while (choice != 0)
    {
        printf("=================MENU_1=================\n");
        printf("=================图示例=================\n");
        printf("1. 建立并输入图\n");
        printf("2. 输出图（邻接表表示）\n");
        printf("2. 输出图（邻接矩阵表示）\n");
        printf("4. 销毁图\n");
        printf("5. DFS输出遍历顺序\n");
        printf("6. BFS输出遍历顺序\n");
        printf("7. 小组任务（基础）\n");
        printf("8. 小组任务（提高）\n");
        printf("0. 退出\n");
        printf("========================================\n");
        printf("\n请选择:");
        scanf_s("%d", &choice);

        switch (choice)
        {
        case 1://建立并输入图
            CreateGraph(&G,&M);
            cout<<"图建立成功！\n\n";
            break;

        case 2://输出图
            cout << "提示： 弧头编号[弧的权值]" << endl;
            PrintGraph(&G);
            cout<<"\n\n";
            break;

        case 3://邻接矩阵输出
            PrintMatrix(&M);
            break;

        case 4://销毁图
            DestoryGraph(&G);
            cout << "图已销毁\n\n";
            break;

        case 5://dfs输出
            cout << "要从哪个顶点开始？(结点编号只能取[1，顶点数]之间的整数)"<<endl;
            cin >> tempa;
            dfs(&G, tempa);
            for (int i = 1; i <= G.n; i++)
            {
                if (visited[i] == 0)  q.push(i);
            }
            while (!q.empty())
            {
                tempb = q.front();
                q.pop();
                if (visited[tempb] == 0) dfs(&G, tempb);
            }
            memset(visited, 0, sizeof(visited));
            cout << "dfs遍历完成"<<"\n\n";
            break;

        case 6://bfs输出
            cout << "要从哪个顶点开始？(结点编号只能取[1，顶点数]之间的整数)" << endl;
            cin >> tempa;
            bfs(&G, tempa);
            for (int i = 1; i <= G.n; i++)
            {
                if (visited[i] == 0)  q.push(i);
            }
            while (!q.empty())
            {
                tempb = q.front();
                q.pop();
                if (visited[tempb] == 0) dfs(&G, tempb);
            }
            memset(visited, 0, sizeof(visited));
            cout << "bfs遍历完成" << "\n\n";
            break;

        case 7://小组基础任务
            while (tchoice != 0)
            {
                printf("=====================MENU_2=======================\n");
                printf("=================小组任务（基础）=================\n");
                printf("1. 朋友圈问题\n");
                //printf("2. 求最大岛屿的面积\n");
                //printf("3. 判断是否是二分图\n");
                //printf("4. 求解两个动物之间通信的最少翻译问题\n");
                printf("0. 退出分支\n");
                printf("========================================\n");
                printf("\n请选择:");
                scanf_s("%d", &tchoice);
                switch (tchoice)
                {
                case 1:
                    Friends(&M);
                    break;
                //case 2:
                //    break;
                //case 3: //判断是否是二分图
                //    evengraph(&M);
                //    break;
                //case 4:
                //    break;
                }
            }
            tchoice = -1;
            break;

        case 8://小组基础任务
            while (tchoice != 0)
            {
                printf("=====================MENU_3========================\n");
                printf("==================（提高任务）=====================\n");
                printf("1. 任务调度的合理性\n");
                printf("2. 公路村村通\n");
                printf("0. 退出分支\n");
                printf("========================================\n");
                printf("\n请选择:");
                scanf_s("%d", &tchoice);

                switch (tchoice)
                {
                case 1:  //此题不采用一开始输入的图。要再函数中自行输入
                    topological_sort();   
                    break;

                case 2: //此题采用一开始输入的图
                    villege_connect(&M);
                    break;
                }
            }
            tchoice = -1;
            break;
        }
    }
}




//====================================分割线===========================================
//------------------------------------基本功能-----------------------------------------


//completed
/*
函数名：CreateGraph
功能：输入图的各项值
输入：Adjgraph型指针G,MatrixVertex型指针M （分别对应邻接表和邻接矩阵）
输出：赋值后的图  */
void CreateGraph(Adjgraph* G,MatrixVertex *M)
{
    G->e = 0; G->n = 0;
    int tempa, tempb, tempc;
    int x, y;

    printf("请依次输入 图的顶点数和图的边数：");  
    cin >> G->n >> G->e;
    x = G->n; y = G->e;
    M->n = G->n; M->e = G->e;
    for (int i = 1; i < MAXSIZE; i++)   for (int j = 1; j < MAXSIZE; j++)  M->matrix[i][j] = -1;   //邻接矩阵初始化
    printf("请依次输入 起点 终点 路径权值(正值)。（结点编号只能取[1，顶点数]之间的整数）\n");
    for (int i = 0; i < G->e; i++)
    {
        cin >> tempa >> tempb >> tempc;
        M->matrix[tempa][tempb] = tempc;
    }

    ArcNode* p;
    for (int i = 1; i <= G->n; i++)
    {
        G->head[i].data = i;
        G->head[i].firstarc = NULL;         //头结点初始化
    }

    for (int i = 1; i <= G->n; i++)
    {
        for (int j = 1; j <= G->n; j++)
        {
            if (M->matrix[i][j] != -1 && M->matrix[i][j] < INF)
            {
                p = (ArcNode*)malloc(sizeof(ArcNode));
                if (NULL == p) exit(ERROR);
                p->archead = j;
                p->weight = M->matrix[i][j];
                //头插法
                p->nextarc = G->head[i].firstarc;
                G->head[i].firstarc = p;
            }
        }
    }
}


//completed
/*
函数名：PrintGraph
功能：输出图的各项值 （以邻接表的形式打印）
输入：Adjgraph型指针 G
输出：邻接表形式打印出的图  */
void PrintGraph(Adjgraph* G)
{
    ArcNode* p;
    for (int i = 1; i <= G->n; i++)
    {
        p = G->head[i].firstarc;
        printf("%3d: ", i);
        while (p != NULL)
        {
            printf("%3d[%d] --> ", p->archead, p->weight);
            p = p->nextarc;
        }
        printf("∧\n");
    }    
}

//completed
/*
函数名：PrintMatrix
功能：输出图的各项值 （以邻接矩阵的形式打印）
输入：MatrixVertex型指针 M
输出：邻接矩阵形式打印出的图  */
void PrintMatrix(MatrixVertex* M)
{
    cout << "   ";
    for (int i = 1; i <= M->n; i++) cout << i << "  " ;
    cout << endl;
    for (int i = 1; i <= M->n; i++)
    {
        cout << i << "  ";
        for (int j = 1; j <= M->n; j++)
        {
            if (j == M->n) cout << M->matrix[i][j] << endl;
            else cout << M->matrix[i][j] << "  ";
        }
    }
}

//completed
/*
函数名：DestoryGraph
功能：销毁图
输入：Adjgraph型指针 G
输出：销毁G  */
void DestoryGraph(Adjgraph* G)
{
    ArcNode* p, * q;
    for (int i = 1; i <= G->n; i++)
    {

        if (G->head[i].firstarc == NULL) continue;
        p = G->head[i].firstarc;
        if(p!=NULL)//else
        {
            q = p->nextarc;
            while (q != NULL)
            {
                free(p);
                p = q;
                q = q->nextarc;
            }
            free(p);
            p = NULL;
        }
    }
    //free(G);
    for (int i = 1; i <= G->n;i++)
    {
        G->head[i].firstarc = NULL;
        G->head[i].data = 0;
    }
    G->n = G->e = 0;
}

//completed
/*
函数名：dfs
功能：深度优先搜索（遍历）
输入：Adjgraph型指针 G，结点编号v   全局变量 visited[MAXSIZE] 表示指定结点是否已访问(1代表已访问)
输出：深度优先输出顶点  */
void dfs(Adjgraph* G, int v)
{
    ArcNode* p;
    int cur;
    visited[v] = 1;
    cout << v << " ";
    p = G->head[v].firstarc;
    while (p != NULL)
    {
        cur = p->archead;
        if (visited[cur] == 0) dfs(G, cur);
        p = p->nextarc;
    }
}

//completed
/*
函数名：bfs
功能：广度优先搜索（遍历）
输入：Adjgraph型指针 G，结点编号v   全局变量 visited[MAXSIZE] 表示指定结点是否已访问(1代表已访问)
输出：广度优先输出顶点  */
void bfs(Adjgraph* G, int v)
{
    ArcNode* p;
    int cur;
    queue<int>v_queue;
    cout << v << " ";
    v_queue.push(v);
    visited[v] = 1;
    while (v_queue.empty() == 0)
    {
        cur=v_queue.front();
        v_queue.pop();
        p = G->head[cur].firstarc;
        while (p != NULL)
        {
            if (visited[p->archead] == 0)
            {
                cout << p->archead << " ";
                visited[p->archead] = 1;
                v_queue.push(p->archead);
            }
            p = p->nextarc;
        }
    }
    //cout << endl;
}
//----------------------------------小组基础任务---------------------------------------


//completed
//1.朋友圈问题  (fset[]为全局变量)
int find(int a)
{
    int s = fset[a];
    while (s != fset[s]) s = fset[s];
    return s;
}

void combine(int x, int y)
{
    if (find(x) != find(y))
    {
        int lower = min(find(x), find(y));
        fset[x] = fset[y] = lower;
    }
}


void Friends(MatrixVertex* M)
{
    int num[MAXSIZE + 1] = {0};  //统计一个集合的最小值,num[i]>0 说明num[i]代表一个集合，统计num中>0的元素个数即可统计出集合数
    int count=0;
    for (int i = 1; i <= M->n; i++) fset[i] = i;  //初始化

    //划分朋友圈
    for (int i = 1; i <= M->n; i++)
    {
        for (int j = 1; j <= M->n; j++)
        {
            if (M->matrix[i][j] == 1)
            {
                combine(i, j);    //将 i,j 合并到一个集合中
            }
        }
    }
    //统计朋友圈
    for (int i = 1; i <= M->n; i++)  num[fset[i]]++;
    for (int i = 1; i <= M->n; i++)  if (num[i] > 0) count++;
    printf("有 %d 个朋友圈\n",count);
}


////判断是否是二分图
//void evengraph(MatrixVertex* M)
//{
//
//}
//----------------------------------小组提高任务---------------------------------------

//completed
//1.任务调度合理性问题 （拓扑排序）
void topological_sort()
{
    int n,x,temp,t;
    int indegree[MAXSIZE] = {0};
    vector<int> g_connect[MAXSIZE];
    cout << "请输入任务的个数n：";
    cin >> n;
    cout << "对于每个任务，依次输入 任务的前驱数、具体前驱" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        indegree[i] = temp;
        for (int j = 1; j <= temp; j++)
        {
            cin >> x;
            g_connect[x].push_back(i);
        }
    }
    cout << endl;
    //拓扑排序逐个删除子任务
    x = 0;
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {   //前驱为0的任务入队
        if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int i = 0; i < g_connect[temp].size(); i++)
        {
            t = g_connect[temp][i];      
            //t为结点temp的其中一个后继，删去temp则temp的所有后继的入度-1
            indegree[t]--;
            if (indegree[t] == 0) q.push(t);
        }
        x++;
    }
    if (x == n) cout << 1 << endl;
    else cout << 0 << endl;
}


//completed
//2.公路村村通(最小生成树)

void InsertSort(edge e[],int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (e[i - 1].w > e[i].w)
        {
            edge k = e[i];
            int j = i;
            while (j > 1 && e[j - 1].w > k.w)
            {
                e[j] = e[j - 1];
                j--;
            }
            e[j] = k;
        }
    }
}

void villege_connect(MatrixVertex* M)
{
    int v[MAXSIZE];
    edge e[MAXSIZE * 3 + 2];
    int k = 1, t = 1;
    int sum = 0;
    for (int i = 1; i <= M->n; i++)
    {
        v[i] = i;
        for (int j = 1; j <= M->n; j++)
        {
            if (M->matrix[i][j] != -1 && M->matrix[i][j] != INF)
            {
                e[k].start = i;
                e[k].end = j;
                e[k].w = M->matrix[i][j];
                k++;
            }
        }
        
    }
    InsertSort(e ,M->e);  //按权值插入排序
    for (int i = 1; i <= M->e; i++) cout << e[i].start << "  " << e[i].end << "  " << e[i].w << endl;  //查看排序后的公路
    k = 1;
    while (k <= M->n && t<=M->e)    //并查集
    {
        int start = e[t].start;
        int end = e[t].end;
        int s1 = v[start];
        int s2 = v[end];
        if (s1 != s2)      //判断s1与s2是否处于同一个集合中
        {
            k++;
            for (int i = 1; i <= M->n; i++) if (v[i] == s2) v[i] = s1;             
            sum += e[t].w;
        }
        t++;
    }
    if (sum == 0 || t<M->n-1) cout << -1 << endl;
    else cout << sum << endl;
}