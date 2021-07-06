#include "graph.h"

//===============ȫ�ֱ���=============
int visited[MAXSIZE] = { 0 };
int fset[MAXSIZE + 1];  //�������顣ͬһ�������У�ÿ��Ԫ�ص�fsetֵΪ�����е���СԪ��ֵ
//====================================

//ͼ����
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
        printf("=================ͼʾ��=================\n");
        printf("1. ����������ͼ\n");
        printf("2. ���ͼ���ڽӱ��ʾ��\n");
        printf("2. ���ͼ���ڽӾ����ʾ��\n");
        printf("4. ����ͼ\n");
        printf("5. DFS�������˳��\n");
        printf("6. BFS�������˳��\n");
        printf("7. С�����񣨻�����\n");
        printf("8. С��������ߣ�\n");
        printf("0. �˳�\n");
        printf("========================================\n");
        printf("\n��ѡ��:");
        scanf_s("%d", &choice);

        switch (choice)
        {
        case 1://����������ͼ
            CreateGraph(&G,&M);
            cout<<"ͼ�����ɹ���\n\n";
            break;

        case 2://���ͼ
            cout << "��ʾ�� ��ͷ���[����Ȩֵ]" << endl;
            PrintGraph(&G);
            cout<<"\n\n";
            break;

        case 3://�ڽӾ������
            PrintMatrix(&M);
            break;

        case 4://����ͼ
            DestoryGraph(&G);
            cout << "ͼ������\n\n";
            break;

        case 5://dfs���
            cout << "Ҫ���ĸ����㿪ʼ��(�����ֻ��ȡ[1��������]֮�������)"<<endl;
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
            cout << "dfs�������"<<"\n\n";
            break;

        case 6://bfs���
            cout << "Ҫ���ĸ����㿪ʼ��(�����ֻ��ȡ[1��������]֮�������)" << endl;
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
            cout << "bfs�������" << "\n\n";
            break;

        case 7://С���������
            while (tchoice != 0)
            {
                printf("=====================MENU_2=======================\n");
                printf("=================С�����񣨻�����=================\n");
                printf("1. ����Ȧ����\n");
                //printf("2. �����������\n");
                //printf("3. �ж��Ƿ��Ƕ���ͼ\n");
                //printf("4. �����������֮��ͨ�ŵ����ٷ�������\n");
                printf("0. �˳���֧\n");
                printf("========================================\n");
                printf("\n��ѡ��:");
                scanf_s("%d", &tchoice);
                switch (tchoice)
                {
                case 1:
                    Friends(&M);
                    break;
                //case 2:
                //    break;
                //case 3: //�ж��Ƿ��Ƕ���ͼ
                //    evengraph(&M);
                //    break;
                //case 4:
                //    break;
                }
            }
            tchoice = -1;
            break;

        case 8://С���������
            while (tchoice != 0)
            {
                printf("=====================MENU_3========================\n");
                printf("==================���������=====================\n");
                printf("1. ������ȵĺ�����\n");
                printf("2. ��·���ͨ\n");
                printf("0. �˳���֧\n");
                printf("========================================\n");
                printf("\n��ѡ��:");
                scanf_s("%d", &tchoice);

                switch (tchoice)
                {
                case 1:  //���ⲻ����һ��ʼ�����ͼ��Ҫ�ٺ�������������
                    topological_sort();   
                    break;

                case 2: //�������һ��ʼ�����ͼ
                    villege_connect(&M);
                    break;
                }
            }
            tchoice = -1;
            break;
        }
    }
}




//====================================�ָ���===========================================
//------------------------------------��������-----------------------------------------


//completed
/*
��������CreateGraph
���ܣ�����ͼ�ĸ���ֵ
���룺Adjgraph��ָ��G,MatrixVertex��ָ��M ���ֱ��Ӧ�ڽӱ���ڽӾ���
�������ֵ���ͼ  */
void CreateGraph(Adjgraph* G,MatrixVertex *M)
{
    G->e = 0; G->n = 0;
    int tempa, tempb, tempc;
    int x, y;

    printf("���������� ͼ�Ķ�������ͼ�ı�����");  
    cin >> G->n >> G->e;
    x = G->n; y = G->e;
    M->n = G->n; M->e = G->e;
    for (int i = 1; i < MAXSIZE; i++)   for (int j = 1; j < MAXSIZE; j++)  M->matrix[i][j] = -1;   //�ڽӾ����ʼ��
    printf("���������� ��� �յ� ·��Ȩֵ(��ֵ)���������ֻ��ȡ[1��������]֮���������\n");
    for (int i = 0; i < G->e; i++)
    {
        cin >> tempa >> tempb >> tempc;
        M->matrix[tempa][tempb] = tempc;
    }

    ArcNode* p;
    for (int i = 1; i <= G->n; i++)
    {
        G->head[i].data = i;
        G->head[i].firstarc = NULL;         //ͷ����ʼ��
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
                //ͷ�巨
                p->nextarc = G->head[i].firstarc;
                G->head[i].firstarc = p;
            }
        }
    }
}


//completed
/*
��������PrintGraph
���ܣ����ͼ�ĸ���ֵ �����ڽӱ����ʽ��ӡ��
���룺Adjgraph��ָ�� G
������ڽӱ���ʽ��ӡ����ͼ  */
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
        printf("��\n");
    }    
}

//completed
/*
��������PrintMatrix
���ܣ����ͼ�ĸ���ֵ �����ڽӾ������ʽ��ӡ��
���룺MatrixVertex��ָ�� M
������ڽӾ�����ʽ��ӡ����ͼ  */
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
��������DestoryGraph
���ܣ�����ͼ
���룺Adjgraph��ָ�� G
���������G  */
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
��������dfs
���ܣ��������������������
���룺Adjgraph��ָ�� G�������v   ȫ�ֱ��� visited[MAXSIZE] ��ʾָ������Ƿ��ѷ���(1�����ѷ���)
�������������������  */
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
��������bfs
���ܣ��������������������
���룺Adjgraph��ָ�� G�������v   ȫ�ֱ��� visited[MAXSIZE] ��ʾָ������Ƿ��ѷ���(1�����ѷ���)
�������������������  */
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
//----------------------------------С���������---------------------------------------


//completed
//1.����Ȧ����  (fset[]Ϊȫ�ֱ���)
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
    int num[MAXSIZE + 1] = {0};  //ͳ��һ�����ϵ���Сֵ,num[i]>0 ˵��num[i]����һ�����ϣ�ͳ��num��>0��Ԫ�ظ�������ͳ�Ƴ�������
    int count=0;
    for (int i = 1; i <= M->n; i++) fset[i] = i;  //��ʼ��

    //��������Ȧ
    for (int i = 1; i <= M->n; i++)
    {
        for (int j = 1; j <= M->n; j++)
        {
            if (M->matrix[i][j] == 1)
            {
                combine(i, j);    //�� i,j �ϲ���һ��������
            }
        }
    }
    //ͳ������Ȧ
    for (int i = 1; i <= M->n; i++)  num[fset[i]]++;
    for (int i = 1; i <= M->n; i++)  if (num[i] > 0) count++;
    printf("�� %d ������Ȧ\n",count);
}


////�ж��Ƿ��Ƕ���ͼ
//void evengraph(MatrixVertex* M)
//{
//
//}
//----------------------------------С���������---------------------------------------

//completed
//1.������Ⱥ��������� ����������
void topological_sort()
{
    int n,x,temp,t;
    int indegree[MAXSIZE] = {0};
    vector<int> g_connect[MAXSIZE];
    cout << "����������ĸ���n��";
    cin >> n;
    cout << "����ÿ�������������� �����ǰ����������ǰ��" << endl;
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
    //�����������ɾ��������
    x = 0;
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {   //ǰ��Ϊ0���������
        if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int i = 0; i < g_connect[temp].size(); i++)
        {
            t = g_connect[temp][i];      
            //tΪ���temp������һ����̣�ɾȥtemp��temp�����к�̵����-1
            indegree[t]--;
            if (indegree[t] == 0) q.push(t);
        }
        x++;
    }
    if (x == n) cout << 1 << endl;
    else cout << 0 << endl;
}


//completed
//2.��·���ͨ(��С������)

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
    InsertSort(e ,M->e);  //��Ȩֵ��������
    for (int i = 1; i <= M->e; i++) cout << e[i].start << "  " << e[i].end << "  " << e[i].w << endl;  //�鿴�����Ĺ�·
    k = 1;
    while (k <= M->n && t<=M->e)    //���鼯
    {
        int start = e[t].start;
        int end = e[t].end;
        int s1 = v[start];
        int s2 = v[end];
        if (s1 != s2)      //�ж�s1��s2�Ƿ���ͬһ��������
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