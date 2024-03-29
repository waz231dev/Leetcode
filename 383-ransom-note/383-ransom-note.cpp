class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int freq[26] = {0};
        for(char c : magazine){
            freq[c-'a']++;
        }
        for(char c : ransomNote){
            freq[c-'a']--;
            if(freq[c-'a'] < 0)
                return false;
        }
        
        // for(int i = 0 ; i < 26 ; i++){
        //     if(freq[i]<0)
        //         return false;
        // }
        
        return true;
    }
};