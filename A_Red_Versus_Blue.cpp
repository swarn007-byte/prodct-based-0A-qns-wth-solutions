#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;

        int groups = b + 1;
        int q = r / groups;
        int rem = r % groups;

        string ans;

        for (int i = 0; i < groups; i++) {
            int cnt = q + (rem > 0);
            rem--;

            while (cnt--) ans += 'R';

            if (i < b) ans += 'B';
        }

        cout << ans << '\n';
    }

    return 0;
}