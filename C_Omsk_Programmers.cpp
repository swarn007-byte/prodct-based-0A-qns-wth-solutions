#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, x;
        cin >> a >> b >> x;
        
        vector<pair<long long,long long>> ca, cb;
        long long v = a,  count = 0;
        while(true){
            ca.push_back({v,  count});
            if(v == 0) break;
            v = v / x;
             count++;
        }
        v = b;  count = 0;
        while(true){
            cb.push_back({v,  count});
            if(v == 0) break;
            v = v / x;
             count++;
        }
        
        long long ans = LLONG_MAX;
        for(auto [u, sw] : ca){
            for(auto [v, sr] : cb){
                long long cost = sw + sr + abs(u - v);
                ans = min(ans, cost);
            }
        }
        cout << ans << "\n";
    }
}