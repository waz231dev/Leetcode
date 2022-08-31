class Solution {
public:
    int del[5] = {-1,0,1,0,-1};
    int m,n;
    void dfs(vector<vector<int>>& heights,int x,int y,set<pair<int,int>>& s,int height){
        s.insert({x,y});
        // cout<<x<<" "<<y<<endl;
        for(int i = 0 ; i < 4 ; i++){
            int newx = x + del[i];
            int newy = y + del[i+1];
            if(newx>=0 && newx<m && newy>=0 && newy<n && s.find({newx,newy}) == s.end() && heights[newx][newy] >= height){
                // cout<<newx<<" "<<newy<<endl;
                dfs(heights,newx,newy,s,heights[newx][newy]);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        set<pair<int,int>> pacific;
        set<pair<int,int>> atlantic;
        // dfs(heights,0,0,pacific,heights[0][0]);
        for(int i = 0 ; i < m ; i++){
            dfs(heights,i,0,pacific,heights[i][0]);
            dfs(heights,i,n-1,atlantic,heights[i][n-1]);
        }
        
        for(int j = 0 ; j < n ; j++){
            dfs(heights,0,j,pacific,heights[0][j]);
            dfs(heights,m-1,j,atlantic,heights[m-1][j]);
        }
        vector<vector<int>> res;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(pacific.find({i,j}) != pacific.end() && atlantic.find({i,j}) != atlantic.end())
                    res.push_back({i,j});
            }
        }
        // for(auto it : pacific){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        return res;
    }
};