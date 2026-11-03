class Solution {
public:
    int minMoves(vector<int>& nums) {
        short res = 0, m = *max_element(nums.begin(), nums.end());

        for(char n: nums) res += m - n;

        return res;
    }
};