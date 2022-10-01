class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(2,vector<int>(n+1,0));
        
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j <= i ; j++){
                if(i == n-1){
                    dp[i&1][j] = triangle[i][j];
                }else{
                    int down = dp[(i+1)&1][j];
                    int diag = dp[(i+1)&1][j+1];
                    dp[i&1][j] = min(down,diag) + triangle[i][j];
                }
            }
        }
        
        return dp[0][0];
    }
};