class Solution {
    int solve(int i,vector<int>& arr,int k,vector<int>& dp){
        if(i == arr.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        int ans = -1e9;
        int currMax = arr[i];
        
        for(int j = i ; j < i+k && j < arr.size() ; j++){
            currMax = max(currMax,arr[j]);
            int temp = (j-i+1)*currMax + solve(j+1,arr,k,dp);
            ans = max(ans,temp);
        }
        
        return dp[i] = ans;        
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,k,dp);
    }
};