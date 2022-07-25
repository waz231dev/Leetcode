class Solution {
public:
    int firstPos(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
    
    int lastPos(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstPos(nums,target),lastPos(nums,target)};
    }
};