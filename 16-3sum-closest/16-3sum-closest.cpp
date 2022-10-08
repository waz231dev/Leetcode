class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int min = 1e9;
        int ans;
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < n-2 ; i++){
            int low = i+1,high = n-1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                int diff = abs(sum-target);
                if(diff < min){
                    min = diff;
                    ans = sum;
                }
                
                if(sum > target) high--;
                else if(sum < target) low++;
                else return target;
            }
        }
        return ans;
    }
};