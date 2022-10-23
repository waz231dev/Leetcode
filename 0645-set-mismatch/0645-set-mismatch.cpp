class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> s;
        int n1 = 0,n2 = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            n2 = n2^(i+1)^nums[i];
            if(s.find(nums[i]) != s.end()){
                n1 = nums[i];
            }
            s.insert(nums[i]);
        }
        
        return {n1,n2^n1};
    }
};