class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;

        for(int i = 1, inc = 1, dec = 1; i < nums.size(); i++){
            if(nums[i - 1] < nums[i]) res = max(res, ++inc);
            else inc = 1;
            if(nums[i - 1] > nums[i]) res = max(res, ++dec);
            else dec = 1;
        }

        return res;
    }
};