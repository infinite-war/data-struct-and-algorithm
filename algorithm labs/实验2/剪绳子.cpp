#include <iostream>
using namespace std;

int max_product_cutting(int target) 
{
    if(target<2) return 0;
    else if(target==2) return 1;
    else if(target==3) return 2;

    int production[target+1];//存储每个长度的绳子分割之后的最大乘积值
    //最小子问题的答案
    for(int i=0;i<=3;i++) production[i]=i;

    int max=0;
    for(int i=4;i<=target;i++){
        max=0;
        for(int j=1;j<=i/2;j++){ //优化：不用考虑一次减去一半以上的绳子
            int tmp=production[j] * production[i-j];//计算当前分割策略最大乘积值
            if(max<tmp) max=tmp;
            production[i]=max;//绳子长度为i的问题最优解更新
        }
    }
    return production[target];
}


int main()
{
	int target; cin>>target;
	cout <<max_product_cutting(target) << endl;
	return 0;
} 
