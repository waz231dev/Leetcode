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
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int canBuy = 0 ; canBuy <= 1 ; canBuy++){
                int profit = 0;
                if(canBuy){
                    int buy = -prices[ind] + dp[ind+1][0];
                    int notBuy = dp[ind+1][1];
                    profit = max(buy,notBuy);
                }else{
                    int sell = prices[ind];
                    if(ind+2 <= n) sell += dp[ind+2][1];
                    int notSell = dp[ind+1][0];
                    profit = max(sell,notSell);
                }
                dp[ind][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
};