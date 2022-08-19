class Solution {
public:
    int bfs(int n,vector<int> adj[],set<pair<int,int>>& map){
        int cnt = 0;
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                    if(map.find({it,node}) == map.end())
                        cnt++;
                }
            }
        }
        return cnt;        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n+1];
        set<pair<int,int>> map;
        
        for(auto edge : connections){
            map.insert({edge[0],edge[1]});
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        return bfs(n,adj,map);
    }
};