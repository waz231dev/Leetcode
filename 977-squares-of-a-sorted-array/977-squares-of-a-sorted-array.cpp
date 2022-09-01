class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0;
        int j = n-1;
        for(int it = n-1 ; it>=0 ; it--){
            int i2 = nums[i]*nums[i];
            int j2 = nums[j]*nums[j];
            if(i2>j2){
                ans[it] = i2;
                i++;
            }else{
                ans[it] = j2;
                j--;
            }
        }
        return ans;
    }
};