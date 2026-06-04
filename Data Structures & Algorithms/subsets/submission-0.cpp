class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include nums[index]
        subset.push_back(nums[index]);
        backtrack(nums, index + 1);

        // Exclude nums[index]
        subset.pop_back();
        backtrack(nums, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};