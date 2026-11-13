class Solution {
public:
    // APPROACH 1
    // TC -> O(N + E)
    // SC -> O(N + E)

    // void DFS(unordered_map<int, vector<pair<int, int>>>& adj, 
    //     vector<bool>& visited, int& ans, int u){
        
    //     visited[u] = true;

    //     for(auto pair : adj[u]){
    //         int v = pair.first;
    //         int d = pair.second;

    //         ans = min(ans, d);

    //         if(!visited[v]){
    //             DFS(adj, visited, ans, v);
    //         }
    //     }
    // }

    // APPROACH 2
    // TC -> O(N + E)
    // SC -> O(N + E)
    void BFS(unordered_map<int, vector<pair<int, int>>>& adj, 
        vector<bool>& visited, int& ans, int u){
        
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto pair : adj[node]){
                int v = pair.first;
                int d = pair.second;

                ans = min(ans, d);

                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

    }

    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto vec : roads){

            int u = vec[0];
            int v = vec[1];
            int d = vec[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        
        vector<bool> vis(n + 1, false);

        int ans = INT_MAX;

        // DFS(adj, vis, ans, 1);
        BFS(adj, vis, ans, 1);

        return ans;
    }
};