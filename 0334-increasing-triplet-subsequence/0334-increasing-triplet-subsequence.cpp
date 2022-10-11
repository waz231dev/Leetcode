class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n);
        vector<int> rightMax(n);
        leftMin[0] = INT_MAX;
        rightMax[n-1] = INT_MIN;
        
        for(int i = 1 ; i < n ; i++)
            leftMin[i] = min(leftMin[i-1],nums[i-1]);
        
        for(int i = n-2 ; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1],nums[i+1]);
        
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > leftMin[i] && nums[i] < rightMax[i]) return true;
        }
        
        return false;
    }
};