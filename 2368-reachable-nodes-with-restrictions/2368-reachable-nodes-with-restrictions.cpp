class Solution {
public:
    int dfs(int node, vector<int> adj[], vector<int>& vis){
        vis[node] = true;
        int cnt = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                cnt += dfs(it,adj,vis);
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
        for(int i = 0 ; i < restricted.size() ; i++){
            vis[restricted[i]] = 1;
        }
        return dfs(0,adj,vis);
    }
};