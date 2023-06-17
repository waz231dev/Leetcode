//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &fruits) {
        int i = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        for(int j = 0 ; j < n ; j++){
            mp[fruits[j]]++;
            while(mp.size() > 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            ans = max(ans,j-i+1);
            // cout<<j<<"-"<<i<<"->"<<ans<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends