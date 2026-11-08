class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();

        vector<int> same;
        
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] == s2[i]) same.push_back(i);
        
        vector<vector<string>> res;

        if(!same.empty()){
            if(same.front() > 0) res.push_back({ s1.substr(0, same.front()), s2.substr(0, same.front())});

            for(int i = 1; i < same.size(); i++){
                int cnt = same[i] - same[i - 1] - 1;
                
                if(cnt > 0) res.push_back({ s1.substr(same[i - 1] + 1, cnt), s2.substr(same[i - 1] + 1, cnt) });
            }
            
            if(same.back() < n - 1) res.push_back({ s1.substr(same.back() + 1, n - (same.back() + 1)), s2.substr(same.back() + 1, n - (same.back() + 1))});
        }
        else res.push_back({ s1, s2 });
        
        return res;
    }
};