//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    long long int solve(int i,int r[],int g[], int b[], int prev,vector<vector<long long int>>& dp){
        if(i < 0){
            return 0;
        }
        
        if(dp[i][prev] != -1){
            return dp[i][prev];
        }
        if(prev == 0){
            return dp[i][prev] = min(g[i] + solve(i-1,r,g,b,1,dp),b[i] + solve(i-1,r,g,b,2,dp));
        }else if(prev == 1){
            return dp[i][prev] = min(r[i] + solve(i-1,r,g,b,0,dp),b[i] + solve(i-1,r,g,b,2,dp));
        }else if(prev == 2){
            return dp[i][prev] = min(g[i] + solve(i-1,r,g,b,1,dp),r[i] + solve(i-1,r,g,b,0,dp));
        }
        
        return dp[i][prev] = min(r[i] + solve(i-1,r,g,b,0,dp),min(g[i] + solve(i-1,r,g,b,1,dp),b[i] + solve(i-1,r,g,b,2,dp)));
    }
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here
        vector<vector<long long int>> dp(N,vector<long long int>(4,-1));
        return solve(N-1,r,g,b,3,dp);
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends