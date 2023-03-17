//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
//   bool dfsCheck(int node, vector<int> adj[],int vis[],int pathVis[]){
//       vis[node] = 1;
//       pathVis[node] = 1;
       
       
//       for(auto adjNode : adj[node]){
//           if(!vis[adjNode]){
//               if(dfsCheck(adjNode,adj,vis,pathVis)) return true;
//           }
//             else if(pathVis[adjNode]){
//                 return true;
//             }
//       }
       
       
       
//       pathVis[node] = 0;
//       return false;
//   }
    bool dfsCheck(int node, vector<int> adj[],int vis[]){
       vis[node] = 2;
       
       for(auto adjNode : adj[node]){
           if(!vis[adjNode]){
               if(dfsCheck(adjNode,adj,vis)) return true;
           }
            else if(vis[adjNode] == 2){
                return true;
            }
       }
       
       
       
       vis[node] = 1;
       return false;
   }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        // int pathVis[V] = {0};
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(dfsCheck(i,adj,vis)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends