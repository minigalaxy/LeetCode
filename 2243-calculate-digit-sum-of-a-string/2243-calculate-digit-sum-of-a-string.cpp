class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string ns;

            for(int i = 0; i < s.size(); i += k){
                int g = 0;

                for(int j = 0; j < k && i + j < s.size(); j++) g += s[i + j] - '0';

                ns += to_string(g);
            }

            s = ns;
        }

        return s;
    }
};