class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9+7;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]] = 1;
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            long long cnt = 0;
            for(int j = 0 ; j < i ; j++){
                if(arr[i]%arr[j] == 0){
                    if(mp.find(arr[i]/arr[j]) != mp.end()){
                        // cout<<mp[arr[j]];
                        cnt = (cnt%mod + ((long long)mp[arr[j]]*mp[arr[i]/arr[j]])%mod)%mod;
                    }
                }
            }
            mp[arr[i]] = (mp[arr[i]]+cnt)%mod;
            ans = (ans+mp[arr[i]])%mod;
            // cout<<i<<" "<<mp[arr[i]]<<endl;
        }
        
        return ans;
    }
};