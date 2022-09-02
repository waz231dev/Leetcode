class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        // cout<<n<<endl;
        vector<int> temp = nums1;
        sort(temp.begin(),temp.end());
        long diff = 0;
        long maxDecrement = 0;
        for(int i = 0 ; i < n ; i++){
            long currDiff = abs(nums1[i]-nums2[i]);
            diff += currDiff;
            int lo = 0;
            int hi = n;
            while(lo<hi){
                int mid = (lo+hi)/2;
                if(temp[mid]>=nums2[i])
                    hi = mid;
                else
                    lo = mid + 1;
            }
            // if(lo>=n)
            //     cout<<i<<lo<<endl;
            if(lo<n)maxDecrement = max(maxDecrement,currDiff-abs(temp[lo]-nums2[i]));
            if(lo>0) maxDecrement = max(maxDecrement,currDiff-abs(temp[lo-1]-nums2[i]));
        }
        
        return (diff-maxDecrement)%1000000007;
    }
};