class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> bucket(100001,0);
        for(int x : arr){
            bucket[x]++;
        }
        
        sort(bucket.begin(),bucket.end(),greater<int>());
        
        int i;
        int delFreq = 0;
        for(i = 0 ; i < bucket.size() && delFreq < n/2 ; i++){
            delFreq += bucket[i];
        }
        return i;
    }
};