class Solution {
    int solve(int day,int canBuy,int trans,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(trans == 0) return 0;
        if(day == prices.size()) return 0;
        
        if(dp[day][canBuy][trans] != -1) return dp[day][canBuy][trans];
        int profit = 0;
        if(canBuy){
            int buy = -prices[day] + solve(day+1,0,trans,prices,dp);
            int notBuy = solve(day+1,1,trans,prices,dp);
            profit = max(buy,notBuy);
        }else{
            int sell = prices[day] + solve(day+1,1,trans-1,prices,dp);
            int notSell = solve(day+1,0,trans,prices,dp);
            profit = max(sell,notSell);
        }
        return dp[day][canBuy][trans] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};