class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int,int>> numsIndex(n);
        for(int i = 0 ; i < n ; i++){
            numsIndex[i] = make_pair(nums[i],i);
        }
        
        vector<int> count(n,0);
        
        mergeSort(count,numsIndex,0,n-1);
        return count;
    }
    
private:
    void mergeSort(vector<int>& count,vector<pair<int,int>>& v,int left,int right){
        if(left<right){
            int mid = left + (right-left)/2;
            mergeSort(count,v,left,mid);
            mergeSort(count,v,mid+1,right);
            merge(count,v,left,mid,right);
        }
    }
    
    void merge(vector<int>& count,vector<pair<int,int>>& v,int left,int mid, int right){
        vector<pair<int,int>> temp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;
        int cnt = 0;
        while(i<=mid && j <= right){
            
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }else{
                count[v[i].second] += right-j+1;
                temp[k++] = v[i++];
            }
        }
        
        while(i<=mid){
            temp[k++]=v[i++];
        }
        while(j<=right){
           temp[k++]=v[j++];
        }
        for(int i=left;i<=right;i++){
           v[i]=temp[i-left];
        }
    }
};