//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        // code here
        vector<int> st;
        
        for(int x : asteroids){
            if(st.empty()){
                st.push_back(x);
            }else{
                if(x>0){
                    st.push_back(x);
                }else{
                    while(!st.empty() && st.back()>0 && st.back()<abs(x)){
                        st.pop_back();
                    }
                    if(!st.empty() && st.back() == abs(x)){
                        st.pop_back();
                        continue;
                    }
                    if(!st.empty() && st.back()>abs(x)){
                        continue;
                    }
                    st.push_back(x);
                }
            }
        }
        return st;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends