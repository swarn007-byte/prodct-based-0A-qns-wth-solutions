#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long c;
    cin >> n >> c;

    vector<long long> costs(n);
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        // 1-based index means the distance from 0 is (i + 1)
        costs[i] = a + (i + 1); 
    }

    // Sort the total costs to pick the cheapest options first
    sort(costs.begin(), costs.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (c >= costs[i]) {
            c -= costs[i];
            count++;
        } else {
            // Since it's sorted, if we can't afford this one, we can't afford any subsequent ones
            break; 
        }
    }

    cout << count << "\n";
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