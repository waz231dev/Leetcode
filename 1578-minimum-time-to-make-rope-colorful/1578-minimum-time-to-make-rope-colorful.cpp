class Solution {
    int solve(int ind,string& colors,char last,vector<int>& neededTime,vector<vector<int>>& dp){
        
        if(ind == 0){
            if(colors[ind] == last) return 0;
            else return neededTime[ind];
        }
        
        if(dp[ind][last-'a'] != -1) return dp[ind][last-'a'];
        
        int pick = 0;
        if(colors[ind] != last){
            pick = neededTime[ind] + solve(ind-1,colors,colors[ind],neededTime,dp);
        }
        
        int notpick = solve(ind-1,colors,last,neededTime,dp);
        
        return dp[ind][last-'a'] = max(pick,notpick);
    }
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int sum = 0;
        for(int time : neededTime){
            sum += time;
        }
        int n = colors.size();
        vector<vector<int>> dp(n,vector<int>(27,-1));
        return sum - solve(n-1,colors,'{',neededTime,dp);
    }
};