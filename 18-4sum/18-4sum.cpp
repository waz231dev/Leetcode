class Solution {
public:
     vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
		set<vector<int> >rs;
		int n = nums.size();
		for (int i = 0; i < n - 3; i++) {
			for (int j = i + 1; j < n - 2; j++) {
				int p = j + 1;
				int q = n - 1;

				while (p < q) {
					long sum = (long)nums[i] + nums[j] + nums[p] + nums[q];
					if (sum == target) {
						vector<int> tmp(4);
						tmp[0] = nums[i];
						tmp[1] = nums[j];
						tmp[2] = nums[p];
						tmp[3] = nums[q];
						rs.insert(tmp);
						p++;
						q--;
					} else if (sum < target) {
						p++;
					} else {
						q--;
					}
				}
			}
		}
		vector<vector<int> > result(rs.begin(), rs.end());
		return result;
    }
};