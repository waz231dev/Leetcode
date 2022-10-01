class Solution {
    // int solve(string& s,int ind,vector<int>& dp){
    //     if(ind < 0)
    //         return 1;
    //     if(s[ind] == '0')
    //         return 0;
    //     if(dp[ind] != -1) return dp[ind];
    //     int left = solve(s,ind-1,dp);
    //     int right = 0;
    //     if(ind >= 1 &&(s[ind-1] == '1' || (s[ind-1] == '2' && s[ind] <= '6'))){
    //         right = solve(s,ind-2,dp);
    //     }
    //     // cout<<left<<endl;
    //     return dp[ind] = left+right;
    // }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '0') dp[i] = 0;
            else{ 
                dp[i] = dp[i+1];
                if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){
                    dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
        
    }
};