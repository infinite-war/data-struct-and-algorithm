#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 递归方法
int BS1(vector<int>& arr, int left, int right, int x){
    int mid=(left+right)>>1;
    if(left>right) return 0;
    if(arr[mid]==x) return mid;  //找到就直接返回下标
    else if(arr[mid]>x) return BS1(arr,left,mid-1,x);  //x在左半部分
    else return BS1(arr,mid+1,right,x);    //x在右半部分
    return 0;
}


//非递归方法
int BS2(vector<int>& arr, int left, int right, int x){
    while(left<=right){
        int mid=(left+right)>>1;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x) right=mid-1;
        else left=mid+1;
    }
    return 0;
}


/*输入格式：
    数组元素个数
    数组具体元素
    要查找的数
*/
int main(){
    int x,n,index=0;
    vector<int>arr(2000,0);  // arr[0]不存放数据
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        arr[i]=x;
    }
    //要查询的数
    while(1){
        cin>>x;
        index=BS1(arr,1,n,x);
        if(index>0 && index<=n && arr[index]==x) cout<<"BS1: index="<<index<<endl;
        else cout<<"BS1: null"<<endl;
        index=BS1(arr,1,n,x);
        if(index>0 && index<=n && arr[index]==x) cout<<"BS2: index="<<index<<endl;
        else cout<<"BS2: null"<<endl;
    }
    return 0;
}