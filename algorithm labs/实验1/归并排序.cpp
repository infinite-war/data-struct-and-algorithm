#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//合并操作
void mergeArr(vector<int>&arr, int left, int mid, int right){
    vector<int>temp;
    int l=left,r=mid+1;
    while(l<=mid && r<=right){
        if(arr[l]<=arr[r]){
            temp.push_back(arr[l]);
            l++;
        }
        else {
            temp.push_back(arr[r]);
            r++;
        }
    }
    while(l<=mid)  {temp.push_back(arr[l]); l++;}
    while(r<=right) {temp.push_back(arr[r]); r++;}
    for(int i=0;i<=right-left;i++){
        //cout<<temp[i]<<" ";
        arr[left+i]=temp[i];
    }
    //cout<<endl;
}

// 归并排序
void mergeSort(vector<int>&arr,int left,int right){
    if(left==right) return ;
    int mid=(left+right)>>1;
    mergeSort(arr,mid+1,right);
    mergeSort(arr,left,mid);
    mergeArr(arr,left,mid,right);
}




/*输入格式：
    数组元素个数
    数组元素
*/
int main(){
    int x,n,index=0;
    vector<int>arr;  // arr[0]不存放数据
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }

    mergeSort(arr,0,n-1);
    for(auto& num:arr){
        cout<<num<<" ";
    }
    return 0;
}