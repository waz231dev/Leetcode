class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        stringstream str(s);
        string word;
        int i = 0;
        unordered_map<string,char> mp1;
        unordered_map<char,string> mp2;
        while(str>>word){
            if(i == n) return false;
            if(mp1.find(word) != mp1.end()){
                if(mp1[word] != pattern[i]){
                    return false;
                }
            }else{
                mp1[word] = pattern[i];
            }
            if(mp2.find(pattern[i]) != mp2.end()){
                if(mp2[pattern[i]] != word){
                    return false;
                }
            }else{
                mp2[pattern[i]] = word;
            }
            i++;
        }
        return i == n;
    }
};