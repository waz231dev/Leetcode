class Solution {
    vector<int> countLetters(string& word){
        vector<int> freq(26);
        for(char c : word)
            freq[c-'a']++;
        return freq;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> tempFreq(26);
        vector<int> freq(26);
        for(string word : words2){
            tempFreq = countLetters(word);
            for(int i = 0 ; i < 26 ; i++){
                freq[i] = max(freq[i],tempFreq[i]);
            }
        }
        
        for(string word : words1){
            tempFreq = countLetters(word);
            bool flag = true;
            for(int i = 0 ; i < 26 ; i++){
                if(tempFreq[i] < freq[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(word);
        }
        return ans;
    }
};