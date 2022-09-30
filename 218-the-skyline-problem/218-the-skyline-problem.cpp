class Solution {
//     static bool compare(pair<int,int>& p1,pair<int,int>& p2){
//         if(p1.first == p2.first){
//             p1.second < p2.second;
//         }
        
//         return p1.first < p2.first;
//     }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{0};
        
        vector<pair<int,int>> v;
        for(auto b : buildings){
            v.push_back({b[0],-b[2]});
            v.push_back({b[1],b[2]});
        }
        
        sort(v.begin(),v.end());
        
        int curr = 0;
        
        for(int i = 0 ; i < v.size() ; i++){
            int x = v[i].first;
            int ht = v[i].second;
            
            if(ht < 0){
                pq.insert(-ht);
            }else{
                auto it = pq.find(ht);
                pq.erase(it);
            }
            
            auto pqTop = *pq.rbegin();
            if(curr != pqTop){
                curr = pqTop;
                ans.push_back({x, curr});
            }
        }
        return ans;
    }
};