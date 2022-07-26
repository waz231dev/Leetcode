class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remFreq(k,0);
        int pre = 0;
        remFreq[0] = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            pre += nums[i];
            int rem = (k+pre%k)%k;
            remFreq[rem]++;
        }
        int count = 0;
        for(int i = 0 ; i < k ; i++){
            count += (remFreq[i]*(remFreq[i]-1))/2;
        }
        return count;
    }
};