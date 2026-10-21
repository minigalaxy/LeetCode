class Solution {
public:
    int minOperations(string s) {
        string sorted_s = s;

        sort(sorted_s.begin(), sorted_s.end());

        if(s == sorted_s) return 0;
        else {
            if(s.size() == 2) return -1;

            int min_idx = min_element(s.begin(), s.end()) - s.begin();
            int max_idx = max_element(s.rbegin(), s.rend()) - s.rbegin();

            if(min_idx == 0 || max_idx == 0) return 1;
            else if(min_idx == s.size() - 1 && max_idx == s.size() - 1) return 3;
            else return 2;
        }
    }
};