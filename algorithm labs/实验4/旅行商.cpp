#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 100

int n,m;  //地点数   边数
vector<int>w,v;
vector<bool>choose;  // true代表已经去过
vector<int>curtrack;  //记录当前的解
vector<vector<int>>map;  //邻接矩阵
int passedCity=1;  //当前已经经过了几个地点
int currentCost=0;  //当前的旅费

int ans=INT_MAX;//最少旅费
vector<int>track;//最优解


void dfs(int k){

    if(passedCity==n){
        if(currentCost<ans){
            ans=currentCost;
            for(int i=1;i<=n;i++){
                track[i]=curtrack[i];
            }
        }
        return ;
    }


    for(int i=2;i<=n;i++){
        if(!choose[i]){
            choose[i]=true;
            currentCost+=map[k][i];
            passedCity++;
            curtrack[i]=passedCity;
            dfs(i);
            passedCity--;
            currentCost-=map[k][i];
            choose[i]=false;
        }
    }
}




/* 输入：
    地点数n  路线n*(n-1)/2   组合数(n个点中挑2个进行组合) 默认是完全图
    端点1 端点2 旅费   //输入n*(n-1)/2次。无向边，不考虑端点先后
*/


int main(){

    cin>>n;
    m=n*(n-1)/2;
    map=vector<vector<int>>(n+1,vector<int>(n+1,-1));
    int temp1,temp2,tempw;
    for(int i=0;i<m;i++){
        cin>>temp1>>temp2>>tempw;
        map[temp1][temp2]=map[temp2][temp1]=tempw;
    }
    choose=vector<bool>(n+1);
    track=curtrack=vector<int>(n+1,-1);
    choose[1]=true;
    track[1]=curtrack[1]=1;

    dfs(1); //选择0做起点

    cout<<"ans= "<<ans<<endl;
    cout<<"track:   place     order"<<endl;
    for(int i=1;i<=n;i++){
        cout<<"    "<<i<<"   "<<track[i]<<endl;
    }
    
	return 0;
} 
