class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(2,0));
        
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int canBuy = 0 ; canBuy <= 1 ; canBuy++){
                int profit = 0;
                if(canBuy){
                    int buy = -prices[ind] + dp[(ind+1)%2][0];
                    int notBuy = dp[(ind+1)%2][1];
                    profit = max(buy,notBuy);
                }else{
                    int sell = prices[ind] - fee + dp[(ind+1)%2][1];
                    int notSell = dp[(ind+1)%2][0];
                    profit = max(sell,notSell);
                }
                dp[ind%2][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
};