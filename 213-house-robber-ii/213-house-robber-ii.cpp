class Solution {
    int solve(vector<int>& nums,int left,int right){
        vector<int> dp(2);
        dp[0] = nums[left];
        dp[1] = max(nums[left],nums[left+1]);
        for(int i = left+2 ; i <= right ; i++){        
            dp[(i-left)%2] = max(dp[(i-left-1)%2],nums[i] + dp[(i-left-2)%2]);
        }
        return dp[(right-left)%2];
    }
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        // int ans = solve(nums,1,n-1);
        // return ans;
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};