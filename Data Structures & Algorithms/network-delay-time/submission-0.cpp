class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
          // Adjacency list: {neighbor, weight}
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
        }

        // Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Min-heap: {distance, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            // Skip outdated entries
            if (time > dist[node])
                continue;

            for (auto &[neighbor, weight] : graph[node]) {
                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
