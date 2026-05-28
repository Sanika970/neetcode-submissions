class Solution {
private:
    bool fun(int i, vector<int>& nums) {
        int n = nums.size();

        if (i >= n - 1)
            return true;

        for (int jump = 1; jump <= nums[i]; jump++) {
            if (fun(i + jump, nums))
                return true;
        }

        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        return fun(0, nums);
    }
};