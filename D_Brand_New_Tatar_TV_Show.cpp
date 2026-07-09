#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int a;
    long long b;
    cin >> a >> b;
    
    vector<long long> c(a);
    for (int i = 0; i < a; i++) {
        cin >> c[i];
    }
    
    sort(c.begin(), c.end());
    
    vector<int> drug(a, 0);
    int r = a - 1;
    int losing_count = 0;
    
    for (int i = a - 1; i >= 0; i--) {
        while (c[r] - c[i] > b) {
            if (drug[r] == 0) {
                losing_count--;
            }
            r--;
        }
        
        if (losing_count > 0) {
            drug[i] = 1;
        } else {
            drug[i] = 0;
        }
        
        if (drug[i] == 0) {
            losing_count++;
        }
    }
    
    bool can_win = false;
    for (int i = 0; i < a; i++) {
        if (drug[i] == 1) {
            can_win = true;
            break;
        }
    }
    
    if (can_win) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}