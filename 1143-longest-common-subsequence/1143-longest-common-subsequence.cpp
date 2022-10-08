class Solution {
//     int solve(int i,int j,string& t1,string& t2,vector<vector<int>>& dp){
//         if(i < 0 || j < 0) return 0;
//         if(i == 0 && j == 0){
//             return t1[i] == t2[j];
//         }
//         if(dp[i][j] != -1) return dp[i][j];
        
//         if(t1[i] == t2[j]){
//             return dp[i][j] = 1+solve(i-1,j-1,t1,t2,dp);
//         }
        
//         int one = solve(i-1,j,t1,t2,dp);
//         int two = solve(i,j-1,t1,t2,dp);
//         return dp[i][j] = max(one,two);
//     }
public:
    int longestCommonSubsequence(string s1, string s2) {
        
        int m = s1.size();
        int n = s2.size();
        vector<int> prev(n),curr(n);
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(s1[i] == s2[j]){
                    curr[j] = 1;
                    if(i > 0 && j > 0)
                        curr[j] += prev[j-1];
                }else{
                    if(i > 0) curr[j] = max(curr[j],prev[j]);
                    if(j > 0) curr[j] = max(curr[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};