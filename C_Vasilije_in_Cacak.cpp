#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;
        
        long long min_sum = k * (k + 1) / 2;
        long long max_sum = k * n - k * (k - 1) / 2;
        
        if (x >= min_sum && x <= max_sum)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}