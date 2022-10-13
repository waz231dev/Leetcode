class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int day = prices.size()-1 ; day >= 0 ; day--){
            for(int canBuy = 0 ; canBuy <= 1 ; canBuy++){
                for(int trans = 1 ; trans <= k ; trans++){
                    int profit = 0;
                    if(canBuy){
                        int buy = -prices[day] + dp[day+1][0][trans];
                        int notBuy = dp[day+1][1][trans];
                        profit = max(buy,notBuy);
                    }else{
                        int sell = prices[day] + dp[day+1][1][trans-1];
                        int notSell = dp[day+1][0][trans];
                        profit = max(sell,notSell);
                    }
                    dp[day][canBuy][trans] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};