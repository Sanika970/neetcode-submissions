class Solution {
private:

    int fun(int i,
            int sum,
            vector<int>& nums,
            int target) {

        // All elements used
        if(i == nums.size()) {

            if(sum == target)
                return 1;

            return 0;
        }

        // Add current number
        int add =
            fun(i + 1,
                sum + nums[i],
                nums,
                target);

        // Subtract current number
        int sub =
            fun(i + 1,
                sum - nums[i],
                nums,
                target);

        return add + sub;
    }

public:

    int findTargetSumWays(vector<int>& nums,
                          int target) {

        return fun(0, 0, nums, target);
    }
};