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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0, x; i < n; i++) cin >> x;

        vector<long long> pref(n), suff(n);

        pref[0] = a[0];
        for (int i = 1; i < n; i++)
            pref[i] = gcd(pref[i - 1], a[i]);

        suff[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suff[i] = gcd(suff[i + 1], a[i]);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long g = gcd(pref[i], suff[i]);
            if (g < a[i]) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}