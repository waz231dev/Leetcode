class Solution {
//     bool solve(int i, int j,string& s,string& p,vector<vector<int>>& dp){
        
//         if(i == 0 && j == 0) return true;
//         if(j == 0 && i > 0) return false;
        
//         if(i == 0 && j > 0){
//             for(int it = 0 ; it < j ; it++){
//                 if(p[it] != '*') return false;
//             }
//             return true;
//         }
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i-1] == p[j-1] || p[j-1] == '?')
//             return dp[i][j] = solve(i-1,j-1,s,p,dp);
        
//         if(p[j-1] == '*'){
//             return dp[i][j] = solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
//         }
        
//         return dp[i][j] = false;
//     }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> prev(m+1),curr(m+1);
        
        //Base Case
        prev[0] = 1;
        for(int j = 1 ; j <= m ; j++){
            prev[j] = 1;
            for(int it = 0 ; it < j ; it++){
                if(p[it] != '*') prev[j] = 0;
            }
        }
        
        for(int i = 1; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    curr[j] = prev[j-1];
                else if(p[j-1] == '*')
                    curr[j] = prev[j] || curr[j-1];
                else 
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};