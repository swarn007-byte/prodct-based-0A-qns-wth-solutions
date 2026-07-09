#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        vector<int> used(n, 0);
        vector<int> pos(n);

        bool ok = true;

        for (int i = 0; i < n; i++) {
            int chosen = -1;

            for (int j = 0; j < n; j++) {
                if (!used[j] && b[j] >= a[i]) {
                    chosen = j;
                    break;
                }
            }

            if (chosen == -1) {
                ok = false;
                break;
            }

            used[chosen] = 1;
            pos[i] = chosen;
        }

        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (pos[i] > pos[j]) ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}