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
        
        vector<string> buckt(s.size()+1,"");
        
        for(auto it : freq){
            int count = it.second;
            char c = it.first;
            buckt[count] += string(count,c);
        }
        string res = "";
        for(int i = s.size() ; i > 0 ; i--){
            if(!buckt[i].empty()){
                res += buckt[i];
            }
        }
        return res;
    }
};