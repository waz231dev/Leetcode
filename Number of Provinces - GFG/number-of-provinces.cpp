//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int node,vector<int> adj[],vector<bool>& vis){
        vis[node] = true;
        for(auto child : adj[node]){
            if(!vis[child]) dfs(child,adj,vis);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int v) {
        // code here
        vector<int> adjList[v];
        for(int i = 0 ; i < v ; i++){
            for(int j = 0 ; j < v ; j++){
                if(i != j && adj[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool> vis(v,false);
        int cnt = 0;
        for(int i = 0 ; i < v ; i++){
            if(!vis[i]){
                dfs(i,adjList,vis);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends