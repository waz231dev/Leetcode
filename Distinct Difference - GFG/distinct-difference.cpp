//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        
        for(int i = 1 ; i < N ; i++){
            mp2[A[i]]++;
        }
        vector<int> ans;
        for(int i = 0 ; i < N ; i++){
            ans.push_back(mp1.size()-mp2.size());
            mp1[A[i]]++;
            if(i < N-1){
                mp2[A[i+1]]--;
                if(mp2[A[i+1]] == 0) mp2.erase(A[i+1]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends