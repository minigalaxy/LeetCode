class Solution {
public:
    int minChanges(string s) {
        return ranges::count_if(s | ranges::views::chunk(2), [](auto c){ return c[0] != c[1]; });
    }
};