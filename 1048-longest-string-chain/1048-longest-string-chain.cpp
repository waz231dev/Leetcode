class Solution {
    bool isPredecessor(string& s1,string& s2){
        if(s2.size()-s1.size() > 1 || s2.size() == s1.size()) return false;
        bool flag = false;
        for(int i = 0,j = 0; i < s1.size() ; j++){
            if(s1[i] != s2[j]){
                if(flag) return false;
                flag = true;
            }else{
                i++;
            }
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const auto& s1,const auto& s2){
            return s1.size() < s2.size();
        });
        int n = words.size();
        vector<int> dp(n,1);
        int ans = 1;
        // for(int i = 1 ; i < n ; i++){
        //     cout<<isPredecessor(words[i-1],words[i]);
        // }
        for(int i = 1 ; i < n ; i++){
            // cout<<words[i]<<" ";
            for(int j = 0 ; j < i ; j++){
                if(isPredecessor(words[j],words[i])){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            // cout<<dp[i]<<" ";
            ans = max(ans,dp[i]);
        }
        
        return ans;
    }
};