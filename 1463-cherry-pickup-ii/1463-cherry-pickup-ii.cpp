class Solution {
//     int solve(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
//         if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()){
//             return -1e8;
//         }
        
//         if(i == grid.size()-1){
//             if(j1 == j2) return grid[i][j1];
//             else return grid[i][j1] + grid[i][j2];
//         }
        
//         if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
//         int maxim = -1e8;
//         for(int p = -1 ; p <= 1 ; p++){
//             for(int q = -1 ; q <= 1 ; q++){
//                 int value = 0;
//                 if(j1 == j2) value = grid[i][j1];
//                 else value = grid[i][j1] + grid[i][j2];
//                 value += solve(i+1,j1+p,j2+q,grid,dp);
//                 maxim = max(maxim,value);
//             }
//         }
//         return dp[i][j1][j2] = maxim;
//     }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        for(int j1 = 0 ; j1 < m ; j1++){
            for(int j2 = 0 ; j2 < m ; j2++){
                if(j1 == j2)
                dp[n-1][j1][j2] = grid[n-1][j1];
                else
                dp[n-1][j1][j2] = grid[n-1][j1]+grid[n-1][j2];
            }
        }
        
        for(int i = n-2 ; i>= 0 ; i--){
            for(int j1 = 0 ; j1 < m ; j1++){
                for(int j2 = 0 ; j2 < m ; j2++){
                    int maxim = -1e8;
                    for(int p = -1 ; p <= 1 ; p++){
                        for(int q = -1 ; q <= 1 ; q++){
                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1+p<0 || j1+p>=m || j2+q<0 ||j2+q>=m) continue;
                            value += dp[i+1][j1+p][j2+q];
                            maxim = max(maxim,value);
                        }
                    }
                    dp[i][j1][j2] = maxim;
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};