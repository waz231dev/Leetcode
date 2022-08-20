class Solution {
public:
    int dfs(int node, vector<int> adj[], vector<int>& vis,unordered_set<int>& res){
        vis[node] = true;
        int cnt = 1;
        
        for(auto it : adj[node]){
            if(!vis[it] && res.find(it) == res.end()){
                cnt += dfs(it,adj,vis,res);
            }
        }
        return cnt;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<int> adj[n];
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        unordered_set<int> res(restricted.begin(),restricted.end());
        return dfs(0,adj,vis,res);
    }
};