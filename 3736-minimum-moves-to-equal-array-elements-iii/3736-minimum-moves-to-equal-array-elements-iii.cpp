class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0, m = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > m) res += i * (nums[i] - m), m = nums[i];
            else res += m - nums[i];
        }

        return res;
    }
};