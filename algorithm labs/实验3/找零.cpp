#include <iostream>
using namespace std;


// 计算时会将2角5分转换成25，1角转换成10，以此类推

int main()
{
	int n;cin>>n;
    int ans=0;
    int a=0,b=0,c=0,d=0;
    if(n>=25){
        ans+=n/25;
        a+=n/25;
        n%=25;
    }
    if(n>=10){
        ans+=n/10;
        b+=n/10;
        n%=10;
    }
    if(n>=5){
        ans+=n/5;
        c+=n/5;
        n%=5;
    }
    if(n>=1){
        ans+=n;
        d=n;
    }

    cout<<ans<<endl;
    cout<<"25: "<<a<<endl;
    cout<<"10: "<<b<<endl;
    cout<<"5: "<<c<<endl;
    cout<<"1: "<<d<<endl;
	return 0;
} 
