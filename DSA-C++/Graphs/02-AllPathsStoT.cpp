class Solution {
public:
    void DFS(vector<vector<int>>& graph, int u, int target, vector<int>& path, vector<vector<int>>& ans){
        path.push_back(u);
        
        if(u == target){
            ans.push_back(path);
        } else {
            for(int v : graph[u]){
                DFS(graph, v, target, path, ans);
            }
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        int source = 0;
        int target = n - 1;

        vector<int> path;
        vector<vector<int>> ans;

        DFS(graph, source, target, path, ans);

        return ans;
    }
};