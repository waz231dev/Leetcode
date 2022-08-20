class Solution {
public:
    int dp[7001][2];
    int solve(int pos,int a,int b,int x,unordered_set<int>& forb,int back){
        
        if(pos == x)
            return 0;
        
        if(pos < 0 || pos > 6000 || forb.find(pos) != forb.end()){
            return 1e9;
        }
        
        if(dp[pos][back] != -1){
            return dp[pos][back];
        }
        dp[pos][back] = solve(pos+a,a,b,x,forb,0)+1;
        
        if(!back){
            dp[pos][back] = min(dp[pos][back],1 + solve(pos-b,a,b,x,forb,1));
        }
        
        return dp[pos][back];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        memset(dp,-1,sizeof(dp));
        unordered_set<int> forb(forbidden.begin(),forbidden.end());
        
        int ans = solve(0,a,b,x,forb,0);
        
        return ans > 1e9 ? -1 : ans;
    }
};