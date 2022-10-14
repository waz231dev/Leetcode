class Solution {
    int solve(int ind,int canBuy,vector<int>& prices,vector<vector<int>>& dp){
        if(ind >= prices.size()) return 0;
        
        
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        int profit = 0;
        if(canBuy){
            int buy = -prices[ind] + solve(ind+1,0,prices,dp);
            int notBuy = solve(ind+1,1,prices,dp);
            profit = max(buy,notBuy);
        }else{
            int sell = prices[ind] + solve(ind+2,1,prices,dp);
            int notSell = solve(ind+1,0,prices,dp);
            profit = max(sell,notSell);
        }
        
        return dp[ind][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};