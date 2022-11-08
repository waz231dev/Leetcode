class Solution {
public:
    string makeGood(string s) {
        
        string ans = "";
        for(int i = 0 ; i < s.size() ;i++){
            if(i<s.size()-1 && abs(s[i]-s[i+1]) == 'a'-'A'){
                i++;
            }else if(abs(s[i]-ans.back()) == 'a'-'A'){
                ans.pop_back();
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};