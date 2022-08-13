class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int len = s.size();
        int n = words.size();
        if(len == 0 || n == 0)
            return ans;
        int wordLen = words[0].size();
        
        unordered_map<string,int> count;
        for(int i = 0 ; i < n ; i++){
            count[words[i]]++;
        }
        unordered_map<string,int> temp;
        for(int i = 0 ; i < len-wordLen*n+1 ; i++){
            
            for(int j = i ; j < i + n*wordLen ; j += wordLen){
                string currWord = s.substr(j,wordLen);
                temp[currWord]++;
            }
            
            if(temp == count)
                ans.push_back(i);
            
            temp.clear();
        }
        return ans;
    }
};