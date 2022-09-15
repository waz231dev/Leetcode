class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        if(changed.size()&1)
            return {};
        sort(changed.begin(),changed.end());
        unordered_map<int,int> freq;
        
        for(int elem : changed){
            freq[elem]++;
        }
        vector<int> res;
        for(int elem : changed){
            if(freq[elem] == 0) continue;
            if(freq[2*elem] == 0) return {};
            res.push_back(elem);
            freq[elem]--;
            freq[2*elem]--;
        }
        return res;
    }
};