class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        for(int i = 0 ; i < arr.size() ; i++){
            // cout<<arr[arr[i]-1];
            if(arr[abs(arr[i])-1] > 0){
                arr[abs(arr[i])-1] *= -1;
            }else{
                ans.push_back(abs(arr[i]));
            }
        }
        return ans;
    }
};