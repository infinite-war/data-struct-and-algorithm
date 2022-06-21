#include <iostream>
#include <algorithm>
#include <queue>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

vector<int>ans;//一种方案
int n; //n个皇后

struct node{
    int index;   //当前节点代表第几列
    vector<int>choose;  //到目前为止的放置方案，choose[i]=x代表第i列的棋子放在第x行
    node(int index):index(index){};
};


//判断能否放置
bool place(node curNode){
    //当前最新一列(nums)放置的棋子和之前已经摆放号的棋子进行判定
    int nums=curNode.index;
    for(int i=1;i<nums;i++){
        if(abs(nums-i)==abs(curNode.choose[i]-curNode.choose[nums]) 
            || (curNode.choose[i]==curNode.choose[nums])) {
                return false;
            }
    }
    return true;
}


void bfs(){
    queue<node>q;
    node tail=node(-1); //队列中弹出这个点说明要进入下一层了
    q.push(tail); //0~n-1列
    node curNode=node(0);
    int curIndex=1; //当前列

    while(1){
        //下一列有n个选择
        for(int i=1;i<=n;i++){
            node nextNode=node(curIndex);
            nextNode.choose.push_back(0);
            //把前curLevel层已经得到的放置方法记录下来
            for(int j=1;j<curIndex;j++){
                nextNode.choose.push_back(curNode.choose[j]);;
            }
            //考虑将下一列的棋子放在第i行
            nextNode.choose.push_back(i);
            if(place(nextNode)){ //没有冲突就入队
                q.push(nextNode);
            }
        }

        curNode=q.front(); q.pop();
        if(curNode.index==-1){  //当前层搜索完毕，进入下一层
            curIndex++;
            q.push(tail); //给下一层添加终点
            curNode=q.front(); q.pop();
        }

        if(curNode.index==n){  //已经摆放完毕,记录摆放方案
            for(int i=0;i<=n;i++){
                ans[i]=curNode.choose[i];
            }
            break;
        }

    }
}


/* 输入：
    n个皇后
*/
int main(){

    ifstream ifs;
    ifs.open("input.txt",ios::in);
    string s;
    getline(ifs,s);
    //input
    n=atoi(s.c_str());
    ifs.close();
    //从1开始编码。choose[i]=0代表未摆放
    ans=vector<int>(n,0);

    bfs();

    //output
    ofstream ofs;
    ofs.open("output.txt",ios::out);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
        ofs<<ans[i]<<" ";
    }
    
    ofs.close();
    
	return 0;
} 
