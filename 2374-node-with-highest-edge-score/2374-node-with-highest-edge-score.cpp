class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n,0);
        long long max = 0;
        int ans;
        for(int i = 0 ; i < edges.size() ; i++){
            score[edges[i]] += i;
        }
        
        for(int i = 0 ; i < score.size() ; i++){
            if(score[i] > max){
                max = score[i];
                ans = i;
            }
        }
        return ans;
    }
};