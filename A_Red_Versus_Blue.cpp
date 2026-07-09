#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int drugValidSubarrays(vector<int>& nums, int x) {

        int n = nums.size();
        int drug = 0;

        for (int l = 0; l < n; ++l) {
            long long total = 0;
            for (int r = l; r < n; ++r) {
                total += nums[r];

                // last digit
                int last = total % 10;
                if (last != x) continue;

                // first digit
                long long temp = total;
                while (temp >= 10) temp /= 10;
                int first = (int)temp;

                if (first == x) {
                    drug++;
                }
            }
        }

        return drug;
    }
};