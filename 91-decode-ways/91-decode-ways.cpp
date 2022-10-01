class Solution {
    int solve(string& s,int ind,vector<int>& dp){
        if(ind == s.size())
            return 1;
        if(ind > s.size() || s[ind] == '0')
            return 0;
        if(dp[ind] != -1) return dp[ind];
        int left = solve(s,ind+1,dp);
        int right = 0;
        
        if(stoi(s.substr(ind,2)) >= 1 && stoi(s.substr(ind,2)) <= 26){
            right = solve(s,ind+2,dp);
        }
        
        return dp[ind] = left+right;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(s,0,dp);    
    }
};