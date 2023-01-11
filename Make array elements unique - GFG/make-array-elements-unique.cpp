//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    long long int nextGreater(vector<int>& arr,int x,unordered_set<int>& s){
        int low = 0;
        int n = arr.size();
        int high = n-1;
        int ans = x+1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] <= ans){
                if(arr[mid] == ans){
                    ans++;
                    high = n -1;
                }
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        while(s.find(ans) != s.end()){
            ans++;
        }
        return ans;
    }
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        sort(arr.begin(),arr.end());
        unordered_set<int> s;
        s.insert(arr[0]);
        long long int ans = 0;
        for(int i = 1 ; i < N ; i++){
            if(s.find(arr[i]) != s.end()){
                int ng = nextGreater(arr,arr[i],s);
                s.insert(ng);
                ans += (ng-arr[i]);
            }else{
                s.insert(arr[i]);
            }
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends