class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long maxSum = 0;
    // int flag = 1;
    // for(int i = 0 ; i < n ; i++){
    //     maxSum = max(maxSum,(long long)arr[i]);
    //     if(arr[i]>0){
    //         flag = 0;
    //         break;
    //     }
    // }
    // if(flag){
    //     return maxSum;
    // }
    
    long long currSum = 0;
    
    for(int i = 0 ; i < n*min(2,k) ; i++){
        currSum += (arr[i%n]);
//         cout<<currSum<<endl;
        if(currSum < 0)
            currSum = 0;
        maxSum = max(maxSum,currSum);
    }
        return (maxSum + max(0ll,accumulate(arr.begin(),arr.end(),0ll)*max(0,k-2)))%1000000007;
    }
};