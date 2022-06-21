#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


//最长公共子序列
void dp(string x,string y,vector<vector<int>>&ans,vector<vector<char>>&track){
    int n=x.size(),m=y.size();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                ans[i][j]=ans[i-1][j-1]+1;;
                track[i][j]='T';
            }
            else if(ans[i-1][j]>=ans[i][j-1]){
                ans[i][j]=ans[i-1][j];
                track[i][j]='U';
            }
            else{
                ans[i][j]=ans[i][j-1];
                track[i][j]='L';
            }
        }
    }
    return ;
}


// 打印二维数组
template<typename T>
void print(vector<vector<T>>& arr){
    int row=arr.size(),col=arr[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return ;
}

void print_LCS(vector<vector<char>>& track,string x,int i,int j){
    if(i==0 || j==0) return ;
    if(track[i][j]=='T'){
        
        print_LCS(track,x,i-1,j-1);
        cout<<x[i-1]<<"-->";
    }
    else if(track[i][j]=='U'){
        print_LCS(track,x,i-1,j);
    }
    else{
        print_LCS(track,x,i,j-1);
    }
    return;
}

/*输入格式：
    数组元素个数
    数组具体元素
    要查找的数
*/
int main(){
    string x,y;
    cin>>x>>y;
    int n=x.size(),m=y.size();
    vector<vector<int>>ans(n+1,vector<int>(m+1,0));
    vector<vector<char>>track(n+1,vector<char>(m+1,'N'));
    dp(x,y,ans,track);

    cout<<"=============dp table============="<<endl;
    print(ans);
    cout<<"=================================="<<endl<<endl;
    cout<<"============track table==========="<<endl;
    print(track);
    cout<<"=================================="<<endl;

    //获取最优解
    print_LCS(track,x,x.size(),y.size());

    return 0;
}