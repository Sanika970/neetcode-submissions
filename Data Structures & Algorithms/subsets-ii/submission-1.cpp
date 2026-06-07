class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(int idx, vector<int>& nums) {
        ans.push_back(subset);

        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates at the same level
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);
            backtrack(i + 1, nums);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return ans;
    }
};