//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string lower = "";
        string upper = "";
        for(int i = 0 ; i < n ; i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                upper += str[i];
            }else{
                lower += str[i];
            }
        }
        
        sort(begin(lower),end(lower));
        sort(begin(upper),end(upper));
        
        int i = 0;
        int j = 0;
        string ans = "";
        for(int k = 0 ; k < n ; k++){
            if(str[k] >= 'A' && str[k] <= 'Z'){
                ans += upper[j];
                j++;
            }else{
                ans += lower[i];
                i++;
            }
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
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends