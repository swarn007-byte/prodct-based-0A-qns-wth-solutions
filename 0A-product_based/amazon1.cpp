#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;
vector<int> freq(26, 0);

int f(int i, int j, string &a, string &b)
{
    if (i == (int)a.size() && j == (int)b.size())
    {
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];

    int t1 = INT_MAX;
    if (i < (int)a.size())
    {
        int c = a[i] - 'a';
        int k = 0;
        for (int x = c + 1; x < 26; x++) k += freq[x];  
        freq[c]++;
        t1 = k + f(i + 1, j, a, b);
        freq[c]--;   
    }

    int t2 = INT_MAX;
    if (j < (int)b.size())
    {
        int c = b[j] - 'a';
        int k = 0;
        for (int x = c + 1; x < 26; x++) k += freq[x];  
        freq[c]++;
        t2 = k + f(i, j + 1, a, b);
        freq[c]--;
    }

    return dp[i][j] = min(t1, t2);
}

int getMinimumConflicts(string a, string b)
{
    dp.assign(a.size() + 1, vector<int>(b.size() + 1, -1));
    fill(freq.begin(), freq.end(), 0);
    return f(0, 0, a, b);
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << getMinimumConflicts(a, b) << endl;
    return 0;
}