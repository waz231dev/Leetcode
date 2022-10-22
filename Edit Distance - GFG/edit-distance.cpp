//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int solve(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        //Matches
        if(s[i] == t[j]) return dp[i][j] = solve(i-1,j-1,s,t,dp);
        
        int insert = 1+solve(i,j-1,s,t,dp);
        int remove = 1+solve(i-1,j,s,t,dp);
        int replace = 1+solve(i-1,j-1,s,t,dp);
        
        return dp[i][j] = min(insert,min(remove,replace));
    }
  public:
    int editDistance(string s, string t) {
        // Code here
        int m = s.size();
        int n = t.size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends