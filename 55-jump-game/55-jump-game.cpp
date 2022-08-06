class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int minJump = 1;
        for(int i = n-2 ; i >=0 ; i--){
            if(nums[i] >= minJump)
                minJump = 1;
            else
                minJump++;
        }
        return minJump==1;
    }
};