class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long startSum = 0;
        long lastSum = 0;
        int min = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            lastSum += nums[i];
        }
        int ans;
        for(int i = 0 ; i < n ; i++){
            startSum += nums[i];
            lastSum -= nums[i];
            int startAvg = startSum/(i+1);
            int lastAvg = lastSum == 0 ? 0 : lastSum/(n-i-1);
            int avgDiff = abs(startAvg - lastAvg);
            if(avgDiff<min){
                ans = i;
                min = avgDiff;
            }
        }
        return ans;
    }
};