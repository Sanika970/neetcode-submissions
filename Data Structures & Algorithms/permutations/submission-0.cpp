class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);      // Choose
            backtrack(nums, start + 1);      // Explore
            swap(nums[start], nums[i]);      // Undo (backtrack)
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};