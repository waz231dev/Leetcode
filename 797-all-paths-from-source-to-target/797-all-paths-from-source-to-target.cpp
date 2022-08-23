class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph,int node,vector<int>& vis,vector<int>& path){
        vis[node] = 1;
        path.push_back(node);
        if(node == graph.size()-1){
            ans.push_back(path);
        }
        for(auto it : graph[node]){
            dfs(graph,it,vis,path);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n);
        vector<int> path;
        dfs(graph,0,vis,path);
        return ans;
    }
};