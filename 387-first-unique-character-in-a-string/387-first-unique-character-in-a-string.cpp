class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,INT_MAX);
        for(int i = 0 ; i <s.size();i++){
            if(freq[s[i]-'a'] == INT_MAX){
                freq[s[i]-'a'] = i;
            }else{
                freq[s[i]-'a'] = -1;
            }
        }
    int ans = INT_MAX;
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] >= 0)
                ans = min(ans,freq[i]);
            }
        return ans == INT_MAX ? -1 : ans;
    }
};