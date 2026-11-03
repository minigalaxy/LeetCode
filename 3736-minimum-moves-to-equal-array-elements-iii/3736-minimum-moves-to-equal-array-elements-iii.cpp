class Solution {
public:
    short minMoves(vector<int>& nums) {
        short res = 0;
        char m = *max_element(nums.begin(), nums.end());

        for(char n: nums) res += m - n;

        return res;
    }
};