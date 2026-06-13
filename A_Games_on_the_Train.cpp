#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int maxi = 0;
    int mini = 7; 
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        if (h > maxi){
            maxi= h;
        }
        if (h < mini){
           mini = h;
        } 
    }
    
    int k = maxi-mini+1;
    
    cout << k << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}