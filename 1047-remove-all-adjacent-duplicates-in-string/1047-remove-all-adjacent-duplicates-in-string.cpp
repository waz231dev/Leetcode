class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        
        for(int i = 0 ; i < s.size() ; i++){
            if(i < s.size()-1 && s[i] == s[i+1]){
                i++;
            }else if(s[i] == ans.back()){
                ans.pop_back();
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};