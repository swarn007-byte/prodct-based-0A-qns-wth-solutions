#include <iostream>
using namespace std;

void solve(){
    string s;
    cin>>s;
    
    int count=0;
    for(auto it:s){
        if(it=='(')count++;
        else count--;
    }
    if(count==0){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}