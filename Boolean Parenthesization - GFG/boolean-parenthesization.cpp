//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod = 1003;
    int solve(int i,int j,int isTrue,string s,vector<vector<vector<int>>>& dp){
        if(i > j) return 0;
        if(i == j){
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        int ways = 0;
        for(int k = i+1 ; k < j ; k+=2){
            int lT = solve(i,k-1,1,s,dp);
            int lF = solve(i,k-1,0,s,dp);
            int rT = solve(k+1,j,1,s,dp);
            int rF = solve(k+1,j,0,s,dp);
            
            if(s[k] == '&'){
                if(isTrue){
                    ways += rT*lT;
                }else{
                    ways += (rT*lF) + (lT*rF) + (lF*rF);
                }
            }else if(s[k] == '|'){
                if(isTrue){
                    ways += (rT*lF) + (lT*rF) + (lT*rT);
                }else{
                    ways += (lF*rF);
                }
            }else{
                if(isTrue){
                    ways += (lT*rF) + (rT*lF);
                }else{
                    ways += (lT*rT) + (lF*rF);
                }
            }
        }
        
        return dp[i][j][isTrue] = ways%1003;
    }
public:
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return solve(0,N-1,1,S,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends