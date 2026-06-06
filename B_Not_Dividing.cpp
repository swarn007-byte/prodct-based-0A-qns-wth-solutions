#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric> // Required for std::gcd

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < n; i++) {
            if (a[i] == 1) a[i] = 2;
        }

        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] % a[i] == 0) {
                a[i + 1]++;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}