#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    long long n = s.length();

    // Count total number of '1's
    long long ones = 0;
    for (char c : s) {
        if (c == '1') ones++;
    }

    // Edge case: If the string is all 1s, the whole matrix is 1s
    if (ones == n) {
        cout << n * n << "\n";
        return;
    }

    // Duplicate string to handle cyclic/wrap-around sequences easily
    string double_s = s + s;
    
    long long max_k = 0;
    long long current_k = 0;

    for (char c : double_s) {
        if (c == '1') {
            current_k++;
            max_k = max(max_k, current_k);
        } else {
            current_k = 0;
        }
    }

    // Calculate maximum area based on max_k consecutive 1s
    long long width = (max_k + 1) / 2;
    long long height = (max_k + 1) - width;
    
    long long max_area = width * height;
    cout << max_area << "\n";
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