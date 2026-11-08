class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        vector<int> abc;

        for(int i = 0; i < n - 2; i++){
            if(s.substr(i, 3) == "abc") abc.push_back(i);
        }

        long long res = n;
        
        if(!abc.empty()) res += 1LL * (abc.front() + 2) * (abc.front() + 1) / 2 + 1LL * (n - (abc.back() + 1)) * (n - (abc.back() + 1) - 1) / 2;
        else res += 1LL * n * (n - 1) / 2;

        for(int i = 1; i < abc.size(); i++){
            res += 1LL * (abc[i] + 2 - (abc[i - 1] + 1)) * (abc[i] + 2 - (abc[i - 1] + 1) - 1) / 2;
        }

        return res;
    }
};