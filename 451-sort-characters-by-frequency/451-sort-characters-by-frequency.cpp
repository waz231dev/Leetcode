class Solution {
static bool comp(const pair<int,int>& p1,const pair<int,int>& p2){
    return p1.second > p2.second;
}
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }
        
        vector<pair<char,int>> V(freq.begin(),freq.end());
        // for(auto it : freq){
        //     V.push_back(it);
        // }
        
        sort(V.begin(),V.end(),comp);
        string ans = "";
        for(int i = 0 ; i < V.size() ; i++){
            for(int j = 0 ; j < V[i].second ; j++){
                ans += V[i].first;
            }
        }
        return ans;
    }
};