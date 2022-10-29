class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> p;
        for(int i = 0 ; i < plantTime.size() ; i++){
            p.push_back({growTime[i],plantTime[i]});
        }
        
        sort(p.begin(),p.end(),[](auto const& p1,auto const& p2){
            if(p1.first == p2.first) return p1.second > p2.second;
            return p1.first > p2.first;
        });
        
        int ans = 0;
        int pt = 0;
        for(int i = 0 ; i < p.size() ; i++){
            pt += p[i].second;
            ans = max(ans,pt+p[i].first);
        }
        
        return ans;
    }
};