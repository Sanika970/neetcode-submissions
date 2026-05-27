class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    // find ultimate parent
    int findParent(int node) {

        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    // union by rank
    void unionSet(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)
            return;

        if(rank[pu] < rank[pv]) {

            parent[pu] = pv;
        }

        else if(rank[pv] < rank[pu]) {

            parent[pv] = pu;
        }

        else {

            parent[pv] = pu;
            rank[pu]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // initialize parent
        for(int i=1; i<=n; i++) {

            parent[i] = i;
        }

        for(auto it : edges) {

            int u = it[0];
            int v = it[1];

            // already connected
            if(findParent(u) == findParent(v)) {

                return {u, v};
            }

            unionSet(u, v);
        }

        return {};
    }
};