class Solution {
    static bool compare(pair<int,int>& p1,pair<int,int>& p2){
        if(p1.first == p2.first){
            return p1.second>p2.second;
        }
        return p1.first < p2.first;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i = 0 ; i < nums.size() ; i++){    
            freq[nums[i]]++;
        }
        
        vector<pair<int,int>> v;
        for(auto it : freq){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),compare);
        
        vector<int> ans;
        for(int i = 0 ; i < v.size() ; i++){
            int cnt = v[i].first;
            while(cnt--){
                ans.push_back(v[i].second);
            }
        }
        return ans;
    }
};