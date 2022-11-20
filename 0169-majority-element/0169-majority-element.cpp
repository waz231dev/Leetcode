class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 0;
        int elem = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(cnt == 0){
                elem = nums[i];
            }
            
            if(elem == nums[i])
                cnt++;
            else
                cnt--;
        }
        
        return elem;
    }
};