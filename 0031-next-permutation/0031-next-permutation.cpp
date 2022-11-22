class Solution {
public:
    void reverse(vector<int>& nums,int s,int e){
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int index1 = -1;
        int n = nums.size();
        
        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i]<nums[i+1]){
                index1 = i;
                break;
            }
        }
        int index2 = 0;
        if(index1 != -1){
            for(int i = n-1 ; i >= 0 ; i--){
            if(nums[i] > nums[index1]){
                index2 = i;
                break;
                }
            }
            swap(nums[index1],nums[index2]);
        }
        
        
        
        
        
        
        reverse(nums,index1+1,n-1);
    }
};