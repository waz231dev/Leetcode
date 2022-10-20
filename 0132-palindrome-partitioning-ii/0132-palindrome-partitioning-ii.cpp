class Solution {
    bool isPalindrome(string& s){
        int i = 0;
        int j = s.size()-1;
        
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,string& s,vector<int>& dp){
        if(i == s.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        string tempStr = "";
        int minCuts = 1e9;
        for(int j = i ; j < s.size() ; j++){
            tempStr += s[j];
            if(isPalindrome(tempStr))
                minCuts = min(minCuts,1+solve(j+1,s,dp));
        }
        
        return dp[i] = minCuts;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp)-1;
    }
};