#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long sumAbs = 0;
    long long mn = LLONG_MAX;
    int neg = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        if (x < 0) neg++;

        sumAbs += abs(x);
        mn = min(mn, abs(x));
    }

    if (neg % 2 == 0)
        cout << sumAbs << '\n';
    else
        cout << sumAbs - 2 * mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}