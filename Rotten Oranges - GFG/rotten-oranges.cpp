//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        queue<pair<pair<int,int>,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int time = 0;
        int del[5] = {-1,0,1,0,-1};
        while(!q.empty()){
            auto front = q.front();
            int r = front.first.first;
            int c = front.first.second;
            int t = front.second;
            q.pop();
            time = max(time,t);
            for(int i = 0 ; i < 4 ; i++){
                int nextr = r+del[i];
                int nextc = c+del[i+1];
                if(nextr >= 0 && nextr < m && nextc >= 0 && nextc < n && grid[nextr][nextc] == 1){
                    q.push({{nextr,nextc},t+1});
                    grid[nextr][nextc] = 2;
                    fresh--;
                }
            }
        }
        if(fresh) return -1;
        
        return time;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends