class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int evenSum = 0;
        for(int num : nums){
            if(num%2==0){
                evenSum += num;
            }
        }
        vector<int> ans;
        for(int i = 0 ; i < queries.size() ; i++){
            int ind = queries[i][1];
            int val = queries[i][0];
            if(nums[ind] % 2 == 0){
                evenSum -= nums[ind];
            }
            nums[ind] += val;
            if(nums[ind] % 2 == 0){
                evenSum += nums[ind];
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};