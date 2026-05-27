class Solution {
private:

    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for(auto it : adj[node]) {

            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

public:

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        // build graph
        for(auto it : edges) {

            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int count = 0;

        // dfs on every component
        for(int i=0; i<n; i++) {

            if(!vis[i]) {

                dfs(i, adj, vis);

                count++;
            }
        }

        return count;
    }
};