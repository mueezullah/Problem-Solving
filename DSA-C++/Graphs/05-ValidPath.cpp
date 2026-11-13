class Solution {
public:
    // APPROACH 1
    // TC -> O(n + e)
    // SC -> O(n + e)
    // bool DFS(unordered_map<int, vector<int>>& adj, int& source, int destination, vector<bool>& vis){
    //     if(source == destination)
    //         return true;

    //     if(vis[source] == true)
    //         return false;
        
    //     vis[source] = true;

    //     for(auto node : adj[source]){
    //         if(DFS(adj, node, destination, vis)){
    //             return true;
    //         }
    //     }

    //     return false;
    // }

    // APPROACH 2
    // TC -> O(n + e)
    // SC -> O(n + e)
    bool BFS(unordered_map<int, vector<int>>& adj, int& source, int destination, vector<bool>& vis){

        queue<int> q;
        q.push(source);
        vis[source] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == destination)
                return true;

            for(auto V : adj[node]){
                
                if(!vis[V]){
                    q.push(V);
                    vis[V] = true;
                }
            }

        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int, vector<int>> adj;

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        // return DFS(adj, source, destination, visited);
        return BFS(adj, source, destination, visited);
    }
};