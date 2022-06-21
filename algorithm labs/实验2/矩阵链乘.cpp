#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


//最长公共子序列
void dp(vector<int>&matrix,vector<vector<int>>&ans,vector<vector<int>>&track){
    int n=matrix.size()-1;

    for(int i=1;i<=n;i++) {
        ans[i][i]=0;
    }

    for(int length=2;length<=n;length++){
        for(int i=1;i<=n-length+1;i++){
            int j=i+length-1;
            for(int k=i;k<=j-1;k++){
                int cur=ans[i][k]+ans[k+1][j]+matrix[i-1]*matrix[k]*matrix[j];
                if(cur<ans[i][j]){
                    ans[i][j]=cur;
                    track[i][j]=k;
                }
            }
        }
    }
    return ;
}


// 打印二维数组
template<typename T>
void print(vector<vector<T>>& arr){
    int row=arr.size(),col=arr[0].size();
    for(int i=1;i<=row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j]==1e8) cout<<"N ";
            else cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return ;
}

void print_M(vector<vector<int>>& track,int i,int j){
    if(i==j){
        cout<<"U_{"<<i<<"}";
        return ;
    }
    cout<<"(";
    print_M(track,i,track[i][j]);
    cout<<")(";
    print_M(track,track[i][j]+1,j);
    cout<<")";
    return;
}

/*输入格式：
    矩阵个数 n
    数组具体元素 n+1个
*/
int main(){
    int n; cin>>n;
    vector<int>matrix(n+1,0);
    for(int i=0;i<=n;i++){
        cin>>matrix[i];
    }
    
    vector<vector<int>>ans(n+1,vector<int>(n+1,1e8));
    vector<vector<int>>track(n+1,vector<int>(n+1,0));

    dp(matrix,ans,track);

    cout<<"=============dp table============="<<endl;
    //print(ans);
    cout<<"=================================="<<endl<<endl;
    cout<<"============track table==========="<<endl;
    print_M(track,1,n);
    cout<<endl<<"=================================="<<endl;

    //获取最优解
    cout<<ans[1][n]<<endl;    

    return 0;
}