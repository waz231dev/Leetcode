class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> index(n);
        int maxim = 1;
        int lastIndex = 0;
        for(int i = 0 ; i < n ; i++){
            index[i] = i;
            for(int j = 0 ; j < i ; j++){
                if(nums[i]%nums[j] == 0 && 1+dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    index[i] = j;
                }
            }
            
            if(dp[i] > maxim){
                maxim = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        
        while(index[lastIndex] != lastIndex){
            lastIndex = index[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        
        return ans;
    }
};