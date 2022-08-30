class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int,int> count;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i] == key){
                count[nums[i+1]]++;
            }
        }
        int max = 0;
        int ans;
        for(auto it = count.rbegin() ; it != count.rend() ; it++){
            if(it->second > max){
                ans = it->first;
                max = it->second;
            }
        }
        return ans;
    }
};