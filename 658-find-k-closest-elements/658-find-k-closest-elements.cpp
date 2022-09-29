class Solution {
    static bool compare(pair<int,int>& p1,pair<int,int>& p2){
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        
        return p1.first < p2.first;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<int,int>> v;
        for(int i = 0 ; i < arr.size() ; i++){
            v.push_back({abs(arr[i]-x),arr[i]});
        }
        
        sort(v.begin(),v.end(),compare);
        vector<int> ans(k);
        for(int i = 0 ; i < k ; i++){
            ans[i] = v[i].second;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};