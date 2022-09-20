class Solution {
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int>& nums1,vector<int>& nums2,int& ans){
        if(i == nums1.size() || j == nums2.size())
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        solve(i+1,j,nums1,nums2,ans);
        solve(i,j+1,nums1,nums2,ans);
        int len = 0;
        if(nums1[i] == nums2[j]){
            dp[i][j] = 1 + solve(i+1,j+1,nums1,nums2,ans);
        }else{
            dp[i][j] = 0;
        }
        ans = max(ans,dp[i][j]);
        return dp[i][j];
        
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(nums2.size(),-1));
        int ans = 0;
        solve(0,0,nums1,nums2,ans);
        return ans;
    }
};