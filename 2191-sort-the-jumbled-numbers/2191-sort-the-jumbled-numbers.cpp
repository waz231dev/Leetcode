class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> temp;
        
        for(int i = 0 ; i < nums.size() ; i++){
            string num = to_string(nums[i]);
            string mapped = "";
            for(char c : num){
                mapped += mapping[c-'0'] + '0';
            }
            temp.push_back({stoi(mapped),i});
        }
        
        sort(temp.begin(),temp.end());
        vector<int> ans;
        for(int i = 0 ; i < temp.size() ; i++){
            ans.push_back(nums[temp[i].second]);
        }
        return ans;
    }
};