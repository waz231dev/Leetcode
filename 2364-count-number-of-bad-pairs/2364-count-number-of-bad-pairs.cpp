class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        // long long total = (n*(n-1))/2;
        long long cnt = 0;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            cnt += i-mp[i-nums[i]]++;
        }

        return cnt;
    }
};