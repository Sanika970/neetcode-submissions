class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void dfs(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            ans.push_back(subset);
            return;
        }

        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            subset.push_back(candidates[i]);

            dfs(candidates, target - candidates[i], i + 1);

            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, 0);

        return ans;
    }
};