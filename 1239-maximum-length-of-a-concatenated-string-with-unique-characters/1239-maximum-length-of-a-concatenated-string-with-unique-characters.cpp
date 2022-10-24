class Solution {
    bool isunique(string &s)
    {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++)
        {
            if(v[s[i]-'a']==1)
            {
                return false;
            }
            v[s[i]-'a']++;
        }
        return true;
    }
    int solve(int i,vector<string>& arr,string asf){
        if(!isunique(asf)) return -1e8;
        if(i < 0) return 0;
        
        int take = arr[i].size() + solve(i-1,arr,asf+arr[i]);
        int notTake = solve(i-1,arr,asf);
        return max(take,notTake);
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string asf="";
        return solve(n-1,arr,asf);
    }
};