//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m = grid.size();
	    int n = grid[0].size();
	    queue<pair<pair<int,int>,int>> q;
	    vector<vector<int>> vis(m,vector<int>(n));
	    for(int i = 0 ; i < m ; i++){
	        for(int j = 0 ; j < n ; j++){
	            if(grid[i][j] == 1){
	                q.push({{i,j},0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    
	    int del[5] = {-1,0,1,0,-1};
	    while(!q.empty()){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        grid[r][c] = d;
	        for(int i = 0 ; i < 4 ; i++){
	            int nr = r + del[i];
	            int nc = c + del[i+1];
	            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]){
	                q.push({{nr,nc},d+1});
	                vis[nr][nc] = 1;
	            }
	        }
	    }
	    return grid;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends