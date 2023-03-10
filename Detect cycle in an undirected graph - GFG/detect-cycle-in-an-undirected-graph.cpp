//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // bool isCycle(int src,vector<int> adj[],vector<int>& vis){
    //     vis[src] = 1;
    //     queue<pair<int,int>> q;
    //     q.push({src,-1});
    //     while(!q.empty()){
    //         auto front = q.front();
    //         q.pop();
    //         int node = front.first;
    //         int par = front.second;
    //         for(auto child : adj[node]){
    //             if(child != par){
    //                 if(!vis[child]){
    //                     q.push({child,node});
    //                     vis[child] = 1;
    //                 }else{
    //                     return true;
    //                 }
    //             }
    //         }
    //     }
        
    //     return false;
    // }
    bool isCycle(int src,vector<int> adj[],vector<int>& vis,int par){
        if(vis[src]) return true;
        vis[src] = 1;
        for(auto child : adj[src]){
            if(child != par){
                if(isCycle(child,adj,vis,src)) return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i] && isCycle(i,adj,vis,-1)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends