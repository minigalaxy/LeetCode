class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(), s.end())) return 0;
        else {
            if(s.size() == 2) return -1;

            int min_idx = 0, max_idx = 0;

            for(int i = 0; i < s.size(); i++){
                if(s[i] < s[min_idx]) min_idx = i;
                if(s[i] >= s[max_idx]) max_idx = i;
            }

            if(min_idx == 0 || max_idx == s.size() - 1) return 1;
            else if(min_idx == s.size() - 1 && max_idx == 0) return 3;
            else return 2;
        }
    }
};