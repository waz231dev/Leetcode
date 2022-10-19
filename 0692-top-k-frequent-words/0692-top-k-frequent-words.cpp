class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(string word : words){
            freq[word]++;
        }
        
        vector<pair<string,int>> v;
        for(auto it : freq){
            v.push_back({it.first,it.second});
        }
        
        sort(v.begin(),v.end(),[](const auto& p1,const auto& p2){
           if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second>p2.second;
        });
        
        vector<string> ans(k);
        
        for(int i = 0 ; i < k ; i++){
            ans[i] = v[i].first;
        }
        
        return ans;
    }
};