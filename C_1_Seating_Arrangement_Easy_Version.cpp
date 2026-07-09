#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(){
    int n; int m;
    cin>>n;
    cin>>m;
    vector<int>crates(n);
    vector<int>parates(m);

    for(int i=0;i<n;i++)cin>>crates[i];
    for(int i=0;i<n;i++)cin>>parates[i];

    sort(crates.rbegin(),crates.rend());
   

    for(int i=0;i<n;i++){
        crates[i]+=i;
    }
    priority_queue<int> pq;
    for(auto it:parates){
        pq.push(it);
    }
    int cnt=0;
    for(int i=0;i<crates.size();i++){
        int drug=pq.top();
        if(crates[i]<=drug){
            cnt++;
            drug-=crates[i];
            pq.pop();
            pq.push(drug);
            
        }
    }
    cout<<count<<endl;

    


    

}

int main(){
    solve();
   
}