#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric> // Required for std::gcd

using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    // Step 1: Store the maximum 1-based index for each unique value
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        // i + 1 converts the 0-based loop index to the 1-based problem index
        mpp[a[i]] = i + 1; 
    }

    int ans = -1;

    // Step 2: Use nested range-based loops to iterate through the map
    for(auto const& element1 : mpp) {
        for(auto const& element2 : mpp) {
            
            int val1 = element1.first;
            int idx1 = element1.second;
            
            int val2 = element2.first;
            int idx2 = element2.second;
            
            // Step 3: Check if they are coprime using std::gcd
            if(std::gcd(val1, val2) == 1) {
                ans = max(ans, idx1 + idx2);
            }
        }
    }
    
    cout << ans << "\n";
}

int main(){
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    // For your local testing environment
    freopen("Error.txt", "w", stderr);
#endif
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}