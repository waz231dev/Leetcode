//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // bool check(int start,vector<int> adj[],vector<int>& color){
    //     queue<int> q;
	   // q.push(start);
	   // color[start] = 0;
	   // while(!q.empty()){
	   //     int node = q.front();
	   //     q.pop();
	   //     int col = color[node];
	   //     for(auto adjNode : adj[node]){
	   //         if(color[adjNode] == -1){
	   //             q.push(adjNode);
	   //             color[adjNode] = col ^ 1;
	   //         }else{
	   //             if(color[adjNode] == col) return false;
	   //         }
	   //     }
	   // }
	   //     return true;
    // }
    bool dfs(int node,vector<int> adj[],vector<int>& colors,int color){
        colors[node] = color;
        for(auto adjNode : adj[node]){
            if(colors[adjNode] == -1){
                if(!dfs(adjNode,adj,colors,!color)) return false;
            }else{
                if(colors[adjNode] == colors[node]) return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    vector<int> color(v,-1);
	    for(int i = 0 ; i < v ; i++){
	        if(color[i] == -1)
	            if(!dfs(i,adj,color,0)) return false;
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends