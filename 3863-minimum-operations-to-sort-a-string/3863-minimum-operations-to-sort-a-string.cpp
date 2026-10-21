class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(), s.end())) return 0;
        else {
            if(s.size() == 2) return -1;

            auto min_it = s.begin(), max_it = s.begin();

            for(auto it = s.begin(); it != s.end(); it++){
                if(*it < *min_it) min_it = it;
                if(*it >= *max_it) max_it = it;
            }

            if(min_it == s.begin() || max_it == s.begin() + s.size() - 1) return 1;
            else if(min_it == s.begin() + s.size() - 1 && max_it == s.begin()) return 3;
            else return 2;
        }
    }
};