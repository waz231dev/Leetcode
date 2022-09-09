class Solution {
    static bool compare(vector<int>& v1,vector<int>& v2){
        if(v1[0] == v2[0]){
            return v1[1]<v2[1];
        }
        return v1[0]>v2[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),compare);
        int currMax = INT_MIN;
        int ans = 0;
        for(int i = 0 ; i < properties.size() ; i++){
            if(properties[i][1] < currMax)
                ans++;
            
            currMax = max(currMax,properties[i][1]);
        }
        return ans;
    }
};