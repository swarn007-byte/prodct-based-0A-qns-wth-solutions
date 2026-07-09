#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ops;
    int flips = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        long long current_val = a[i];
        
        if (flips % 2 != 0) {
            current_val = -current_val;
        }

        if (current_val > 0) {
            ops.push_back(i + 1); 
            flips++;
        }
    }

    cout << ops.size() << "\n";
    for (int i = 0; i < ops.size(); i++) {
        cout << ops[i] << (i == ops.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}