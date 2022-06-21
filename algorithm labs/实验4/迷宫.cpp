#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 100

int row,col;  //行，列
vector<vector<int>>map;   //map[i][j]  0代表障碍  1代表通路  2代表已经路过的位置
vector<vector<int>>bestmap;  //路径
//入口默认左上角   出口默认右下角
bool ans=false;
vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};  //移动方向


void dfs(int x,int y){

    if(x==row && y==col){
        ans=true;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                bestmap[i][j]=map[i][j];
            }
        }
        return ;
    }

    for(auto& dir:dirs){
        int nextx=x+dir[0];
        int nexty=y+dir[1];
        //假如移动的位置没有越界而且是没有访问过的位置
        if(nextx>=1 && nextx<=row && nexty>=1 && nexty<=col
            && map[nextx][nexty]==0){
                map[nextx][nexty]=2;
                dfs(nextx,nexty);
                map[nextx][nexty]=0;
                
            }
        if(ans) return ; //找到结果就结束
    }
}




/* 输入：
    行数row  列数col
    迷宫
*/


int main(){

    cin>>row>>col;
    map=bestmap=vector<vector<int>>(row+1,vector<int>(col+1,-1));
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cin>>map[i][j];
        }
    }
    
    cout<<endl<<"=========================="<<endl;
    dfs(1,1);
    if(ans){
        bestmap[1][1]=2;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(bestmap[i][j]==2) cout<<"# ";
                else cout<<bestmap[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"no answer"<<endl;
    }

	return 0;
} 
