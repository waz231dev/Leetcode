class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> freq;
        for(char c : t){
            freq[c]++;
        }
        int i = 0;
        int j;
        int minLen = s.size()+1;
        int minStart = 0;
        int required = t.size();
        for(j = 0 ; j < s.size() ; j++){
            if(freq.find(s[j]) != freq.end()){
                freq[s[j]]--;
                if(freq[s[j]] >= 0)
                    required--;
            }
            
            while(!required){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    minStart = i;
                }
                
                if(freq.find(s[i]) != freq.end()){
                    freq[s[i]]++;
                    if(freq[s[i]]>0)
                        required++;
                }
                i++;
            }
        }
        
        if(minLen > s.size()) return "";
        
        return s.substr(minStart,minLen);
    }
};