class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(),0);
        
        for(int i = n-2 ; i >= 0 ; i--){
            int minJump = 1e5;
            for(int j = 1 ; j <= nums[i] && i+j<n ; j++){
                minJump = min(minJump,dp[i+j]);
            }
            dp[i] = minJump+1;
        }
        return dp[0];
    }
};