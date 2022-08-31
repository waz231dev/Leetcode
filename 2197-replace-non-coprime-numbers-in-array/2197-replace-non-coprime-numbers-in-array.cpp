class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        stack<int> st;
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            int a = nums[i];
            while(!st.empty() && __gcd(a,st.top()) > 1){
                int b = st.top();
                st.pop();
                a = a*(b/__gcd(a,b));                
            }
            st.push(a);
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};