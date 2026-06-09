class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > p;

        vector<vector<int>> ans;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;   // squared distance

            p.push({dist, i});
        }

        for (int i = 0; i < k; i++) {
            ans.push_back(points[p.top().second]);
            p.pop();
        }

        return ans;
    }
};