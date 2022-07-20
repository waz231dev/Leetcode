class Solution {
public:
    bool isSubsequence(string& s,string word){
        int i = 0,j=0;
        int m = s.size(),n=word.size();
        while(i < m && j < n){
            if(s[i] == word[j]){
                i++,j++;
            }else{
                i++;
            }
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        // if(isSubsequence(s,"ace",0,0))
        //     cout<<"true";
        unordered_map<string,int> mp;
        for(auto word : words){
            mp[word]++;
        }
        
        for(auto it : mp){
            if(isSubsequence(s,it.first))
                count += it.second;
        }
        return count;
    }
};