class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remFreq(k,0);
        int pre = 0;
        remFreq[0] = 1;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            pre += nums[i];
            int rem = (k+pre%k)%k;
            count += remFreq[rem];
            remFreq[rem]++;
        }
        return count;
    }
};