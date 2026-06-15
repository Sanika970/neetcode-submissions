class Solution {
public:
    int maxArea(vector<int>& heights) {
        int vol=0;
        int n= heights.size();
      for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int neww= min(heights[i], heights[j])*(j-i);
  vol= max(neww, vol);
        }
      }

 return vol;
    }
};
