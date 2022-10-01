class Solution {
    int solve(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j < 0 || j == n) return INT_MAX;
        if(i == 0) return matrix[i][j];
        
        if(dp[i][j] != INT_MIN) return dp[i][j];
        
        int leftd = solve(i-1,j-1,n,matrix,dp);
        int rightd = solve(i-1,j+1,n,matrix,dp);
        int up = solve(i-1,j,n,matrix,dp);
        
        return dp[i][j] = min(up,min(leftd,rightd)) + matrix[i][j];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            vector<vector<int>> dp(m,vector<int>(n,INT_MIN));
            ans = min(ans,solve(m-1,i,n,matrix,dp));
        }
        return ans;
    }
};