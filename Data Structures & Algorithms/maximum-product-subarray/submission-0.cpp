class Solution {
public:

    int maxProduct(vector<int>& nums) {

        int maxProd = nums[0];
        int minProd = nums[0];

        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            // Sign flip
            if(nums[i] < 0)
                swap(maxProd, minProd);

            // Best product ending here
            maxProd =
                max(nums[i],
                    nums[i] * maxProd);

            // Worst product ending here
            minProd =
                min(nums[i],
                    nums[i] * minProd);

            ans = max(ans, maxProd);
        }

        return ans;
    }
};