#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int a[7];
        for(int i=0;i<7;i++) cin>>a[i];
        sort(a,a+7);
        int sum=a[6];
        for(int i=0;i<6;i++) sum+=-a[i];
        cout<<sum<<"\n";
    }
}