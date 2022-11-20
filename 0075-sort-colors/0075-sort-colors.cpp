class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nextZero = 0;
        int nextTwo = nums.size()-1;
        int i = 0;
        while(i <= nextTwo){
            if(nums[i] == 0){
                swap(nums[i++],nums[nextZero++]);
            }else if(nums[i] == 2){
                swap(nums[i],nums[nextTwo--]);
            }else{
                i++;
            }
        }
    }
};