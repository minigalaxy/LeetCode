class Solution {
public:
    int minChanges(string s) {
        vector<int> parts;
        parts.push_back(1);

        for(int i = 1; i < s.size(); i++){
            if(s[i - 1] != s[i]) parts.push_back(1);
            else parts.back()++;
        }

        int res = 0;

        for(int i = 0; i < parts.size() - 1; i++){
            if((parts[i] & 1) == 1){
                parts[i + 1]--;
                res++;
            }
        }

        return res;
    }
};