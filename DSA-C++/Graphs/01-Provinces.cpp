class Solution {
public:
    // void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& isVisited){
    //     isVisited[u] = true;

    //     for(int v : adj[u]){
    //         if(!isVisited[v]){
    //             DFS(adj, v, isVisited);
    //         }
    //     }
    // }

    void BFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& isVisited){
        queue<int> q;

        q.push(u);
        isVisited[u] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int u : adj[curr]){
                if(!isVisited[u]){
                    BFS(adj, u, isVisited);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // APPROACH 1
        // TC -> O()
        // SC -> O()
        // int n = isConnected.size();

        // vector<bool> isVisited(n, false);
        // unordered_map<int, vector<int>> adj;
        
        // for(int i = 0; i < n; i++){

        //     for(int j = 0; j < n; j++){
                
        //         if(isConnected[i][j] == 1){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }

        // int count = 0;
        // for(int i = 0; i < n; i++){

        //     if(!isVisited[i]){
        //         DFS(adj, i, isVisited);
        //         count++;
        //     }
        // }
        // return count;


        // APPROACH 2
        // TC -> O()
        // SC -> O()

        int n = isConnected.size();

        vector<bool> isVisited(n, false);
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(!isVisited[i]){
                BFS(adj, i, isVisited);
                count++;
            }
        }

        return count;
    }
};