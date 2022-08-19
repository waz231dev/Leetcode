class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int,int> freqMap;
        unordered_map<int,int> subsEnd;
        
        for(auto num : nums){
            freqMap[num]++;
        }
        for(auto num : nums){
            if(freqMap[num] == 0) continue;
            
            if(subsEnd[num-1] > 0){
                subsEnd[num-1]--;
                subsEnd[num]++;
            }else if(freqMap[num+1] > 0 && freqMap[num+2] > 0){
                freqMap[num+1]--;
                freqMap[num+2]--;
                subsEnd[num+2]++;
            }else{
                return false;
            }
            freqMap[num]--;
        }
        return true;
    }
};