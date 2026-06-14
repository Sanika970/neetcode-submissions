class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        vector<int>nums;
        int count =0;

        for(int i=0; i<=n; i++){
            nums.push_back(i);
        }
       for( int i =1; i<=n; i++){
        count=0;
        while(true){
            count+= nums[i]%2;
            if(nums[i]/2==0){
                ans.push_back(count);
                break;
            }
            nums[i]= nums[i]/2;
        }
       } 
       return ans;
    }
};
