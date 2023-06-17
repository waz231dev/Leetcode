//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int left = 0;
        vector<int> mp(26,-1);
        int ans = 0;
        for(int right = 0 ; right < S.size() ; right++){
            if(mp[S[right]-'a'] != -1){
                left = max(mp[S[right]-'a']+1,left);
            }
            ans = max(ans,right-left+1);
            mp[S[right]-'a'] = right;
            // cout<<ans<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends