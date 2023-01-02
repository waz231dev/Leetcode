//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int lengthOfLIS(int nums[],int n) {
        
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i = 1 ; i < n ; i++){
            auto ind = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            if(ind == lis.size())
                lis.push_back(nums[i]);
            else
                lis[ind] = nums[i];
        }
        
        return lis.size();
    }
  public:
    int removeStudents(int H[], int N) {
        // code here
        return N - lengthOfLIS(H,N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends