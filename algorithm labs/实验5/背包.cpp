#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 100



struct node{
    int index,wSum,vSum;   //当前节点的深度   到当前节点为止的总重量(总价值)
    node(int index,int w,int v):index(index),wSum(w),vSum(v){};
};
queue<node>q;

int n,m;  //物品个数，包的容量
vector<int>w,v;

int ans=0;//最大价值



int bfs(){
    q.push(node(-1,0,0)); //-1代表尚未取任何物品

    while(!q.empty()){
        node tempNode=q.front();  q.pop();
        if(tempNode.index==n-1 && tempNode.vSum>ans){//已经到了最深层，则考虑是不是最优解
            ans=tempNode.vSum;
        }
        if(tempNode.index+1<n){ //还有物品可选
            if(tempNode.wSum+w[tempNode.index+1]<=m){ //假如下一个物品可以放入，则入队
                node next=node(tempNode.index+1,tempNode.wSum+w[tempNode.index+1],tempNode.vSum+v[tempNode.index+1]);
                q.push(next);
            }
            //所有物品都有不选的可能
            q.push(node(tempNode.index+1,tempNode.wSum,tempNode.vSum));
        }

    }

    return ans;
}




/* 输入：
    物品种类n  背包容量m
    物品重量w[i] 物品价值v[i]
*/



int main(){

    cin>>n>>m;
    int tempw,tempv;
    for(int i=0;i<n;i++){
        cin>>tempw>>tempv;
        w.push_back(tempw);
        v.push_back(tempv);
    }

    cout<<bfs()<<endl;
    
	return 0;
} 
