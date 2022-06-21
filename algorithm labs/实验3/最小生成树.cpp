#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 100   //最大顶点数


struct edge{
    int v1;
    int v2;
    int w; //路径的权重
    bool operator > (const edge &a) const{
		return w>a.w;
	};
    bool operator < (const edge &a) const{
		return w<a.w;
	};
};

int n,m;
vector<edge>G;  //记录每个点衍生出的有向边
vector<int>parent(MAXN);
priority_queue<edge, vector<edge>, greater<edge>>pq;


//==============采用并查集进行图的连通===================
int find(int x){
    if(x==parent[x]) return x;
    else return parent[x]=find(parent[x]);
}

bool unionNode(int a,int b){
    int pa=find(a);
    int pb=find(b);
    if(pa==pb) return false;   //加入两个点的父节点相同，说明二者已经连通
    else if(pa<pb){//值小的作父节点
        parent[pb]=pa;
    }
    else{
        parent[pa]=pb;
    }
    return true;
}

//对相关变量初始化
void init(){
    cin>>n>>m;
    int v1,v2,w;
    edge e;
    while(!pq.empty()){
        pq.pop();
    }

    for(int i=1;i<=m;i++){
        cin>>v1>>v2>>w;
        e.v1=v1;e.v2=v2;e.w=w;
        pq.push(e);
    }
    
    for(int i=1;i<=n;i++){ //初始化，每个点之间暂不连通
        parent[i]=i;
    }
}

//返回最小生成树的权值
int kruskal(int m,vector<vector<int>>&g){
    int ans=0;
    while(!pq.empty()){
        edge cur=pq.top(); pq.pop();
        if(unionNode(cur.v1,cur.v2)){
            ans+=cur.w;
            g[cur.v1][cur.v2]=g[cur.v2][cur.v1]=cur.w;
        }
    }
    return ans;
}


/* 输入：
    点的个数n，边的个数m (无向图)
    端点1  端点2  边的权重 (重复m次)
*/

int main(){
    

    init();
    
    vector<vector<int>>ans(n+1,vector<int>(n+1,INT_MAX));  //最小生成树的邻接矩阵

    int sum=kruskal(m,ans);
    
    cout<< sum <<endl;


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j]==INT_MAX){
                cout<<"N ";
            }
            else cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

	return 0;
} 
