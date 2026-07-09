#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<long long> b;
    int c = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            c++;
        } else {
            b.push_back(c);
            c = 1;
        }
    }
    b.push_back(c);
    
    sort(b.begin(), b.end());
    int m = b.size();
    
    vector<long long> d(m + 1, 0);
    for (int i = m - 1; i >= 0; i--) {
        d[i] = d[i+1] + b[i];
    }
    
    int ans = 0;
    
    for (int i = 0; i < m; i++) {
        if (i == 0 || b[i-1] < b[i]) {
            long long x = m - i;
            long long y = d[i];
            
            if (k % x == y % x) {
                long long mini = y - x * (b[i] - 1);
                
                if (k >= mini) {
                    ans++;
                }
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}