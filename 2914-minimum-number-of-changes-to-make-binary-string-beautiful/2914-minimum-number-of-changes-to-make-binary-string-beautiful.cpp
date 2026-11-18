class Solution {
public:
    int minChanges(string s) {
        int res = 0;

        for(int i = 0, p = -1; i < s.size() - 1; i++){
            if(s[i] != s[i + 1]){
                if(((i - p) & 1) == 1) res++, i++;
                p = i;
            }
        }

        return res;
    }
};