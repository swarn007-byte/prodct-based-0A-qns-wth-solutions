#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        
        vector<long long> b(n + 1, 0), c(n + 1, 0);
        for(int i = 1; i <= n; i++){
            b[i] = b[i - 1] + (a[i] == 1);   
            c[i] = c[i - 1] + (a[i] == 3);   
        }
        
        vector<long long> d(n + 1);
        for(int i = 0; i <= n; i++) d[i] = 2 * c[i] - i;
        
        vector<long long> e(n + 2, LLONG_MAX);
        for(int i = n - 1; i >= 1; i--)
            e[i] = min(d[i], e[i + 1]);
        
        bool ok = false;
        for(int l = 1; l <= n - 2 && !ok; l++){
            long long f = 2 * b[l] - l; 
            if(f >= 0){
                long long g = e[l + 1];  
                if(g <= d[l]) ok = true;
            }
        }
        
        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;
}