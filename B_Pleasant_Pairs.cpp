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

        vector<int> pos(2 * n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            pos[x] = i;
        }

        long long ans = 0;

        for (int x = 1; x <= 2 * n; x++) {
            if (!pos[x]) continue;

            for (int y = x + 1; x * y <= 2 * n; y++) {
                if (!pos[y]) continue;

                if (pos[x] + pos[y] == x * y)
                    ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}