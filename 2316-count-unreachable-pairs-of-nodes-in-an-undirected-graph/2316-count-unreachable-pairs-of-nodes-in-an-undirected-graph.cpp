class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& graph,int i,vector<int>& vis,int& cnt){
        vis[i] = 1;
        cnt++;
        for(int it : graph[i]){
            if(vis[it] == 0){
                dfs(graph,it,vis,cnt);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> graph(n);
        for(int i = 0 ; i < edges.size() ; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        
        long long ans = ((long long)n*(n-1))/2;
        for(int i = 0 ; i < n ; i++){
            
            if(vis[i] == 0){
                int cnt = 0;
                dfs(graph,i,vis,cnt);
                ans -= ((long long)cnt*(cnt-1))/2;
            }
            
        }
        
        return ans;
    }
};