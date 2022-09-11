class Solution {
    static bool compare(pair<int,int>& p1,pair<int,int>& p2){
        return p1.first>p2.first;
    }
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int m = 1e9+7;
        vector<pair<int,int>> ens(n);
        for(int i = 0 ; i < n ; i++){
            ens[i] = {efficiency[i],speed[i]};
        }
        
        sort(ens.begin(),ens.end(),compare);
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long speedSum = 0;
        long res = 0;
        for(auto it : ens){
            pq.push(it.second);
            speedSum += it.second;
            if(pq.size()>k){
                speedSum -= pq.top();
                pq.pop();
            }
            // cout<<it.second<<endl;
            // cout<<speedSum<<endl;
            res = max(res,speedSum*it.first);
            // cout<<res<<endl;
        }
        
        return res%m;
    }
};