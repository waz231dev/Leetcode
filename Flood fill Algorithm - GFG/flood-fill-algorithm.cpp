//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int del[5] = {-1,0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>& image,int newColor,int color){
        if(color == newColor) return;
        image[i][j] = newColor;
        for(int it = 0 ; it < 4 ; it++){
            int nexti = i + del[it];
            int nextj = j + del[it+1];
            if(nexti >= 0 && nexti < image.size() && nextj >= 0 && nextj < image[0].size() && image[nexti][nextj] == color){
                dfs(nexti,nextj,image,newColor,color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        
        dfs(sr,sc,image,newColor,image[sr][sc]);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends