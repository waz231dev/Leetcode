class Solution {
//     int solve(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
//         if(j < 0 || j == n) return INT_MAX;
//         if(i == 0) return matrix[i][j];
        
//         if(dp[i][j] != INT_MIN) return dp[i][j];
        
//         int leftd = solve(i-1,j-1,n,matrix,dp);
//         int rightd = solve(i-1,j+1,n,matrix,dp);
//         int up = solve(i-1,j,n,matrix,dp);
        
//         return dp[i][j] = min(up,min(leftd,rightd)) + matrix[i][j];
//     }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MAX;
        for(int k = 0 ; k < n ; k++){
            vector<vector<int>> dp(2,vector<int>(n));
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(i == 0) dp[i][j] = matrix[i][j];
                    else{
                        int left = INT_MAX,right = INT_MAX,up = INT_MAX;
                        if(j > 0) left = dp[(i-1)&1][j-1];
                        if(j < n-1) right = dp[(i-1)&1][j+1];
                        up = dp[(i-1)&1][j];
                        dp[i&1][j] = min(up,min(left,right))+matrix[i][j];
                    }
                }
            }
            ans = min(ans,dp[(n-1)&1][k]);
        }
        return ans;
    }
};