#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];

        vector<long long> ans(n);

        for (int i = 0; i < n; i++) {
            vector<long long> a(n + 1, 0), b(n + 1, 0);

            for (int j = 1; j <= n; j++) {
                a[j] = max(a[j - 1], h[(i + j - 1) % n]);
            }

            for (int j = n - 1; j >= 0; j--) {
                b[j] = max(b[j + 1], h[(i + j) % n]);
            }

            long long c = 0;
            for (int j = 1; j < n; j++) {
                c += min(a[j], b[j]);
            }

            ans[i] = c;
        }

        for (int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}