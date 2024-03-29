class Solution {
public:
    bool isCycleHelper(vector<int> adj[],int src,vector<int> vis){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it] = 1;
                }else if(parent != it){
                    return true;
                }
            }
            
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+1];
        
        for(int i = 0 ; i < n ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
            // print(adj,n);
            vector<int> vis(n+1,0);
            if(isCycleHelper(adj,edges[i][0],vis))
                return edges[i];
            // cout<<isCycle(n,adj);
            // isCycle(n,adj);
        }
        
        return {};
    }
    
    void print(vector<int> adj[],int n){
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                cout<<i<<"-"<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
    // bool isCycle(int n,vector<int> adj[]){
    //     vector<int> vis(n+1,0);
    //     for(int i = 1 ; i <= n ; i++){
    //         if(!vis[i]){
    //             if(isCycleHelper(adj,i,vis))
    //                 return true;
    //         }
    //     }
    //     return false;
    // }