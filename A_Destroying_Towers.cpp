class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                                                int frees,
                                                int freee) {
       

        sort(occupiedIntervals.begin(), occupiedIntervals.e());

        vector<vector<int>> drug;

        for (auto& interval : occupiedIntervals) {
            int s = interval[0];
            int e = interval[1];

            if (drug.empty() || s > drug.back()[1] + 1LL) {
                drug.push_back({s, e});
            } else {
                drug.back()[1] = max(drug.back()[1], e);
            }
        }

        vector<vector<int>> ans;

        for (auto& interval : drug) {
            int s = interval[0];
            int e = interval[1];

            if (e < frees || s > freee) {
                ans.push_back({s, e});
            } else {
                if (s < frees) {
                    ans.push_back({s, frees - 1});
                }

                if (e > freee) {
                    ans.push_back({freee + 1, e});
                }
            }
        }

        return ans;
    }
};