class Solution {
    vector<vector<int>> dp;
    int solve(int i,int j,string& s,string& p){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == s.size() && j == p.size()){
            return dp[i][j] = 1;
        }
        // cout<<i<<j<<endl;
        if(j == p.size()) return dp[i][j] = 0;
        if(i == s.size()) {
            while(j<p.size() && p[j] == '*'){
                j++;
            }
            return dp[i][j] = j == p.size();
        }
        // cout<<i<<j<<endl;
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(i+1,j+1,s,p);
        if(p[j] == '*'){
            // cout<<i<<j<<endl;
            return dp[i][j] = solve(i+1,j,s,p) || solve(i,j+1,s,p);
        }
        return dp[i][j] = false;
        
    }
public:
    bool isMatch(string s, string p) {
        dp.resize(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(0,0,s,p);
    }
};