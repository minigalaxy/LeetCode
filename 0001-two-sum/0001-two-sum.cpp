class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums2;
        vector<int> res = { 0, 0 };
        
        for(int i = 0; i < nums.size(); i++) nums2.push_back({ nums[i], i });

        sort(nums2.begin(), nums2.end());

        int l = 0, r = nums.size() - 1;
        long long sum;

        while(l < r){
            sum = 1LL * nums2[l].first + nums2[r].first;

            if(sum > target) r--;
            else if(sum < target) l++;
            else {
                res[0] = nums2[l].second, res[1] = nums2[r].second;

                break;
            }
        }

        return res;
    }
};