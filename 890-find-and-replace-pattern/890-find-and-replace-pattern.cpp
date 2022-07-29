class Solution {
    string normal(string word){
        unordered_map<char,int> mapping;
        for(char c : word){
            if(mapping.find(c) == mapping.end())
                mapping[c] = mapping.size();
        }
        
        for(int i = 0 ; i < word.length() ; i++){
            word[i] = 'a' + mapping[word[i]];
        }
        return word;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        pattern = normal(pattern);
        for(string word : words){
            if(pattern == normal(word))
                res.push_back(word);
        }
        return res;
    }
};