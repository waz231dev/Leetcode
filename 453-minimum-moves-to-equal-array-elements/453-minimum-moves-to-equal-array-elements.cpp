class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0,minim = INT_MAX;
        for(auto n : nums){
            minim = min(n,minim);
        }
        
        for(auto n : nums){
            res += (n - minim);
        }
        
        return res;
    }
};