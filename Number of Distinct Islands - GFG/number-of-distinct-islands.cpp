//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int sr,int sc,vector<pair<int,int>>& path){
        vis[r][c] = 1;
        path.push_back({r-sr,c-sc});
        int m = grid.size();
        int n = grid[0].size();
        
        int del[5] = {-1,0,1,0,-1};
        for(int i = 0 ; i < 4 ; i++){
            int nr = r + del[i];
            int nc = c + del[i+1];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1){
                dfs(nr,nc,grid,vis,sr,sc,path);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n));
        set<vector<pair<int,int>>> st;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> path;
                    dfs(i,j,grid,vis,i,j,path);
                    st.insert(path);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends