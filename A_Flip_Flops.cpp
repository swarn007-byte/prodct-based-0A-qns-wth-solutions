#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        long long n,c,k; cin>>n>>c>>k;
        vector<long long>a(n);
        for(auto&x:a)cin>>x;
        sort(a.begin(),a.end());
        
        for(auto&x:a) if(x==0&&k>0){x=1;k--;}
        
        long long cur=c;
        int last=-1;
        for(int i=0;i<n;i++)
            if(a[i]>0&&a[i]<=cur){last=i;cur+=a[i];}
        
        cur=c;
        for(int i=0;i<n;i++){
            if(a[i]>0&&a[i]<=cur){
                if(i==last){
                    long long boost=min(k, cur-a[i]);
                    cur+=boost;
                }
                cur+=a[i];
            }
        }
        cout<<cur<<"\n";
    }
}