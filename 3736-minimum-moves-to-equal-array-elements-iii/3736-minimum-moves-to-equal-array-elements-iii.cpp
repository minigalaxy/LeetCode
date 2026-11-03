class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0, m = *max_element(nums.begin(), nums.end());

        for(int n: nums) res += m - n;

        return res;
    }
};