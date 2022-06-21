#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 100

int n,m;  //物品个数，包的容量
vector<int>w,v;
vector<bool>choose;  // true代表放入背包
int currentW=0;  //当前重量
int currentV=0;  //当前价值

int ans=0;//最大价值
vector<bool>track;//最优解

//k表示判断是否将第k个物品放入
void dfs(int k){

    if(k>n){ //物品已经遍历完了
        if(currentV>ans){
            ans=currentV;
            for(int i=0;i<n;i++){  //当前的选择记录为最优解
                track[i]=choose[i];
            }
        }
        return ;
    }


    for(int i=0;i<=1;i++){ //只有放和不放两种选择
        choose[k]=i;
        if(!i){ //不放入就不对辅助数组w，v做修改
            dfs(k+1);
        }
        else if((currentW+w[k])<=m){ //若要放入且剩余容量足够，则要修改总价值
            currentW+=w[k];
            currentV+=v[k];
            dfs(k+1);
            currentW-=w[k];
            currentV-=v[k];
        }
    }
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
    choose=track=vector<bool>(n,false);
    dfs(0);
    cout<<"best value = "<<ans<<endl;
    cout<<"choose: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"    "<<i<<" "<<(track[i]?"chosen":"")<<endl;
    }
    
	return 0;
} 
