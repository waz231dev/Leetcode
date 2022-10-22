//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    bool isAllStars(string& p,int i){
        for(int j = 0 ; j <= i ; j++){
            if(p[j] != '*') return false;
        }
        return true;
    }
    bool solve(int i,int j,string& p,string& s,vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        
        if(j<0 && i >= 0){
            return isAllStars(p,i);
        }
        
        if(p[i] == s[j] || p[i] == '?'){
            return dp[i][j] = solve(i-1,j-1,p,s,dp);
        }
        
        if(p[i] == '*') return dp[i][j] = solve(i-1,j,p,s,dp) || solve(i,j-1,p,s,dp);
        
        return dp[i][j] = false;
    }
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int m = pattern.size();
        int n = str.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,pattern,str,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends