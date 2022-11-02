class Solution {
    bool valid(string& s1,string& s2){
        bool flag = false;
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] != s2[i]){
                if(flag) return false;
                flag = true;
            }
        }
        return true;
    }
    int solve(string& start,string& end,vector<string>& bank,vector<bool>& vis){
        if(start == end) return 0;
        int ans = 1e9;
        for(int i = 0 ; i < bank.size() ; i++){
            if(!vis[i] && valid(start,bank[i])){
                vis[i] = true;
                ans = min(ans,1+solve(bank[i],end,bank,vis));
                vis[i] = false;
            }
        }
        
        return ans;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        int n = bank.size();
        vector<bool> vis(n,false);
        int ans = solve(start,end,bank,vis);
        return ans >= 1e9 ? -1 : ans;
    }
};