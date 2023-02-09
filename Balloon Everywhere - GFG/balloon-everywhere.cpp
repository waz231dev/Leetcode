//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int> freq(5,0);
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'b'){
                freq[0]++;
            }else if(s[i] == 'a'){
                freq[1]++;
            }else if(s[i] == 'l'){
                freq[2]++;
            }else if(s[i] == 'o'){
                freq[3]++;
            }else if(s[i] == 'n'){
                freq[4]++;
            }
        }
        
        int ans = 1e9;
        for(int i = 0 ; i < 5 ; i++){
            if(i == 2 || i == 3){
                ans = min(ans,freq[i]/2);
            }else{
                ans = min(ans,freq[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends