#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 100   //最大顶点数
#define inf INT_MAX


typedef pair<int,int>Pii;
struct edge{
    int v; //路径的终点
    int w; //路径的权重
};

int n,m;
vector<int>dis; //单源路径长度
vector<int>pre; //前一个点
vector<vector<edge>>G;  //记录每个点衍生出的有向边



void dijkstra(int startV){
    //按路径长度升序排列的优先队列
    priority_queue<Pii, vector<Pii>, greater<Pii>>pq;
    fill(dis.begin(),dis.end(),inf);
    dis[startV]=0;
    pre[startV]=startV;
    pq.push({dis[startV],startV});

    while(!pq.empty()){
        // curp.first:到当前点的最短路径。
        // curp.second:当前是哪个点。
        Pii curp=pq.top(); pq.pop();
        int nextV=curp.second;

        // 已经更新过点nextp
        if(dis[nextV]<curp.first) continue;

        for(auto& e:G[nextV]){
            if(dis[e.v]>dis[nextV]+e.w){ //发现更短的路径
                dis[e.v]=dis[nextV]+e.w;
                pre[e.v]=nextV;
                pq.push({dis[e.v],e.v});
            }
        }
    }
}




/* 输入：
    点的个数n，边的个数m (有向图)
    端点1  端点2  边的权重 (重复m次)

*/



int main(){
    cin>>n>>m;
    dis=vector<int>(MAXN,INT_MAX);
    pre=vector<int>(MAXN,-1);
    G=vector<vector<edge>>(MAXN);

    int from,to,weight;
    edge e;
    for(int i=1;i<=m;i++){
        cin>>from>>to>>weight;
        e.v=to; e.w=weight;
        G[from].push_back(e);
    }


    cout<<"where to start: ";
    int s; cin>>s;

    dijkstra(s);

    cout<<"distance: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    cout<<"preNode : "<<endl;
    for(int i=1;i<=n;i++){
        cout<<pre[i]<<" ";
    }

	return 0;
} 
