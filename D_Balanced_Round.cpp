#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        long long k;
        scanf("%d %lld", &n, &k);
        vector<long long> a(n);
        for(auto &x : a) scanf("%lld", &x);
        sort(a.begin(), a.end());
        
        int best = 1, cur = 1;
        for(int i = 1; i < n; i++){
            if(a[i] - a[i-1] <= k){
                cur++;
            } else {
                cur = 1;
            }
            best = max(best, cur);
        }
        
        printf("%d\n", n - best);
    }
    return 0;
}