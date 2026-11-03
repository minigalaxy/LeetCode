class Solution {
public:
    short minMoves(vector<int>& nums) {
        short res = 0;
        char m = 0;

        for(char n: nums) m = max(m, n);

        for(char n: nums) res += m - n;

        return res;
    }
};